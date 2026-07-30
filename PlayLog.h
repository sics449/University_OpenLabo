//
//  PlayLog.hpp
//  ExploreGame
//
//  Created by tanizawa atsushi on 2026/05/21.
//

#pragma once

#include <stdio.h>
#include "ofMain.h"

// 定義書（コードブック）の共通化
enum LogMapDifficulty { L_EASY = 0, L_NORMAL = 1, L_HARD = 2, L_VERY_HARD = 3 };
enum LogMulLimit { L_99 = 0, L_10x10 = 1, L_11x11 = 2, L_NONE = 3 };

struct PlaySessionData {
    string sessionId;
    int age;
    int courseId;     // コース番号
    int stageId;      // ステージ番号
    bool isCleared;   // クリアしたか
    
    // クイズ統計
    int totalQuizzes;
    int correctAnswers;
    int hintUses;
    float totalTime;
    float avgTime;
    
    // アイテム・探索統計
    // 0:爆弾, 1:時計, 2:靴...など、インデックスで種類を区別
    std::vector<int> itemUsage;
    int treasureTouches; // 宝箱に触れた回数
    int penaltyCount;    // ペナルティ回数
    
    // --- 追加：子供の行動分析用の指標 ---
    float totalDistance;      // ステージ内の総移動距離（迷子度の指標）
    int maxConsecutiveMiss;   // 連続不正解の最大数（お手上げ度の指標）
    float timeToFirstAction;  // 開始から最初の行動までの時間（迷い度の指標）
};

class PlayLogger {
public:
    // ゲーム開始時に一度だけ呼ぶ
    void setup(int age);

    // ステージ（またはコース）開始時に呼ぶ
    void startStage(int courseId, int stageId);
    
    // プレイヤーが移動したときに、そのフレームの移動距離を足していく
    void recordMovement(float distance);

    // クイズ回答ごとに呼ぶ
    void recordQuizResult(bool isCorrect, bool usedHint, float responseTime);

    // アイテム使用時に呼ぶ (itemIdは0, 1, 2...等)
    void recordItemUse(int itemId);

    // 宝箱に触れるなどの特定アクション時に呼ぶ
    void recordTreasureTouch();
    void recordPenalty();

    // ステージ終了・クリア時に呼び、CSVに書き出す
    void endAndSaveStage(bool isCleared);

private:
    PlaySessionData currentData;
    void resetCurrentData();
    
    // 内部計算用のワーク変数
    int tempConsecutiveMiss;  // 現在の連続不正解数を一時的にカウント
    float stageStartTime;     // ステージ開始時の時間（ofGetElapsedTimef用）
    bool hasTakenFirstAction; // 最初の行動（移動や回答、アイテム使用）を既に行ったか
    
    void triggerFirstAction(); // 最初の行動を検知して時間を記録する内部関数
    
    const int ITEM_TYPE_COUNT = 4; // 記録したいアイテムの種類数
};

// 難易度（マップ）ごとに通算のプレイ回数と勝利数を保持する構造体
struct MapPlayData {
    int playCount = 0;
    int winCount = 0;
};
