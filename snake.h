#ifndef snake
#define snake
struct SNAKE {
    bool IsSurvivor;            //當前結點是否存在（被畫）
    int coor_x;                 //節點橫座標
    int coor_y;                 //節點縱座標
    SNAKE* link;                //指向下一個節點的指標
    //建構函式
    SNAKE(int x, int y, bool survivor = true, SNAKE* link = NULL) {
        //初始化座標值,賦值方式為tail派生
        coor_x = x;
        coor_y = y;
    }
};
//蛇精靈類定義——基於單鏈表實現蛇身
class Snake{
public:
    Snake(int x = 300, int y = 200);
    ~Snake() { delete snakeHead; }
    void drawThisSnake();                       //繪製當前蛇身
    void clear_Tail();
    void positionAction();                      //完成蛇身移動(更新每個節點的座標)
    void turnLeft();                            //蛇頭的基本轉向
    void turnRight();
    void turnUp();
    void turnDown();
    void recordCurrentDirection(int d = LEFT);  //記錄蛇的當前運動方向，藉助列舉類
    int getDirection();
    void IsDeath();                             //是否碰撞草叢，是蛇死亡返回true，否則返回false
    void getCurrentPosRect(RECT& rect);
    void getCurrentCoor(int& x, int& y);
protected:
    int len;                                    //蛇身長度_以塊為單位
    SNAKE* snakeHead;                           //蛇頭指標
    SNAKE* tail;                                //蛇尾指標
    SNAKE* beforeTail;                          //尾巴節點的前一個節點，方便移動
    int directions;
};
void Snake::drawThisSnake() //畫蛇
{
    for (int k = 0; k < snake.size(); k++)
    {
        gotoxy(snake[k].position_x, snake[k].position_y);
        cout << snake[k].body;
    }
}
void Snake::clear_Tail()
{
    int k = snake.size() - 1;
    gotoxy(snake[k].position_x, snake[k].position_y);
    cout << " "; //蛇每移動一次（即一格），就把上一次畫出來的蛇尾擦掉
}

//蛇類的成員函式
void Snake::turnDown() {
    //向下轉頭
    if (directions != UP) {
        snakeHead->coor_y += 1;
    }
}

void Snake::turnLeft() {
    //想左轉頭
    if (directions != RIGHT) {
        snakeHead->coor_x -= 1;
    }
}

void Snake::turnRight() {
    //向右轉頭
    if (directions != LEFT) {
        snakeHead->coor_x += 1;
    }
}

void Snake::turnUp() {
    if (directions != DOWN) {
        snakeHead->coor_y -= 1;
    }
}
//蛇類的成員函式
void Snake::positionAction() {
    //實現蛇的自動運動,即依次更新每個節點內座標的值
    if (UP == directions) {
        snakeHead->coor_y--;
    }
    if (DOWN == directions) {
        snakeHead->coor_y++;
    }
    if (LEFT == directions) {
        snakeHead->coor_x--;
    }
    if (RIGHT == directions) {
        snakeHead->coor_x++;
    }
    SNAKE* current = snakeHead;
    int LEN = len;
    for (int i = 1; i < len; i++) {
        current = snakeHead;
        for (int j = 1; j < LEN - 1 && len >= 3; j++) {
            //令current迴圈到指定位置
            current = current->link;
        }
        current->link->coor_x = current->coor_x;
        current->link->coor_y = current->coor_y;
        LEN--;
    }
}
#endif
