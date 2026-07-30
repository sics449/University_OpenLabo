//
//  PlayLog.cpp
//  ExploreGame
//
//  Created by tanizawa atsushi on 2026/05/21.
//

#include "PlayLog.h"

void PlayLogger::setup(int age) {
    currentData.age = age;
    // セッションごとにユニークなIDを生成
    currentData.sessionId = ofGetTimestampString("%Y%m%d_%H%M%S");
}

void PlayLogger::resetCurrentData() {
    currentData.totalQuizzes = 0;
    currentData.correctAnswers = 0;
    currentData.hintUses = 0;
    currentData.totalTime = 0.0f;
    currentData.avgTime = 0.0f;
    currentData.treasureTouches = 0;
    currentData.penaltyCount = 0;
    
    // 追加指標の初期化
    currentData.totalDistance = 0.0f;
    currentData.maxConsecutiveMiss = 0;
    currentData.timeToFirstAction = 0.0f;
    
    tempConsecutiveMiss = 0;
    stageStartTime = ofGetElapsedTimef(); // 開始時の経過秒数を記録
    hasTakenFirstAction = false;
    
    currentData.itemUsage.assign(ITEM_TYPE_COUNT, 0);
}

void PlayLogger::startStage(int courseId, int stageId) {
    resetCurrentData();
    currentData.courseId = courseId;
    currentData.stageId = stageId;
}

// 最初の行動時間を確定させる内部関数
void PlayLogger::triggerFirstAction() {
    if (!hasTakenFirstAction) {
        currentData.timeToFirstAction = ofGetElapsedTimef() - stageStartTime;
        hasTakenFirstAction = true;
    }
}

void PlayLogger::recordMovement(float distance) {
    // わずかでも動いたら最初の行動とみなす
    if (distance > 0.001f) {
        triggerFirstAction();
    }
    currentData.totalDistance += distance;
}

void PlayLogger::recordQuizResult(bool isCorrect, bool usedHint, float responseTime) {
    triggerFirstAction(); // クイズに答えた場合も最初の行動
    
    currentData.totalQuizzes++;
    if (isCorrect) {
        currentData.correctAnswers++;
        tempConsecutiveMiss = 0; // 正解したら連続ミスはリセット
    } else {
        tempConsecutiveMiss++;
        // 過去最高の連続ミス数を記録していたら更新
        if (tempConsecutiveMiss > currentData.maxConsecutiveMiss) {
            currentData.maxConsecutiveMiss = tempConsecutiveMiss;
        }
    }
    
    if (usedHint) currentData.hintUses++;
    currentData.totalTime += responseTime;
}

void PlayLogger::recordItemUse(int itemId) {
    triggerFirstAction(); // アイテム使用も最初の行動
    
    if (itemId >= 0 && itemId < currentData.itemUsage.size()) {
        currentData.itemUsage[itemId]++;
    }
}

void PlayLogger::recordTreasureTouch() {
    triggerFirstAction();
    currentData.treasureTouches++;
}

void PlayLogger::recordPenalty() {
    currentData.penaltyCount++;
}

void PlayLogger::endAndSaveStage(bool isCleared) {
    currentData.isCleared = isCleared;
    
    // もし一度も行動せずに終了した場合のケア
    if (!hasTakenFirstAction) {
        currentData.timeToFirstAction = ofGetElapsedTimef() - stageStartTime;
    }
    
    // 平均時間の計算（0除算防止）
    if (currentData.totalQuizzes > 0) {
        currentData.avgTime = currentData.totalTime / (float)currentData.totalQuizzes;
    }

    // CSV保存処理
    string filePath = "play_log.csv";
    ofFile file;
    bool exists = file.doesFileExist(filePath);
    
    if (file.open(filePath, ofFile::Append, false)) {
        // 新規ファイルならBOMとヘッダーを書き込む
        if (!exists) {
            file << "\xEF\xBB\xBF"; // BOM
            // 末尾を Item_0~2 ではなく、明確に4つのスキル名にする
            file << "SessionID,Age,CourseID,StageID,IsCleared,TotalQuizzes,CorrectRate,AvgTime,HintUses,TreasureTouches,Penalty,TotalDistance,MaxConsecutiveMiss,TimeToFirstAction,Item_Dash,Item_Freeze,Item_Trap,Item_TimeStop" << endl;
        }

        // 正答率の計算
        float correctRate = 0;
        if (currentData.totalQuizzes > 0) {
            correctRate = (float)currentData.correctAnswers / currentData.totalQuizzes;
        }

        // データの1行作成（新しい項目を順番通りに出力）
        file << currentData.sessionId << ","
             << currentData.age << ","
             << currentData.courseId << ","
             << currentData.stageId << ","
             << (currentData.isCleared ? 1 : 0) << ","
             << currentData.totalQuizzes << ","
             << ofToString(correctRate, 2) << ","
             << ofToString(currentData.avgTime, 2) << ","
             << currentData.hintUses << ","
             << currentData.treasureTouches << ","
             << currentData.penaltyCount << ","
             << ofToString(currentData.totalDistance, 2) << ","
             << currentData.maxConsecutiveMiss << ","
             << ofToString(currentData.timeToFirstAction, 2) << ",";
        
        // アイテム使用数をループで書き出し
        for (int i = 0; i < currentData.itemUsage.size(); i++) {
            file << currentData.itemUsage[i] << (i == currentData.itemUsage.size() - 1 ? "" : ",");
        }
        
        file << endl;
        file.close();
        ofLogNotice("PlayLogger") << "Stage log saved: Course " << currentData.courseId << " Stage " << currentData.stageId;
    }
}
