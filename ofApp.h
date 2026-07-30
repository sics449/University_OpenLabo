#pragma once

#include "ofMain.h"
#include "Player.h"
#include "Computer.h"
#include "PlayLog.h"

//const int GridW = 60;
//const int GridH = 60;


struct BspRect {
    int x, y, w, h;
};

enum GameState{
    TITLE_MODE,
    TUTORIAL_MODE,
    AGE_SELECT_MODE,        // 年齢選択
    DIFFICULTY_CONFIG_MODE, // 詳細設定
    SELECT_MODE,
    MAP_MODE,
    QUIZ_MODE,
    RESULT_MODE,
    SUMMARY_MODE
};

enum CalcLimitMode {
    CL_KUKU,       // 0: 九九の範囲 (小2〜小4、またはカスタム九九)
    CL_STAGE56,    // 1: 小5〜6年基準 (乗除は九九＋割られる数100まで/割る数2桁まで)
    CL_FREE        // 2: 制限なし (中学生以上、またはカスタム制限なし)
};

// 5月末の進度を考慮した難易度レベル設定（例）
struct CalcRule {
    int maxA;       // 割られる数の上限
    int maxB;       // 割る数の上限
    bool forceZero; // 0を含む問題を優先するかどうか
};

// 難易度設定の例
CalcRule getCalcRule(int grade) {
    if (grade <= 3) return {99, 9, true};  // 小3まで：九九の範囲、0の概念あり
    if (grade == 4) return {999, 99, false}; // 小4：割り算の基礎、大きな数
    return {9999, 99, false};               // 小5以上：発展
}

enum SkillType {
    NONE,
    DASH,      // 直進突進
    FREEZE,    // 敵停止
    TRAP,       // 罠設置
    TIME_STOP, // 時間停止
    SKILL_COUNT
};

struct TreasureChest {
    int x, y;
    int type;      // 0:ショートカットキー, 1:ゴールキー, 2:レア
    bool isOpen;   // 開いているか
    int frame;     // アニメーション用 (0〜2)
};

// 追加：トラップの状態を管理する構造体
struct ActiveTrap {
    int x, y;             // トラップが設置された座標
    bool isActivated;     // COMが踏んで作動中（足止め中）かどうか
    uint64_t timer;       // 作動（足止め）が開始された時刻
    uint64_t duration;    // 足止めする時間 (ミリ秒)
};

class ofApp : public ofBaseApp{

	public:
        
        int gridW;
        int gridH;
        int currentTilesize = 64;
        vector<vector<int>> mapData;
		void setup();
        void initGame();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void initTutorial();
        void drawTutorialGuide();
        void generateMap();
        // ofApp.h の generateMap() の下あたりに追加
        int getCurrentRoom(int gridX, int gridY);
        void updateComGoal(); // COMの目的地を更新する関数
        GameState currentState = MAP_MODE;
        GameState previousState;
        GameState prePauseState;
        bool isPaused = false;
    
        // 隠しコマンド判定用
        std::vector<int> ageCommandInput;       // プレイヤーのキー入力履歴を溜めるバッファ
        std::vector<int> ageSecretCommand = {
            'b', 'a', 'e'
        };      // 正解のコマンド配列
        bool isAgeConfirmed = false; // 年齢選択の確認画面(これでいいか聞く画面)
    
        vector<int> secretCommand = {
            OF_KEY_LEFT,
            OF_KEY_RIGHT,
            '1', '2'
        };
        vector<int> inputHistory;
        bool isSecretLevelUnlocked = false; // 解放フラグ
        //問題のレベル設定関連------------------------
        bool showCustomMode = false;      // カスタムモードが解放されているか
        std::string commandInput = "";    // 入力されたコマンドの履歴をためる文字列
    
        // 加減算用のカスタム桁数設定（-3桁〜5桁に対応できるようにする値）
        int minDigits = 1;                // 最低桁数 (1〜5)
        int maxDigits = 2;                // 最大桁数 (1〜5)
        bool allowNegative = false;       // マイナス（負の数）の答え・出題を許可するか
        //-----------------------------------------
    
