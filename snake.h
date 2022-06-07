#ifndef Snake_H
#define Snake_H
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
private:
    int len;                                    //蛇身長度_以塊為單位
    SNAKE* snakeHead;                           //蛇頭指標
    SNAKE* tail;                                //蛇尾指標
    SNAKE* beforeTail;                          //尾巴節點的前一個節點，方便移動
    int directions;
};
#endif
