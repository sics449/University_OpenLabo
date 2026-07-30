#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    screenW = ofGetWidth();
    screenH = ofGetHeight();
    gridW = 60;
    gridH = 60;
    //ofSetWindowShape(gridW * currentTilesize, gridH * currentTilesize);
    mapchip[0].load("sougen.png");
    mapchip[1].load("Water.png");
    mapchip[2].load("mounts1/tile_0_0.png");
    mapchip[3].load("Roads/tile_0_0.png");
    mapchip[4].load("Roads/tile_1_0.png");
    mapchip[5].load("Roads/tile_2_0.png");
    mapchip[6].load("Roads/tile_3_0.png");
    mapchip[7].load("Roads/tile_4_0.png");
    mapchip[8].load("maptile_wood_01.png");
    mapchip[9].load("maptile_renga_gray_01_matt.png");
    for(int i=0; i<=9; i++){
        mapchip[i].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    }
    
    // VERYHARD用マップチップload-----------------------------
    ofImage temp;
    temp.load("Green.png");
    for(int i = 0; i < 4; i++) {
        // cropFrom(元画像, x, y, w, h)
        mapchip[10 + i].cropFrom(temp, i * 16, 0, 16, 16);
        // ドットをクッキリさせる設定
        mapchip[10 + i].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    }
    
    temp.load("Skyblue.png");
    for(int i = 0; i < 4; i++) {
        mapchip[14 + i].cropFrom(temp, i * 16, 0, 16, 16);
        mapchip[14 + i].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    }
    
    temp.load("Masenta_wall.png");
    for(int i = 0; i < 4; i++) {
        mapchip[18 + i].cropFrom(temp, i * 16, 0, 16, 16);
        mapchip[18 + i].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    }
    
    goalchip[0].load("宝の山.png");
    goalchip[1].load("Goal/tile_0_1.png");
    goalchip[1].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    skillIcons[DASH].load("item/hane_right_white.png");
    skillIcons[DASH].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    skillIcons[FREEZE].load("item/block_koori.png");
    skillIcons[FREEZE].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    skillIcons[TRAP].load("item/block_tsuchi.png");
    skillIcons[TRAP].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    skillIcons[TIME_STOP].load("item/udedokei_gold.png");
    skillIcons[TIME_STOP].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    starImg.load("effect/ornament_star_gold.png");
    starImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    titleImg.load("タイトルロゴ.png");
    chestImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    chestImg.load("Treasures/tile_0_2.png");
    chestImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    trapImg.load("ana_brown.png");
    trapImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    piyoImg.load("effect/Guruguru.png");
    piyoImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    effect[0].load("effect/inazuma.png");
    effect[0].getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    cursorImg.load("effect/モード選択の手.png");
    cursorImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    boxImg.load("effect/チェックボックス.png");
    boxImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    checkImg.load("effect/チェック.png");
    checkImg.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    comArrowSheet.load("icon/tile_6_1.png");
    goalArrowSheet.load("icon/tile_6_1.png");
    comArrowSheet.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    goalArrowSheet.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);

    comArrowAngle = 0.0;
    goalArrowAngle = 0.0;
    
    playerLabel.load("icon/tile_8_4.png");
    playerLabel.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    comLabel.load("icon/tile_8_5.png");
    comLabel.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    stageScreenshots[0].load("Demo/easyPreview.png");
    stageScreenshots[1].load("Demo/normalPreview.png");
    stageScreenshots[2].load("Demo/hardPreview.png");
    
    stageVideos[0].load("Demo/easyDemo.mp4");
    stageVideos[1].load("Demo/normalDemo.mp4");
    stageVideos[2].load("Demo/hardDemo.mp4");
    for (int i = 0; i < 3; i++) {
        stageVideos[i].setLoopState(OF_LOOP_NORMAL); // ループ再生を有効にする
        stageVideos[i].setVolume(0);                 // 選択画面で音が鳴るとうるさいので音量は0（消音）に
    }
    selectArrow.load("icon/tile_6_0.png");
    selectArrow.getTexture().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
    
    bgm[0].load("bgm/MusMus-BGM-052.mp3");
    bgm[1].load("bgm/MusMus-BGM-134.mp3");
    bgm[2].load("bgm/MusMus-BGM-125.mp3");
    bgm[3].load("bgm/MusMus-BGM-029.mp3");
    bgm[4].load("bgm/MusMus-BGM-069.mp3");
    bgm[5].load("bgm/MusMus-BGM-103.mp3");
    
    for(int i=0; i<6; i++){
        bgm[i].setLoop(true); // ループ再生有効
        bgm[i].setVolume(normalVolume); // 音量は適宜調整
    }
    
    seQuizStart.load("Sounds/クイズ出題1.mp3");
    seCorrect.load("Sounds/クイズ正解1.mp3");
    seIncorrect.load("Sounds/クイズ不正解1.mp3");
    seCountdown.load("Sounds/カウントダウン.mp3");
    seStart.load("Sounds/スタート.mp3");
    seFinish.load("Sounds/試合終了のゴング.mp3");
    seSelect.load("Sounds/カーソル移動1.mp3");
    seChoose.load("Sounds/決定ボタンを押す52.mp3");
    seDash.load("Sounds/超高速ダッシュ.mp3");
    seFrozen.load("Sounds/氷魔法で凍結.mp3");
    seTrapset.load("Sounds/岩にヒビが入る.mp3");
    seTimeStop.load("Sounds/ブウーン.mp3");
    sePlayerBoost.load("Sounds/ヒーローの決めポーズ.mp3");
    seComBoost.load("Sounds/男性の悲鳴.mp3");
    seFinishBoost.load("Sounds/煙モクモク.mp3");
    
    seStun.load("Sounds/シビレ.mp3");
    sePiyo.load("Sounds/ヒヨコが頭の上を回るmp3.mp3");
    seAlert.load("Sounds/ほら貝を吹き鳴らす.mp3");
    seGenerateVeryHard.load("Sounds/警報が鳴る.mp3");
    
    seQuizStart.setVolume(0.9);
    seCorrect.setVolume(0.9);
    seIncorrect.setVolume(1.0);
    seCountdown.setVolume(1.0);
    seStart.setVolume(1.0);
    seFinish.setVolume(0.8);
    
    seSelect.setVolume(0.9);
    seChoose.setVolume(0.9);
    seDash.setVolume(1.0);
    seFrozen.setVolume(1.0);
    seTrapset.setVolume(1.0);
    seTimeStop.setVolume(1.0);
    sePlayerBoost.setVolume(0.9);
    seComBoost.setVolume(0.9);
    seFinishBoost.setVolume(0.9);
    
    seStun.setVolume(0.6);
    sePiyo.setLoop(true);
    sePiyo.setVolume(0.6);
    seAlert.setVolume(0.9);
    seGenerateVeryHard.setVolume(0.6);
    
    ofTrueTypeFontSettings settings("Fonts/Nosutaru-dotMPlusH-10-Regular.ttf",32);
    settings.antialiased = true;
    settings.addRanges(ofAlphabet::Latin);
    settings.addRanges(ofAlphabet::Japanese);
    myFont.load(settings);
    
    
    ofTrueTypeFontSettings settings2("Fonts/Nosutaru-dotMPlusH-10-Regular.ttf",18);
    settings2.antialiased = true;
    settings2.addRanges(ofAlphabet::Latin);
    settings2.addRanges(ofAlphabet::Japanese);
    smallFont.load(settings2);
    
    ofTrueTypeFontSettings settings3("Fonts/Nosutaru-dotMPlusH-10-Regular.ttf",52);
    settings3.antialiased = true;
    settings3.addRanges(ofAlphabet::Latin);
    settings3.addRanges(ofAlphabet::Japanese);
    bigFont.load(settings3);
        
    myPlayer.setup();
    myCom.setup();
    
    ageCommandInput.clear();
    inputHistory.clear();
    activeTraps.clear();
    isPaused = false;
    titleMenuCursor = 0;
    titleStep = 0;
    currentState = TITLE_MODE; // 最初はタイトル
}