        float comArrowAngle;
        float goalArrowAngle;

        void updateArrows();  // 角度更新用関数
        void drawArrows(int startX, int endX, int startY, int endY);    // 矢印描画用関数
        void checkAndDrawComAlert(); // comの距離で警告を出す関数

        bool isComNearGoalAlert = false; // アラート中かどうかのフラグ
        bool hasFiredLevelAlert = false;
        float alertTextX = 0;            // 流れる文字の現在のX座標
        bool hasPlayedAlertSound = false; // 警告音が何度も鳴るのを防ぐフラグ
        // チュートリアル用--------
        float chestSpawnTimer;
        float chestSpawnInterval = 3.0; // 何秒ごとに出現させるか（例：10秒）
    
        string tutorialMessage = "";
        float messageTimer = 0;
        //--------------------------
        CalcLimitMode mulLimitMode = CL_KUKU; // 掛け算のデフォルト設定
        CalcLimitMode divLimitMode = CL_KUKU; // 割り算のデフォルト設定
        int selectedLevel = 0; // 0:Easy, 1:Normal, 2:Hard, 3:TUTORIAL, 4:SuperHard
        int comBaseInterval = 0;
        bool isComBoostMode = false; // 追い上げモード中かどうかのフラグ
        bool isPlayerBoost = false;
        // 正解時のメッセージテキスト-------------------------
        string resultMessage;
        string resultMessageEnd;
        int gainedSkillType = 0;
    
        void drawWindow(float x, float y, float w, float h);
    
        int correctIdx;
    
   
        int titleStep = 0;       // 0:「ボタンをおしてね」, 1:「スタート / れんしゅう 選択」
        int titleMenuCursor = 0; // 0: スタート, 1: れんしゅう
        int ageCursor = 0;
    
        float tutorialTimer;       // チュートリアルの経過時間を秒で記録
        bool bShowNextPrompt;
        GameState previousModeBeforeTutorial;
        
        int configCursor = 0;
        int selectCursor = 0;
        bool useAdd = true, useSub = false, useMul = false, useDiv = false;
        int maxNumLimit = 10;
        bool isEditingNum = false;
        bool isShowingConfirm = false;
        bool showErrorMessage = false;
        int errorTimer = 0;
        bool confirmCursor = true; // true: はい, false: いいえ
    
        float animTimer = 0;
        int animFrame = 0;
    
        int selectVerticalZone = 0; // 0: 上側（スクショ選択中）, 1: 下側（「もどる」選択中）
        float stageSpacing = 950.0f; // スクショ同士の横の間隔（ピクセル）
        int selectedBottomLevel = 0;
        float selectOffsetX = 0.0f;     // 画面全体のスライド位置を滑らかに動かすためのオフセット
        bool isVeryHardUnlocked = false; // コマンド入力で解放されたかどうかのフラグ
        float cursorHoverTime = 0.0f;   // 同じステージにカーソルが合ってからの経過時間
        int lastSelectedLevel = 0;       // 前のフレームで選択していたレベル（タイマーリセット用）

        void setRecommendedSettings(int ageIndex); // おすすめセット用関数
    
        struct Question {
            string genreName;   // ジャンル名（「算数」「英語」など）
            string text;        // 問題文
            string choices[4];  // 選択肢（A〜D）
            int correctIndex;   // 正解の番号（0〜3）
        } currentQuestion;
    
        void setupMathQ();
        string quizHintText = "";     // 右側に表示する文字解説用
        string quizHintGraph = "";    // 中央に表示する図解・数式用（新規追加）
        void drawColorButton(float x, float y, string label, ofColor color, string choiceText);
        void drawTitleChip(int gridX, int gridY, int chipIdx);
    
        int totalQuestions = 0;   // 出題数
        int correctAnswers = 0;   // 正解数
    
        int summaryCursor = 0; // 0: Retry, 1: Difficulty, 2: Title

