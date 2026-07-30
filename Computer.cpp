//
//  Computer.cpp
//  ExploreGame
//
//  Created by tanizawa atsushi on 2026/04/16.
//

#include "Computer.h"
void Com::setup(){
    playerSheet.load("pipo-charachip018.png");
    // 2. 拡大したときにドットを綺麗に見せる設定
    playerSheet.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
        
    // 3. 初期状態の設定
    dir = 0;    // 下向き
    frame = 1;  // 直立
    lastAnimTime = ofGetElapsedTimeMillis();
        
    moveInterval = 1000; // 移動速度（ミリ秒）
    lastMoveTime = ofGetElapsedTimeMillis();
    
    currentPath.clear(); //再挑戦時に初期位置からスタートさせるため
    lastMoveTime = ofGetElapsedTimeMillis();
}

//-------------------------------
void Com::findPath(vector<vector<int>>& map, int gridW, int gridH) {
    currentPath.clear();
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    // 経路計算ごとにランダムな「寄り道度（探索のブレ）」を生成
    // 毎回同じ経路を完璧に選ぶのを防ぎ、人間らしい「迷い」を
    float pathNoise = ofRandom(0.8f, 1.8f);

    auto getH = [&](int tx, int ty) {
        // マンハッタン距離
        int baseDist = (abs(goalX - tx) + abs(goalY - ty)) * 10;
        
        // ゴール付近では正確に、遠くではノイズ（pathNoise）の影響を強くする
        // これにより、プレイヤーが遠くにいる（行き止まり等にいる）時はCOMがルートを「見誤る」ように
        return (int)(baseDist * pathNoise);
    };

    pq.push({x, y, 0, getH(x, y), {}});

    vector<int> minCost(gridW * gridH, 1e9);
    minCost[x * gridH + y] = 0;

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (curr.x == goalX && curr.y == goalY) {
            currentPath = curr.path;
            return;
        }

        if (curr.g > minCost[curr.x * gridH + curr.y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < gridW && ny >= 0 && ny < gridH) {
                int tile = map[nx][ny];
                if (tile == 0 || tile == 8 || (tile >= 10 && tile <= 17)) {
                    
                    // 過去に通った場所（history）はコストを高くする
                    // これにより「行ったり来たり」のループを防ぐ
                    int moveCost = 10;
                    for (auto& histPos : history) {
                        if ((int)histPos.x == nx && (int)histPos.y == ny) {
                            moveCost += 15; // 過去に通ったマスは通りにくくする（索敵の広がりにも繋がる）
                        }
                    }

                    int nextG = curr.g + moveCost;
                    if (nextG < minCost[nx * gridH + ny]) {
                        minCost[nx * gridH + ny] = nextG;
                        
                        auto nextPath = curr.path;
                        nextPath.push_back({nx, ny});
                        pq.push({nx, ny, nextG, getH(nx, ny), nextPath});
                    }
                }
            }
        }
    }
}
//-------------------------------
void Com::update(int tilesize, vector<vector<int>>& mapData, int gridW, int gridH) {
    Player::update(tilesize);

    uint64_t now = ofGetElapsedTimeMillis();
    int currentInterval = moveInterval;

    if (!currentPath.empty()) {
        pair<int, int> nextStep = currentPath.front();
        if (!history.empty()) {
            ofVec2f lastPos = history.back();
            if (nextStep.first == (int)lastPos.x && nextStep.second == (int)lastPos.y) {
                currentInterval = moveInterval / 3;
            }
        }
    }

    if (now - lastMoveTime < currentInterval) return;

    // 「常に最新のゴールを追いかける」のをやめる
    // currentPath がまだ残っている（＝まだ迷いながら歩いている途中）なら、
    // クールダウン（pathfindCooldown）が明けるまではプレイヤーの位置が変わっても経路を再計算しない
    // これにより、プレイヤーが行き止まりに急に方向転換しても、COMは古いルートを数歩進むため「遅れ」が生じる
    if (currentPath.empty() || (now - lastPathfindTime > pathfindCooldown && currentPath.size() > 5)) {
        findPath(mapData, gridW, gridH);
        lastPathfindTime = now; // 再計算時間を記録
    }

    if (!currentPath.empty()) {
        // 実際に移動する直前に、今の座標を履歴に保存
        history.push_back(ofVec2f(x, y));
        if (history.size() > maxHistory) history.pop_front();

        pair<int, int> nextStep = currentPath.front();
        
        if (nextStep.first == x && nextStep.second == y) {
            currentPath.erase(currentPath.begin());
            if (currentPath.empty()) return;
            nextStep = currentPath.front();
        }

        currentPath.erase(currentPath.begin());

        if (nextStep.first > x) dir = 2;
        else if (nextStep.first < x) dir = 1;
        else if (nextStep.second > y) dir = 0;
        else if (nextStep.second < y) dir = 3;

        x = nextStep.first;
        y = nextStep.second;
        lastMoveTime = now;
    }
}

//---------------------------------
void Com::drawFace(float screenX, float screenY, float w, float h, ofColor color) {
    // 親クラス(Player)がロードした playerSheet をそのまま利用できます
    if (playerSheet.isAllocated()) {
        float sw = playerSheet.getWidth() / 3.0f;  // 1マスの幅
        float sh = playerSheet.getHeight() / 4.0f; // 1マスの高さ
        
        // 正面を向いて足が止まっている位置（真ん中の列=1、上の行=0）
        float sx = 1 * sw;
        float sy = 0 * sh;
        
        // 頭の部分だけにするため、切り出す高さを少し小さく(0.6倍)する
        float cropH = sh * 0.6f;
        ofSetColor(color);
        // 指定された座標を中心に、頭の部分を切り出して描画
        // (0,0) を基準に回転させるため、引数の中心位置からサイズ w, h の半分を引いて描画
        playerSheet.drawSubsection(screenX - w / 2.0f, screenY - h / 2.0f, w, h, sx, sy, sw, cropH);
    }
}