//------------------------------------------------
void ofApp::initGame() {
    
    lastAnimTime = ofGetElapsedTimeMillis();
    for(int i=0; i<5; i++) {
        if(bgm[i].isPlaying()) bgm[i].stop();
    }
    
    if (selectedLevel == 0) {
        currentTilesize = 64; // Easy: キャラを大きく、見やすく
        gridW = 60; // 標準
        gridH = 60;
    } else if (selectedLevel == 1) {
        currentTilesize = 56; // Normal: 少し視野を広げる
        gridW = 60; // 標準
        gridH = 60;
    } else if(selectedLevel == 2) {
        currentTilesize = 48; // Hard: 視界を広くして迷わせる
        gridW = 100; // 標準
        gridH = 100;
    }else if(selectedLevel == 3){
        currentTilesize = 64;
        gridW = 25; // チュートリアル用サイズ
        gridH = 15;
    }else if(selectedLevel == 4){
        currentTilesize = 48;
        gridW = 120;
        gridH = 120;
    }
    
    mapData.assign(gridW, std::vector<int>(gridH, 0));
    
    generateMap(); // マップ生成
    
    if (!rooms.empty()) {
        if(selectedLevel == 3){
            BspRect startRoom = rooms.front();
            myPlayer.x = startRoom.x + startRoom.w / 3;
            myPlayer.y = startRoom.y + startRoom.h / 4;
            
            myCom.x = myPlayer.x + 1;
            myCom.y = myPlayer.y;
            
            // チュートリアル開始時に、COMが保持している古い移動経路を完全に空にする
            myCom.currentPath.clear();
            
        }else{
            // --- スタート位置の設定 ---
            BspRect startRoom = rooms.front(); // 左上
            myPlayer.dir = 0;
            myPlayer.frame = 1;
            myPlayer.x = startRoom.x + startRoom.w / 3;
            myPlayer.y = startRoom.y + startRoom.h / 4;
            
            myCom.dir = 0;
            myCom.frame = 1;
            myCom.x = myPlayer.x + 1;
            myCom.y = myPlayer.y;
            myCom.currentPath.clear();
            
            
            // --- ゴール位置の設定ロジック ---
            if (selectedLevel == 0) {
                // Easy: 必ずリストの末尾の部屋をゴールにする
                BspRect targetRoom = rooms.back();
                GoalX = targetRoom.x + targetRoom.w / 2;
                GoalY = targetRoom.y + targetRoom.h / 2;
                
                for (int yy = 0; yy < 2; yy++) {
                    for (int xx = 0; xx < 2; xx++) {
                        int tx = GoalX + xx;
                        int ty = GoalY + yy;
                        
                        // マップの範囲内であることを確認
                        if (tx >= 0 && tx < gridW && ty >= 0 && ty < gridH) {
                            mapData[tx][ty] = 0;
                        }
                    }
                }
            }
            else {
                // Normal / Hard: 「道のり」が最も遠い部屋を計算して決定
                vector<vector<int>> distMap(gridW, vector<int>(gridH, 1e9));
                queue<pair<int, int>> q;
                
                distMap[myPlayer.x][myPlayer.y] = 0;
                q.push({myPlayer.x, myPlayer.y});
                
                int dx[] = {0, 0, 1, -1};
                int dy[] = {1, -1, 0, 0};
                
                while (!q.empty()) {
                    pair<int, int> curr = q.front();
                    q.pop();
                    
                    for (int i = 0; i < 4; i++) {
                        int nx = curr.first + dx[i];
                        int ny = curr.second + dy[i];
                        
                        if (nx >= 0 && nx < gridW && ny >= 0 && ny < gridH) {
                            int tile = mapData[nx][ny];
                            if ((tile == 0 || tile == 8 || (tile >= 10 && tile <= 17)) && distMap[nx][ny] == 1e9) {
                                distMap[nx][ny] = distMap[curr.first][curr.second] + 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                
                int maxSteps = -1;
                int bestRoomIdx = 0;
                for (int i = 1; i < rooms.size(); i++) {
                    int rx = rooms[i].x + rooms[i].w / 2;
                    int ry = rooms[i].y + rooms[i].h / 2;
                    if (distMap[rx][ry] != 1e9 && distMap[rx][ry] > maxSteps) {
                        maxSteps = distMap[rx][ry];
                        bestRoomIdx = i;
                    }
                }
                GoalX = rooms[bestRoomIdx].x + rooms[bestRoomIdx].w / 2;
                GoalY = rooms[bestRoomIdx].y + rooms[bestRoomIdx].h / 2;
                
                int goalFloorTile = (selectedLevel == 4) ? 10 : 8;
                
                for (int yy = 0; yy < 2; yy++) {
                    for (int xx = 0; xx < 2; xx++) {
                        int tx = GoalX + xx;
                        int ty = GoalY + yy;
                        
                        if (tx >= 0 && tx < gridW && ty >= 0 && ty < gridH) {
                            mapData[tx][ty] = goalFloorTile;
                        }
                    }
                }
            }
            // COMの目標を確定したゴールに設定
            myCom.goalX = GoalX;
            myCom.goalY = GoalY;
        }
    }
    // --- COMの難易度設定 ---
    if (selectedLevel == 0 || selectedLevel == 3)      comBaseInterval = 1000;
    else if (selectedLevel == 1) comBaseInterval = 700;
    else if (selectedLevel == 2) comBaseInterval = 450;
    else                         comBaseInterval = 300;
    myCom.moveInterval = comBaseInterval;
    isComBoostMode = false;               // フラグもリセット
    if(selectedLevel == 3){
        isCountingDown = false;
    }else{
        isCountingDown = true;
    }
    countdownTimer = 3.0;
    lastCountdownSeconds = 4;
    
    // 直前で確定した新しい難易度の currentTilesize を使って、
    // プレイヤーとCOMの描画座標（drawPos）を完全にここで上書きを確定
    myPlayer.drawPos.set(myPlayer.x * currentTilesize, myPlayer.y * currentTilesize);
    myCom.drawPos.set(myCom.x * currentTilesize, myCom.y * currentTilesize);
    
    // --- 各種変数の初期化 ---
    step = 0;
    targetStep = (int)ofRandom(minStep, maxStep + 1);
    for (int i = 0; i < SKILL_COUNT; i++) skillStocks[i] = 0;
    
    // --- ここで距離マップを生成し、初期位置の距離を取得する ---
    calculateDistanceMap();
    cachedPlayerPathLength = distanceMap[myPlayer.x][myPlayer.y];
    myComPathSizeCached = distanceMap[myCom.x][myCom.y];
    
    if (selectedLevel == 3) { // TUTORIAL_MODE の条件
        tutorialTimer = 0.0f;     // タイマーを0にリセット
        bShowNextPrompt = false;  // 最初はメッセージを非表示に
    }
    
    showHintButton = false;
    isHintActive = false;
    
    isGameCleared = false;
    isGameFailed = false;
    hasFiredLevelAlert = false;
    hasPlayedAlertSound = false;
    isComNearGoalAlert = false;
    isPlayerBoost = false;
    clearTime = 0.0;
    totalQuestions = 0;
    correctAnswers = 0;
    summaryCursor = 0;
    trapX = -1;
    trapY = -1;
    isDashStunned = false;
    isComFrozen = false;
    activeTraps.clear();
    bgm[selectedLevel].play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (currentState == TITLE_MODE) {
        if (!bgm[5].isPlaying()) {
            // 他のBGMが鳴っていたら止める
            for(int i=0; i<5; i++) {
                if(bgm[i].isPlaying()) bgm[i].stop();
            }
            bgm[5].play();
        }
    }
    
    // --- 追加：設定画面系BGM(bgm[3])の管理 ---
    if (currentState == AGE_SELECT_MODE || currentState == DIFFICULTY_CONFIG_MODE || currentState == SELECT_MODE) {
        if (!bgm[3].isPlaying()) {
            bgm[3].setVolume(0);
            bgm[3].play();
        }
    } else {
        // 設定画面以外では止める（MAP_MODEやTITLE_MODEなど）
        if (bgm[3].isPlaying() && currentState != TUTORIAL_MODE && previousState != TUTORIAL_MODE) {
            bgm[3].stop();
        }
    }
    
    if (currentState == SELECT_MODE) {
        // 1. スライド位置の滑らかな計算 (線形補間/イージング)
        // 選択しているステージが画面中央 (X = 0) に来るように目標値を設定
        float targetOffsetX = -selectedLevel * stageSpacing;
        // 毎フレーム、目標値に15%ずつ近づける
        selectOffsetX += (targetOffsetX - selectOffsetX) * 0.15f;
        
        // 2. ホバータイマーの更新（動画切り替え用）
        if (selectedLevel == lastSelectedLevel) {
            cursorHoverTime += ofGetLastFrameTime(); // 秒単位で足していく
        } else {
            // ステージが切り替わったらタイマーをリセット
            cursorHoverTime = 0.0f;
            lastSelectedLevel = selectedLevel;
        }
        
        // ---------------------------------------------------------
        //  3. すべての通常ステージ(1〜3)の動画を一括制御・アップデート
        // ---------------------------------------------------------
        for (int i = 0; i < 3; i++) {
            // 現在のカーソルが「上側ゾーン(0)」にあり、かつこのステージ(i)を指していて、2秒以上経っている場合
            if (i == selectedLevel && selectVerticalZone == 0 && cursorHoverTime >= 2.0f) {
                
                if (stageVideos[i].isLoaded()) {
                    // まだ再生されていなければ再生を開始
                    if (!stageVideos[i].isPlaying()) {
                        stageVideos[i].play();
                    }
                    // 動画のフレームを次のコマに進める
                    stageVideos[i].update();
                }
                
            } else {
                //  カーソルが外れた、または2秒未満の場合は動画を安全に停止・巻き戻し
                if (stageVideos[i].isLoaded() && stageVideos[i].isPlaying()) {
                    stageVideos[i].stop();
                    stageVideos[i].firstFrame(); // 停止した時に最初の1コマ目（静止画状態）に巻き戻す
                }
            }
        }
    }
    
    if (isCountingDown) {
        int currentSeconds = ceil(countdownTimer); // 現在の残り秒数 (3, 2, 1)

        // 秒数が変わった瞬間に音を鳴らす
        if (currentSeconds != lastCountdownSeconds) {
            if (currentSeconds > 0) {
                seCountdown.play(); // 3, 2, 1 の音（既存の音を流用、または専用のSE）
            }
            lastCountdownSeconds = currentSeconds;
        }

        countdownTimer -= ofGetLastFrameTime();

        if (countdownTimer <= 0) {
            isCountingDown = false;
            seStart.play(); // 開始音
            lastCountdownSeconds = 3; // 次回のためにリセット
        }
        
    }
    
    if (isCountingDown || currentState == TUTORIAL_MODE) {
        animTimer += ofGetLastFrameTime();
        if (animTimer > 0.2) { // 0.2秒ごとに切り替え
            animFrame = (animFrame + 1) % 3; // 0, 1, 2, 0... と繰り返す
            animTimer = 0;
        }
    }
    
    if (!isCountingDown && !isGameCleared && previousState != TUTORIAL_MODE && (currentState == MAP_MODE || currentState == QUIZ_MODE || currentState == RESULT_MODE)) {
        clearTime += ofGetLastFrameTime();
    }
    
    if (isPaused) {
        return;
    }
    if(!isCountingDown){
        if (isDashing) {
            uint64_t now = ofGetElapsedTimeMillis();
            if (now - lastDashTime > dashInterval) {
                int nextX = myPlayer.x + dashDx;
                int nextY = myPlayer.y + dashDy;

                // 壁か画面外ならダッシュ終了
                if (nextX < 0 || nextX >= gridW || nextY < 0 || nextY >= gridH || (mapData[nextX][nextY] != 0 && mapData[nextX][nextY] != 8 && mapData[nextX][nextY] != 10 && mapData[nextX][nextY] != 11 && mapData[nextX][nextY] != 12 && mapData[nextX][nextY] != 13 && mapData[nextX][nextY] != 14 && mapData[nextX][nextY] != 15 && mapData[nextX][nextY] != 16 && mapData[nextX][nextY] != 17)) {
                    
                    isDashStunned = true;
                    isDashing = false;         // ダッシュ移動を即座にストップ
                    isDashStunned = true;      // 硬直状態をON
                    dashStunTimer = now;       // 硬直開始時間を記録
                                        
                    piyoTimer = 2.0f;          // 2秒間のピヨり画像用タイマーを設定
                    sePiyo.play();             // ピヨピヨSEを再生
                } else {
                    // 1マス進む
                    myPlayer.x = nextX;
                    myPlayer.y = nextY;
                    lastDashTime = now;
                    if (myPlayer.x == GoalX && myPlayer.y == GoalY) {
                        isDashing = false;
                        
                    }
                }
            }
        }
        
        if (piyoTimer > 0) {
            piyoTimer -= ofGetLastFrameTime(); // 残り時間を減らす
            
            // 0.1秒（100ミリ秒）ごとに 0 -> 1 -> 2 -> 0 -> 1... とコマをループさせる
            piyoAnimFrame = (int)(ofGetElapsedTimef() / 0.1f) % 3;
            
            if (piyoTimer <= 0) {
                piyoTimer = 0;
                sePiyo.stop(); // 2秒経ったらピヨピヨ音を止める
            }
        }
        
        // 1. ダッシュ硬直の解除判定
        if (isDashStunned) {
            if (ofGetElapsedTimeMillis() - dashStunTimer > 2000) {
                isDashStunned = false;
            }
        }
        if (isComFrozen) {
            if(currentState != QUIZ_MODE){
                if (ofGetElapsedTimeMillis() - skillTimer > currentSkillDuration) {
                    isComFrozen = false;
                }
            }else {
                // クイズ中はタイマーの起点（skillTimer）を更新し続けて、時間を止めさせる
                skillTimer += ofGetLastFrameTime() * 1000;
            }
        }
        // 3. トラップの当たり判定（COMが踏んだか）
        // =================================================================
        // 【大幅修正】複数トラップの更新・当たり判定・足止め処理
        // =================================================================
        uint64_t nowTime = ofGetElapsedTimeMillis();

        // COMが現在別の効果（フリーズアイテム等）で止まっていない場合のみ、トラップの踏み判定を行う
        bool canTriggerTrap = !isComFrozen;

        for (int i = (int)activeTraps.size() - 1; i >= 0; i--) {
            // すでに作動中（足止め中）のトラップのタイマー更新
            if (activeTraps[i].isActivated) {
                if (currentState != QUIZ_MODE && currentState != RESULT_MODE) {
                    if (nowTime - activeTraps[i].timer > activeTraps[i].duration) {
                        // 効果時間が切れたらトラップを消滅させる（COMの移動制限も解除）
                        activeTraps.erase(activeTraps.begin() + i);
                        continue;
                    }
                } else {
                    // クイズ中はフリーズ同様にタイマーの起点を進めて停止時間を維持
                    activeTraps[i].timer += ofGetLastFrameTime() * 1000;
                }
            }
            // まだ踏まれていないトラップの当たり判定
            else if (canTriggerTrap && myCom.x == activeTraps[i].x && myCom.y == activeTraps[i].y) {
                float targetX = activeTraps[i].x * currentTilesize;
                float targetY = activeTraps[i].y * currentTilesize;
                float dist = ofDist(myCom.drawPos.x, myCom.drawPos.y, targetX, targetY);

                // COMの描画位置がトラップの真上に近づいたら作動
                if (dist < 10.0) {
                    activeTraps[i].isActivated = true;
                    activeTraps[i].timer = nowTime;
                    activeTraps[i].duration = trapDuration; // 既存のtrapDuration変数を使用
                    seTrapact.play();
                    
                    // このターンはこれ以上他のトラップを踏まないようにする
                    canTriggerTrap = false;
                }
            }
        }

        // COMの移動を制限する判定
        // 「フリーズアイテムの効果中」または「いずれかのトラップが作動（足止め）中」ならCOMは動けない
        bool isComTotallyStopped = isComFrozen;
        for (const auto& trap : activeTraps) {
            if (trap.isActivated) {
                isComTotallyStopped = true;
                break;
            }
        }
        
        // 時間停止の終了判定
        if (isTimeStopped) {
            
            if (bgm[selectedLevel].isPlaying()) {
                bgm[selectedLevel].setPaused(true); // BGMも一時停止
            }
                
            if (ofGetElapsedTimeMillis() - timeStopTimer > timeStopDuration) {
                isTimeStopped = false;
                bgm[selectedLevel].setPaused(false); // タイムアップで再開
            }
            if (ofGetElapsedTimeMillis() - timeStopTimer > timeStopDuration) {
                isTimeStopped = false;
            }
        }
        
        // --- 修正ポイント：タイルサイズの決定 ---
        float ts = currentTilesize;

        // キャラクターの内部状態更新
        myPlayer.update(ts); // ここで内部の drawPos が更新される
        
        if (isStunned) {
            if (ofGetElapsedTimeMillis() - stunTimer > stunDuration) {
                isStunned = false; // 2秒経ったら解除
            }
        }
        if (currentState == MAP_MODE || currentState == TUTORIAL_MODE) {
            
            if (currentState == TUTORIAL_MODE) {
                chestSpawnTimer += ofGetLastFrameTime(); // タイマーを進める
                
                if (chestSpawnTimer >= chestSpawnInterval) {
                    TreasureChest newChest;
                    bool positionFound = false;
                    int attempts = 0;
                    
                    // 空いている場所を探す
                    while (!positionFound && attempts < 50) {
                        int rx = (int)ofRandom(1, gridW - 1);
                        int ry = (int)ofRandom(1, gridH - 1);
                        
                        // 床(0)かつ、ゴール(8)ではない場所、かつ既存の宝箱がない
                        if (mapData[rx][ry] == 0) {
                            bool alreadyExists = false;
                            for (auto& c : chests) {
                                if (c.x == rx && c.y == ry) {
                                    alreadyExists = true;
                                    break;
                                }
                            }
                            if (!alreadyExists) {
                                newChest.x = rx;
                                newChest.y = ry;
                                newChest.isOpen = false;
                                newChest.frame = 0;
                                newChest.type = (int)ofRandom(0, 3); // アイテム/スタン/タイムストップ
                                chests.push_back(newChest);
                                positionFound = true;
                            }
                        }
                        attempts++;
                    }
                    chestSpawnTimer = 0; // タイマーリセット
                }
            }
            
            
            // ---------------------------------------------------------
            // COMの速度・移動処理
            // ---------------------------------------------------------
            if (isComBoostMode) {
                myCom.moveInterval = comBaseInterval / 2;
            } else {
                myCom.moveInterval = comBaseInterval;
            }

            if (!isCountingDown && !isComTotallyStopped && !isTimeStopped) {
                updateComGoal();
                int oldComX = myCom.x;
                int oldComY = myCom.y;
                
                myCom.update(ts, mapData, gridW, gridH);
                
                // COMが動いた時だけ、距離とブースト判定を行う
                if (myCom.x != oldComX || myCom.y != oldComY) {
                    myComPathSizeCached = distanceMap[myCom.x][myCom.y];
                    int playerDist = distanceMap[myPlayer.x][myPlayer.y];
                    int diff = myComPathSizeCached - playerDist;

                    // ヒステリシス判定（ON/OFFの境界をずらして安定化）
                    if (!isComBoostMode) {
                        if (diff >= 20) { // 20差でON
                            isComBoostMode = true;
                            seComBoost.play();
                        }
                    } else {
                        if (diff <= 5) { // 5差でOFF（ここを絞ることで解除を確実に）
                            isComBoostMode = false;
                            seFinishBoost.play();
                        }
                    }
                }
            }

            updateArrows();


            // -----------------------------------------------------------------
            // 2. プレイヤーの移動処理（キー入力）と歩数カウント
            // -----------------------------------------------------------------
            int dx = 0;
            int dy = 0;

            if (upPressed)         dy = -1;
            else if (downPressed)  dy = 1;
            else if (leftPressed)  dx = -1;
            else if (rightPressed) dx = 1;

            uint64_t now = ofGetElapsedTimeMillis();
            int playerMoveInterval = 200; // プレイヤーの速度は200ms固定

            if ((dx != 0 || dy != 0) && now - lastAnimTime > playerMoveInterval) {
                int oldX = myPlayer.x;
                int oldY = myPlayer.y;
                
                myPlayer.move(dx, dy, gridW, gridH, mapData, ts);
                
                // 壁にぶつかっておらず、実際に【1マス進むことに成功した瞬間】だけ中に入る
                if (myPlayer.x != oldX || myPlayer.y != oldY) {
                    
                    // プレイヤーが動いた瞬間に1回だけ、あなたのA*関数で残り歩数を計算
                    cachedPlayerPathLength = distanceMap[myPlayer.x][myPlayer.y];
                    
                    // 通常の歩数カウント
                    if (!isTimeStopped) {
                        step++;
                    }
                    
                    // クイズ出題判定
                    if (step >= targetStep) {
                        previousState = currentState;
                        currentState = QUIZ_MODE;
                        
                        seQuizStart.play();
                        quizStartTime = ofGetElapsedTimeMillis();
                        setupMathQ();
                        
                        showHintButton = false;
                        isHintActive = false;
                        isQuizShowReady = true;
                        quizShowTimer = 1.5;
                        
                        step = 0;
                        targetStep = (int)ofRandom(minStep, maxStep);
                    }
                }
                // 壁スタック時（キーを押しっぱなしで壁に当たり続けている時）に、
                // 裏でA*が毎フレーム連打されて画面がカクつくのを防ぐため、タイマー更新を外側に出す
                lastAnimTime = now;
            }
            
            
            // --- ここにシステム（COM）の移動処理も追加可能 ---
            if(currentState == MAP_MODE){
                
                // 前フレームからの移動距離を計算（マス単位、またはピクセル単位）
                ofVec2f currentVec(myPlayer.x, myPlayer.y);
                float dist = currentVec.distance(lastPlayerPos);
                        
                // ログに移動距離を記録
                logger.recordMovement(dist);
                        
                // 現在の座標を次のフレームのために保存
                lastPlayerPos = currentVec;
                // プレイヤーのゴール判定 (x, y が goalX〜goalX+1 かつ goalY〜goalY+1 の範囲内か)
                if ((myPlayer.x == GoalX || myPlayer.x == GoalX + 1) &&
                    (myPlayer.y == GoalY || myPlayer.y == GoalY + 1)) {
                    bgm[selectedLevel].stop();
                    isDashing = false;
                    isGameCleared = true;
                    seFinish.play();
                    currentState = RESULT_MODE;
                    logger.endAndSaveStage(true);
                    sendText2server("--game clear--");
                    resultMessage = "ゴール!! あなたの勝ちです!";
                    goalTime = ofGetElapsedTimeMillis(); // ゴールした時刻を記録
                }
                
                // COMのゴール判定
                if ((myCom.x == GoalX || myCom.x == GoalX + 1) &&
                    (myCom.y == GoalY || myCom.y == GoalY + 1)) {
                    bgm[selectedLevel].stop();
                    isGameFailed = true; // 敗北フラグをオン
                    seFinish.play();
                    goalTime = ofGetElapsedTimeMillis(); // 遷移タイマー開始
                    currentState = RESULT_MODE;
                    logger.endAndSaveStage(false);
                    sendText2server("--game failed--");
                    resultMessage = "あいてがさきにゴールしました!\nあなたのまけです...";
                }
            }
            
            for (auto& c : chests) {
                if (!c.isOpen && myPlayer.x == c.x && myPlayer.y == c.y) {
                    c.isOpen = true;
                    seSelect.play();
                    logger.recordTreasureTouch();
                    
                    
                    if (c.type == 0) { // ランダムアイテム
                        int s = (int)ofRandom(1, 4); // DASH, FREEZE, TRAP
                        if (skillStocks[s] < 3) skillStocks[s]++; // 上限チェック
                        lastGetItemType = s;
                    }
                    else if (c.type == 1) { // スタン
                        if(upPressed || downPressed || rightPressed || leftPressed){
                            upPressed = downPressed = rightPressed = leftPressed = false;
                        }
                        isStunned = true;
                        isDashing = false;
                        stunTimer = ofGetElapsedTimeMillis();
                        seStun.play();
                    }
                    else if (c.type == 2) { // タイムストップ
                        if (skillStocks[TIME_STOP] < 2) skillStocks[TIME_STOP]++;// 上限チェック
                        lastGetItemType = TIME_STOP;
                    }
                    // --- ここから演出用セット ---
                    if (c.type != 1) { // スタン（マイナスアイテム）以外の場合
                        itemPopTimer = 1.0; // 1秒間表示
                        itemPopY = 0;       // 位置リセット
                    }
                }
            }
        }// MAP_MODE
    }// !isCountingdown
    
    if (messageTimer > 0) {
        messageTimer -= ofGetLastFrameTime();
    }
    
    if (currentState == RESULT_MODE && (isGameCleared || isGameFailed)) {
        // 3000ミリ秒（3秒）経過したら SUMMARY_MODE へ
        if (ofGetElapsedTimeMillis() - goalTime > 1500) {
            currentState = SUMMARY_MODE;
            summaryCursor = 0; // カーソル初期化
        }
    }
    
    if (currentState == QUIZ_MODE && isQuizShowReady) {
        quizShowTimer -= ofGetLastFrameTime();
        if (quizShowTimer <= 0) {
            isQuizShowReady = false; // 規定時間すぎたら入力を解禁
        }
    }
    
    // 1. 目標となる音量を決める
    float targetVol = 0.5;
    if (currentState == QUIZ_MODE) {
        targetVol = 0.2; // クイズ中は小さく
        // 現在の時刻からクイズ開始時刻を引いて、5000ミリ秒（5秒）以上経ったか判定
        if (ofGetElapsedTimeMillis() - quizStartTime >= 5000) {
            showHintButton = true;
        }
    } else if(currentState == MAP_MODE || currentState == TUTORIAL_MODE){
        targetVol = 0.3; // 通常時は大きく
    }
    else if (currentState == AGE_SELECT_MODE || currentState == DIFFICULTY_CONFIG_MODE || currentState == SELECT_MODE) {
        targetVol = 0.3; // 設定画面系も適切な音量を指定
    }

    // タイムストップ中の場合は、音量を0（または一時停止）にするならここで調整
    if (isTimeStopped) {
        targetVol = 0.0;
    }
    
    // 2. 再生中のBGMの音量を滑らかに更新
    for(int i = 0; i < 5; i++) {
        if(bgm[i].isPlaying()) {
            float current = bgm[i].getVolume();
            // 線形補間で近づける（爆音防止のため、急激な変化を避ける）
            float nextVol = current + (targetVol - current) * 0.05;
            
            // 念のため 0.0 〜 1.0 の範囲にクランプ（固定）する
            bgm[i].setVolume(ofClamp(nextVol, 0.0, 1.0));
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    screenW = ofGetWidth();
    screenH = ofGetHeight();
    ofSetColor(255);
    ofEnableAlphaBlending();
    if (currentState == TITLE_MODE) {
        ofBackground(0);
        
        // 【解像度対策】画面の縦幅(screenH)を基準にして、タイルが縦に約10~11枚並ぶようにサイズを自動決定
        
        currentTilesize = screenH / 11.0f;
        if (currentTilesize < 64) currentTilesize = 64; // 小さくなりすぎないように下限を設定
        
        ofSetColor(255, 255, 255, 255); // 全体の描画色を「白」に固定
        
        // 1. 背景の草原 (画面サイズ全体をループ)
        for (float x = 0; x < screenW; x += currentTilesize) {
            for (float y = 0; y < screenH; y += currentTilesize) {
                mapchip[0].draw(x, y, currentTilesize, currentTilesize);
            }
        }
        
        // 2. 道の描画 (画面サイズから中央のグリッド位置を計算)
        ofSetColor(255, 255, 255, 255);
        int midGridX = (screenW / currentTilesize) / 2;
        int midGridY = (screenH / currentTilesize) / 2;
        
        for (int gx = 0; gx < (screenW / currentTilesize); gx++) {
            drawTitleChip(gx, midGridY, 5);
        }
        for(int gy = 0; gy <= (screenH / currentTilesize); gy++){
            drawTitleChip(midGridX, gy, 4);
        }
        drawTitleChip(midGridX, midGridY, 6);
        
        // 3. ゴールとキャラクター（画面の縦横比が変わっても中央の道にジャストフィット）
        ofSetColor(255, 255, 255, 255);
        float goalX = screenW - currentTilesize * 2.5f;
        float goalY = (midGridY - 1) * currentTilesize;
        goalchip[1].draw(goalX, goalY - currentTilesize, currentTilesize * 2, currentTilesize * 2);
        
        ofSetColor(255, 255, 255, 255);
        myPlayer.drawPos.set(screenW * 0.45f, midGridY * currentTilesize);
        myPlayer.dir = 2;
        myPlayer.draw(currentTilesize); // タイルサイズに合わせてキャラも自動拡大縮小
        
        ofSetColor(255, 255, 255, 255);
        myCom.drawPos.set(screenW * 0.2f, midGridY * currentTilesize);
        myCom.dir = 2;
        myCom.draw(currentTilesize);
        
        
        // 2. 画像の描画色を白（元の色のまま）に設定
        ofSetColor(255, 255, 255, 255);

        // ドット絵ロゴの元のサイズ
        float originalW = 256.0f;
        float originalH = 160.0f;

        // 3. 画面の横幅（screenW）の 70% の大きさに拡大する計算（お好みで 0.7f を 0.8f などに調整してください）
        float logoW = screenW * 0.4f;
        // 横幅の拡大比率に合わせて、縦幅もアスペクト比を維持して拡大
        float logoH = logoW * (originalH / originalW);

        // 4. 画面中央に配置するための座標計算
        float logoX = (screenW / 2.0f) - (logoW / 2.0f);
        float logoY = (screenH * 0.2f) - (logoH / 2.0f); // 画面の上から30%付近の中心に配置

        // 5. タイトルロゴ画像を描画
        titleImg.draw(logoX, logoY, logoW, logoH);
        
        if (titleStep == 0) {
            // --- 「なにかボタンをおしてね」を画面の下部（80%の位置）に配置 ---
            if (ofGetElapsedTimeMillis() % 1000 < 500) {
                ofSetColor(255);
                myFont.drawString("なにか ボタンを おしてね", screenW / 2.0f - 210, screenH * 0.90f);
            }
        }
        else if (titleStep == 1) {
            // --- 「スタート / れんしゅう」の選択テキストを表示 ---
            
            // 1. タイトルメッセージ（えらんでね）を画面下部（75%の位置）に配置
            string titleText = "えらんでね";
            float titleX = screenW / 2.0f - 210;
            float titleY = screenH * 0.75f;
            
            // 黒いフチ（上下左右に2ピクセルずらして描画）
            ofSetColor(0, 0, 0, 255);
            myFont.drawString(titleText, titleX - 2, titleY);
            myFont.drawString(titleText, titleX + 2, titleY);
            myFont.drawString(titleText, titleX,     titleY - 2);
            myFont.drawString(titleText, titleX,     titleY + 2);
            // 中心（白色）
            ofSetColor(255, 255, 255);
            myFont.drawString(titleText, titleX, titleY);
            
            // 2. メニュー項目の描画（えらんでね の少し下に配置）
            std::vector<std::string> menuLabels = { "スタート", "れんしゅう (そうさ,アイテムせつめいはこちら)" };
            
            for(int i = 0; i < 2; i++){
                float textX = screenW / 2.0f - 210;
                float textY = (screenH * 0.8f) + i * 60; // 行間を調整
                
                // メニュー文字の黒いフチ（上下左右）
                ofSetColor(0, 0, 0, 255);
                myFont.drawString(menuLabels[i], textX - 2, textY);
                myFont.drawString(menuLabels[i], textX + 2, textY);
                myFont.drawString(menuLabels[i], textX,     textY - 2);
                myFont.drawString(menuLabels[i], textX,     textY + 2);
                
                if(titleMenuCursor == i) {
                    // 選択中の文字は黄色
                    ofSetColor(255, 255, 0);
                    myFont.drawString(menuLabels[i], textX, textY);
                    
                    // --- 選択中の項目に cursorImg (指) を描画 ---
                    ofSetColor(255, 255, 255);
                    
                    float cycleDuration = 0.7f;
                    float progress = fmod(ofGetElapsedTimef(), cycleDuration);
                    int frame = (progress < 0.5f) ? 0 : (progress < 0.6f ? 1 : 2);
                    int subX = frame * 32;
                    
                    cursorImg.getTexture().drawSubsection(textX - 50, textY - 32, 48, 48, subX, 0, 32, 32);
                    
                } else {
                    // 非選択の文字は少し暗い白色
                    ofSetColor(180, 180, 180);
                    myFont.drawString(menuLabels[i], textX, textY);
                }
            }
            
            // =================================================================
            // 操作ガイド（自動アニメーションするスティックと白ボタン）
            // =================================================================
            ofPushStyle();
            
            // ガイド全体の描画位置（「えらんでね」テキストの右側付近に自動追従）
            float guideX = titleX + 420;
            float guideY = titleY + 45;
            
            // --- A. スティック（時間で上下に動く） ---
            float stickX = guideX;
            float stickY = guideY;
            float autoStickY = sin(ofGetElapsedTimef() * 5.0f) * 12.0f;
            
            ofSetColor(80);
            ofDrawCircle(stickX, stickY, 25); // スティック台座
            ofSetColor(255, 125, 0);
            ofSetLineWidth(4);
            ofDrawLine(stickX, stickY, stickX, stickY + autoStickY);
            ofDrawCircle(stickX, stickY + autoStickY, 14); // スティック頭
            
            // --- B. 白ボタン（リザルト画面と同じフェード枠明滅） ---
            float btnX = guideX + 90;
            float btnY = guideY;
            
            float fadePulse = abs(sin(ofGetElapsedTimef() * 3.5f));
            int alpha = 40 + (fadePulse * 195);
            
            ofPushMatrix();
            ofTranslate(btnX, btnY);
            ofRotateDeg(45);
            
            ofSetColor(255, 255, 255, 50);
            ofDrawRectangle(-12, -12, 24, 24);
            
            ofSetColor(255, 255, 255, alpha);
            ofNoFill();
            ofSetLineWidth(2.5);
            ofDrawRectangle(-12, -12, 24, 24);
            
            ofSetColor(255, 255, 255, alpha * 0.4f);
            ofDrawRectangle(-17, -17, 34, 34);
            
            ofPopMatrix();
            ofPopStyle();
        }
    }
    
    else if(currentState == AGE_SELECT_MODE){
        ofBackground(30, 30, 60); // 少し青みがかった背景
        ofSetColor(255);
        
        // タイトル文を画面上部（上から8%の位置）に配置
        myFont.drawString("あそびたいコースを えらんでね", screenW * 0.08f, screenH * 0.08f);
        
        // 1. 画面リスト用の「シンプルなコース名」の配列
        std::vector<std::string> ageLabels = {
            "がっこうにいくまえ コース",
            "しょうがく1ねんせい コース",
            "小学2年生 コース",
            "小学3年生 コース",
            "小学4年生 コース",
            "小学高学年 コース",
            "中学生以上 コース"
        };
        
        // 2. 画面下部に切り替えて表示する「詳しいルール説明文」の配列
        std::vector<std::string> ageDescriptions = {
            "[けいさんルール] 1から10までの たしざん と,かんたんな ひきざん が でるよ!",
            "[けいさんルール] 1けたの たしざん,ひきざん と,3つの 数の 計算も でるよ!",
            "[けいさんルール] 2けたの くり上がり,くり下がりのある たしざん・ひきざんだよ!",
            "[けいさんルール] 3,4けたのたしひき,かけざん九九や,わりざんが でるよ!",
            "[けいさんルール] 万のたしひき,何十をかけるかけ算、3けた÷1けたのわりざんだよ!",
            "[けいさんルール] カッコのある式や,3桁x2桁のかけ算、割る数が2桁のわりざんだよ!",
            "[けいさんルール] マイナスをふくむ 正負の計算や,式がながい四則混合計算が でるよ!"
        };
        
        // 隠しコマンド成功時の追加処理
        if (showCustomMode) {
            ageLabels.push_back("⭐︎ カスタムモード");
            ageDescriptions.push_back("[じぶんで設定] 演算子,ケタ数,九九制限などを じゆうに設定できるよ!");
        }
        
        // --- 3. コース名リストの一覧描画 ---
        int maxChoices = ageLabels.size();
        
        // 画面の縦幅に合わせて行間を自動で均等割り付け（15%の位置から開始して60%の範囲に収める）
        float startListY = screenH * 0.16f;
        float rowGap = screenH * 0.075f; // 画面サイズに合わせた行間
        
        for(int i = 0; i < maxChoices; i++){
            float textX = screenW * 0.12f; // 文字の開始位置（左側から12%）
            float textY = startListY + i * rowGap;
            
            if(ageCursor == i) {
                ofSetColor(255); // 画像の色リセット
                
                // --- 指カーソルのアニメーション計算 ---
                float cycleDuration = 0.7f;
                float progress = fmod(ofGetElapsedTimef(), cycleDuration);
                int frame = (progress < 0.5f) ? 0 : (progress < 0.6f ? 1 : 2);
                int subX = frame * 32;
                
                // 選択中の滑らかな揺れ演出
                float animX = sinf(ofGetElapsedTimef() * 8.0f) * 6.0f;
                float posX = textX - 70; // 文字の左側に配置
                float posY = textY - 45; // bigFontのサイズに合わせてY座標を微調整
                
                // アニメーション指カーソルを描画
                cursorImg.getTexture().drawSubsection(posX + animX, posY, 54, 54, subX, 0, 32, 32);
                
                // 選択中の文字は黄色（大きなbigFontで描画！）
                ofSetColor(255, 255, 0);
                bigFont.drawString(ageLabels[i], textX + animX, textY);
            } else {
                // 非選択の文字は少し暗い白色
                ofSetColor(180, 180, 180);
                bigFont.drawString(ageLabels[i], textX, textY);
            }
        }
        
        // =====================================================================
        // 4. カーソルが合っているコースの説明文を画面下部に固定表示
        // =====================================================================
        if (ageCursor >= 0 && ageCursor < ageDescriptions.size()) {
            ofPushStyle();
            
            float bgX = screenW * 0.05f;
            float bgY = screenH * 0.78f; // 下部78%の位置
            float bgW = screenW * 0.90f; // 画面幅の90%
            float bgH = screenH * 0.10f; // 画面高さの10%
            
            // 説明文を目立たせるための薄い黒帯（座布団）を敷く
            ofSetColor(0, 0, 0, 140);
            ofDrawRectRounded(bgX, bgY, bgW, bgH, 12);
            
            // 切り替わる説明テキストの描画
            ofSetColor(150, 255, 150); // 読みやすいマイルドな緑色
            myFont.drawString(ageDescriptions[ageCursor], bgX + 30, bgY + bgH / 2.0f + 10);
            ofPopStyle();
        }
        
        // --- 操作の案内（白の明滅フェードボタンを適用して下に配置） ---
        ofPushStyle();
        float guideX = screenW * 0.12f;
        float guideY = screenH * 0.73f;
        
        // 白ボタン（リザルト、タイトル共通の45度傾いたフェード枠）
        float fadePulse = abs(sin(ofGetElapsedTimef() * 3.5f));
        int alpha = 40 + (fadePulse * 195);
        
        ofPushMatrix();
        ofTranslate(guideX, guideY);
        ofRotateDeg(45);
        ofSetColor(255, 255, 255, 50);
        ofDrawRectangle(-10, -10, 20, 20);
        ofSetColor(255, 255, 255, alpha);
        ofNoFill(); ofSetLineWidth(2);
        ofDrawRectangle(-10, -10, 20, 20);
        ofPopMatrix();
        
        ofSetColor(255);
        myFont.drawString("しろいボタン で けってい", guideX + 30, guideY + 8);
        ofPopStyle();
        
        ofPushStyle();
        // 説明文の座布団（bgY = screenH * 0.78f, bgH = screenH * 0.10f）のすぐ下、
        // 画面の最下部（上から91%の位置）に
        float adviceX = screenW * 0.05f;
        float adviceY = screenH * 0.91f;
        
        // 子供たちを応援するような、明るくて優しい水色（シアン）
        ofSetColor(100, 220, 255);
        string adviceText = "*もっと むずかしい もんだいに チャレンジしたいときは おしえてね!";
        myFont.drawString(adviceText, adviceX + 30, adviceY);
        ofPopStyle();
        
        // =====================================================================
        // 年齢確認ポップアップの描画処理
        // =====================================================================
        if (isAgeConfirmed) {
            ofPushStyle();
            
            // 1. 画面全体を少し暗くする半透明の暗幕レイヤー
            ofSetColor(0, 0, 0, 200);
            ofDrawRectangle(0, 0, screenW, screenH);
            
            // 2. 中央に表示する確認メッセージボックスの背景枠
            float pW = screenW * 0.6f;  // 画面幅の60%
            float pH = screenH * 0.38f; // 画面高さの38%
            float pX = (screenW - pW) / 2.0f;
            float pY = (screenH - pH) / 2.0f;
            
            ofSetColor(40, 45, 70); // ボックスの背景色（深い紺色）
            ofDrawRectRounded(pX, pY, pW, pH, 20);
            ofSetColor(255);
            ofNoFill(); ofSetLineWidth(3);
            ofDrawRectRounded(pX, pY, pW, pH, 20); // 白い外枠線
            ofFill();
            
            // 3. 選択された年齢の確認テキスト
            ofSetColor(255, 255, 0); // 黄色文字で強調
            string selectedAgeStr = ageLabels[ageCursor];
            myFont.drawString("[" + selectedAgeStr + "]", pX + pW * 0.1f, pY + pH * 0.3f);
            
            ofSetColor(255);
            myFont.drawString("で よろしいですか?", pX + pW * 0.1f, pY + pH * 0.5f);
            
            // 4. 操作ボタンの案内（白：はい ／ 青：ちがう）
            float btnLineY = pY + pH * 0.78f; // ボタン案内を並べる高さ
            
            // --- 「はい」の案内 (左側：白いひし形フェードボタン) ---
            float yesX = pX + pW * 0.15f;
            ofPushMatrix();
            ofTranslate(yesX, btnLineY);
            ofRotateDeg(45);
            ofSetColor(255, 255, 255, 50);
            ofDrawRectangle(-12, -12, 24, 24);
            ofSetColor(255, 255, 255, alpha); // 同期して明滅
            ofNoFill(); ofSetLineWidth(2.5);
            ofDrawRectangle(-12, -12, 24, 24);
            ofPopMatrix();
            
            ofSetColor(255);
            myFont.drawString("はい(しろ)", yesX + 30, btnLineY + 8);
            
            // --- 「ちがう」の案内 (右側：青い正方形ボタン) ---
            float noX = pX + pW * 0.55f;
            ofSetColor(colorB); // 前のステップで定義したコントローラーの「青色」を使用
            ofDrawRectRounded(noX - 12, btnLineY - 12, 24, 24, 5); // 角丸の正方形ボタン
            
            ofSetColor(255);
            myFont.drawString("ちがう(あお)", noX + 30, btnLineY + 8);
            
            ofPopStyle();
        }
    }
    
    else if (currentState == DIFFICULTY_CONFIG_MODE) {
        ofBackground(20, 20, 40); // 開発者ツールのような少しダークな背景
        ofSetColor(255);
        
        // タイトルを画面サイズ基準（上から6%の位置）に配置
        myFont.drawString("もんだいの せってい", screenW * 0.08f, screenH * 0.06f);
        
        // 演算子リストとフラグ
        string opLabels[] = {"たしざん", "ひきざん", "かけざん", "わりざん"};
        bool opFlags[] = {useAdd, useSub, useMul, useDiv};
        
        // 新しい制限モードのテキスト
        string limitTexts[] = {"九九のみ", "小5から6年基準", "制限なし"};
        
        // 画面の解像度に合わせて項目の開始位置と間隔を自動計算
        float baseLeftX = screenW * 0.12f;  // 基本の左端位置
        float startItemsY = screenH * 0.13f; // 1項目めのY座標
        float rowGap = screenH * 0.055f;     // 各項目の行間
        
        // ---------------------------------------------------------------------
        // 1〜4項目め：演算子のオンオフ描画
        // ---------------------------------------------------------------------
        for (int i = 0; i < 4; i++) {
            float textX = baseLeftX + 60;
            float textY = startItemsY + i * rowGap;
            
            if (configCursor == i) {
                ofSetColor(255, 255, 0); // 選択中は黄色
                myFont.drawString(">" + opLabels[i], textX, textY);
            } else {
                ofSetColor(255);
                myFont.drawString(opLabels[i], textX, textY);
            }
            
            // --- チェックボックスとチェックマークの絵を描画 ---
            ofSetColor(255);
            float boxX = baseLeftX; // 文字の左側に綺麗に整列
            float boxY = textY - 33; // 文字のベースラインに合わせて微調整
            
            // ベースの空枠を描画
            boxImg.draw(boxX, boxY, 36, 36); // 裏設定画面らしく少しシャープに(36x36)
            
            // フラグがオンならチェックマークを上に重ねる
            if (opFlags[i]) {
                checkImg.draw(boxX, boxY, 36, 36);
            }
        }
        
        // ---------------------------------------------------------------------
        // 5項目め：加減算 最低桁数
        // ---------------------------------------------------------------------
        float item5X = baseLeftX;
        float item5Y = startItemsY + 4 * rowGap + 15; // 演算子ブロックと少し隙間を空ける
        string minDigStr = "加減算 最低： ";
        string minValDetail = "";
        
        if (minDigits < 0) {
            minValDetail = "マイナス " + ofToString(abs(minDigits)) + "けた まで";
        } else if (minDigits == 0) {
            minValDetail = "答えが 0 のみ";
        } else {
            minValDetail = "プラス " + ofToString(minDigits) + "けた から";
        }
        
        if (configCursor == 4) {
            ofSetColor(255, 255, 0);
            myFont.drawString(minDigStr + "<" + minValDetail + ">", item5X, item5Y);
        } else {
            ofSetColor(255);
            myFont.drawString(minDigStr + minValDetail, item5X, item5Y);
        }
        
        // ---------------------------------------------------------------------
        // 6項目め：加減算 最大桁数
        // ---------------------------------------------------------------------
        float item6X = baseLeftX;
        float item6Y = item5Y + rowGap;
        string maxDigStr = "加減算 最大： ";
        
        if (configCursor == 5) {
            ofSetColor(255, 255, 0);
            myFont.drawString(maxDigStr + "<" + ofToString(maxDigits) + " けた まで" + ">", item6X, item6Y);
        } else {
            ofSetColor(255);
            myFont.drawString(maxDigStr + ofToString(maxDigits) + " けた まで", item6X, item6Y);
        }
        
        // ---------------------------------------------------------------------
        // 7項目め：かけざん制限設定
        // ---------------------------------------------------------------------
        float item7X = baseLeftX;
        float item7Y = item6Y + rowGap;
        string mulLimitStr = "かけざん： ";
        
        if (configCursor == 6) {
            ofSetColor(255, 255, 0);
            myFont.drawString(mulLimitStr + "<" + limitTexts[mulLimitMode] + ">", item7X, item7Y);
        } else {
            ofSetColor(useMul ? 255 : 100); // そもそも掛け算オフならグレーアウト
            myFont.drawString(mulLimitStr + limitTexts[mulLimitMode], item7X, item7Y);
        }
        
        // ---------------------------------------------------------------------
        // 8項目め：わりざん制限設定
        // ---------------------------------------------------------------------
        float item8X = baseLeftX;
        float item8Y = item7Y + rowGap;
        string divLimitStr = "わりざん： ";
        
        if (configCursor == 7) {
            ofSetColor(255, 255, 0);
            myFont.drawString(divLimitStr + "<" + limitTexts[divLimitMode] + ">", item8X, item8Y);
        } else {
            ofSetColor(useDiv ? 255 : 100); // 割り算オフならグレーアウト
            myFont.drawString(divLimitStr + limitTexts[divLimitMode], item8X, item8Y);
        }
        
        // ---------------------------------------------------------------------
        // 9項目め：決定ボタン (この設定ではじめる)
        // ---------------------------------------------------------------------
        float item9X = baseLeftX;
        float item9Y = item8Y + rowGap + 20; // 確定エリアとして少し離す
        string startLabel = "[[ この せっていで 確定する ]]";
        
        if (configCursor == 8) {
            ofSetColor(0, 255, 100); // 選択中は鮮やかな緑
            myFont.drawString(">" + startLabel, item9X, item9Y);
        } else {
            ofSetColor(150);
            myFont.drawString(startLabel, item9X, item9Y);
        }
        
        // ---------------------------------------------------------------------
        // 10項目め：戻るボタン (コース選択にもどる)
        // ---------------------------------------------------------------------
        float item10X = baseLeftX;
        float item10Y = item9Y + rowGap;
        string backLabel = "コース選択に もどる";
        
        if (configCursor == 9) {
            ofSetColor(255, 100, 100); // 選択中は赤
            myFont.drawString(">" + backLabel, item10X, item10Y);
        } else {
            ofSetColor(150);
            myFont.drawString(backLabel, item10X, item10Y);
        }
        
        // ---------------------------------------------------------------------
        // エラー表示
        // ---------------------------------------------------------------------
        if (showErrorMessage) {
            ofSetColor(255, 0, 0);
            myFont.drawString("どれかひとつは えらんでね!", baseLeftX, item10Y + rowGap);
        }
        
        // ---------------------------------------------------------------------
        // 確認画面（ダイアログ）
        // ---------------------------------------------------------------------
        if (isShowingConfirm) {
            // 暗幕レイヤー
            ofSetColor(0, 0, 0, 220);
            ofDrawRectangle(0, 0, screenW, screenH);
            
            // ダイアログ中央基準
            float cx = screenW / 2.0f;
            float cy = screenH / 2.0f;
            
            ofSetColor(255);
            myFont.drawString("この せっていを 反映する?", cx - 220, cy - 40);
            
            // 白ボタン（明滅フェード用アルファ値）
            float fadePulse = abs(sin(ofGetElapsedTimef() * 3.5f));
            int alpha = 40 + (fadePulse * 195);
            
            // --- 「はい」ボタン (白いひし形フェードボタン仕様) ---
            ofPushStyle();
            float yesBtnX = cx - 120;
            float btnLineY = cy + 40;
            
            ofPushMatrix();
            ofTranslate(yesBtnX, btnLineY);
            ofRotateDeg(45);
            ofSetColor(255, 255, 255, 200);
            ofDrawRectangle(-10, -10, 20, 20);
            ofSetColor(255, 255, 255, alpha); // タイトル等と同調して明滅
            ofNoFill(); ofSetLineWidth(2);
            ofDrawRectangle(-10, -10, 20, 20);
            ofPopMatrix();
            
            if (confirmCursor == true) {
                ofSetColor(255, 255, 0); // 選択中（はい）
                myFont.drawString("はい", yesBtnX + 25, btnLineY + 8);
            } else {
                ofSetColor(255);
                myFont.drawString("はい", yesBtnX + 25, btnLineY + 8);
            }
            ofPopStyle();
            
            // --- 「いいえ」ボタン (コントローラーの青い正方形ボタン仕様) ---
            ofPushStyle();
            float noBtnX = cx + 60;
            
            ofSetColor(colorB); // ofApp.cppの冒頭で定義した見やすい青色
            ofDrawRectRounded(noBtnX - 10, btnLineY - 10, 20, 20, 4); // 角丸正方形
            
            if (confirmCursor == false) {
                ofSetColor(255, 255, 0); // 選択中（いいえ）
                myFont.drawString("いいえ", noBtnX + 25, btnLineY + 8);
            } else {
                ofSetColor(255);
                myFont.drawString("いいえ", noBtnX + 25, btnLineY + 8);
            }
            ofPopStyle();
        }
    }
    
    else if (currentState == SELECT_MODE) {
        ofBackground(20, 20, 40); // 豪華な画面に合うように少し濃い背景色に
        
        // 画面の中心座標を取得（screenW, screenH ベース）
        float centerX = screenW / 2.0f;
        float centerY = screenH / 2.0f;
        
        //  画面サイズに合わせて、プレビュー画像のサイズをレスポンシブに計算
        // (例: 1920x1080なら w=800, h=480 のバランスを維持)
        float imgW = screenW * 0.416f;
        float imgH = screenH * 0.444f;
        
        // ---------------------------------------------------------
        // guideText を完璧に中央寄せして描画する処理 (textGrowを使用)
        // ---------------------------------------------------------
        string guideText = "ステージを スティックでえらんで,しろいボタンでけってい";
        
        float textX = textGrow(guideText); // 自作関数でX座標を自動計算
        float textY = screenH * 0.09f;     // Y座標は画面上部から9%の位置
        
        // 計算された textX を使って、上下左右2pxずらして黒フチ取りを描画
        ofSetColor(0);
        myFont.drawString(guideText, textX - 2, textY);
        myFont.drawString(guideText, textX + 2, textY);
        myFont.drawString(guideText, textX,     textY - 2);
        myFont.drawString(guideText, textX,     textY + 2);
        
        // 本体の白色を描画
        ofSetColor(255);
        myFont.drawString(guideText, textX, textY);
        
        // =========================================================
        // 画面全体を横スライドさせるための行列プッシュ
        // =========================================================
        ofPushMatrix();
        
        stageSpacing = imgW * 1.25f;
        // 画面中央 (centerX, centerY) を基準とし、毎フレーム計算される selectOffsetX 分だけずらす
        // プレビューが上下移動と干渉しないよう、centerYから少し上（-20px）にベースラインを設定
        ofTranslate(centerX + selectOffsetX, centerY - 20);
        
        // 各ステージ（0:ステージ1, 1:ステージ2, 2:ステージ3, 3:EX）の描画ループ
        int maxLoop = isSecretLevelUnlocked ? 3 : 2; // 解放状態で行く先を決める
        for (int i = 0; i <= maxLoop; i++) {
            float x = i * stageSpacing;
            float y = 0; // 上下中央揃え
            
            // 上側ゾーン(0)で、今このステージが選ばれているか
            bool isCurrentSelected = (i == selectedLevel && selectVerticalZone == 0);
            
            // 選択中のステージは1.1倍に大きく、非選択は1.0倍
            float currentScale = isCurrentSelected ? 1.1f : 1.0f;
            float w = imgW * currentScale;
            float h = imgH * currentScale;
            
            // 各ステージの表示名
            string stageNames[4] = {"ステージ 1", "ステージ 2", "ステージ 3", "EX"};
            
            if (i == 3) {
                // ---------------------------------------------------------
                // EX (VERY HARD) の特殊描写（灰色の画面にガタガタ動く「？」）
                // ---------------------------------------------------------
                if (isCurrentSelected) {
                    ofSetColor(140, 140, 140, 255); // 選択中は明るい灰色
                } else {
                    ofSetColor(70, 70, 70, 180);    // 非選択は暗い灰色
                }
                // 灰色の四角形（スクショの代わり）
                ofDrawRectangle(x - w / 2, y - h / 2, w, h);
                
                // 文字「？」をガタガタ震えさせる不気味演出のノイズ
                float shakeX = isCurrentSelected ? ofRandom(-2, 2) : 0;
                float shakeY = isCurrentSelected ? ofRandom(-2, 2) : 0;
                
                ofSetColor(0); // 黒フチ
                myFont.drawString("???", x - 13 + shakeX, y + 17 + shakeY);
                
                if (isCurrentSelected) {
                    ofSetColor(255, 0, 0); // 選択中は怖い赤色の「？」
                } else {
                    ofSetColor(200, 200, 200);
                }
                myFont.drawString("???", x - 15 + shakeX, y + 15 + shakeY);
                
            } else {
                // ---------------------------------------------------------
                // 通常ステージ (1〜3) の描写 (1.5秒経過で動画再生)
                // ---------------------------------------------------------
                if (isCurrentSelected) {
                    ofSetColor(255, 255, 255, 255); // 本来の明るさ
                    
                    // カーソルが合ってから1.5秒以上経っていたら動画を、そうでなければ静止画を描画
                    if (cursorHoverTime >= 1.5f && stageVideos[i].isLoaded()) {
                        stageVideos[i].draw(x - w / 2, y - h / 2, w, h);
                    } else {
                        stageScreenshots[i].draw(x - w / 2, y - h / 2, w, h);
                    }
                } else {
                    ofSetColor(120, 120, 120, 180); // 選ばれていないスクショは暗く透明に
                    stageScreenshots[i].draw(x - w / 2, y - h / 2, w, h);
                }
            }
            
            // ---------------------------------------------------------
            // 被り防止：ステージ名・星（画像）を下側へシフトして描画
            // ---------------------------------------------------------
            // テキストを表示する基準Y座標（拡大された枠「h/2」の下端からさらに余裕を持たせる）
            float textBaseY = y + (h / 2) + 45;
            float starBaseY = textBaseY + 30; // 星はテキストのさらに下に配置
            
            // 星画像の描画設定
            int starW = 28;       // 星画像の表示横幅
            int starH = 28;       // 星画像の表示縦幅
            int starSpacing = 32; // 星同士の間隔
            int starCount = (i == 3) ? 5 : (i + 1); // 難易度数
            
            // アニメーション用（ピコピコ揺れる演出）のX移動量を計算
            float animX = isCurrentSelected ? sinf(ofGetElapsedTimef() * 8.0f) * 6.0f : 0.0f;
            
            // ─── 1. ステージ名の中央寄せX座標を計算 ───
            ofRectangle nameBox = myFont.getStringBoundingBox(stageNames[i], 0, 0);
            
            // 指カーソル（幅48px）を表示する場合は、その分も計算に含めて全体を中央に寄せる
            float nameStartX;
            if (isCurrentSelected) {
                // [指カーソル(48px)] + [間隙(10px)] + [文字の幅] のカタマリをスクショの中心(x)に合わせる
                float totalWidth = 48 + 10 + nameBox.width;
                nameStartX = x - (totalWidth / 2) + 48 + 10;
            } else {
                // 非選択時は文字の幅だけでシンプルに中央寄せ
                nameStartX = x - (nameBox.width / 2);
            }
            
            // 毎フレームのピコピコ揺れをプラス
            nameStartX += animX;
            
            // ─── 2. 星画像の中央寄せX座標を計算 ───
            float starTotalWidth = (starCount - 1) * starSpacing + starW;
            float starStartX = x - (starTotalWidth / 2) + animX;
            
            // ─── 3. 実際の描画処理 ───
            if (isCurrentSelected) {
                // 選択中の太い枠線（EXなら赤、他は黄）
                ofNoFill();
                ofSetLineWidth(5);
                if (i == 3) ofSetColor(255, 0, 0);
                else ofSetColor(255, 255, 0);
                ofDrawRectangle(x - w / 2, y - h / 2, w, h);
                ofFill();
                
                // 「指カーソル」のアニメーション計算
                float cycleDuration = 0.7f;
                float progress = fmod(ofGetElapsedTimef(), cycleDuration);
                int frame = (progress < 0.5f) ? 0 : (progress < 0.6f ? 1 : 2);
                int subX = frame * 32;
                
                // 計算した文字の左端から、58px左側（カーソル分48px + 隙間10px）に指を描画
                ofSetColor(255);
                float cursorX = nameStartX - 58;
                float cursorY = textBaseY - 33; // 文字の高さに微調整
                cursorImg.getTexture().drawSubsection(cursorX, cursorY, 48, 46, subX, 0, 32, 32);
                
                // --- 選択中のステージ名（黒フチ＋カラー） ---
                ofSetColor(0);
                myFont.drawString(stageNames[i], nameStartX + 2, textBaseY);
                myFont.drawString(stageNames[i], nameStartX - 2, textBaseY);
                myFont.drawString(stageNames[i], nameStartX,     textBaseY + 2);
                myFont.drawString(stageNames[i], nameStartX,     textBaseY - 2);
                
                if (i == 3) ofSetColor(255, 0, 0);    // EXは赤色
                else ofSetColor(255, 255, 0);         // 他は黄色
                myFont.drawString(stageNames[i], nameStartX, textBaseY);
                
                // --- 選択中の星画像を描画 ---
                for (int s = 0; s < starCount; s++) {
                    float sx = starStartX + s * starSpacing;
                    if (i == 3) ofSetColor(255, 50, 50);   // EXは禍々しい赤
                    else ofSetColor(255, 255, 255);       // 通常は画像本来の色
                    
                    starImg.draw(sx, starBaseY, starW, starH);
                }
                
            } else {
                // --- 非選択時のステージ名（黒フチ＋白色） ---
                ofSetColor(0);
                myFont.drawString(stageNames[i], nameStartX + 2, textBaseY);
                myFont.drawString(stageNames[i], nameStartX - 2, textBaseY);
                myFont.drawString(stageNames[i], nameStartX,     textBaseY + 2);
                myFont.drawString(stageNames[i], nameStartX,     textBaseY - 2);
                
                if (i == 3) ofSetColor(200, 0, 0);    // 解放後のEXは非選択でも赤っぽく
                else ofSetColor(255);                 // 他は白
                myFont.drawString(stageNames[i], nameStartX, textBaseY);
                
                // --- 非選択時の星画像を描画（半透明グレー） ---
                for (int s = 0; s < starCount; s++) {
                    float sx = starStartX + s * starSpacing;
                    if (i == 3) ofSetColor(120, 0, 0, 180);       // 非選択EXは暗い赤透明
                    else ofSetColor(130, 130, 130, 150);          // 通常は暗いグレー透明
                    
                    starImg.draw(sx, starBaseY, starW, starH);
                }
            }
        }
        
        // --- VERY HARD解放前 かつ ステージ3(2) を選択している時、右側にヒントの赤矢印を出す ---
        if (!isSecretLevelUnlocked && selectedLevel == 2 && selectVerticalZone == 0) {
            float arrowX = 2 * stageSpacing + (imgW * 1.1f) / 2 + 50;
            float animArrowX = sinf(ofGetElapsedTimef() * 10.0f) * 10.0f;
            ofSetColor(0);
            myFont.drawString(">?", arrowX + animArrowX + 2, 0);
            ofSetColor(255, 0, 0);
            myFont.drawString(">?", arrowX + animArrowX, 0);
        }
        
        ofPopMatrix(); // 横スライドの行列を終了 (これ以降は画面の定位置に固定描画されます)
        
        // =========================================================
        // 画面下部：下側ゾーン（れんしゅう ＆ もどる）の描画
        // =========================================================
        float bottomY = screenH - 70; // 下側アイテムのY座標（画面最下部から70px上）
        float screenCenterX = screenW / 2.0f;
        
        // 配置するテキストの定義
        string practiceText = "れんしゅう";
        string backText     = "もんだいせっていにもどる";
        
        // それぞれの文字サイズを取得して中央寄せの基準にする
        ofRectangle practiceBox = myFont.getStringBoundingBox(practiceText, 0, 0);
        ofRectangle backBox     = myFont.getStringBoundingBox(backText, 0, 0);
        
        // ─── 1. 座標の計算（画面中央から左右に振り分ける） ───
        // 画面中央から左に280pxの位置を「れんしゅう」の中心、右に280pxの位置を「もどる」の中心にする
        float practiceTargetX = screenCenterX - 280;
        float backTargetX     = screenCenterX + 280;
        
        // 指カーソル（48px）と隙間（10px）の分、選択されている側だけテキストを少し右にずらすための計算
        float practiceStartX = practiceTargetX - (practiceBox.width / 2);
        float backStartX     = backTargetX - (backBox.width / 2);
        
        // 下側ゾーン（1）が選ばれている時の処理
        bool isBottomZone = (selectVerticalZone == 1);
        // 下側の中で、左（0:れんしゅう）か右（1:もどる、またはそれ以上）か
        bool isPracticeSelected = (isBottomZone && selectedBottomLevel == 0);
        bool isBackSelected     = (isBottomZone && selectedBottomLevel == 1);
        
        // ピコピコアニメーションの移動量計算
        float animOffset = sinf(ofGetElapsedTimef() * 8.0f) * 6.0f;
        if (isPracticeSelected) practiceStartX += 58 + animOffset; // カーソルが入るスペースを空ける
        if (isBackSelected)     backStartX     += 58 + animOffset;
        
        // ─── 2. 「れんしゅう」ボタンの描画 ───
        // 黒フチ
        ofSetColor(0);
        myFont.drawString(practiceText, practiceStartX - 2, bottomY);
        myFont.drawString(practiceText, practiceStartX + 2, bottomY);
        myFont.drawString(practiceText, practiceStartX,     bottomY - 2);
        myFont.drawString(practiceText, practiceStartX,     bottomY + 2);
        
        if (isPracticeSelected) {
            ofSetColor(100, 255, 100); // 練習は「みどり色」で目立たせる！
            myFont.drawString(practiceText, practiceStartX, bottomY);
            
            // 左側に指カーソル
            float progress = fmod(ofGetElapsedTimef(), 0.7f);
            int frame = (progress < 0.5f) ? 0 : (progress < 0.6f ? 1 : 2);
            cursorImg.getTexture().drawSubsection(practiceStartX - 58, bottomY - 33, 48, 46, frame * 32, 0, 32, 32);
        } else {
            ofSetColor(isBottomZone ? 160 : 110, isBottomZone ? 160 : 110, isBottomZone ? 160 : 110); // 非選択時はグレー
            myFont.drawString(practiceText, practiceStartX, bottomY);
        }
        
        // ─── 3. 「もんだいせっていにもどる」ボタンの描画 ───
        // 黒フチ
        ofSetColor(0);
        myFont.drawString(backText, backStartX - 2, bottomY);
        myFont.drawString(backText, backStartX + 2, bottomY);
        myFont.drawString(backText, backStartX,     bottomY - 2);
        myFont.drawString(backText, backStartX,     bottomY + 2);
        
        if (isBackSelected) {
            ofSetColor(255, 255, 0); // もどるは「黄色」
            myFont.drawString(backText, backStartX, bottomY);
            
            // 左側に指カーソル
            float progress = fmod(ofGetElapsedTimef(), 0.7f);
            int frame = (progress < 0.5f) ? 0 : (progress < 0.6f ? 1 : 2);
            cursorImg.getTexture().drawSubsection(backStartX - 58, bottomY - 33, 48, 46, frame * 32, 0, 32, 32);
        } else {
            ofSetColor(isBottomZone ? 160 : 110, isBottomZone ? 160 : 110, isBottomZone ? 160 : 110); // 非選択時はグレー
            myFont.drawString(backText, backStartX, bottomY);
        }
        
        // =========================================================
        // 上下移動をナビゲートする矢印（大型化 ＆ 本来の色で描画）
        // =========================================================
        float arrowX = screenCenterX;
        float arrowFloatY = sinf(ofGetElapsedTimef() * 6.0f) * 5.0f; // フワフワ感を少し強めに
        
        int arrowW = 72; 
        int arrowH = 72; 
        int arrowSubX = ((fmod(ofGetElapsedTimef(), 0.7f) < 0.5f) ? 0 : (fmod(ofGetElapsedTimef(), 0.7f) < 0.6f ? 1 : 2)) * 32;
        
        if (selectVerticalZone == 0) {
            // ─── ステージ選択中：下に行ける案内「▼」 ───
            // 拡大したプレビュー（imgH * 1.1f）や移動したテキストに被らないよう、位置を bottomY から逆算
            float ay = bottomY - 65 + arrowFloatY;
            
            ofSetColor(255); // 矢印本来のオリジナル色で描画
            ofPushMatrix();
            ofTranslate(arrowX, ay);
            ofRotateDeg(180); // 180度回転して下向きにする
            selectArrow.getTexture().drawSubsection(-arrowW / 2, -arrowH / 2, arrowW, arrowH, arrowSubX, 0, 32, 32);
            ofPopMatrix();
        } else {
            // ─── 下側ゾーン選択中：上に戻れる案内「▲」 ───
            // 下側の「れんしゅう」ボタン等の文字の上側に綺麗に配置
            float ay = bottomY - 65 + arrowFloatY;
            
            ofSetColor(255); // 矢印本来のオリジナル色で描画
            selectArrow.getTexture().drawSubsection(arrowX - arrowW / 2, ay - arrowH / 2, arrowW, arrowH, arrowSubX, 0, 32, 32);
        }
        
        ofSetColor(255); // カラーを完全に元に戻して終了
    }
    
    else if(currentState == MAP_MODE || currentState == TUTORIAL_MODE || currentState == QUIZ_MODE || currentState == RESULT_MODE){
        // --- カメラの計算開始 ---
        ofPushMatrix();
        
        // 1. 本来の目標位置（プレイヤーを画面中央にする位置）
        float targetX = ofGetWidth()/2 - myPlayer.drawPos.x;
        float targetY = ofGetHeight()/2 - myPlayer.drawPos.y;
        
        // 2. マップ全体のピクセルサイズを計算
        float mapWidth = gridW * currentTilesize;
        float mapHeight = gridH * currentTilesize;
        
        // 3. カメラがマップの外（黒い部分）を表示しないように制限する
        // ofClamp(値, 最小値, 最大値)
        // 最小値：画面右端/下端にマップの端がピッタリつく位置
        // 最大値：0 (マップの左端/上端)
        float offsetX;
        float offsetY;
        
        // マップが画面より「大きい」場合のみスクロールさせる
        if (mapWidth > ofGetWidth()) {
            offsetX = ofClamp(targetX, ofGetWidth() - mapWidth, 0);
        } else {
            // マップが画面より小さいなら中央に置く
            offsetX = (ofGetWidth() - mapWidth) / 2.0f;
        }
        
        if (mapHeight > ofGetHeight()) {
            offsetY = ofClamp(targetY, ofGetHeight() - mapHeight, 0);
        } else {
            offsetY = (ofGetHeight() - mapHeight) / 2.0f;
        }
        
        ofTranslate(offsetX, offsetY);
        
        float camX = -offsetX;
        float camY = -offsetY;
        
        // 2. 画面内に映るタイルのインデックスの範囲を計算
        // のりしろ（マージン）として、上下左右に「- 1」〜「+ 2」マス多めに計算して、パッと消えるのを防ぐ
        int camStartX = ofClamp(floor(camX / currentTilesize) - 1, 0, gridW);
        int camEndX   = ofClamp(ceil((camX + ofGetWidth()) / currentTilesize) + 2, 0, gridW);
        int camStartY = ofClamp(floor(camY / currentTilesize) - 1, 0, gridH);
        int camEndY   = ofClamp(ceil((camY + ofGetHeight()) / currentTilesize) + 2, 0, gridH);
        
        // --- STEP 1: 土台（地面と壁）の描画 ---
        for (int y = camStartY; y < camEndY; y++) {
            for (int x = camStartX; x < camEndX; x++) {
                int tileType = mapData[x][y];
                ofSetColor(255, 255, 255, 255); // 基本は白（フィルターなし）
                
                // ==================================================
                // 1. VERY HARD (selectedLevel == 4) の場合のマップ描画
                // ==================================================
                if (selectedLevel == 4) {
                    // 【対策】VERY HARDでもし3〜7が紛れ込んだら、安全なベース床(10)に化けさせる
                    if (tileType >= 3 && tileType <= 7) {
                        tileType = 10;
                    }
                    if (tileType >= 10 && tileType <= 17) {
                        // VERY HARD用の床
                        mapchip[tileType].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                    }
                    else if (tileType >= 18 && tileType <= 21) {
                        // 障害物・壁（18〜21）
                        int bgIdx = 10 + ((x * 7 + y * 13) % 8);
                        mapchip[bgIdx].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                        mapchip[tileType].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                    }
                    else {
                        // 床・壁以外のもの（0:スタート, 3:ゴールなど）
                        int bgIdx = 10 + ((x * 7 + y * 13) % 8);
                        mapchip[bgIdx].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                        
                        // 配列の安全な範囲（0〜9）であれば描画
                        if (tileType >= 0 && tileType <= 9) {
                            mapchip[tileType].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                        }
                    }
                }
                // ==================================================
                // 2. 通常の難易度（Easy, Normal, Hard）の場合のマップ描画
                // ==================================================
                else {
                    // 【対策】通常ステージでもし3〜7が紛れ込んだら、通常の床に化けさせる
                    if (tileType >= 3 && tileType <= 7) {
                        tileType = (selectedLevel == 0) ? 0 : 8; // Easyなら草原(0)、それ以外なら木目床(8)
                    }
                    if (tileType == 2) {
                        // 山の描画（背景をチカチカさせず、固定の床にする）
                        int bgIdx = (selectedLevel == 0) ? 0 : 8;
                        mapchip[bgIdx].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                        mapchip[2].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                    }
                    else if (tileType == 1 || tileType == 9) {
                        // 【壁タイル】
                        mapchip[tileType].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                    }
                    else {
                        // その他（0:草原, 8:床, もしくはゴールなど）
                        if (tileType >= 10) {
                            int safeIdx = (selectedLevel == 0) ? 0 : 8;
                            mapchip[safeIdx].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                        } else {
                            // 通常の安全な値（0〜9）のみ描画を実行する
                            mapchip[tileType].draw(x * currentTilesize, y * currentTilesize, currentTilesize, currentTilesize);
                        }
                    }
                }
            }
        }
        
        for (auto& c : chests) {
            if (!c.isOpen) {
                ofSetColor(255,255,255,255); // 宝箱を描画する前にも念のためリセット
                chestImg.draw(c.x * currentTilesize,
                              c.y * currentTilesize,
                              currentTilesize,
                              currentTilesize);
            }
        }
        
        for (const auto& trap : activeTraps) {// トラップ描画
            // 画面内に入っているかの簡易チェック（カメラのスクロール等があれば合わせる）
            // 既存の描画ロジックに合わせて、座標に currentTilesize（または ts）を掛けて描画
            float tx = trap.x * currentTilesize;
            float ty = trap.y * currentTilesize;
            
            
            if (!trap.isActivated) {
                // まだ作動していない（設置されただけ）のとき
                // マップタイルの上に、ちょっと暗い（または少し青み・赤みがかった）色をうっすら重ねる
                ofSetColor(255, 0, 0, 40); //薄い赤
                ofDrawRectangle(tx, ty, currentTilesize, currentTilesize);
            } else {
                // 作動中（COMがハマっている間）の演出
                ofSetColor(255); // 画像をそのままの色で出すために色リセット
                trapImg.draw(tx, ty, currentTilesize, currentTilesize);
            }
        }
        ofSetColor(255); // 色空間のリセット
        
        // ゴール・プレイヤー・COMの描画（背景が透明になるように）
        
        ofSetColor(255,255,255,255);
        goalchip[0].draw(GoalX * currentTilesize, GoalY * currentTilesize, currentTilesize*2, currentTilesize*2);
        
        if(isPlayerBoost){
            ofSetColor(180,100,255,180);
            myPlayer.draw(currentTilesize);
        }else{
            ofSetColor(255,255,255,255);
            myPlayer.draw(currentTilesize);
        }
        ofSetColor(255,255,255,255);
        // --- COMの描画 ---
        if (isComFrozen) {
            // フリーズ状態のとき：水色（R:100, G:200, B:255）を透明度180で重ねる
            ofSetColor(100, 200, 255, 180);
            myCom.draw(currentTilesize);
            ofSetColor(255); // 描き終わったらすぐに白色（色ブレンドなし）に戻す！
        }else if(isComBoostMode){
            ofSetColor(255, 0, 0, 180);
            myCom.draw(currentTilesize);
            ofSetColor(255);
        } else {
            // 通常時
            ofSetColor(255);
            myCom.draw(currentTilesize);
        }
        
        if (itemPopTimer > 0) {
            // 1.0 -> 0.0 に向かって減っていくタイマーを利用
            float alpha = itemPopTimer * 255;
            float fadeUp = (1.0 - itemPopTimer) * 60; // 1秒かけて60ピクセル上昇
            
            ofPushStyle();
            ofSetColor(255, 255, 255, alpha); // 徐々に透明にする
            
            // 描画位置：プレイヤーのdrawPosを基準にする
            float x = myPlayer.drawPos.x + (currentTilesize / 2) - 20; // 中央付近
            float y = myPlayer.drawPos.y - 40 - fadeUp;               // 頭上
            
            float itemPlusTextX = x+42;
            float itemPlusTextY = y+25;
            
            // アイコンの描画
            if (lastGetItemType >= 0 && lastGetItemType < SKILL_COUNT) {
                skillIcons[lastGetItemType].draw(x - 10, y - 10, 40, 40);
                
                ofSetColor(0, 0, 0, alpha); // 黒色に設定
                // 上下左右に少しずつずらして描く
                myFont.drawString("+1", itemPlusTextX - 2, itemPlusTextY - 2);
                myFont.drawString("+1", itemPlusTextX + 2, itemPlusTextY - 2);
                myFont.drawString("+1", itemPlusTextX - 2, itemPlusTextY + 2);
                myFont.drawString("+1", itemPlusTextX + 2, itemPlusTextY + 2);
                
                
                ofSetColor(255, 255, 255, alpha); // 白色に戻す
                // 「+1」の文字（太字っぽく見せるためにhighlight）
                myFont.drawString("+1", itemPlusTextX, itemPlusTextY);
            }
            
            ofPopStyle();
            
            // updateに入れ忘れた場合、ここでタイマーを減らしてもOK
            itemPopTimer -= ofGetLastFrameTime();
        }
        
        
        if (isStunned) {
            ofPushStyle(); // 現在の描画設定を保存
            
            // 1. 点滅させる（高速に透明度を変化させる）
            float alpha = 150 + 105 * sin(ofGetElapsedTimef() * 20);
            ofSetColor(255, 255, 255, alpha);
            
            // 2. 座標を少しランダムに震わせる（ビリビリ感）
            float shakeX = ofRandom(-2, 2);
            float shakeY = ofRandom(-2, 2);
            
            // 3. 描画（プレイヤーと同じ位置、同じサイズで重ねる）
            // effect[0] が "inazuma.png" です
            if (effect[0].isAllocated()) {
                effect[0].draw(myPlayer.x * currentTilesize + shakeX,
                               myPlayer.y * currentTilesize + shakeY,
                               currentTilesize, currentTilesize);
            }
            
            ofPopStyle(); // 設定を元に戻す
        }
        
        // プレイヤーがピヨっている時（isDashStunned が true のとき）
        if (isDashStunned) {
            // プレイヤーの頭上の座標を計算
            float piyoX = myPlayer.x * currentTilesize + (currentTilesize / 2);
            float piyoY = myPlayer.y * currentTilesize - 24; // 頭上24ピクセル上
            
            // アニメーションのコマ数（インデックス）を計算する
            // 15フレーム（約0.25秒）ごとにコマを進める例。3枚並びなので「% 3」で 0, 1, 2 をループ
            int currentFrame = (ofGetFrameNum() / 15) % 3;
            
            // 1コマのサイズ
            int frameW = 32;
            int frameH = 32;
            
            // 横並び画像から切り出す左端のX座標 (0枚目: 0, 1枚目: 32, 2枚目: 64)
            int srcX = currentFrame * frameW;
            int srcY = 0; // 縦は1行だけなので 0 固定
            
            ofSetColor(255); // 色のブレを防ぐために白リセット
            
            ofPushMatrix();
            // 描画の中心をプレイヤーの頭上に移動
            ofTranslate(piyoX, piyoY);
            
            piyoImg.drawSubsection(-frameW / 2, -frameH / 2, frameW, frameH, srcX, srcY, frameW, frameH);
            
            ofPopMatrix();
        }
        
        
        if(isPaused){
            // カメラがズレている分（-offsetX, -offsetY）を基準(0,0)とみなすことで、画面固定にする
            float screenLeft = -offsetX;
            float screenTop  = -offsetY;
            
            // 1. 画面全体に薄い黒（半透明）を重ねる
            ofSetColor(0, 0, 0, 180);
            // 画面の左上(screenLeft, screenTop)からウィンドウサイズ分描画する
            ofDrawRectangle(screenLeft, screenTop, ofGetWidth(), ofGetHeight());
            
            // 2. 案内テキストを表示
            ofSetColor(255); // 白色リセット
            
            string pauseText  = "== PAUSE ==";
            string resumeText = "Press 'q' to Resume";
            string titleText  = "Press 'c' to Return to Title";
            
            // 画面の中央に配置（画面中央の座標に、カメラのズレ分を足す）
            myFont.drawString(pauseText,  screenLeft + ofGetWidth()/2 - 60,  screenTop + ofGetHeight()/2 - 30);
            myFont.drawString(resumeText, screenLeft + ofGetWidth()/2 - 95,  screenTop + ofGetHeight()/2 + 15);
            myFont.drawString(titleText,  screenLeft + ofGetWidth()/2 - 135, screenTop + ofGetHeight()/2 + 60);
        }
        
        if (isCountingDown || currentState == TUTORIAL_MODE) {
            
            // 1コマあたりのサイズを計算（画像サイズが同じなら共通でOK）
            float sw = playerLabel.getWidth() / 3;
            float sh = playerLabel.getHeight();
            
            // コマ送りの切り取り位置
            float offsetX = animFrame * sw;
            
            ofPushStyle();
            ofSetColor(255);
            
            // --- 1. プレイヤーの頭上に描画 ---
            float px = myPlayer.drawPos.x + (currentTilesize / 2) - (sw / 2);
            float py = myPlayer.drawPos.y - sh - 15; // 少し上に配置
            playerLabel.drawSubsection(px, py, sw, sh, offsetX, 0);
            
            // --- 2. COMの頭上に描画 ---
            // チュートリアルでもCOMがいるなら描画する
            float cx = myCom.drawPos.x + (currentTilesize / 2) - (sw / 2);
            float cy = myCom.drawPos.y - sh - 15;
            comLabel.drawSubsection(cx, cy, sw, sh, offsetX, 0);
            
            ofPopStyle();
        }
        
        
        ofPopMatrix();
        if(currentState == MAP_MODE || previousState == MAP_MODE){
            drawArrows(camStartX, camEndX, camStartY, camEndY);
            checkAndDrawComAlert();
        }
        
        if (isCountingDown) {
            ofPushStyle();
            
            // --- 【追加】画面全体を薄黒くしてカウントダウンを引き立たせる ---
            ofSetColor(0, 0, 0, 110); // 最後の数値を0〜255で調整（110で約43%の不透明度）
            ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
            
            // 画面中央に大きく表示
            ofSetColor(255, 200, 0); // オレンジっぽい黄色
            
            // 残り秒数を整数にして文字列にする（3, 2, 1）
            string displayNum = ofToString(ceil(countdownTimer));
            
            // 文字のサイズに合わせて中央寄せ（数値は適宜調整してください）
            myFont.drawString(displayNum, ofGetWidth()/2 - 20, ofGetHeight()/2);
            
            myFont.drawString("さきにたからのやまにたどり着け!!", ofGetWidth()/2 - 300, ofGetHeight()/2 - 160);
            
            ofPopStyle();
        }
        
        // ★追加：チュートリアルモードなら左下にコントローラーガイドを表示
        if (currentState == TUTORIAL_MODE || previousState == TUTORIAL_MODE) {
            drawTutorialGuide(); // さきほど作成した左下表示の関数
            
            ofPushStyle();
            // --- 【追加】左上のチュートリアル文章の後ろに薄黒い四角を置く ---
            ofSetColor(0, 0, 0, 150); // 文字を読みやすくするため少し濃いめの150
            // 文字の表示位置に合わせて四角を描画（x=35, y=20 から、幅720, 高さ160の範囲）
            ofDrawRectangle(35, 15, 920, 160);
            
            ofSetColor(255);
            myFont.drawString("れんしゅう:スティックで あるいてみよう！\nたからばこにふれるといろいろな効果があるよ！", 50, 50);
            myFont.drawString("しろいボタンを おすと 難しさ選択にもどるよ", 50, 150);
            
            if (bShowNextPrompt) {
                // 文字の点滅演出（1秒周期でふわふわ点滅）
                float alpha = 128 + 127 * sin(ofGetElapsedTimef() * 3.0f);
                ofSetColor(255, 255, 255, alpha); // 白色（アルファ値で点滅）
                
                string msg = "1分が経過しました！白いボタンを押して次に進んでください。";
                
                // 画面の下部中央あたりに表示する例
                float textX = textGrow(msg); // 既存の文字中央寄せ関数を利用
                float textY = ofGetHeight() - 100;
                
                myFont.drawString(msg, textX, textY);
            }
            ofSetColor(255); // カラー設定を元に戻しておく
            ofPopStyle();
        }
        // --- カメラの計算終了 ---
        
        if (currentState == QUIZ_MODE) {
            float winW = ofGetWidth() * 0.8;
            float winH = 350;
            float winX = (ofGetWidth() - winW) / 2;
            float winY = ofGetHeight() - winH - 50;
            
            // 黒いウィンドウ（四角）を描画
            drawWindow(winX, winY, winW, winH);
            
            if (isQuizShowReady) {
                // --- 演出中の表示 ---
                ofSetColor(255);
                bigFont.drawString(quizAlertText, winX + 50, winY + 180);
            } else {
                float col1 = winX + 60;
                float col2 = winX + 400;
                float row1 = winY + 160;
                float row2 = winY + 250;
                
                // キー入力ロジック（1=A, 2=B, 3=C, 4=D）とボタン順序・色を完全一致
                // Aボタン (キー1 / 赤)
                drawColorButton(col1, row1, "A", colorA, currentQuestion.choices[0]);
                // Bボタン (キー2 / 青)
                drawColorButton(col2, row1, "B", colorB, currentQuestion.choices[1]);
                // Cボタン (キー3 / 黄：colorD)
                drawColorButton(col1, row2, "C", colorD, currentQuestion.choices[2]);
                // Dボタン (キー4 / 緑：colorE)
                drawColorButton(col2, row2, "D", colorE, currentQuestion.choices[3]);
                
                ofSetColor(255);
                // 問題文の表示
                bigFont.drawString(currentQuestion.text, winX + 50, winY + 90);
                
                // =======================================================
                // 演出が終わっており、かつ5秒経過している場合にウィンドウ内に描画
                // =======================================================
                if (showHintButton) {
                    ofPushStyle();
                    
                    // ウィンドウ内の右側の空きスペース（col2のさらに右側）に配置
                    float hintX = winX + winW - 270;
                    float hintY = winY + 50; // A・Bボタンと高さを合わせる
                    
                    if (!isHintActive) {
                        // --- 【まだヒントを押していない時】：四角い赤いボタンと案内を表示 ---
                        ofSetColor(255, 255, 255); // 赤色
                        ofFill();
                        
                        ofDrawRectangle(hintX - 15, hintY - 15, 30, 30);
                        
                        ofSetColor(255, 255, 255); // 白色文字
                        myFont.drawString("ヒント", hintX + 30, hintY + 10);
                        
                    } else {
                        // 1. 中央部分に「図解（グラフや注目する数式）」を描画
                        float graphX = col2 + 400;
                        float graphY = winY + 110;
                        
                        ofSetColor(255, 255, 100); // 鮮やかな黄色（図解用）
                        smallFont.drawString(quizHintGraph, graphX, graphY);
                        
                        // 2. 右側部分に「文字解説テキスト」を描画
                        float textX = winX + winW - 400;
                        float textY = winY + 45; // 解説文の1行目の高さ
                        
                        ofSetColor(200, 255, 200); // 目に優しい薄緑
                        smallFont.drawString(quizHintText, textX, textY);
                    }
                    
                    ofPopStyle();
                }
            }
        }
        else if (currentState == RESULT_MODE) {
            // クイズ時と同じ位置にウィンドウを表示
            float winW = ofGetWidth() * 0.8;
            float winH = 150;
            float winX = (ofGetWidth() - winW) / 2;
            float winY = ofGetHeight() - winH - 100;
            
            drawWindow(winX, winY, winW, winH);
            
            ofPushStyle();
            ofSetColor(255);
            
            float startTextX = winX + 50;
            
            if (!isGameCleared && !isGameFailed) {
                
                // アイコン画像と後半の文字がある場合（正解して新しくスキルをゲットした時）の連結処理
                if (gainedSkillType >= 1 && gainedSkillType < SKILL_COUNT && resultMessageEnd != "") {
                    
                    // 1. 前半のメッセージを描画
                    float textY = winY + 50;
                    myFont.drawString(resultMessage, startTextX, textY);
                    
                    // 2行目のテキスト「[アイテム名」だけの横幅を計算して、アイコンのX座標を割り出す
                    string skillNames[] = { "なし", "ダッシュ", "フリーズ", "トラップ", "タイムストップ" };
                    string row2Text = "[" + skillNames[gainedSkillType];
                    
                    // X座標：開始位置 + 2行目の文字の横幅 + 隙間10px
                    float currentX = startTextX + myFont.stringWidth(row2Text) + 10;
                    
                    //【真ん中：アイコンの描画】
                    float iconSize = 40;
                    float iconY = textY + 15;
                    
                    if (skillIcons[gainedSkillType].isAllocated()) {
                        skillIcons[gainedSkillType].draw(currentX, iconY, iconSize, iconSize);
                    }
                    
                    // さらに右にずらす
                    currentX += iconSize + 10;
                    
                    //【後半：後ろのメッセージを描画】
                    myFont.drawString(resultMessageEnd, currentX, textY + 45);
                    
                } else {
                    // --- 上限でもてない時、または不正解の時（通常通りそのまま表示） ---
                    myFont.drawString(resultMessage, startTextX, winY + 60);
                }
                
                // --- 右下の次へ進むための白ボタン（フェード枠エフェクト） ---
                // 次の入力（Enterキー）を待つ通常の正誤画面のときだけ右下に表示
                float bx = winX + winW - 140;  // ウィンドウの右端から少し内側
                float by = winY + winH - 50;  // ウィンドウの下側付近
                
                // 時間経過からフェード用のアルファ値（透明度）を計算
                float fadePulse = abs(sin(ofGetElapsedTimef() * 3.5));
                int alpha = 40 + (fadePulse * 195); // 40〜235の間でなめらかに明滅
                
                ofPushMatrix();
                ofTranslate(bx, by);
                ofRotateDeg(45); // コントローラーと同じ45度傾いた白い正方形
                
                // ボタン本体（ごく薄い白）
                ofSetColor(255, 255, 255, 200);
                ofDrawRectangle(-16, -16, 32, 32);
                
                // フェードする外枠（線）
                ofSetColor(255, 255, 255, alpha);
                ofNoFill();
                ofSetLineWidth(3);
                ofDrawRectangle(-16, -16, 32, 32);
                
                // さらに一回り大きなフェード外枠
                ofSetColor(255, 255, 255, alpha * 0.4);
                ofDrawRectangle(-22, -22, 44, 44);
                
                ofFill();
                ofPopMatrix();
                
            } else {
                // --- 【ゲームクリア、またはゲーム失敗（終了時）の場合】 ---
                // アイテム獲得などのUIを完全に隠し、クリア/失敗のメインテキストのみをスッキリ中央付近に表示
                myFont.drawString(resultMessage, startTextX, winY + 75);
            }
            
            ofPopStyle();
        }
        ofPushStyle();
        ofSetColor(255);
        
        // ==============================================================
        // 【サイズ調整】全体を大きく調整
        // ==============================================================
        float iconSize = 48;               // 32 から 48 に拡大
        float spacing = 65;                // アイコン拡大に合わせて間隔を 45 から 65 に拡大
        float startX = ofGetWidth() - 190; // アイコンが大きくなった分、少し左側から開始
        float startY = ofGetHeight() - 80; // 下端からの開始位置を調整
        
        // ラベルと色の配列
        string labels[] = { "", "", "", "", "" };
        ofColor colors[] = {
            ofColor::black,
            ofColor(255, 0, 0),     // a: Dash (緑)
            ofColor(0, 100, 255), // b: Freeze (青)
            ofColor(0, 255, 0),   // d: Trap (緑)
            ofColor(255, 215, 0)    // e: TimeStop (e)
        };
        
        // ==============================================================
        // ひと繋がりの背景ボックスをループの前に描画する
        // ==============================================================
        ofSetColor(0, 0, 0, 130); // 半透明の黒
        
        // タイムストップ（i=4）が表示対象に入っているかチェック
        bool showTimeStop = (skillStocks[TIME_STOP] > 0);
        
        // 表示するスキルの総数（通常は3つ、タイムストップがあれば4つ）
        int visibleCount = showTimeStop ? 4 : 3;
        
        // 拡大したUIに合わせた背景ボックスのサイズ計算
        float bgWidth = 240;                            // 幅を広げてテキストとアイコンを包む
        float bgHeight = (visibleCount * spacing) + 15; // 個数に応じた高さ
        
        // 一番下のアイテムの少し下から、全体の高さ分上へ描画位置を計算
        float bgX = startX - 60;                        // 丸枠の拡大に合わせて左側に広げる
        float bgY = (startY + iconSize + 8) - bgHeight;
        
        // ひと繋がりの背景を描画
        ofDrawRectangle(bgX, bgY, bgWidth, bgHeight);
        // ==============================================================
        
        
        // 各スキルのアイコンやテキストを描画するループ
        for (int i = 1; i < SKILL_COUNT; i++) {
            // 【重要】時間停止(i=4)かつ在庫がない場合は、描画を飛ばして「隠す」
            if (i == TIME_STOP && skillStocks[i] <= 0) {
                continue;
            }
            
            // 1. アイコン画像を描画
            ofSetColor(255);
            if (skillIcons[i].isAllocated()) {
                skillIcons[i].draw(startX, startY, iconSize, iconSize);
            }
            
            // 2. ボタンガイド（丸枠と文字）
            // アイコンの大きさに合わせて、丸枠の位置とサイズを調整
            float circleX = startX - 35;
            float circleY = startY + iconSize / 2;
            
            ofSetColor(0); // 縁取り
            ofDrawCircle(circleX, circleY, 19); // 14 から 19 に大きく
            
            ofSetColor(colors[i]); // ボタン色
            ofDrawCircle(circleX, circleY, 16); // 12 から 16 に大きく
            
            // ボタン文字 (a, b, c, d)
            ofSetColor((i == 2) ? 0 : 255); // 白ボタン(b)の時だけ文字を黒にする
            // 大きくなった丸の中心に文字が来るように座標を微調整 (+5 から +6)
            ofDrawBitmapString(labels[i], circleX - 4, circleY + 6);
            
            // 3. 所持数テキストの上限判定
            bool isMax = false;
            if (i == TIME_STOP) {
                if (skillStocks[i] >= 2) isMax = true;
            } else {
                if (skillStocks[i] >= 3) isMax = true;
            }
            
            // 色を設定して描画
            if (isMax) {
                ofSetColor(255, 215, 0); // 上限時はゴールド
            } else {
                ofSetColor(255); // 通常時は白
            }
            
            // テキストの位置も、大きくなったアイコンに合わせて横・縦を微調整
            string info = "x " + ofToString(skillStocks[i]);
            myFont.drawString(info, startX + 55, startY + 34);
            
            // 次のアイコンのために上にずらす
            startY -= spacing;
        }
        ofPopStyle();
    }
    
    // (カウントダウン中も含めて表示)
    if (currentState != TITLE_MODE && currentState != AGE_SELECT_MODE && currentState != DIFFICULTY_CONFIG_MODE && currentState != SELECT_MODE && currentState != TUTORIAL_MODE && previousState != TUTORIAL_MODE && !isGameCleared) {
        ofPushStyle();
        string timeStr = getTimeString(clearTime);
        ofSetColor(255);
        
        float tw = myFont.stringWidth(timeStr);
        // 画面中央上に配置
        myFont.drawString(timeStr, ofGetWidth()/2 - tw/2, 50);
        ofPopStyle();
    }
    
    // カウントダウンの数字（3, 2, 1）はタイマーとは別に中央に大きく出す
    if (isCountingDown) {
        ofPushStyle();
        ofSetColor(255, 200, 0);
        string countStr = ofToString(ceil(countdownTimer));
        myFont.drawString(countStr, ofGetWidth()/2 - 20, ofGetHeight()/2);
        ofPopStyle();
    }
    
    ofSetColor(255); // 他の描画に影響が出ないように白に戻す
    
    if (currentState == TUTORIAL_MODE && messageTimer > 0) {
        float rectW = 500;
        float rectH = 150;
        float rx = (ofGetWidth() - rectW) / 2; // 中央に配置
        float ry = 100; // 画面上部
        
        // 背景の黒い枠
        ofSetColor(0, 0, 0, 200);
        ofDrawRectRounded(rx, ry, rectW, rectH, 15);
        
        // 説明テキスト
        ofSetColor(255);
        // フォントがある場合はフォントで、なければ ofDrawBitmapString
        smallFont.drawString(tutorialMessage, rx + 20, ry + 40);
    }
    
    if (currentState == SUMMARY_MODE) {
        ofBackground(20, 20, 40); // 落ち着いた紺色背景
        
        if (isGameCleared) {
            ofSetColor(255, 215, 0); // 金色
            myFont.drawString("★ YOU WIN!! ★", ofGetWidth()/2 - 150, 150);
        }
        else if (isGameFailed) {
            ofSetColor(200, 50, 50); // 赤色
            myFont.drawString("YOU LOSE...", ofGetWidth()/2 - 150, 150);
        }
        
        ofSetColor(255);
        myFont.drawString("クリアタイム: " + getTimeString(clearTime), ofGetWidth()/2 - 220, 250);
        myFont.drawString("正解したかず: " + getAccuracyString(), ofGetWidth()/2 - 220, 310);
        myFont.drawString("(" + ofToString(correctAnswers) + " / " + ofToString(totalQuestions) + ")", ofGetWidth()/2 - 60, 350);
        
        // =====================================================================
        // Hard(selectedLevel == 2) でクリアした時だけの隠しコマンドヒント
        // =====================================================================
        if (selectedLevel == 2 && isGameCleared) {
            ofSetColor(50, 255, 150); // 明るいミントグリーン（目立つ色）
            string secretHint = "ひみつ: マップせんたくで「ひだり,みぎ,あか,あお」とおすと…?";
            myFont.drawString(secretHint, ofGetWidth()/2 - 480, 410); // 選択肢の少し上に表示
        }
        
        // 選択肢
        string menu[] = {"もういちどプレイする", "ステージせんたくにもどる", "もんだいのむずかしさをかえる", "ゲームをやめる"};
        for (int i = 0; i < 4; i++) {
            // 文字を描画する基準の座標
            float textX = ofGetWidth()/2 - 200;
            float textY = 480 + i * 60;
            
            if (i == summaryCursor) {
                // --- 1. 手のカーソルのアニメーション計算 ---
                ofSetColor(255); // 画像本来の色（白）で描画するために一度リセット
                
                float cycleDuration = 1.0f; // 1サイクル合計 1.0秒
                float progress = fmod(ofGetElapsedTimef(), cycleDuration);
                int frame = 0;
                
                if (progress < 0.6f) {
                    frame = 0; // 0.0〜0.6秒は 1枚目（長め）
                } else if (progress < 0.8f) {
                    frame = 1; // 0.6〜0.8秒は 2枚目
                } else {
                    frame = 2; // 0.8〜1.0秒は 3枚目
                }
                
                int subX = frame * 32; // 切り出す画像内の左端X座標
                
                // ピコピコ動かす演出（文字の動きと同期）
                float animX = sinf(ofGetElapsedTimef() * 8.0f) * 6.0f;
                
                // 手の絵の描画位置（文字のX座標から45px左に配置し、高さ中央を合わせる）
                float imgX = textX - 45;
                float imgY = textY - 28;
                
                // 32x32の範囲を切り出して描画
                cursorImg.getTexture().drawSubsection(imgX, imgY, 32, 32, subX, 0, 32, 32);
                
                // --- 2. 選択中の文字の描画 ---
                ofSetColor(255, 255, 0); // 黄色
                // "> " を取り除き、アニメーションの揺れ（animX）を加えて描画
                myFont.drawString(menu[i], textX + animX, textY);
                
            } else {
                // --- 3. 非選択時の文字の描画 ---
                ofSetColor(150);
                // "  "（スペース）を取り除いてそのまま描画
                myFont.drawString(menu[i], textX, textY);
            }
        }
        
        ofPushStyle();
        
        // 画面サイズ（横幅）に合わせて、中央に並ぶようにX座標をオフセット計算しています
        float btnBaseX = ofGetWidth() / 2 - 170;
        float btnY = 740; // 選択肢の一番下（タイトルにもどる：660px）よりさらに下
        
        ofSetColor(255, 255, 255);      // 赤色
        ofDrawCircle(btnBaseX, btnY - 10, 15); // ボタンの円
        
        ofSetColor(255);
        
        // 2. 「でけってい」のテキストを描画
        myFont.drawString(" で けってい", btnBaseX + 35, btnY);
    }
    
    ofSetColor(255);
    
    if (isTimeStopped && !isGameCleared && !isGameFailed) {
        ofPushStyle();
        ofEnableAlphaBlending(); // 透明度を有効にする
        
        // グレーの色を設定 (赤, 緑, 青, 透明度)
        ofSetColor(50, 50, 70, 150);
        ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
        
        // 中央に文字を表示
        ofSetColor(255);
        string msg = "TIME STOPPED";
        float tw = myFont.stringWidth(msg);
        myFont.drawString(msg, ofGetWidth()/2 - tw/2, ofGetHeight()/2);
        
        ofPopStyle();
    }
    
    ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (currentState == TITLE_MODE) {
        sendText2server("--wake up--");
        isAgeConfirmed = false;  // 確認画面を確実に閉じた状態にする
        showCustomMode = false;
        inputHistory.clear();    // タイトルで押した 'c' を履歴から消去する
        ageCursor = 0;
        
        if (titleStep == 0 && (key == '1' || key == '2' || key == '3' || key == '4' || key == OF_KEY_RETURN)) {
            // --- 最初の状態：何かボタンが押されたら選択テキスト切り替えへ ---
            seChoose.play();     // 決定音
            titleStep = 1;       // テキスト切り替えフラグをONに
            titleMenuCursor = 0; // カーソルを初期化
        }
        else if (titleStep == 1) {
            // --- 切り替え後の状態：上下で選択、特定のボタンで決定 ---
            if (key == OF_KEY_UP) {
                seSelect.play();
                titleMenuCursor--;
                if (titleMenuCursor < 0) titleMenuCursor = 1;
            }
            if (key == OF_KEY_DOWN) {
                seSelect.play();
                titleMenuCursor++;
                if (titleMenuCursor > 1) titleMenuCursor = 0;
            }
            
            // 決定キー（Enterや、ゲームの仕様に合わせたメインの決定ボタン）
            if (key == OF_KEY_RETURN) {
                seChoose.play();
                bgm[5].stop();
                
                if (titleMenuCursor == 0) {
                    // スタートなら本来の次のモードへ
                    titleStep = 0; // 次回のためにタイトルのステップを戻しておく
                    currentState = AGE_SELECT_MODE;
                }
                else if (titleMenuCursor == 1) {
                    // 練習ならチュートリアルを直接初期化して開始
                    titleStep = 0; // 次回のためにタイトルのステップを戻しておく
                    selectedLevel = 3; // チュートリアル用の難易度/マップ番号
                    initGame();        // 選択されたレベルでマップやプレイヤーを初期化
                    previousModeBeforeTutorial = AGE_SELECT_MODE;
                    currentState = TUTORIAL_MODE;
                }
            }
        }
    }
    
    // =====================================================================
    // AGE_SELECT_MODE : 学年コース選択画面（旧年齢選択）
    // =====================================================================
    else if (currentState == AGE_SELECT_MODE) {
        
        // 1. 入力されたキーを履歴に追加し、最大15回分に制限
        inputHistory.push_back(key);
        if (inputHistory.size() > 15) {
            inputHistory.erase(inputHistory.begin());
        }
        
        // 2. 年齢選択画面用の隠しコマンド判定（vector<int> ageSecretCommand との比較）
        if (inputHistory.size() >= ageSecretCommand.size()) {
            bool match = true;
            for (int i = 0; i < ageSecretCommand.size(); i++) {
                int historyIndex = inputHistory.size() - ageSecretCommand.size() + i;
                if (inputHistory[historyIndex] != ageSecretCommand[i]) {
                    match = false;
                    break;
                }
            }
            // コマンドが一致し、まだカスタムモードが解放されていない場合
            if (match && !showCustomMode) {
                showCustomMode = true;
                seChoose.play();      // 解放音を鳴らす
                inputHistory.clear(); // コマンドが連続で判定されないよう履歴をクリア
            }
        }
        
        // 選択肢の最大数（通常は7、カスタム解放時は8項目）
        int maxChoices = showCustomMode ? 8 : 7;
        
        // --- 年齢確認ポップアップが出ている間のキー操作 ---
        if (isAgeConfirmed) {
            // 赤いボタン('c') で「はい（確定）」
            if (key == OF_KEY_RETURN) {
                seChoose.play();
                isAgeConfirmed = false; // フラグを下ろす
                
                // 【重要】別の画面に遷移するので、一度入力履歴を綺麗にする
                inputHistory.clear();
                
                // カスタムモードが選ばれた場合
                if (showCustomMode && ageCursor == 7) {
                    logger.setup(7);
                    currentState = DIFFICULTY_CONFIG_MODE;
                    configCursor = 0;
                }
                // 通常の学年コースが選ばれた場合
                else {
                    logger.setup(ageCursor);
                    setRecommendedSettings(ageCursor);
                    currentState = SELECT_MODE;
                    selectedLevel = 0;       // カーソルを「ステージ 1」に強制リセット
                    lastSelectedLevel = 0;   // 前回のホバー位置もリセット
                    cursorHoverTime = 0.0f;  // 動画タイマーもリセット
                    selectOffsetX = 0.0f;    // 画面のスライド位置もステージ1（中心）にリセット
                    selectVerticalZone = 0;  // カーソル位置を上側（ステージ選択）に戻す
                }
            }
            
            // 青いボタン('2') で「いいえ（ちがう・キャンセル）」
            if (key == '2') {
                seSelect.play();
                isAgeConfirmed = false; // 確認をキャンセルして学年選択に戻る
            }
            
            return; // ポップアップ中はこれ以降の処理を通さない
        }
        
        // --- 通常時のキー操作（確認画面が出ていないとき） ---
        if (key == OF_KEY_UP) {
            seSelect.play();
            ageCursor = (ageCursor - 1 + maxChoices) % maxChoices;
        }
        if (key == OF_KEY_DOWN) {
            seSelect.play();
            ageCursor = (ageCursor + 1) % maxChoices;
        }
        // 赤いボタン('c')が押されたら、確認ポップアップを呼び出す
        if (key == OF_KEY_RETURN) {
            seSelect.play();
            isAgeConfirmed = true; // 確認ポップアップを表示
        }
    }

    // =====================================================================
    // DIFFICULTY_CONFIG_MODE : 詳細設定（カスタム設定）画面
    // =====================================================================
    else if (currentState == DIFFICULTY_CONFIG_MODE) {
        // --- 1. 確認画面（ダイアログ）表示中の処理 ---
        if (isShowingConfirm) {
            if (key == OF_KEY_LEFT || key == OF_KEY_RIGHT) {
                seSelect.play();
                confirmCursor = !confirmCursor; // はい / いいえ の切り替え
            }
            if (key == OF_KEY_RETURN) {
                seChoose.play();
                if (confirmCursor) {
                    // カスタムで決定された桁数やマイナス設定をシステムに最終同期
                    maxNumLimit = pow(10, maxDigits) - 1;
                    allowNegative = (minDigits < 0);
                    
                    // 【重要】設定を終えてマップ選択へ進む前に履歴をクリア
                    inputHistory.clear();
                    
                    // 設定を終えたら、マップ選択（SELECT_MODE）へ進む
                    currentState = SELECT_MODE;
                    selectedLevel = 0;       // カーソルを「ステージ 1」に強制リセット
                    lastSelectedLevel = 0;   // 前回のホバー位置もリセット
                    cursorHoverTime = 0.0f;  // 動画タイマーもリセット
                    selectOffsetX = 0.0f;    // 画面のスライド位置もステージ1（中心）にリセット
                    selectVerticalZone = 0;  // カーソル位置を上側（ステージ選択）に戻す
                    isShowingConfirm = false;
                } else {
                    isShowingConfirm = false; // 設定画面に戻る
                }
            }
            return;
        }
        
        // --- 2. 通常の設定画面の処理 ---
        int maxConfigItems = 10;
        if (key == OF_KEY_UP) {
            seSelect.play();
            configCursor = (configCursor - 1 + maxConfigItems) % maxConfigItems;
        }
        if (key == OF_KEY_DOWN) {
            seSelect.play();
            configCursor = (configCursor + 1) % maxConfigItems;
        }
        
        // 【右キー】設定値を「増やす・切り替える」
        if (key == OF_KEY_RIGHT) {
            seSelect.play();
            if (configCursor == 4) { // 最低けた数
                minDigits++;
                if (minDigits > maxDigits) minDigits = maxDigits;
            }
            else if (configCursor == 5) { // 最大けた数
                maxDigits++;
                if (maxDigits > 5) maxDigits = 5;
            }
            else if (configCursor == 6) { // かけざん制限
                mulLimitMode = (CalcLimitMode)((mulLimitMode + 1) % 3);
            }
            else if (configCursor == 7) { // わりざん制限
                divLimitMode = (CalcLimitMode)((divLimitMode + 1) % 3);
            }
        }
        
        // 【左キー】設定値を「減らす・戻す」
        if (key == OF_KEY_LEFT) {
            seSelect.play();
            if (configCursor == 4) { // 最低けた数
                minDigits--;
                if (minDigits < -3) minDigits = -3;
            }
            else if (configCursor == 5) { // 最大けた数
                maxDigits--;
                if (maxDigits < minDigits) maxDigits = minDigits;
            }
            else if (configCursor == 6) { // かけざん制限
                mulLimitMode = (CalcLimitMode)((mulLimitMode - 1 + 3) % 3);
            }
            else if (configCursor == 7) { // わりざん制限
                divLimitMode = (CalcLimitMode)((divLimitMode - 1 + 3) % 3);
            }
        }
        
        // 【決定ボタン】
        if (key == OF_KEY_RETURN) {
            seChoose.play();
            
            if (configCursor < 4) {
                bool* f[] = {&useAdd, &useSub, &useMul, &useDiv};
                *f[configCursor] = !*f[configCursor];
            }
            else if (configCursor == 8) { // この設定でゲームをはじめる
                if (useAdd || useSub || useMul || useDiv) {
                    isShowingConfirm = true;
                    confirmCursor = true;
                } else {
                    showErrorMessage = true;
                    errorTimer = 60;
                }
            }
            else if (configCursor == 9) { // コース選択にもどる
                // 【重要】前の画面に戻る際も履歴をクリアしておく
                inputHistory.clear();
                
                currentState = AGE_SELECT_MODE;
                isShowingConfirm = false;
                isAgeConfirmed = false;
            }
        }
    }

    // =====================================================================
    // SELECT_MODE : マップ難易度選択画面
    // =====================================================================
    else if (currentState == SELECT_MODE) {
        inputHistory.push_back(key);
        if (inputHistory.size() > 15) {
            inputHistory.erase(inputHistory.begin());
        }
        
        // --- 1. マップ画面用隠しコマンド判定 ---
        if (inputHistory.size() >= secretCommand.size()) {
            bool match = true;
            for (int i = 0; i < secretCommand.size(); i++) {
                int historyIndex = inputHistory.size() - secretCommand.size() + i;
                if (inputHistory[historyIndex] != secretCommand[i]) {
                    match = false;
                    break;
                }
            }
            if (match && !isSecretLevelUnlocked) {
                isSecretLevelUnlocked = true;
                seGenerateVeryHard.play();
                inputHistory.clear();
                
                selectVerticalZone = 0;
                selectedLevel = 3;
            }
        }
        
        // --- 2. 上下キー：選択ゾーンの切り替え ---
        if (key == OF_KEY_UP) {
            if (selectVerticalZone == 1) {
                selectVerticalZone = 0; // 下側からスクショ選択（上側）へ戻る
                seSelect.play();
            }
        }
        if (key == OF_KEY_DOWN) {
            if (selectVerticalZone == 0) {
                selectVerticalZone = 1; // スクショ選択（上側）から下側ゾーンへ移動
                selectedBottomLevel = 0; // 下に降りた時は、まず左側の「れんしゅう」に合わせる
                seSelect.play();
            }
        }
        
        // --- 3. 左右キー：各ゾーンでの選択移動 ---
        if (selectVerticalZone == 0) {
            // ─── 【上側ゾーン】：通常ステージ選択 ───
            int maxStageIndex = isSecretLevelUnlocked ? 3 : 2;
            if (key == OF_KEY_LEFT) {
                if (selectedLevel > 0) {
                    selectedLevel--;
                    seSelect.play();
                }
            }
            if (key == OF_KEY_RIGHT) {
                if (selectedLevel < maxStageIndex) {
                    selectedLevel++;
                    seSelect.play();
                }
            }
        }
        else if (selectVerticalZone == 1) {
            // ───【下側ゾーン】：専用変数 selectedBottomLevel を左右で切り替え ───
            // 0 = れんしゅう, 1 = もんだいせっていにもどる
            if (key == OF_KEY_LEFT) {
                if (selectedBottomLevel > 0) {
                    selectedBottomLevel = 0; // 左（れんしゅう）へ
                    seSelect.play();
                }
            }
            if (key == OF_KEY_RIGHT) {
                if (selectedBottomLevel < 1) {
                    selectedBottomLevel = 1; // 右（もどる）へ
                    seSelect.play();
                }
            }
        }
        
        // --- 4. 決定キー ---
        if (key == OF_KEY_RETURN) {
            seChoose.play();
            inputHistory.clear();
            
            if (selectVerticalZone == 0) {
                // ─── 【上側：ステージ選択の決定】 ───
                sendText2server("--start--");
                if (selectedLevel <= 2) {
                    logger.startStage(selectedLevel, 1);
                    if(selectedLevel == 0) sendText2server("--easy play--");
                    else if(selectedLevel == 1) sendText2server("--normal play--");
                    else if(selectedLevel == 2) sendText2server("--hard play--");
                    
                    initGame();
                    lastPlayerPos.set(myPlayer.x, myPlayer.y);
                    currentState = MAP_MODE;
                    previousState = MAP_MODE;
                    isCountingDown = true;
                    countdownTimer = 3.0;
                }
                else if (selectedLevel == 3) {
                    selectedLevel = 4;
                    logger.startStage(3, 1);
                    initGame();
                    lastPlayerPos.set(myPlayer.x, myPlayer.y);
                    sendText2server("--veryhard play--");
                    currentState = MAP_MODE;
                    previousState = MAP_MODE;
                    isCountingDown = true;
                    countdownTimer = 3.0;
                }
            }
            else if (selectVerticalZone == 1) {
                // ───【下側：れんしゅう または もどる の決定】 ───
                if (selectedBottomLevel == 0) {
                    selectedLevel = 3;
                    initGame();
                    //【左側：れんしゅうの開始処理】
                    sendText2server("--start tutorial--");
                    previousModeBeforeTutorial = currentState;
                    currentState = TUTORIAL_MODE;
                    previousState = TUTORIAL_MODE;
                    isCountingDown = true;
                    countdownTimer = 3.0;
                    
                    selectVerticalZone = 0; // 次回のためにゾーンを戻しておく
                    selectedLevel = 0;
                }
                else if (selectedBottomLevel == 1) {
                    // 【右側：「もどる」の決定処理】
                    selectVerticalZone = 0; // ゾーンを初期値に戻しておく
                    selectedLevel = 0;      // ステージ選択位置もリセット
                    if (ageCursor == 7 && showCustomMode) {
                        currentState = DIFFICULTY_CONFIG_MODE;
                    } else {
                        currentState = AGE_SELECT_MODE;
                        isAgeConfirmed = false;
                    }
                }
            }
        }
    }
    else if (currentState == MAP_MODE || currentState == TUTORIAL_MODE) {
        if(currentState == TUTORIAL_MODE && key == OF_KEY_RETURN){
            seSelect.play();
            currentState = previousModeBeforeTutorial;
            return;
        }
        
        if (isStunned) return;
        if (isDashing) return;
        
        // --- MAP_MODE 中に 'q' が押されたらポーズ ---
        if (currentState == MAP_MODE) {
            if (isPaused) {
                    // ポーズ中のキー入力処理はここにまとめる
                    if (key == 'q') {
                        isPaused = false;       // ゲームに戻る
                        seSelect.play();        // 効果音（お好みで変更してください）
                        return;
                    }
                    else if (key == 'c') {
                        isPaused = false;       // ポーズ状態を解除しておく

                        // 1. 再生中のゲームBGMをすべて停止（音の重なり防止）
                        for(int i = 0; i < 5; i++) {
                            if(bgm[i].isPlaying()) {
                                bgm[i].stop();
                            }
                        }
                        currentState = TITLE_MODE;
                        ageCommandInput.clear();  // コース選択用のコマンド履歴を消去
                        inputHistory.clear();     // マップセレクト等のコマンド履歴を消去
                        showCustomMode = false;
                        isSecretLevelUnlocked = false;
                        seChoose.play();
                        return;
                    }
                }
            else {
                // 通常プレイ中（ポーズしていないとき）のキー入力処理
                if (key == 'q') {
                    isPaused = true;        // ポーズ画面を開く
                    seSelect.play();        // メニューを開く効果音
                    return;
                }
                
                // ここから下に、普段のプレイヤーの移動処理（十字キーなど）が続くように
            }
        }
        if(isPaused) return;
        if(!isGameCleared && !isGameFailed && !isDashStunned){
            if (key == OF_KEY_UP)    upPressed = true;
            if (key == OF_KEY_DOWN)  downPressed = true;
            if (key == OF_KEY_LEFT)  leftPressed = true;
            if (key == OF_KEY_RIGHT) rightPressed = true;
            
            if (key == '1') {
                            if (currentState == TUTORIAL_MODE) {
                                tutorialMessage = "[ダッシュ]\n壁にぶつかるまで 前にこうそくで進む!";
                                messageTimer = 3.0; // 3秒間表示
                            }
                            if(skillStocks[DASH] > 0){
                                activateDash();
                                seDash.play();
                                
                                // ★【追加】DASH (SkillTypeの値を配列インデックス 0〜3 に変換)
                                logger.recordItemUse(static_cast<int>(DASH) - 1);
                                
                                skillStocks[DASH]--; // 使うと減る
                            }
                        }
                        if (key == '2') {
                            if (currentState == TUTORIAL_MODE) {
                                tutorialMessage = "[フリーズ]\nあいてを 3びょうかん こおらせて\nうごきを とめる!\n(こうかちゅうは つぎのフリーズは\n つかえません)";
                                messageTimer = 3.0;
                            }
                            if(skillStocks[FREEZE] > 0 && !isComFrozen){
                                activateFreeze();
                                
                                // ★【追加】FREEZE
                                logger.recordItemUse(static_cast<int>(FREEZE) - 1);
                                
                                skillStocks[FREEZE]--;
                            }
                        }
                        
                        if (key == '3') {
                            if (currentState == TUTORIAL_MODE) {
                                if(skillStocks[TIME_STOP] > 0){
                                    tutorialMessage = "[タイムストップ]\nじぶん以外のすべてを4びょうかんていしさせて\n自由に動くことができる!\nたからばこからしか\nゲットできない!";
                                }else{
                                    tutorialMessage = "[???]\nじぶん以外のすべてを?びょうかん???させて\n???ことができる!\nたからばこからしか\nゲットできない!";
                                }
                                messageTimer = 3.0;
                            }
                            if(skillStocks[TIME_STOP] > 0){
                                isTimeStopped = true;
                                timeStopTimer = ofGetElapsedTimeMillis();
                                
                                // ★【追加】TIME_STOP
                                logger.recordItemUse(static_cast<int>(TIME_STOP) - 1);
                                
                                skillStocks[TIME_STOP]--;
                                seTimeStop.play(); // 停止っぽい音を流用
                            }
                        }

                        // --- トラップアイテムの使用 ---
            if (key == '4') {
                if (currentState == TUTORIAL_MODE) {
                    tutorialMessage = "[トラップ]\nじぶんの足もとに あいてがふむと5びょうかん \n動けなくなるトラップを しかける! \n(4つ目を置くと、一番最初においたトラップがきえます)";
                    messageTimer = 3.0;
                }
                
                if(skillStocks[TRAP] > 0){
                    // いまプレイヤーがいる足元に、すでにトラップがあるかチェックする
                    bool isAlreadyTrapExist = false;
                    for (const auto& trap : activeTraps) {
                        if (trap.x == myPlayer.x && trap.y == myPlayer.y) {
                            isAlreadyTrapExist = true;
                            break;
                        }
                    }
                    
                    // 足元にまだトラップがない場合だけ、設置処理とストック消費を行う
                    if (!isAlreadyTrapExist) {
                        activateTrap();      // トラップ設置（上限を超えていれば一番古いやつを消す）
                        
                        //【追加】TRAP (足元に罠がなく、設置に成功した時だけ記録)
                        logger.recordItemUse(static_cast<int>(TRAP) - 1);
                        
                        skillStocks[TRAP]--; // 設置が成功したときだけ消費する
                    } else {
                        // (オプション) 重ねて置けなかったときに警告音を鳴らしたい場合はここに追加できます
                        // seAlert.play();
                    }
                }
            }
        }
    }
    
    else if (currentState == QUIZ_MODE) {
        if (isQuizShowReady) return; // 演出中はキー入力を無視
        int selection = -1;
        if (key == '1') selection = 0;
        if (key == '2') selection = 1;
        if (key == '3') selection = 2;
        if (key == '4') selection = 3;
        
        // 5秒経過してボタンが表示されている、かつ 'c' または 'C' が押された時
        if (showHintButton && key == OF_KEY_RETURN) {
            isHintActive = true;
            seChoose.play(); // 必要であれば、ヒントが出た時の効果音
        }

        if (selection != -1) {
            
            // 1. まずミリ秒（uint64_t）同士で引き算を行う
                uint64_t currentMillis = ofGetElapsedTimeMillis();
                uint64_t elapsedMillis = 0;
                
                if (currentMillis > quizStartTime) {
                    elapsedMillis = currentMillis - quizStartTime;
                }
                
                // 2. 最後に float にキャストして 1000.0f で割って秒にする
                float responseTime = (float)elapsedMillis / 1000.0f;
                    
            // 正誤判定のフラグ
            bool isCorrect = (selection == correctIdx);
                    
            // ★【重要】PlayLoggerにクイズの結果を記録する（正誤、ヒント使用有無、解答時間）
            logger.recordQuizResult(isCorrect, isHintActive, responseTime);
            currentState = RESULT_MODE;
            if (isCorrect) {
                // --- 正解時 ---
                seCorrect.play();
                // 【修正】クイズでは TIME_STOP(4) を除いた 1〜3 の範囲で抽選[cite: 17]
                int getIdx = (int)ofRandom(1, 4);
                string skillNames[] = { "なし", "ダッシュ", "フリーズ", "トラップ", "タイムストップ" };
                
                // 【追加】アイテム取得上限の設定
                int maxStock = (getIdx == TIME_STOP) ? 2 : 3;
                if (skillStocks[getIdx] < maxStock) {
                    skillStocks[getIdx]++;
                    
                    // メッセージを2つに分割して保存する
                    resultMessage = "せいかい!\n[" + skillNames[getIdx];
                    resultMessageEnd = "] を 手に入れた！";
                    gainedSkillType = getIdx; // 絵を出すためにIDを記録
                } else {
                    
                    resultMessage = "せいかい!\n（しかし" + skillNames[getIdx] +"を これいじょうもてない!）";
                    resultMessageEnd = "";
                    gainedSkillType = 0;
                }
                correctAnswers++; // 正解数をカウント
                
            } else {
                seIncorrect.play();
                resultMessage = "ざんねん! こたえは" + currentQuestion.choices[correctIdx] + "でした。";
                resultMessageEnd = "";
                gainedSkillType = 0;
                QuizIncorrect();
                logger.recordPenalty();
            }
        }
    }
    else if (currentState == RESULT_MODE && !isGameCleared && !isGameFailed) {
        if(key=='1' || key=='2' || key=='3' || key== '4' || key==OF_KEY_RETURN || key==OF_KEY_UP || key==OF_KEY_DOWN || key==OF_KEY_LEFT || key==OF_KEY_RIGHT){
            
            // 通常の問題正誤表示なら、マップに戻る
            currentState = previousState;
                        
            // ペナルティの実行（既存の処理）
            if (reservedPenalty == P_STUN) {
                isStunned = true;
                seStun.play();
                stunTimer = ofGetElapsedTimeMillis();
            } else if (reservedPenalty == P_ENCOUNTER) {
                step = targetStep - 1;
            }
            reservedPenalty = P_NONE;
        }
        return;
    }
    
    if (currentState == SUMMARY_MODE) {
        if (key == OF_KEY_UP) {
            summaryCursor--;
            if (summaryCursor < 0) summaryCursor = 3; // 4項目なので3へループ
            seSelect.play();
        }
        if (key == OF_KEY_DOWN){
            summaryCursor++;
            if (summaryCursor > 3) summaryCursor = 0; // 4項目なので0へループ
            seSelect.play();
        }
            
        if (key == OF_KEY_RETURN) {
            seChoose.play();
            if (summaryCursor == 0) { // RETRY
                sendText2server("--restart--");
                initGame();
                currentState = MAP_MODE;
            } else if (summaryCursor == 1) { // DIFFICULTY
                currentState = SELECT_MODE;
            } else if (summaryCursor == 2) { // コース選択
                isSecretLevelUnlocked = false;
                currentState = AGE_SELECT_MODE;
            }
            else if(summaryCursor == 3){ // タイトルに
                currentState = TITLE_MODE;
                ageCommandInput.clear();  // コース選択用のコマンド履歴を消去
                inputHistory.clear();     // マップセレクト等のコマンド履歴を消去
                showCustomMode = false;
                isSecretLevelUnlocked = false;
                sendText2server("--quit--");
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == OF_KEY_UP)    upPressed = false;
    if (key == OF_KEY_DOWN)  downPressed = false;
    if (key == OF_KEY_LEFT)  leftPressed = false;
    if (key == OF_KEY_RIGHT) rightPressed = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::setRecommendedSettings(int ageIndex) {
    // 一度すべてのフラグとモードをリセット
    useAdd = useSub = useMul = useDiv = false;
    mulLimitMode = CL_KUKU;
    divLimitMode = CL_KUKU;
    
    // カスタム用変数のデフォルト値（基本はプラス1〜2けた）
    minDigits = 1;
    maxDigits = 2;

    switch(ageIndex) {
        case 0: // がっこうにいくまえ (1〜10の たしざん)
            useAdd = true;
            maxNumLimit = 10;
            minDigits = 1;
            maxDigits = 1; // 10までなので1けた基準
            break;
                    
        case 1: // しょうがく1ねんせい (1〜10の たし・ひき)
            useAdd = true;
            useSub = true;
            maxNumLimit = 10;
            minDigits = 1;
            maxDigits = 1;
            break;
                    
        case 2: //小学2ねんせい (20までのたしひき・かけざん3のだんまで)
            useAdd = true;
            useSub = true;
            useMul = true;
            mulLimitMode = CL_KUKU; // 九九の範囲内
            maxNumLimit = 20;
            minDigits = 1;
            maxDigits = 2; // 20までなので2けた
            break;
                    
        case 3: // 小学3ねんせい (2けたのたしひき・九九・わりざん3のだんまで)
            useAdd = useSub = useMul = true;
            useDiv = false;
            mulLimitMode = CL_KUKU;
            divLimitMode = CL_KUKU;
            maxNumLimit = 30; // 2けた計算ベース
            minDigits = 1;
            maxDigits = 2;
            break;
                    
        case 4: // 小学4ねんせい (3けたのたしひき・かけざんわりざん九九まで)
            useAdd = useSub = useMul = useDiv = true;
            mulLimitMode = CL_KUKU;
            divLimitMode = CL_KUKU;
            maxNumLimit = 50; // 3けたの筆算なども含むため、大きさを50に調整
            minDigits = 1;
            maxDigits = 3; // 3けたまで
            break;
                    
        case 5: // 小学5〜6ねんせい (3けたのたしひき・乗除は割られる数100/割る数2けたまで)
            useAdd = useSub = useMul = useDiv = true;
            mulLimitMode = CL_STAGE56; // 新設：小5〜6年基準ルール
            divLimitMode = CL_STAGE56; // 新設：小5〜6年基準ルール
            maxNumLimit = 50;
            minDigits = 1;
            maxDigits = 3;
            break;
                    
        case 6: // 中学生以上 (大人の脳トレ・マイナス〜4けたの四則演算)
        default:
            useAdd = useSub = useMul = useDiv = true;
            mulLimitMode = CL_STAGE56; // 制限なし
            divLimitMode = CL_STAGE56; // 制限なし
            maxNumLimit = 100;
            
            // 中学生以上はデフォルトでマイナス計算（答えが負の数になる）を許可
            minDigits = -1; // マイナス1けたまでを初期設定にする
            maxDigits = 4;  // 最大4けた
            break;
    }
}

//--------------------------------------------------------------
void ofApp::drawTutorialGuide() {
    // 全体的にサイズを 1.2倍 程度に大きく設定
    float gx = 50;
    float gy = ofGetHeight() - 330;
    if(previousState == TUTORIAL_MODE && currentState == QUIZ_MODE){
        gy = ofGetHeight()/2;
    }
    float baseW = 600;             // 横幅
    float baseH = 300;
    float time = ofGetElapsedTimef();

    // 台座
    ofSetColor(0, 0, 0, 200);
    ofDrawRectRounded(gx, gy, baseW, baseH, 15);

    // --- スティックのアニメーション (位置を調整) ---
    float centerX = gx + 90; // スティックのX位置
    float centerY = gy + 140;
    float sx = 0, sy = 0;
    
    if(ofGetKeyPressed(OF_KEY_LEFT)) sx = -30;
    else if(ofGetKeyPressed(OF_KEY_RIGHT)) sx = 30;
    if(ofGetKeyPressed(OF_KEY_UP)) sy = -30;
    else if(ofGetKeyPressed(OF_KEY_DOWN)) sy = 30;
    
    if(sx == 0 && sy == 0){
        sx = cos(time * 4) * 15;
        sy = sin(time * 4) * 15;
    }

    ofSetColor(100);
    ofDrawCircle(centerX, centerY, 55); // 土座
    ofSetColor(255, 125, 0);
    ofSetLineWidth(8);
    ofDrawLine(centerX, centerY, centerX + sx, centerY + sy);
    ofDrawCircle(centerX + sx, centerY + sy, 30); // 頭
    
    ofSetColor(255);
    myFont.drawString("いどう", centerX - 35, gy + 210);

    // --- 5つのボタン設定 (すべてのボタンを四角に、配置と文字位置を調整) ---
    struct Btn { ofColor col; float x, y; string mapLabel; string quizLabel; int key; bool isRotated; };
    
    // カラーボタンの正方形配置 (左上 X: 260, 右上 X: 370 として少し間隔を広げました)
    // 白ボタンはさらに右へ (X: 500)
    Btn b[] = {
        {ofColor::red,    260, 90,  "ダッシュ",       "こたえA", '1',          false}, // 左上：赤
        {ofColor::blue,   370, 90,  "フリーズ",       "こたえB", '2',          false}, // 右上：青
        {ofColor::yellow, 260, 190, "タイムストップ", "こたえD", '3',          false}, // 左下：黄
        {ofColor::green,  370, 190, "トラップ",       "こたえC", '4',          false}, // 右下：緑
        {ofColor::white,  500, 140, "けってい,もどる", "ヒント",  OF_KEY_RETURN, true}   // 右側：白 (45度回転)
    };

    for(int i = 0; i < 5; i++) {
        // --- ボタン本体（すべて四角形）の描画 ---
        ofSetColor(b[i].col);
        
        ofPushMatrix();
        ofTranslate(gx + b[i].x, gy + b[i].y); // ボタンの中心を原点に
        
        if (b[i].isRotated) {
            ofRotateDeg(45); // 白ボタンのみ45度回転
        }
        
        // 直径56pxの丸ボタン(半径28)と同等サイズになるよう、一辺48pxの正方形を描画
        ofDrawRectangle(-24, -24, 48, 48);
        ofPopMatrix();
            
        // --- ラベルの描画 ---
        ofSetColor(255);
        string label = (currentState == QUIZ_MODE) ? b[i].quizLabel : b[i].mapLabel;

        // 【重なり・ズレ対策】文字数(文字の長さ)に合わせてX座標のズレを自動計算する
        // 1文字あたり約10pxとして、文字列が中心にくるように調整
        float textOffsetX = (label.length() * 10) / 2;

        // 上段（赤・青）と白ボタンは「上」に、下段（黄・緑）は「下」にテキストを配置
        float labelY;
        if (i == 0 || i == 1 || i == 4) {
            labelY = gy + b[i].y - 40;
        } else {
            labelY = gy + b[i].y + 55;
        }

        // 計算したOffsetXを引いて文字を表示
        smallFont.drawString(label, gx + b[i].x - textOffsetX, labelY);

        // --- キー入力時のエフェクト ---
        if(ofGetKeyPressed(b[i].key) || (i == 2 && ofGetKeyPressed(' '))) {
            ofSetColor(255, 255, 255, 180);
            ofNoFill();
            ofSetLineWidth(4);
            
            // 入力時のエフェクト枠も同じ形状の四角形にする
            ofPushMatrix();
            ofTranslate(gx + b[i].x, gy + b[i].y);
            if (b[i].isRotated) {
                ofRotateDeg(45);
            }
            // 少し大きめの四角枠
            ofDrawRectangle(-32, -32, 64, 64);
            ofPopMatrix();
            
            ofFill();
        }
    }
}

//--------------------------------------------------------------
void ofApp::generateMap() {
    rooms.clear();
    chests.clear();
    
    // --- チュートリアル (3) の場合の特別処理 ---
    if (selectedLevel == 3) {
        // チュートリアル用のタイル設定
        int floorTile = 0; // 草原
        int wallTile = 2;  // 山
        
        // 全面を壁で埋める
        mapData.assign(gridW, vector<int>(gridH, wallTile));
        
        // 中を広場としてくり抜く（外周1マスを残す）
        for (int y = 1; y < gridH - 1; y++) {
            for (int x = 1; x < gridW - 1; x++) {
                mapData[x][y] = floorTile;
            }
        }
        
        // roomsが空だとinitGameの処理が走らないので、ダミーを入れる
        BspRect tutorialRoom = {1, 1, gridW - 2, gridH - 2};
        rooms.push_back(tutorialRoom);
        // プレイヤーとCOMの初期位置
        myPlayer.x = 1;
        myPlayer.y = 1;
        myPlayer.drawPos.set(myPlayer.x * currentTilesize, myPlayer.y * currentTilesize);
        myCom.x = 1;
        myCom.y = 1;
        myCom.drawPos.set(myCom.x * currentTilesize, myCom.y * currentTilesize);
        
        // ゴールを右下に設置
        GoalX = gridW - 2;
        GoalY = gridH - 2;
        mapData[GoalX][GoalY] = 3; // ゴールチップ（看板など）
        
        myCom.goalX = GoalX;
        myCom.goalY = GoalY;
        
        return; // ★ここで終了。これ以降のBSP生成ロジックを通さない
    }
    
    // --- 1. タイルと基本変数の設定 ---
    int floorTile;
    int wallTile;
        
    if (selectedLevel == 4) {
        // VERY HARD用（グラデーションのベースとなる最初の番号）
        floorTile = (int)ofRandom(10, 18);
        wallTile = (int)ofRandom(18, 21); // 壁も4種類（18~21）ある想定
    } else {
        floorTile = (selectedLevel == 0) ? 0 : 8;
        wallTile = (selectedLevel == 0) ? 1 : 9;
    }
    int obstacleTile;
    if (selectedLevel == 4) {
        // Very Hardなら 18, 19, 20, 21 の中からランダムに選ぶ
        obstacleTile = (int)ofRandom(18, 22);
    } else {
        // それ以外の難易度なら 2（山）にする
        obstacleTile = 2;
    }
    int corridorFlag = 99; // 【追加】通路であることを示す一時的な番号

    // マップ初期化
    for (int y = 0; y < gridH; y++) {
        for (int x = 0; x < gridW; x++) mapData[x][y] = wallTile;
    }

    // --- 追加するヘルパー：2点間をL字の道で繋ぐ ---
    auto connectPoints = [&](int x1, int y1, int x2, int y2, int tile) {
        int cx = x1, cy = y1;
        // X方向に進む
        while (cx != x2) {
            for (int dy = -1; dy <= 1; dy++) { // 幅3マス
                if (cy + dy >= 0 && cy + dy < gridH) mapData[cx][cy + dy] = tile;
            }
            cx += (x1 < x2) ? 1 : -1;
        }
        // Y方向に進む
        while (cy != y2) {
            for (int dx = -1; dx <= 1; dx++) { // 幅3マス
                if (cx + dx >= 0 && cx + dx < gridW) mapData[cx + dx][cy] = tile;
            }
            cy += (y1 < y2) ? 1 : -1;
        }
    };
    
    // --- 1. BSP分割と部屋生成 (変更なし) ---
    BspRect root = {2, 2, gridW - 4, gridH - 4};
    vector<BspRect> areas;
    areas.push_back(root);
    int splitCount;
    if (selectedLevel == 0) splitCount = 2;
    else if (selectedLevel == 1) splitCount = 3;
    else if (selectedLevel == 2) splitCount = 4;
    else splitCount = 5; // VERY HARDはさらに細かく分割して部屋を増やす
    
    struct Connection { BspRect a; BspRect b; };
    vector<Connection> connections;
    
    for (int i = 0; i < splitCount; i++) {
        vector<BspRect> nextAreas;
        for (auto& a : areas) {
            bool splitH = (ofRandom(1.0) > 0.5);
            if (a.w > a.h * 1.5) splitH = false;
            else if (a.h > a.w * 1.5) splitH = true;
            BspRect a1, a2;
            if (splitH) {
                int splitY = ofRandom(a.h * 0.4, a.h * 0.6);
                a1 = {a.x, a.y, a.w, splitY};
                a2 = {a.x, a.y + splitY, a.w, a.h - splitY};
            } else {
                int splitX = ofRandom(a.w * 0.4, a.w * 0.6);
                a1 = {a.x, a.y, splitX, a.h};
                a2 = {a.x + splitX, a.y, a.w - splitX, a.h};
            }
            nextAreas.push_back(a1);
            nextAreas.push_back(a2);
            
            connections.push_back({a1, a2});
        }
        areas = nextAreas;
    }
    
    // エリアを左上から順にソートする（メインルートを整列させるため）
    sort(areas.begin(), areas.end(), [](const BspRect& a, const BspRect& b) {
        if (a.y != b.y) return a.y < b.y;
        return a.x < b.x;
    });

    for (auto& a : areas) {
        BspRect r;
        r.w = ofRandom(6, a.w - 2);
        r.h = ofRandom(6, a.h - 2);
        r.x = a.x + (a.w - r.w) / 2;
        r.y = a.y + (a.h - r.h) / 2;
        rooms.push_back(r);
        for (int yy = r.y; yy < r.y + r.h; yy++) {
            for (int xx = r.x; xx < r.x + r.w; xx++) mapData[xx][yy] = floorTile;
        }
    }
    
    // --- 2. メインルートの接続（一本の背骨を作る） ---
    // 部屋を 0->1, 1->2, 2->3... と順番に繋いでいく
    for (int i = 0; i < (int)rooms.size() - 1; i++) {
        int x1 = rooms[i].x + rooms[i].w / 2;
        int y1 = rooms[i].y + rooms[i].h / 2;
        int x2 = rooms[i+1].x + rooms[i+1].w / 2;
        int y2 = rooms[i+1].y + rooms[i+1].h / 2;
        connectPoints(x1, y1, x2, y2, corridorFlag);

        // --- 3. 【ハード対策】環状路（ループ）の追加 ---
        // 4つ先のエリアがあるような「深い袋小路」を避けるため、
        // 一定の確率で離れた部屋同士を繋ぎ、ループ（ショートカット）を作る
        if (selectedLevel == 2 && ofRandom(1.0) > 0.6) {
            int target = (i + 3) % rooms.size();
            int tx = rooms[target].x + rooms[target].w / 2;
            int ty = rooms[target].y + rooms[target].h / 2;
            connectPoints(x1, y1, tx, ty, corridorFlag);
        }
    }

    // キャラクター位置・ゴールの設定 (変更なし)
    if (!rooms.empty()) {
        // 1. プレイヤーとCOMの初期位置（最初の部屋：左上）
        myPlayer.x = rooms[0].x + rooms[0].w / 2;
        myPlayer.y = rooms[0].y + rooms[0].h / 2;
        myPlayer.drawPos.set(myPlayer.x * currentTilesize, myPlayer.y * currentTilesize);
        myCom.x = myPlayer.x;
        myCom.y = myPlayer.y;
        myCom.drawPos.set(myCom.x * currentTilesize, myCom.y * currentTilesize);
        
        // 2. ゴール地点の設定
        int targetIdx = 0;
        float maxDistSq = -1.0;

        // プレイヤーの初期位置（rooms[0]の中心）を基準にする
        float startX = rooms[0].x + rooms[0].w / 2.0;
        float startY = rooms[0].y + rooms[0].h / 2.0;

        // 全ての部屋をループして、最も遠い部屋のインデックス(targetIdx)を探す
        for (int i = 0; i < (int)rooms.size(); i++) {
            float rx = rooms[i].x + rooms[i].w / 2.0;
            float ry = rooms[i].y + rooms[i].h / 2.0;
            
            float dx = rx - startX;
            float dy = ry - startY;
            float distSq = dx * dx + dy * dy; // 三平方の定理（距離の2乗）

            if (distSq > maxDistSq) {
                maxDistSq = distSq;
                targetIdx = i;
            }
        }

        // 決定した座標をセット
        GoalX = rooms[targetIdx].x + rooms[targetIdx].w / 2;
        GoalY = rooms[targetIdx].y + rooms[targetIdx].h / 2;

        // 画面端のガード
        if (GoalX >= gridW - 2) GoalX = gridW - 3;
        if (GoalY >= gridH - 2) GoalY = gridH - 3;

        // ここで初めて mapData に 3 を書き込む
        mapData[GoalX][GoalY] = 3;

        myCom.goalX = GoalX;
        myCom.goalY = GoalY;
    }

    // --- 3. 障害物の配置 (通路フラグのある場所を避ける) ---
    int minObs, maxObs;

    // 1. 難易度ごとに上限・下限を設定
    if (selectedLevel == 0 || selectedLevel == 3) {         // EASY (60x60)
        minObs = 70;
        maxObs = 120;
    } else if (selectedLevel == 1) {  // NORMAL (60x60)
        minObs = 110;
        maxObs = 180;
    } else if(selectedLevel == 2) {                          // HARD (100x100)
        // マップが広くなるので、数を大幅に増やす
        minObs = 300;
        maxObs = 450;
    }else {
        // ★ VERY HARD: 広いマップに合わせてさらに増量
        minObs = 600;
        maxObs = 850;
    }

    // 2. その範囲内でランダムに目標数を決定
    int obsTarget = (int)ofRandom(minObs, maxObs + 1);
    int placed = 0;
    int maxAttempts = obsTarget * 20; // 密度が高すぎるときの無限ループ防止策
    int attempts = 0;

    while (placed < obsTarget && attempts < maxAttempts) {
        attempts++;
        int rx = ofRandom(2, gridW - 2);
        int ry = ofRandom(2, gridH - 2);
        
        bool isFloor = false;
        if (selectedLevel == 4) {
            // VERY HARDでは 10-17 が床、18 が壁なので、10-17 の上のみ配置許可
            isFloor = (mapData[rx][ry] >= 10 && mapData[rx][ry] <= 17);
        } else {
            isFloor = (mapData[rx][ry] == floorTile);
        }
        
        // 修正点：ゴールの描画範囲 2x2 (GoalX~X+1, GoalY~Y+1) に重ならないようにする
        bool inGoalArea = (rx >= GoalX && rx <= GoalX + 1 && ry >= GoalY && ry <= GoalY + 1);
        bool inStartPos = (rx == myPlayer.x && ry == myPlayer.y);
        
        if ((isFloor || mapData[rx][ry] == 99) && !inGoalArea && !inStartPos) {
            // 周囲の隣接チェック（既存ロジック）
            bool hasNeighbor = false;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    if (dx == 0 && dy == 0) continue;
                    int tid = mapData[rx + dx][ry + dy];
                    if (selectedLevel == 4) {
                        if (tid >= 18 && tid <= 21) hasNeighbor = true;
                    } else {
                        if (tid == 2) hasNeighbor = true;
                    }
                }
                if (hasNeighbor) break;
            }
            
            if (!hasNeighbor) {
                mapData[rx][ry] = (selectedLevel == 4) ? (18 + (int)ofRandom(4)) : 2;
                placed++;
            }
        }
    }

    // --- 5. 仕上げ（通路フラグの復元） ---
    for (int y = 0; y < gridH; y++) {
        for (int x = 0; x < gridW; x++) {
            if (mapData[x][y] == corridorFlag) {
                mapData[x][y] = floorTile;
            }
        }
    }

    // --- 5. 宝箱の配置 (Easy以外、これも通路を避けるようにmapDataをチェック) ---
    chests.clear();
    int minPerRoom, maxPerRoom;

    // 難易度による1部屋あたりの配置数設定
    if (selectedLevel == 0) { // Easy
        minPerRoom = 1; maxPerRoom = 2;
    } else if (selectedLevel == 1) { // Normal
        minPerRoom = 1; maxPerRoom = 3;
    } else if(selectedLevel == 2) { // Hard
        minPerRoom = 2; maxPerRoom = 4;
    } else if(selectedLevel == 4){
        minPerRoom = 2; maxPerRoom = 5; // 広いので多めに
    }

    for (auto& r : rooms) {
        int count = (int)ofRandom(minPerRoom, maxPerRoom + 1);
        for (int i = 0; i < count; i++) {
            int tx = ofRandom(r.x, r.x + r.w);
            int ty = ofRandom(r.y, r.y + r.h);

            // 【修正ポイント】
            // 1. ゴール地点（2x2マス）の範囲内ではない
            int goalSize = 2;
            bool isInsideGoal = (tx >= GoalX && tx < GoalX + goalSize) && (ty >= GoalY && ty < GoalY + goalSize);
            
            // 2. プレイヤーの初期位置ではない
            bool isPlayerPos = (tx == myPlayer.x && ty == myPlayer.y);

            if (!isInsideGoal && !isPlayerPos) {
                int currentTile = mapData[tx][ty];
                // もしそこに障害物(2)があったら、宝箱と重なって見栄えが悪いので消す
                // ★修正：もしそこに障害物があったら床に戻す判定をVERY HARDにも対応
                bool isObstacle = false;
                if (selectedLevel == 4) {
                    isObstacle = (currentTile >= 18 && currentTile <= 21);
                } else {
                    isObstacle = (currentTile == 2);
                }
                                
                if (isObstacle) {
                    mapData[tx][ty] = floorTile;
                }

                TreasureChest c;
                c.x = tx; c.y = ty;
                c.isOpen = false;
                c.frame = 0;
                // 宝箱の効果抽選--------------------
                float rand = ofRandom(1.0);
                if (rand < 0.75) c.type = 0;
                else if (rand < 0.9) c.type = 1;
                else c.type = 2;
                //--------------------------------
                chests.push_back(c);
            }
        }
    }
}

//----------------------------------------------------
int ofApp::getCurrentRoom(int gridX, int gridY) {
    for (int i = 0; i < rooms.size(); i++) {
        if (gridX >= rooms[i].x && gridX < rooms[i].x + rooms[i].w &&
            gridY >= rooms[i].y && gridY < rooms[i].y + rooms[i].h) {
            return i;
        }
    }
    return -1;
}

//-----------------------------------------------------
// COMの思考ルーチン：現在の立ち位置によって goalX, goalY を書き換える
void ofApp::updateComGoal() {
    // 1. 常に最終的なゴール地点（GoalX, GoalY）を目標にする
    myCom.goalX = GoalX;
    myCom.goalY = GoalY;

    // 2. 部屋の切り替わり判定（これだけで十分です）
    int curRoomIdx = getCurrentRoom(myCom.x, myCom.y);
    static int lastRoomIdx = -1;

    // 部屋が変わった瞬間、古い探索の「逆走防止」や「計算済みパス」をリセットする
    if (curRoomIdx != -1 && curRoomIdx != lastRoomIdx) {
        myCom.history.clear();
        myCom.currentPath.clear();
        lastRoomIdx = curRoomIdx;
    }
}

//-----------------------------------------------------
void ofApp::drawWindow(float x, float y, float w, float h) {
    ofPushStyle(); // 現在の色設定などを保存
    
    // 1. 一番外側の白い枠
    ofSetColor(255);
    ofSetRectMode(OF_RECTMODE_CORNER);
    ofDrawRectangle(x, y, w, h);
    
    // 2. 内側の黒い背景（枠の太さ分だけ小さく描く）
    float frameThickness = 4.0; // 枠の太さ
    ofSetColor(0);
    ofDrawRectangle(x + frameThickness, y + frameThickness,
                    w - frameThickness * 2, h - frameThickness * 2);
    
    // 3. 内側に細い白線を入れる
    ofSetColor(255);
    ofNoFill(); // 塗りつぶしなし
    ofSetLineWidth(2.0);
    ofDrawRectangle(x + frameThickness * 2, y + frameThickness * 2,
                    w - frameThickness * 4, h - frameThickness * 4);
    
    ofPopStyle(); // 色設定などを元に戻す
}

//-----------------------------------------------------
void ofApp::setupMathQ() {
    totalQuestions++; // 出題数をカウント
    
    // --- 1. 有効な演算子のリストを作成 ---
    vector<int> availableTypes;
    
    // 各コースの5月末進度に合わせて有効な演算子を自動調整 (カスタムモード以外)
    if (!showCustomMode || ageCursor != 7) { // カスタムモード(インデックス7)でない場合
        useAdd = true;
        useSub = true;
        useMul = (ageCursor >= 3); // 小3(インデックス3)以降で掛け算解禁
        useDiv = (ageCursor >= 3); // 小3(インデックス3)以降で割り算解禁
    }
    
    if (useAdd) availableTypes.push_back(0); // たしざん
    if (useSub) availableTypes.push_back(1); // ひきざん
    if (useMul) availableTypes.push_back(2); // かけざん
    if (useDiv) availableTypes.push_back(3); // わりざん
    
    if (availableTypes.empty()) availableTypes.push_back(0);
    int type = availableTypes[(int)ofRandom(availableTypes.size())];
    
    int a = 0, b = 0, answer = 0;
    string opStr;
    
    // 桁数設定から生成用の最小・最大数値を算出 (カスタム用のデフォルト値)
    int activeMinDigits = (minDigits < 0) ? 1 : (minDigits == 0 ? 1 : minDigits);
    int currentDigitsMin = (activeMinDigits == 1) ? 0 : pow(10, activeMinDigits - 1);
    int safeMaxDigits = (maxDigits > 7) ? 7 : maxDigits;
    int currentDigitsMax = pow(10, safeMaxDigits) - 1;
    
    // テキスト初期化
    currentQuestion.text = "";
    
    // =====================================================================
    //  2. 各コース（5月末進度）に応じた厳密な数値生成ロジック
    // =====================================================================
    bool isCustom = (showCustomMode && ageCursor == 7); // カスタムモードかどうか
    
    if (!isCustom) {
        // --- ① がっこうにいくまえ コース (インデックス 0) ---
        if (ageCursor == 0) {
            type = (ofRandom(1.0) < 0.6) ? 0 : 1; // 足し算多め、引き算少なめ
            if (type == 0) { // 合計が10以下の足し算
                a = (int)ofRandom(1, 10);
                b = (int)ofRandom(1, 11 - a); // 答えが絶対に10以下
                answer = a + b;
                opStr = "+";
            } else { // 1桁同士の引き算（答えは1以上）
                a = (int)ofRandom(2, 11);
                b = (int)ofRandom(1, a);      // 負の数・0はなし
                answer = a - b;
                opStr = "-";
            }
            currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
        }
        // --- ② しょうがく1ねんせい コース (インデックス 1) ---
        else if (ageCursor == 1) {
            type = (ofRandom(1.0) < 0.5) ? 0 : 1;
            if (ofRandom(1.0) < 0.15) { // 3つの数の計算（15%の確率）
                int n1 = (int)ofRandom(1, 5);
                int n2 = (int)ofRandom(1, 5);
                if (type == 0) { // たし算＋たし算 (合計10以下)
                    int n3 = (int)ofRandom(1, 11 - (n1 + n2));
                    a = n1 + n2; b = n3; answer = n1 + n2 + n3;
                    currentQuestion.text = ofToString(n1) + " + " + ofToString(n2) + " + " + ofToString(n3) + " = ?";
                    opStr = "+";
                } else { // ひき算－ひき算 (答え1以上)
                    int n1_big = (int)ofRandom(5, 11);
                    int n2_sub = (int)ofRandom(1, n1_big - 2);
                    int n3_sub = (int)ofRandom(1, n1_big - n2_sub);
                    a = n1_big - n2_sub; b = n3_sub; answer = n1_big - n2_sub - n3_sub;
                    currentQuestion.text = ofToString(n1_big) + " - " + ofToString(n2_sub) + " - " + ofToString(n3_sub) + " = ?";
                    opStr = "-";
                }
            } else { // 通常の1桁加減算 (5月末：まだ繰り上がりなしが中心)
                if (type == 0) {
                    a = (int)ofRandom(0, 11);
                    b = (int)ofRandom(0, 11 - a); // 答え10以下
                    answer = a + b;
                    opStr = "+";
                } else {
                    a = (int)ofRandom(0, 11);
                    b = (int)ofRandom(0, a + 1);  // 答え0以上、くり下がりなし
                    answer = a - b;
                    opStr = "-";
                }
                currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
            }
        }
        // --- ③ 小学2ねんせい コース (インデックス 2) ---
        else if (ageCursor == 2) {
            type = (ofRandom(1.0) < 0.5) ? 0 : 1;
            if (type == 0) { // 2桁の足し算 (5月末：繰り上がりのある筆算・暗算の基礎)
                a = (int)ofRandom(11, 20);
                b = (int)ofRandom(11, 20 - a); // 100を超えない範囲で暗算しやすく
                answer = a + b;
                opStr = "+";
            } else { // 2桁の引き算
                a = (int)ofRandom(21, 30);
                b = (int)ofRandom(1, a);
                answer = a - b;
                opStr = "-";
            }
            currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
        }
        // --- ④ 小学3年生 コース (インデックス 3) ---
        else if (ageCursor == 3) {
            // 5月末：3桁の加減算の筆算、掛け算九九の復習と簡単な割り算(九九の逆)の始まり
            if (type == 0 || type == 1) {
                a = (int)ofRandom(100, 600);
                b = (int)ofRandom(100, 399);
                if (type == 0) { answer = a + b; opStr = "+"; }
                else { if(a < b) swap(a,b); answer = a - b; opStr = "-"; }
                currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
            }
            else if (type == 2) { // かけ算九九
                a = (int)ofRandom(2, 10);
                b = (int)ofRandom(2, 10);
                answer = a * b;
                opStr = "x";
                currentQuestion.text = ofToString(a) + " x " + ofToString(b) + " = ?";
            }
            else { // 割り算（5月末：九九の逆算で解けるもの限定）
                b = (int)ofRandom(2, 10);      // わる数は 2〜9
                answer = (int)ofRandom(2, 10); // こたえも 2〜9
                a = b * answer;                // わられる数 (1桁×1桁の積になる)
                opStr = "÷";
                currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
            }
        }
        // --- ⑤ 小学4年生 コース (インデックス 4) ---
        else if (ageCursor == 4) {
            // 5月末進度：大きな数の加減算、3桁×1桁の筆算の導入、何十・何百のかけ算暗算
            if (type == 0 || type == 1) {
                a = (int)ofRandom(1000, 5000);
                b = (int)ofRandom(100, 999);
                if (type == 0) { answer = a + b; opStr = "+"; }
                else { if(a < b) swap(a,b); answer = a - b; opStr = "-"; }
            }
            else if (type == 2) { // 何十、何百をかける暗算 (例: 80 x 6, 300 x 4)
                if (ofRandom(1.0) < 0.5) {
                    a = (int)ofRandom(2, 9) * 10;
                    b = (int)ofRandom(3, 9);
                } else {
                    a = (int)ofRandom(2, 5) * 100;
                    b = (int)ofRandom(2, 5);
                }
                answer = a * b;
                opStr = "x";
            }
            else { // 2桁÷1桁の簡単な割り切れ暗算 (例: 63 ÷ 3 = 21, 84 ÷ 4 = 21)
                b = (int)ofRandom(2, 4);
                answer = (int)ofRandom(11, 33);
                a = b * answer;
                opStr = "÷";
            }
            currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
        }
        // --- ⑥ 小学高学年 コース (インデックス 5) ---
        else if (ageCursor == 5) {
            // 5月末：小数・整数の乗除の基礎、工夫して解く暗算
            if (type == 0 || type == 1) { // 3つの数の混ざった計算
                int n1 = (int)ofRandom(5, 25);
                int n2 = (int)ofRandom(2, 9);
                int n3 = (int)ofRandom(2, 6);
                if (ofRandom(1.0) < 0.5) {
                    a = n1; b = n2 * n3; answer = n1 + (n2 * n3);
                    currentQuestion.text = ofToString(n1) + " + " + ofToString(n2) + " x " + ofToString(n3) + " = ?";
                    opStr = "+";
                } else {
                    a = n1; b = n2; answer = (n1 + n2) * n3;
                    currentQuestion.text = "(" + ofToString(n1) + " + " + ofToString(n2) + ") x " + ofToString(n3) + " = ?";
                    opStr = "x";
                }
            }
            else if (type == 2) { // 2桁×1桁、または2桁×何十 (暗算可能な範囲に制限)
                if (ofRandom(1.0) < 0.5) {
                    a = (int)ofRandom(12, 45); // 456のような3桁×2桁は暗算不可のため排除
                    b = (int)ofRandom(3, 8);
                } else {
                    a = (int)ofRandom(11, 35);
                    b = (int)ofRandom(1, 4) * 10; // 20や30をかける
                }
                answer = a * b;
                opStr = "x";
                currentQuestion.text = ofToString(a) + " x " + ofToString(b) + " = ?";
            }
            else { // 何百何十÷何十、またはシンプルな2桁÷2桁
                if (ofRandom(1.0) < 0.5) {
                    answer = (int)ofRandom(3, 9);
                    b = (int)ofRandom(2, 9) * 10; // 20〜90
                    a = answer * b;              // 例: 240 ÷ 30
                } else {
                    b = (ofRandom(1.0) < 0.5) ? (int)ofRandom(11, 15) : 25;
                    answer = (int)ofRandom(3, 6);
                    a = b * answer;              // 例: 75 ÷ 25
                }
                opStr = "÷";
                currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
            }
        }
        // --- ⑦ 中学生以上 コース (インデックス 6) ---
        else if (ageCursor == 6) {
            auto randomSign = []() { return (ofRandom(1.0) < 0.5) ? 1 : -1; };
            
            if (type == 0 || type == 1) {
                a = (int)ofRandom(100, 5000) * randomSign();
                b = (int)ofRandom(100, 4000) * randomSign();
                
                if (type == 0) {
                    answer = a + b;
                    opStr = "+";
                    if (b < 0) currentQuestion.text = ofToString(a) + " + (" + ofToString(b) + ") = ?";
                    else currentQuestion.text = ofToString(a) + " + " + ofToString(b) + " = ?";
                } else {
                    answer = a - b;
                    opStr = "-";
                    if (b < 0) currentQuestion.text = ofToString(a) + " - (" + ofToString(b) + ") = ?";
                    else currentQuestion.text = ofToString(a) + " - " + ofToString(b) + " = ?";
                }
            }
            else if (type == 2) {
                if (ofRandom(1.0) < 0.6) {
                    a = (int)ofRandom(11, 80) * randomSign();
                    b = (int)ofRandom(3, 25) * randomSign();
                } else {
                    a = (int)ofRandom(100, 400) * randomSign();
                    b = (int)ofRandom(2, 9) * randomSign();
                }
                answer = a * b;
                opStr = "x";
                
                string bStr = (b < 0) ? "(" + ofToString(b) + ")" : ofToString(b);
                currentQuestion.text = ofToString(a) + " x " + bStr + " = ?";
            }
            else {
                int b_tmp = (int)ofRandom(6, 35) * randomSign();
                int ans_tmp = (int)ofRandom(5, 40) * randomSign();
                if (b_tmp == 0) b_tmp = 7;
                
                a = b_tmp * ans_tmp;
                b = b_tmp;
                answer = ans_tmp;
                opStr = "÷";
                
                string bStr = (b < 0) ? "(" + ofToString(b) + ")" : ofToString(b);
                currentQuestion.text = ofToString(a) + " ÷ " + bStr + " = ?";
            }
            
            if (ofRandom(1.0) < 0.25) {
                int n3 = (int)ofRandom(3, 12) * randomSign();
                int prev_ans = answer;
                
                if (ofRandom(1.0) < 0.5) {
                    answer = prev_ans * n3;
                    string n3Str = (n3 < 0) ? "(" + ofToString(n3) + ")" : ofToString(n3);
                    
                    string baseExp = currentQuestion.text;
                    size_t pos = baseExp.find(" = ?");
                    if (pos != string::npos) baseExp = baseExp.substr(0, pos);
                    
                    currentQuestion.text = "(" + baseExp + ") x " + n3Str + " = ?";
                    opStr = "x";
                } else {
                    answer = n3 + prev_ans;
                    string baseExp = currentQuestion.text;
                    size_t pos = baseExp.find(" = ?");
                    if (pos != string::npos) baseExp = baseExp.substr(0, pos);
                    
                    currentQuestion.text = ofToString(n3) + " + (" + baseExp + ") = ?";
                    opStr = "+";
                }
            }
        }
    }
    
    // --- 3. カスタムモード用ロジックの判定を厳密に ---
    if (currentQuestion.text.empty()) {
        if (type == 0) { // 【足し算】
            a = (int)ofRandom(currentDigitsMin, currentDigitsMax + 1);
            b = (int)ofRandom(currentDigitsMin, currentDigitsMax + 1);
            answer = a + b;
            opStr = "+";
        }
        else if (type == 1) { // 【引き算】
            a = (int)ofRandom(currentDigitsMin, currentDigitsMax + 1);
            if (minDigits == 0) b = a;
            else if (minDigits < 0) b = (int)ofRandom(currentDigitsMin, currentDigitsMax + 1);
            else b = (int)ofRandom(currentDigitsMin, a + 1);
            answer = a - b;
            opStr = "-";
        }
        else if (type == 2) { // 【掛け算】
            int a_max = 9, b_max = 9;
            if (mulLimitMode == CL_KUKU || mulLimitMode == CL_STAGE56) {
                a = (int)ofRandom(2, 10); b = (int)ofRandom(2, 10);
            } else {
                a_max = maxNumLimit; b_max = (maxNumLimit > 50) ? 20 : 9;
                a = (int)ofRandom(2, a_max + 1);
                if (a >= 10 && ofRandom(1.0) < 0.5) {
                    int step = (int)ofRandom(1, (b_max / 10) + 1);
                    b = (step * 10 > 0) ? step * 10 : 10;
                } else b = (int)ofRandom(2, b_max + 1);
            }
            if (ofRandom(1.0) < 0.5) swap(a, b);
            answer = a * b;
            opStr = "x";
        }
        else { // 【割り算】
            int b_tmp = 2, ans_tmp = 2;
            if (divLimitMode == CL_KUKU) { b_tmp = (int)ofRandom(2, 10); ans_tmp = (int)ofRandom(2, 10); }
            else if (divLimitMode == CL_STAGE56) {
                if (ofRandom(1.0) < 0.5) { b_tmp = (int)ofRandom(10, 25); ans_tmp = (int)ofRandom(2, 5); }
                else { b_tmp = (int)ofRandom(2, 10); ans_tmp = (int)ofRandom(2, 12); }
                if (b_tmp * ans_tmp > 100) { b_tmp = 9; ans_tmp = 9; }
            } else {
                if (maxNumLimit <= 20) { b_tmp = (int)ofRandom(2, 10); ans_tmp = (int)ofRandom(2, maxNumLimit + 1); }
                else {
                    if (ofRandom(1.0) < 0.6) { b_tmp = (int)ofRandom(1, 10) * 10; ans_tmp = (int)ofRandom(2, 10); }
                    else { b_tmp = (int)ofRandom(3, 10); ans_tmp = (int)ofRandom(10, 31); }
                }
            }
            a = b_tmp * ans_tmp; b = b_tmp; answer = ans_tmp;
            opStr = "÷";
        }
        currentQuestion.text = ofToString(a) + " " + opStr + " " + ofToString(b) + " = ?";
    }
    
    // --- 4. 正解の配置とダミー生成 ---
    std::set<int> usedNumbers;
    usedNumbers.insert(answer);
    correctIdx = (int)ofRandom(0, 4);
    
    for (int i = 0; i < 4; i++) {
        if (i == correctIdx) {
            currentQuestion.choices[i] = ofToString(answer);
        } else {
            int dummy;
            int safetyCounter = 0;
            while (true) {
                safetyCounter++;
                int range = (abs(answer) < 10) ? 4 : (abs(answer) / 5 + 2);
                
                if (ageCursor == 6 && range < 30) {
                    range = 30;
                }
                
                dummy = answer + (int)ofRandom(-range, range + 1);
                if (safetyCounter > 50) dummy += (int)ofRandom(-20, 21);
                
                // 幼児・小1コース(0, 1)では、ダミー選択肢に「マイナス」が出ないようにガード
                if ((ageCursor == 0 || ageCursor == 1) && dummy < 0) {
                    dummy = (int)ofRandom(0, 11);
                }
                
                if (dummy >= -99999 && usedNumbers.find(dummy) == usedNumbers.end()) {
                    break;
                }
                if (safetyCounter > 100) {
                    dummy = answer + 100 + i;
                    break;
                }
            }
            currentQuestion.choices[i] = ofToString(dummy);
            usedNumbers.insert(dummy);
        }
    }
    
    // =======================================================
    // 5. 知育ヒント生成システム (定義位置を最上部に修正)
    // =======================================================
    quizHintGraph = "";
    quizHintText = "";
    
    // ---【重要】すべてのブロックで安全に使うため、関数の一番上で定義 ---
    vector<long long> extractedNumbers;
    string tempNumStr = "";
    for (size_t i = 0; i < currentQuestion.text.length(); i++) {
        char ch = currentQuestion.text[i];
        if (isdigit(ch)) {
            tempNumStr += ch;
        } else {
            if (!tempNumStr.empty()) {
                size_t signPos = i - tempNumStr.length() - 1;
                if (i >= tempNumStr.length() + 1 && currentQuestion.text[signPos] == '-') {
                    if (signPos == 0 || currentQuestion.text[signPos - 1] == '(') {
                        tempNumStr = "-" + tempNumStr;
                    }
                }
                extractedNumbers.push_back(stoll(tempNumStr));
                tempNumStr = "";
            }
        }
    }
    if (!tempNumStr.empty()) extractedNumbers.push_back(stoll(tempNumStr));
    
    // --- 【1】 3項以上の複雑な問題かどうかの厳密な判定 ---
    bool isComplexQuestion = false;
    int opCount = 0;
    
    if (currentQuestion.text.find('+') != string::npos) opCount++;
    if (currentQuestion.text.find("x") != string::npos) opCount++;
    if (currentQuestion.text.find("÷") != string::npos) opCount++;
    
    size_t mPos = currentQuestion.text.find('-');
    while (mPos != string::npos) {
        if (mPos > 0) {
            // 直前の1文字を取得
            char prevChar = currentQuestion.text[mPos - 1];
            
            // "÷" はマルチバイトなので、文字単体での比較ではなく、文字列全体の直前の位置に "÷" がないか
            bool isAfterOp = (prevChar == '(' || prevChar == 'x' || prevChar == '+');
            if (mPos >= 2 && currentQuestion.text.substr(mPos - 2, 2) == "÷") {
                isAfterOp = true;
            }
            
            // 演算子やカッコの直後のマイナスでなければ、それは「引き算のマイナス」なのでカウント
            if (!isAfterOp) {
                opCount++;
            }
        }
        mPos = currentQuestion.text.find('-', mPos + 1);
    }
    
    size_t openParen = currentQuestion.text.find('(');
    size_t closeParen = currentQuestion.text.find(')');
    
    if (openParen != string::npos && closeParen != string::npos) {
        string insideParen = currentQuestion.text.substr(openParen + 1, closeParen - openParen - 1);
        size_t opInParen = insideParen.find_first_of("+x÷");
        size_t minusInParen = insideParen.find('-', (insideParen[0] == '-') ? 1 : 0);
        if (opInParen != string::npos || minusInParen != string::npos) {
            isComplexQuestion = true;
        }
    }
    if (opCount >= 2) {
        isComplexQuestion = true;
    }
    
    // --- 【2】 条件に応じたヒント生成 ---
    if (isComplexQuestion) {
        // --- 【3項以上の計算】 ---
        if (extractedNumbers.size() < 3) {
            quizHintGraph = currentQuestion.text;
            quizHintText = "[ヒント]\nカッコの なかや,「x」「÷」の\n計算から さきに やってみよう！";
        }
        else {
            long long n1 = extractedNumbers[0];
            long long n2 = extractedNumbers[1];
            long long n3 = extractedNumbers[2];
            
            size_t firstOpen = currentQuestion.text.find('(');
            size_t lastClose = currentQuestion.text.rfind(')');
            
            bool hasRealParen = false;
            if (firstOpen != string::npos && lastClose != string::npos && firstOpen < lastClose) {
                string pStr = currentQuestion.text.substr(firstOpen + 1, lastClose - firstOpen - 1);
                if (pStr.find('+') != string::npos || pStr.find('x') != string::npos || pStr.find("÷") != string::npos || pStr.find('-', 1) != string::npos) {
                    hasRealParen = true;
                }
            }
            
            if (hasRealParen) {
                string insideParen = currentQuestion.text.substr(firstOpen + 1, lastClose - firstOpen - 1);
                
                long long pA = 0;
                long long pB = 0;
                long long remainingNum = 0;
                string nextFormula = "";
                long long answerPart1 = 0;
                string opSymbol = "";
                
                // カッコが式の先頭にあるか、後ろにあるかで数値のインデックスを正しく分ける
                if (firstOpen == 0) {
                    // パターンA: (112 ÷ 5) x 3 のように先頭にカッコがある場合
                    pA = extractedNumbers[0];
                    pB = extractedNumbers[1];
                    remainingNum = extractedNumbers[2];
                    
                    // カッコ内の計算
                    if (insideParen.find('x') != string::npos) { answerPart1 = pA * pB; opSymbol = " x "; }
                    else if (insideParen.find("÷") != string::npos && pB != 0) { answerPart1 = pA / pB; opSymbol = " ÷ "; }
                    else if (insideParen.find('+') != string::npos) { answerPart1 = pA + pB; opSymbol = " + "; }
                    else { answerPart1 = pA - pB; opSymbol = " - "; }
                    
                    // カッコの後ろにある演算子を探す
                    string afterParen = currentQuestion.text.substr(lastClose + 1);
                    string outerOp = " x "; // デフォルト
                    if (afterParen.find('+') != string::npos) outerOp = " + ";
                    else if (afterParen.find('-') != string::npos) outerOp = " - ";
                    else if (afterParen.find("÷") != string::npos) outerOp = " ÷ ";
                    
                    // 次の式は「カッコの計算結果 ＋/ー/×/÷ 残りの数」
                    nextFormula = ofToString(answerPart1) + outerOp + ofToString(remainingNum);
                }
                else {
                    // パターンB: -10 + (49 * (-17)) のように後ろにカッコがある場合
                    pA = extractedNumbers[1];
                    pB = extractedNumbers[2];
                    remainingNum = extractedNumbers[0];
                    
                    if (insideParen.find('x') != string::npos) { answerPart1 = pA * pB; opSymbol = " x "; }
                    else if (insideParen.find("÷") != string::npos && pB != 0) { answerPart1 = pA / pB; opSymbol = " ÷ "; }
                    else if (insideParen.find('+') != string::npos) { answerPart1 = pA + pB; opSymbol = " + "; }
                    else { answerPart1 = pA - pB; opSymbol = " - "; }
                    
                    // 次の式を綺麗に組み立てる
                    nextFormula = ofToString(remainingNum) + " + (" + ofToString(answerPart1) + ")";
                    if (currentQuestion.text.find('-') != string::npos && currentQuestion.text.find('-') < firstOpen) {
                        nextFormula = ofToString(remainingNum) + " - (" + ofToString(answerPart1) + ")";
                    }
                    if (currentQuestion.text[0] == '-') {
                        nextFormula = "-" + ofToString(abs(remainingNum)) + " + (" + ofToString(answerPart1) + ")";
                    }
                }
                
                quizHintGraph = currentQuestion.text + "\n\n"
                + "[① まずはカッコの中を計算しよう！]\n"
                + "  " + ofToString(pA) + opSymbol + ofToString(pB) + " = " + ofToString(answerPart1) + "\n\n"
                + "[② つぎの計算はこれになるよ！]\n"
                + "  " + nextFormula;
                quizHintText = "[ヒント]\nまずは「（　）」のなかの計算をすませよう！\n"
                "計算すると「" + ofToString(answerPart1) + "」になるよ。\n"
                "最後は、" + nextFormula + " を計算しよう！";
            }
        }
    }
    else if (type == 0 || currentQuestion.text.find("- (-") != string::npos || currentQuestion.text.find("-(-") != string::npos) {
        // --- 【2項 たしざん】 ---
        if (currentQuestion.text.find("- (-") != string::npos || currentQuestion.text.find("-(-") != string::npos) {
            quizHintGraph = ofToString(abs(a)) + " + " + ofToString(abs(b)) + " = ?";
            quizHintText = "[重要なヒント]\n「マイナスを ひく」ということは、\n「プラス（たし算）」に変身するよ！\nまずは符号を直して,普通の\nたし算にしよう！";
        }
        else if (a < 0 && b < 0) {
            quizHintGraph = "-(" + ofToString(abs(a)) + " + " + ofToString(abs(b)) + ") = ?";
            quizHintText = "[ヒント]\nどちらも マイナス（-）の数だね！\nこれはマイナス（借金）がどんどん増えるイメージだよ。\n"
            "数字の大きさを合計して、頭に「-」をつけよう！\n計算： " + ofToString(abs(a)) + " + " + ofToString(abs(b));
        }
        else if (a < 0 || b < 0) {
            long long valA = extractedNumbers.size() >= 2 ? extractedNumbers[0] : abs(a);
            long long valB = extractedNumbers.size() >= 2 ? extractedNumbers[1] : abs(b);
            bool isFirstNegative = (currentQuestion.text[0] == '-');
            quizHintGraph = currentQuestion.text;
            string hint = "[ヒント]\nマイナスとプラスが合体する計算だね。\n";
            if (valA > valB) {
                hint += isFirstNegative ? "マイナスのほうが数字が大きい\nから,答えは「マイナス」になるよ。\n" : "プラスのほうが数字が大きい\nから、答えは「プラス」になるよ。\n";
                hint += "計算は、" + ofToString(valA) + " - " + ofToString(valB) + " をしよう！";
            } else {
                hint += isFirstNegative ? "プラスのほうが数字が大きいから、答えは「プラス」になるよ。\n" : "マイなスのほうが数字が大きいから、答えは「マイナス」になるよ。\n";
                hint += "計算は, " + ofToString(valB) + " - " + ofToString(valA) + " をしよう！";
            }
            quizHintText = hint;
        }
        else {
            //【ここに記述】1〜10 の範囲なら「o」の図解を出す
            if (a >= 1 && a <= 10 && b >= 1 && b <= 10 && (a + b) <= 10) {
                string graph = "[図解ヒント]\n";
                graph += "【 " + ofToString(a) + " 】 のまる：\n";
                for (int i = 0; i < a; i++) {
                    graph += "o ";
                }
                graph += "\n\n";
                
                graph += "+\n【 " + ofToString(b) + " 】 のまる：\n";
                for (int i = 0; i < b; i++) {
                    graph += "o ";
                }
                graph += "\n";
                
                quizHintGraph = graph;
                quizHintText = "[ヒント]\nまるの かずを\nぜんぶ あわせて かぞえてみよう！";
            }
            else {
                // 10を超える場合は筆算を表示
                string strA = ofToString(a);
                string strB = ofToString(b);
                int lenA = strA.length();
                int lenB = strB.length();
                int maxLen = max(lenA, lenB);
                
                string visualA = (lenA < maxLen) ? string(maxLen - lenA, ' ') + strA : strA;
                string visualB = (lenB < maxLen) ? string(maxLen - lenB, ' ') + strB : strB;
                
                quizHintGraph = "  " + visualA + "\n+) " + visualB;
                quizHintText = "[ヒント]\n1の位から順番に、\nたてにそろえて筆算(ひっさん)で\n計算してみよう！\n(右側の一の位がまっすぐそろうよ)";
            }
        }
    }
    else if (type == 1) { // --- 【2項 ひきざん】 ---
        if (a < 0 && b > 0) {
            quizHintGraph = "-(" + ofToString(abs(a)) + " + " + ofToString(b) + ") = ?";
            quizHintText = "[ヒント]\nマイナス(借金)がある状態から\nさらに引き算(引き出す)をするよ。\n数字を合計して、頭に「-」をつけよう!\n計算： " + ofToString(abs(a)) + " + " + ofToString(b);
        }
        else if (answer < 0) {
            quizHintGraph = "-(" + ofToString(b) + " - " + ofToString(a) + ") = ?";
            quizHintText = "[ヒント]\nひく数のほうが大きいから、\n答えは「マイナス」になるよ！\n大きな数から小さな数を引いて,\n頭に「-」をつけよう！\n計算： " + ofToString(b) + " - " + ofToString(a);
        }
        else {
            //【ここに記述】1〜10 の範囲なら「o」が「x」に変わる図解を出す
            if (a >= 1 && a <= 10 && b >= 1 && b <= 10 && a >= b) {
                string graph = "[図解ヒント]\n";
                graph += "ぜんぶの " + ofToString(a) + " 個から " + ofToString(b) + " 個ひくよ\n";
                graph += "（ x のぶんを ひき算しよう）\n\n";
                
                for (int i = 0; i < a; i++) {
                    if (i < b) {
                        graph += "x "; // 引く分を「x」でマスク
                    } else {
                        graph += "o "; // 残る分を「o」で表示
                    }
                }
                graph += "\n";
                
                quizHintGraph = graph;
                quizHintText = "[ヒント]\n全部で " + ofToString(a) + " 個あった まるから、\n" + ofToString(b) + " 個を「x」にしたよ。\nのこった「o」の数を かぞえてみよう！";
            }
            else {
                // 10を超える場合は筆算を表示
                string strA = ofToString(a);
                string strB = ofToString(b);
                int lenA = strA.length();
                int lenB = strB.length();
                int maxLen = max(lenA, lenB);
                string visualA = (lenA < maxLen) ? string(maxLen - lenA, ' ') + strA : strA;
                string visualB = (lenB < maxLen) ? string(maxLen - lenB, ' ') + strB : strB;
                
                quizHintGraph = "  " + visualA + "\n-) " + visualB;
                quizHintText = "[ヒント]\nたてに位をそろえて,\n右の一の位から引き算しよう！";
            }
        }
    }
    else if (type == 2) { // --- 【2項 かけざん】 ---
        if (currentQuestion.text.find('-') != string::npos) {
            quizHintGraph = currentQuestion.text;
            quizHintText = "[ヒント]\nマイナス(-) と プラス(+) の数を\nかけると,\n答えはぜったいに「マイナス(-)」になるよ!\n\n符号を決めたら,\nあとは落ち着いて普通の\n掛け算をしよう！";
        }
        else if (a <= 9 && b <= 9 && a >= 0 && b >= 0) {
            string graph = "";
            for (int i = 0; i < b; i++) {
                for (int j = 0; j < a; j++) graph += "o ";
                graph += "\n";
            }
            quizHintGraph = graph;
            quizHintText = "[図解ヒント]\n" + ofToString(a) + "こずつの まとまりが\n" + ofToString(b) + "グループ あるよ!";
        }
        else if ((a % 10 == 0 && a <= 90) || (a % 100 == 0 && a <= 400)) {
            quizHintGraph = ofToString(a) + " x " + ofToString(b) + " = ?";
            quizHintText = "[ヒント]\n「0」を いったん かくして、\n九九（くく）で かんがえてみよう！\n計算したあと、かくした「0」をうしろにつけよう！";
        }
        else {
            quizHintGraph = ofToString(a) + " x " + ofToString(b);
            quizHintText = "[ヒント]\n大きな数は、「10のまとまり」に\nわけて かけ算してみよう！\n(例: 24 x 4 なら 20x4 と 4x4 をたす)";
        }
    }
    else { // --- 【2項 わりざん】 ---
        if (extractedNumbers.size() >= 2 && extractedNumbers[0] >= 100 && extractedNumbers[1] >= 10) {
            long long dividend = extractedNumbers[0];
            long long divisor = extractedNumbers[1];
            
            long long top2Digits = dividend / 10;
            long long firstQuotient = top2Digits / divisor;
            long long firstRemainder = top2Digits % divisor;
            long long nextStepDividend = (firstRemainder * 10) + (dividend % 10);
            
            quizHintGraph = currentQuestion.text + "\n\n"
            + "[筆算のステップ]\n"
            + "1: まず上の2桁を見るよ： " + ofToString(top2Digits) + " ÷ " + ofToString(divisor) + "\n"
            + "   → 「" + ofToString(firstQuotient) + "」がたって、あまりは 「" + ofToString(firstRemainder) + "」\n\n"
            + "2: あまりの" + ofToString(firstRemainder) + "を10の位にして、残りの" + ofToString(dividend % 10) + "と合体！\n"
            + "   → つぎは 「" + ofToString(nextStepDividend) + " ÷ " + ofToString(divisor) + "」 を計算しよう！";
            
            quizHintText = "[ヒント]\n大きな割り算は、上の位から順番に崩していこう！\n"
            "まずは " + ofToString(top2Digits) + "÷" + ofToString(divisor) + " をすると、あまりが「" + ofToString(firstRemainder) + "」でるよ。\n"
            "次は、そのあまりと一の位をあわせた「" + ofToString(nextStepDividend) + "÷" + ofToString(divisor) + "」を解けばゴールだよ！";
        }
        else if (a <= 81 && b <= 9 && answer <= 9 && a >= 0 && b >= 0) {
            quizHintGraph = "[" + ofToString(b) + " x ? = " + ofToString(a) + "]";
            quizHintText = "[ヒント]\nかけざん九九の ぎゃくだよ!\n\n? にあてはまる数を\nさがそう!";
        }
        else if (a % 10 == 0 && b % 10 == 0 && b > 0) {
            quizHintGraph = ofToString(a) + " ÷ " + ofToString(b) + " = ?";
            quizHintText = "[ヒント]\nうしろの「0」をかくして\n九九で かんがえてみよう!\n(例: 240 ÷ 30 は 24 ÷ 3 とおなじ！)";
        }
        else {
            quizHintGraph = ofToString(a) + " ÷ " + ofToString(b) + " = ?";
            quizHintText = "[ヒント]\nわられる数を「ひっさん(筆算)」のように\n上の位から じゅんばんに\nわる数でわっていこう！";
        }
    }
}

//----------------------------------------------
void ofApp::drawColorButton(float x, float y, string label, ofColor color, string choiceText) {
    float btnSize = 50; // ボタンを少し大きく
    
    // 1. ボタン背景
    ofSetColor(color);
    ofDrawRectRounded(x, y, btnSize, btnSize, 8);
    
    // 2. ボタンの中の文字 (A, B, C, D)
    ofSetColor(0);
    float tw = myFont.stringWidth(label);
    float th = myFont.stringHeight(label);
    // TrueTypeFontはベースライン基準なので、高さの半分を足して中央に寄せる
    myFont.drawString(label, x + (btnSize - tw) / 2, y + (btnSize + th) / 2);
    
    ofSetColor(255);
    // 3. ボタンの横の選択肢テキスト (数値や計算結果)
    // ボタンの右側（+70）に少しずらして描画
    bigFont.drawString(choiceText, x + btnSize + 15, y + (btnSize + th) / 2);
}
//---------------------------------------------

void ofApp::drawTitleChip(int gridX, int gridY, int chipIdx) {
    ofSetColor(255);
    mapchip[chipIdx].draw(gridX * currentTilesize, gridY * currentTilesize, currentTilesize, currentTilesize);
}

//---------------------------------------------
void ofApp::updateArrows() {
    // 1. COMへの角度（自分から見たCOMの方向）
    float diffComX = myCom.x - myPlayer.x;
    float diffComY = myCom.y - myPlayer.y;
    if (diffComX != 0 || diffComY != 0) {
        comArrowAngle = ofRadToDeg(atan2(diffComY, diffComX)) - 90.0;
    }

    // 2. ゴールへの角度（自分から見たゴールの方向）
    float diffGoalX = GoalX - myPlayer.x;
    float diffGoalY = GoalY - myPlayer.y;
    if (diffGoalX != 0 || diffGoalY != 0) {
        goalArrowAngle = ofRadToDeg(atan2(diffGoalY, diffGoalX)) - 90.0;
    }
}

//---------------------------------------------
void ofApp::drawArrows(int startX, int endX, int startY, int endY) {
    if (isCountingDown) return;

    ofPushStyle();
    
    // =================================================================
    // サイズ・レイアウト調整用の変数
    // =================================================================
    int frameW = 32;
    int frameH = 32;
    
    float arrowScale = 2.0f; // 矢印の拡大倍率
    float faceScale  = 1.8f; // COMの顔の拡大倍率
    float margin = 48.0f;    // 画面端からの隙間

    // 表示タイミングのマージン（0.0f で画面外に消えたら即表示）
    float detectionMargin = 0.0f;
    // =================================================================
    
    // アニメーションのコマ計算
    int currentFrame = (ofGetFrameNum() / 15) % 3;
    int srcX = currentFrame * frameW;
    int srcY = 0;

    // 画面の中心座標（スクリーン座標系）
    float screenCenterX = ofGetWidth() / 2.0f;
    float screenCenterY = ofGetHeight() / 2.0f;

    // 画面中央から見て、矢印を固定したい「画面の壁」までの距離
    float borderX = screenCenterX - margin;
    float borderY = screenCenterY - margin;

    // 1. COMへの矢印
    if (comArrowSheet.isAllocated()) {
        // Yの計算が合っていた基準（マス目の差分ベクトル）をそのまま利用
        float diffX = (myCom.x - myPlayer.x) * currentTilesize;
        float diffY = (myCom.y - myPlayer.y) * currentTilesize;

        // 表示判定
        bool isComFarX = abs(diffX) > (screenCenterX - detectionMargin);
        bool isComFarY = abs(diffY) > (screenCenterY - detectionMargin);

        if (isComFarX || isComFarY) {
            
            float arrowX = 0;
            float arrowY = 0;

            // --- 交点計算（Xの反転・ズレを修正） ---
            if (abs(diffX) * borderY > abs(diffY) * borderX) {
                // 左右の壁にぶつかる場合
                // diffXの向き（正負）に合わせて、画面の「右端」か「左端」かを厳密に指定
                if (diffX > 0) {
                    arrowX = screenCenterX + borderX; // 右の画面端
                } else {
                    arrowX = screenCenterX - borderX; // 左の画面端
                }
                // Y座標は合っていた計算をそのまま適用
                arrowY = screenCenterY + borderX * (diffY / abs(diffX));
            } else {
                // 上下の壁にぶつかる場合
                if (diffY > 0) arrowY = screenCenterY + borderY; // 下端
                else           arrowY = screenCenterY - borderY; // 上端
                
                // 上下の壁にいるときの、X座標の引っ張られ方の向きを正しく修正
                arrowX = screenCenterX + borderY * (diffX / abs(diffY));
            }

            ofPushMatrix();
            ofTranslate(arrowX, arrowY);
            
            // A. 矢印の描画
            ofPushMatrix();
            ofRotateDeg(comArrowAngle);
            ofSetColor(0, 255, 255, 255);
            float drawW = frameW * arrowScale;
            float drawH = frameH * arrowScale;
            comArrowSheet.drawSubsection(-drawW / 2.0f, -drawH / 2.0f - (drawH / 4.0f), drawW, drawH, srcX, srcY, frameW, frameH);
            ofPopMatrix();

            // B. COMの顔の描画
            ofColor faceColor = ofColor(255, 255, 255, 255);
            if (isComFrozen)                 faceColor = ofColor(100, 200, 255, 255);
            else if (trapX == myCom.x && trapY == myCom.y) faceColor = ofColor(139, 69, 19, 255);
            else if (isComBoostMode)         faceColor = ofColor(255, 100, 100, 255);
            
            float fW = 32.0f * faceScale;
            float fH = 20.0f * faceScale;
            myCom.drawFace(0, 0, fW, fH, faceColor);
            
            ofPopMatrix();
        }
    }

    // 2. ゴールへの矢印
    if (goalArrowSheet.isAllocated()) {
        float goalDiffX = (GoalX - myPlayer.x) * currentTilesize;
        float goalDiffY = (GoalY - myPlayer.y) * currentTilesize;

        bool isGoalFarX = abs(goalDiffX) > (screenCenterX - detectionMargin);
        bool isGoalFarY = abs(goalDiffY) > (screenCenterY - detectionMargin);

        if (isGoalFarX || isGoalFarY) {

            float arrowX = 0;
            float arrowY = 0;

            // --- 交点計算（Xの反転・ズレを修正） ---
            if (abs(goalDiffX) * borderY > abs(goalDiffY) * borderX) {
                // 左右の壁
                if (goalDiffX > 0) {
                    arrowX = screenCenterX + borderX; // 右の画面端
                } else {
                    arrowX = screenCenterX - borderX; // 左の画面端
                }
                arrowY = screenCenterY + borderX * (goalDiffY / abs(goalDiffX));
            } else {
                // 上下の壁
                if (goalDiffY > 0) arrowY = screenCenterY + borderY; // 下端
                else               arrowY = screenCenterY - borderY; // 上端
                
                arrowX = screenCenterX + borderY * (goalDiffX / abs(goalDiffY));
            }

            ofPushMatrix();
            ofTranslate(arrowX, arrowY);
            ofRotateDeg(goalArrowAngle);
            ofSetColor(255, 255, 255, 255);
            
            float gW = frameW * arrowScale;
            float gH = frameH * arrowScale;
            goalArrowSheet.drawSubsection(-gW / 2.0f, -gH / 2.0f, gW, gH, srcX, srcY, frameW, frameH);
            ofPopMatrix();
        }
    }

    ofPopStyle();
}

//---------------------------------------------
void ofApp::checkAndDrawComAlert() {
    // 1. 難易度（selectedLevel）に応じた警告マス数（しきい値）の決定
    int alertThreshold = 0;
    if (selectedLevel == 0)      alertThreshold = 20; // EASYはあと20マス
    else if (selectedLevel == 1) alertThreshold = 40; // NORMALはあと40マス
    else if (selectedLevel == 2) alertThreshold = 40; // HARDはあと40マス
    else if (selectedLevel == 4) alertThreshold = 50; // VERY HARDはあと50マス
    else return; // チュートリアル（レベル3）などは対象外

    // -----------------------------------------------------------------
    // 修正のコア：COMの残り探索ルートの要素数（＝実際の残り歩数）をダイレクトに取得
    // -----------------------------------------------------------------
    int comActualDistance = myComPathSizeCached;

    // -----------------------------------------------------------------
    // 一度アラートが発火（hasFiredLevelAlert == true）したら、
    // ステージが切り替わるまで二度と音の再生やアニメーションの再スタートをしないガード
    // -----------------------------------------------------------------
    if (comActualDistance <= alertThreshold && comActualDistance > 0 && !isCountingDown) {
        if (!isComNearGoalAlert && !hasFiredLevelAlert) {
            isComNearGoalAlert = true;
            hasFiredLevelAlert = true; // このステージ中、一回だけ流すためのロックをかける
            alertTextX = ofGetWidth(); // 画面右端にセット
            
            // 警告音（seAlert）を1回だけ再生
            if (!hasPlayedAlertSound) {
                seAlert.play();
                hasPlayedAlertSound = true;
            }
        }
    }

    // 2. アラート状態の時の描画＆アニメーション処理（右から左へ流す）
    if (isComNearGoalAlert) {
        ofPushStyle();

        // --- レイアウト設定 ---
        float boxHeight = 60.0f;                       // 背景の黒帯の高さ
        float boxY = ofGetHeight() * 0.35f;            // 画面中央より少し上の位置
        string alertText = "あいてが もうすぐ ゴール!"; // ひらがなメッセージ

        // 文字の横幅（流れる終点の判定用）
        float textWidth = alertText.length() * 24;

        // -------------------------------------------------------------
        // A. 後ろの薄い色の四角（背景の座布団）を描画
        // -------------------------------------------------------------
        ofSetColor(0, 0, 0, 120); // 黒の半透明
        ofFill();
        ofDrawRectangle(0, boxY - (boxHeight / 2.0f), ofGetWidth(), boxHeight);

        // -------------------------------------------------------------
        // B. 流れるテキストの描画
        // -------------------------------------------------------------
        ofSetColor(255, 100, 100, 255); // 警告の薄い赤
        
        // フォント変数「myFont」で描画
        myFont.drawString(alertText, alertTextX, boxY + 12);

        ofPopStyle();

        // -------------------------------------------------------------
        // C. アニメーションの移動処理
        // -------------------------------------------------------------
        alertTextX -= 5.0f; // テロップが左へ流れる速度

        // 文字が画面の左外端に完全に消え去ったら、アニメーションの「描画」だけを終了
        if (alertTextX < -textWidth) {
            isComNearGoalAlert = false;
        }
    }
}

//---------------------------------------------
void ofApp::activateDash() {
    if (isDashing) return; // すでにダッシュ中なら無視

    dashDx = 0; dashDy = 0;
    if (myPlayer.dir == 0) dashDy = 1;      // 下
    else if (myPlayer.dir == 1) dashDx = -1; // 左
    else if (myPlayer.dir == 2) dashDx = 1;  // 右
    else if (myPlayer.dir == 3) dashDy = -1; // 上

    isDashing = true;
    lastDashTime = ofGetElapsedTimeMillis();
}

//-----------------------------------------------
void ofApp::activateFreeze() {
    isComFrozen = true;
    skillTimer = ofGetElapsedTimeMillis();
    currentSkillDuration = freezeDuration;
    seFrozen.play();
}

//------------------------------------------------
void ofApp::activateTrap() {
    // 安全のため、ここでも足元チェックをして、既にあるなら何もしない
    for (const auto& trap : activeTraps) {
        if (trap.x == myPlayer.x && trap.y == myPlayer.y) {
            return;
        }
    }
    
    int unactivatedCount = 0;
    int oldestUnactivatedIndex = -1;

    // まだ作動していないトラップの数と、一番古いトラップの位置を探す
    for (int i = 0; i < activeTraps.size(); i++) {
        if (!activeTraps[i].isActivated) {
            unactivatedCount++;
            if (oldestUnactivatedIndex == -1) {
                oldestUnactivatedIndex = i; // 最初に見つかったものが一番古い
            }
        }
    }

    //【仕様変更】もし作動していない罠がすでに3つあるなら、一番古いやつを1つ消す
    if (unactivatedCount >= MAX_TRAPS && oldestUnactivatedIndex != -1) {
        activeTraps.erase(activeTraps.begin() + oldestUnactivatedIndex);
    }

    // 新しいトラップをプレイヤーの足元に設置
    ActiveTrap newTrap;
    newTrap.x = myPlayer.x;
    newTrap.y = myPlayer.y;
    newTrap.isActivated = false;
    newTrap.timer = 0;
    newTrap.duration = 0;

    activeTraps.push_back(newTrap);
    
    // 設置音
    seTrapset.play();
}

//-------------------------------------------------
void ofApp::QuizIncorrect() {
    float r = ofRandom(1.0);

    if (r < 0.4) {
        reservedPenalty = P_STUN; // スタンを予約
        resultMessage += "\nペナルティ : シビれて 動けない!";
    }
    else if (r < 0.8) {
        // パターンB: エンカウント加速
        reservedPenalty = P_ENCOUNTER; // 加速を予約
        resultMessage += "\nペナルティ : つぎのクイズが すぐくる!";
    }
    else {
        reservedPenalty = P_NONE;
        resultMessage += "\nラッキー! なにもおきなかった。";
    }
}

//-----------------------------------------
string ofApp::getTimeString(float time) {
    int minutes = (int)time / 60;
    int seconds = (int)fmod(time, 60.0);
    int millis  = (int)((time - floor(time)) * 100); // 小数点以下2桁分を取り出す

    return ofToString(minutes, 2, '0') + ":"
        + ofToString(seconds, 2, '0') + "."
        + ofToString(millis, 2, '0');
}

//------------------------------------------
string ofApp::getAccuracyString() {
    if (totalQuestions == 0) return "0%";
    
    // 正答率 = (正解数 / 出題数) * 100
    float accuracy = ((float)correctAnswers / (float)totalQuestions) * 100.0;
    
    // 小数点第1位まで表示
    return ofToString(accuracy, 1) + "%";
}

//--------------------------------------------
int ofApp::getPlayerPathLength(int startX, int startY, int gX, int gY) {
    if (startX == gX && startY == gY) return 0;
    
    int currentW = gridW;
    int currentH = gridH;
    if (selectedLevel == 1) { currentW = 15; currentH = 15; }
    else if (selectedLevel == 2) { currentW = 21; currentH = 21; }
    else if (selectedLevel == 3) { currentW = 31; currentH = 31; }
    else if (selectedLevel == 4) { currentW = 160; currentH = 160; }
    
    // EXモードでも一瞬で終わるように探索上限を設定（これで十分な経路長が測れます）
    int maxNodes = 300;
    
    auto getH = [](int x, int y, int gx, int gy) {
        return abs(x - gx) + abs(y - gy);
    };
    
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    // 静的（static）な1次元配列を使い、メモリ確保を最初の一回だけにする
    // 160*160 = 25600 以上の固定サイズを用意（動的確保を無くして劇的に高速化）
    static bool visitedStatic[165][165];
    // 配列の初期化（memsetはvectorの初期化より圧倒的に高速です）
    memset(visitedStatic, 0, sizeof(visitedStatic));
    
    pq.push({startX, startY, 0, getH(startX, startY, gX, gY)});
    visitedStatic[startX][startY] = true; // スタート地点を訪問済みに
    
    int nodesCount = 0;
    int bestG = 0;
    int minH = getH(startX, startY, gX, gY);
    
    int dirX[] = {0, 0, -1, 1};
    int dirY[] = {-1, 1, 0, 0};
    
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        
        if (current.x == gX && current.y == gY) {
            return current.g; // ゴール到達
        }
        
        nodesCount++;
        if (nodesCount > maxNodes) {
            break;
        }
        
        if (current.h < minH) {
            minH = current.h;
            bestG = current.g;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dirX[i];
            int ny = current.y + dirY[i];
            
            if (nx >= 0 && nx < currentW && ny >= 0 && ny < currentH) {
                // 壁（1）ではなく、まだ訪問していないマスだけを探索
                if (mapData[nx][ny] != 1 && !visitedStatic[nx][ny]) {
                    // ココで訪問済みにする（重複登録を防いで超軽量化）
                    visitedStatic[nx][ny] = true;
                    int nextG = current.g + 1;
                    pq.push({nx, ny, nextG, getH(nx, ny, gX, gY)});
                }
            }
        }
    }
    
    // ゴールに届かなかった場合は、実際の迂回コストを大雑把にシミュレートした値を返す
    return bestG + minH;
}

//---------------------------------------------
void ofApp::calculateDistanceMap() {
    // マップ全体を「9999(到達不能)」で初期化
    distanceMap.assign(gridW, vector<int>(gridH, 9999));
    queue<pair<int, int>> q;

    // ゴール地点（2x2マス）を距離「0」としてキューに入れる
    for (int yy = 0; yy < 2; yy++) {
        for (int xx = 0; xx < 2; xx++) {
            int tx = GoalX + xx;
            int ty = GoalY + yy;
            if (tx >= 0 && tx < gridW && ty >= 0 && ty < gridH) {
                distanceMap[tx][ty] = 0;
                q.push({tx, ty});
            }
        }
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    // 幅優先探索（BFS）で全マスの距離を測る
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        int cx = curr.first;
        int cy = curr.second;
        int currentDist = distanceMap[cx][cy];

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx >= 0 && nx < gridW && ny >= 0 && ny < gridH) {
                int tile = mapData[nx][ny];
                // プレイヤーが歩ける床なら探索を進める
                if (tile == 0 || tile == 3 || tile == 8 || (tile >= 10 && tile <= 17)) {
                    if (distanceMap[nx][ny] > currentDist + 1) {
                        distanceMap[nx][ny] = currentDist + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

//--------------------------------------------
void ofApp::sendText2server(string txt){
    string com = "curl -s -m 3";
    string server = "'http://colors.ise.ibaraki.ac.jp/IoTproj/log.php?";
    string auth = "-u 'iotproj:BrVQxevZ'";
    string who = "who=";
    string ID = "ID=";
    
    who += "tanizawa";
    ID = ID + "oFgame(" + __DATE__ + "/" __TIME__ + ")"; // ビルド日時を追加
    ofStringReplace(who, " ", "%20");
    ofStringReplace( ID, " ", "%20" );
    ofStringReplace( txt, " ", "%20" );
    
    string fullURL = com + " " + auth + " " + server + who +"&"+ ID +"&line="+txt+"'&";
    cout << fullURL << endl;
    ofSystem( fullURL );
}

//--------------------------------------------
float ofApp::textGrow(string text){
    ofRectangle box = myFont.getStringBoundingBox(text,0,0);
    float centerX = (ofGetWidth() / 2) - (box.width / 2);
        
    return centerX;
}

//---------------------------------------------
float ofApp::textGrowsmall(string text){
    ofRectangle box = smallFont.getStringBoundingBox(text,0,0);
    float centerX = (ofGetWidth() / 2) - (box.width / 2);
        
    return centerX;
}

//----------------------------------------------
float ofApp::textGrowbig(string text){
    ofRectangle box = bigFont.getStringBoundingBox(text,0,0);
    float centerX = (ofGetWidth() / 2) - (box.width / 2);
        
    return centerX;
}
