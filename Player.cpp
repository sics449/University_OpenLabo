//
//  Player.cpp
//  ExploreGame
//
//  Created by tanizawa atsushi on 2026/04/15.
//

#include "Player.h"

void Player::setup(){
    // ...
    playerSheet.load("pipo-charachip001.png");
    
    // 拡大してもドットをパキッと表示させる設定
    playerSheet.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    x = 1;
    y = 1;
    drawPos.set(0, 0);
    dir = 0; // 下向き
    frame = 1; // 直立（真ん中）
    lastAnimTime = ofGetElapsedTimeMillis(); // タイマー初期化
}

void Player::update(int tilesize) {
    // 目標のピクセル座標
    float speed = 0.2;
    
    float targetX = x * tilesize;
    float targetY = y * tilesize;

    // 現在の描画位置を目標に近づける (0.2はスピード。0.1〜0.3で調整)
    drawPos.x += (targetX - drawPos.x) * speed;
    drawPos.y += (targetY - drawPos.y) * speed;
    // --- 常時アニメーション処理 ---
    uint64_t now = ofGetElapsedTimeMillis();
    if (now - lastAnimTime > 200) { // 200msごとにコマを進める（足踏みの速さ）
        // frameの動き: 0 -> 1 -> 2 -> 1 -> 0 ... (右足->直立->左足->直立)
        frame += animDir;
        
        if (frame >= 2) {
            frame = 2; animDir = -1;
            
        } // 左足まで行ったら戻る
        if (frame <= 0) {
            frame = 0; animDir = 1;
        }// 右足まで行ったら進む
        
        lastAnimTime = now;
    }
}

void Player::draw(int tileSize) {
    // 1コマのサイズを計算
    float sw = playerSheet.getWidth() / 3;
    float sh = playerSheet.getHeight() / 4;
    
    // 切り出し位置の計算
    float sx = frame * sw;
    float sy = dir * sh;

    //ofSetColor(255);
    playerSheet.drawSubsection(drawPos.x, drawPos.y, tileSize, tileSize, sx, sy, sw, sh);
}

void Player::move(int dx, int dy, int gridW, int gridH, vector<vector<int>>& mapData, int tilesize){
    if (dy > 0) dir = 0; // 下
    else if (dy < 0) dir = 3; // 上
    else if (dx > 0) dir = 2; // 右
    else if (dx < 0) dir = 1; // 左

    // 2. 移動先の座標を計算
    int nextX = x + dx;
    int nextY = y + dy;
        
    if (nextX >= 0 && nextX < gridW && nextY >= 0 && nextY < gridH) {
        // 重要：y * gridW + nextX の順序で計算することで、2次元配列の並びと一致
        int tile = mapData[nextX][nextY];

        // 通行可能（0:草原, 8:木の床, 3:道）のみ許可
        if (tile == 0 || tile == 3 || tile == 8 || (tile >= 10 && tile <= 17)) {
            x = nextX;
            y = nextY;
        }
    }
}
