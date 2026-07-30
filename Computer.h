//
//  Computer.hpp
//  ExploreGame
//
//  Created by tanizawa atsushi on 2026/04/16.
//

#pragma once

#include <stdio.h>
#include <deque>
#include <queue>
#include "ofMain.h"
#include "Player.h"

struct Node {
    int x, y;
    int g;// スタートからの実コスト
    int h;// ゴールまでの推定コスト（ヒューリスティック）
    vector<pair<int, int>> path;
    
    // 優先度付きキューで「コストが低い順」に並べるための比較演算子
        bool operator>(const Node& other) const {
            return (g + h) > (other.g + other.h);
        }
};

class Com : public Player{
public:
    void setup();
    void update(int tilesize, vector<vector<int>>& mapData, int gridW, int gridH); // updateだけCOM専用に書き換える
        
    // COM独自のプロパティ
    int goalX, goalY;
    int moveInterval = 500; // 移動速度（難易度）
    uint64_t lastPathfindTime = 0; // 前回復刻した時間
    const uint64_t pathfindCooldown = 300; // 再計算の最小間隔（ミリ秒）
    // 最近通った場所の履歴（最大5〜10歩分くらい）
    std::deque<ofVec2f> history;
    const int maxHistory = 10;
    uint64_t lastMoveTime = 0;
    
    vector<pair<int, int>> currentPath;
    void findPath(vector<vector<int>>& map, int gridW, int gridH);
    
    void drawFace(float screenX, float screenY, float w, float h, ofColor color = ofColor::white);
};


