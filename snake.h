#ifndef Snake_H
#define Snake_H
struct SNAKE 
{
    bool IsSurvivor;            //當前結點是否存在（被畫）
    int coor_x;                 //節點橫座標
    int coor_y;                 //節點縱座標
};
class Snake
{
public:
    Snake(int x = 300, int y = 200);
    ~Snake() { delete snakeHead; }
    bool addTail();                             //蛇尾增加長度
    void drawThisSnake();                       //繪製當前蛇身
    void positionAction();                      //完成蛇身移動(更新每個節點的座標)
    void turnLeft();                            //蛇頭的基本轉向
    void turnRight();
    void turnUp();
    void turnDown();
    int getDirection();
    bool IsDeath();                             //是否碰撞草叢，是蛇死亡返回true，否則返回false
protected:
    int len;                                    //蛇身長度_以塊為單位
    Snake *snakeHead;                           //蛇頭指標
    Snake *tail;                                //蛇尾指標
    Snake *beforeTail;                          //尾巴節點的前一個節點，方便移動
    int directions;
};
#endif