        // 正答率を計算して文字列で返す関数
        string getAccuracyString();
        Player myPlayer;
        Com myCom;
        ofTrueTypeFont myFont;
        ofTrueTypeFont smallFont;
        ofTrueTypeFont bigFont;
    
        float clearTime = 0.0;      // タイム計測用
        bool isGameCleared = false; // ゴールしたかどうかのフラグ
        bool isGameFailed = false;
        ofTrueTypeFont timeFont;    // タイム表示用のフォント（既存のを流用してもOK）
        string getTimeString(float time);
    
        uint64_t goalTime = 0; // ゴールした時刻を保存
    
        SkillType stockedSkill = NONE;
    
        float itemPopTimer = 0;    // 演出の残り時間
        int lastGetItemType = 0;   // 取得したアイテムのアイコン番号
        float itemPopY = 0;        // アニメーション用のアゲ幅
    
       
        vector<ActiveTrap> activeTraps; // 設置されているトラップのリスト
        const int MAX_TRAPS = 3;        // 同時に存在できる最大数
        int trapX = -1, trapY = -1; // 罠の座標
        uint64_t skillTimer = 0;    // 効果時間測定用
        bool isComFrozen = false;   // 敵が停止中か
    
        float freezeDuration = 3000; // フリーズスキルの時間
        float trapDuration = 5000;   // トラップ（穴）の停止時間
        float currentSkillDuration = 0; // 現在適用されている停止時間（これを判定に使う）
        void activateDash();
    
        bool isDashing = false;
        int dashDx = 0, dashDy = 0;
        uint64_t lastDashTime = 0;
        const int dashInterval = 50;
        bool isDashStunned = false;    // ダッシュ後の硬直フラグ
        float piyoTimer = 0.0f;   // ピヨり（スタン）の残り時間タイマー
        int piyoAnimFrame = 0;    // 現在表示するピヨりのコマ番号 (0〜2)
        uint64_t dashStunTimer = 0;    // 硬直開始時間
    
        void activateFreeze();
        void activateTrap();
        enum PenaltyType {
            P_NONE,
            P_STUN,
            P_ENCOUNTER
        };
        PenaltyType reservedPenalty = P_NONE;
    
        bool isStunned = false;       // スタン中か
        uint64_t stunTimer = 0;      // スタン開始時間
        const int stunDuration = 2000; // スタン時間（2秒）
    
        // ofAppクラスのprivateまたはpublicに追加
        bool isTimeStopped = false;      // 時間停止中か
        uint64_t timeStopTimer = 0;      // 停止開始時間
        const int timeStopDuration = 4000; // 5秒

        void QuizIncorrect(); // 不正解時の処理関数
    
        bool isCountingDown = false;    // カウントダウン中か
        float countdownTimer = 3.0;      // 残り秒数（3.0から開始）
        int lastCountdownSeconds = 3; // 前回の秒数を保存
    
        bool isQuizShowReady = false;    // 「問題があらわれた」表示中か
        float quizShowTimer = 0;         // 演出用のタイマー
        string quizAlertText = "問題が　あらわれた!";
        bool showHintButton = false; // 5秒後に赤い丸ボタンと「ヒント」を出すためのフラグ
        bool isHintActive = false; // cキーが押されて実際にヒントが表示されているかどうかのフラグ
    
        int getPlayerPathLength(int startX, int startY, int targetX, int targetY);
        int myComPathSizeCached = 0;
        int lastComPathSize = 0;
    
        vector<vector<int>> distanceMap;
        void calculateDistanceMap();
        // --- プレイヤーの経路計算軽量化用 ---
        int lastPlayerX = -1;       // 前回計算したときのプレイヤーのX座標
        int lastPlayerY = -1;       // 前回計算したときのプレイヤーのY座標
        int cachedPlayerPathLength = 999; // 保存されたプレイヤーの残りマス数
        float textGrow(string text);
        float textGrowsmall(string text);
        float textGrowbig(string text);
    
