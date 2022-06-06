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
