//
//  Player.hpp
//  ExploreGame
//
//  Created by tanizawa atsushi on 2026/04/15.
//

#pragma once

#include <stdio.h>
#include "ofMain.h"

class Player {
public:
    void setup();
    void update(int tilesize);
    void draw(int tileSize);
    void move(int dx, int dy, int gridW, int gridH, vector<vector<int>>& mapData, int tilesize); // 12はGridH

    int x, y; // グリッド座標
    ofVec2f drawPos;
    int dir;  // 向き (0:DOWN, 1:LEFT, 2:RIGHT, 3:UP)
    int frame; // アニメーションのコマ (0, 1, 2)
    
protected:
    ofImage playerSheet;
    uint64_t lastAnimTime; // ← アニメーション用のタイマーを追加
    int animDir = 1;
};