        // ログ関連 ------------------------------
        void sendText2server( string txt ); // サーバに飛ばすやつ
        GameState state;
        PlayLogger logger;            // ログ管理の専門窓口（インスタンス）
        ofVec2f lastPlayerPos; // 毎フレームの移動距離を計算するための一時変数
        uint64_t quizStartTime = 0;   // クイズが1問出題された瞬間の時刻を記録するタイマー
        int selectedAge = 0;
        //-----------------------------------------
    
private:
    float screenW;               // 画面の横幅
    float screenH;               // 画面の縦幅
    int GoalX, GoalY;
    ofImage mapchip[22];
    ofImage goalchip[2];
    ofImage titleImg;
    ofImage chestImg;              // 宝箱のタイルマップ画像
    vector<TreasureChest> chests;  // 配置された宝箱のリスト
    ofImage trapImg;
    ofImage piyoImg;
    ofImage effect[1];
    ofImage cursorImg;
    ofImage starImg;
    
    ofImage boxImg;       // 空のチェックボックス枠
    ofImage checkImg;     // チェックマーク
    
    ofImage playerLabel; // プレイヤー用（3枚綴り）
    ofImage comLabel;    // COM用（3枚綴り）
    ofImage comArrowSheet;
    ofImage goalArrowSheet;
    
    // 追加する画像と動画の読み込み用（動画は手順②で使います）
    ofImage stageScreenshots[4];     // 0:Easy, 1:Normal, 2:Hard, 3:VeryHard の画像
    ofVideoPlayer stageVideos[3];    // 動画再生用（手順②で使用）
    ofImage selectArrow;
    
    ofSoundPlayer bgm[6];
    float normalVolume = 0.4; // 通常時の音量
    float quizVolume = 0.3;   // クイズ中の音量
    
    ofSoundPlayer seQuizStart;
    ofSoundPlayer seCorrect;
    ofSoundPlayer seIncorrect;
    ofSoundPlayer seCountdown;
    ofSoundPlayer seStart;
    ofSoundPlayer seFinish;
    ofSoundPlayer seSelect;
    ofSoundPlayer seChoose;
    
    ofSoundPlayer seDash;
    ofSoundPlayer seFrozen;
    ofSoundPlayer seTrapset;
    ofSoundPlayer seTrapact;
    ofSoundPlayer seTimeStop;
    ofSoundPlayer sePlayerBoost;
    ofSoundPlayer seComBoost;
    ofSoundPlayer seFinishBoost;
    
    ofSoundPlayer seStun;
    ofSoundPlayer sePiyo;
    ofSoundPlayer seAlert;
    ofSoundPlayer seGenerateVeryHard;
    
    int skillStocks[SKILL_COUNT] = {0, 0, 0, 0}; // 各スキルの所持数
    ofImage skillIcons[SKILL_COUNT];
    vector<BspRect> rooms; // 生成された部屋のリスト
    uint64_t lastAnimTime;
    int step;
    int targetStep;
    const int minStep = 10;
    const int maxStep = 17;
    
    // --- 追加：障害物（山）専用 ---
    //int obstacleCount;      // 障害物を置く目標数
    //const int minObstacles = 50; // 最小数（少なければここを増やす）
    //const int maxObstacles = 100; // 最大数
    
    bool hasShortcutKey = false;   // 近道の鍵を持っているか
    bool hasGoalKey = false;       // ゴールの鍵を持っているか
    
    bool upPressed = false;
    bool downPressed = false;
    bool leftPressed = false;
    bool rightPressed = false;
    uint64_t lastMoveTime = 0; // 移動速度を制限するためのタイマー
    
    ofColor colorA = ofColor(255, 0, 0);     // Aボタン：赤 (キー1)
    ofColor colorB = ofColor(0, 120, 255);   // Bボタン：青 (キー2、少し見やすい鮮やかな青)
    ofColor colorC = ofColor(255, 255, 255); // 白ボタン：白 (Enterキー、ヒントや決定用)
    ofColor colorD = ofColor(255, 215, 0);   // Cボタン：黄 (キー3)
    ofColor colorE = ofColor(0, 200, 50);    // Dボタン：緑 (キー4、暗すぎない明るめの緑)
};
