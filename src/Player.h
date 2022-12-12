#include "Global.h"
#include "Object.h"
#include "raylib.h"
#include "raygui.h"
const int WIDTH = 1200, HEIGHT = 600;

static bool gameOver = false;
static bool pause = false;
class Player{
public:
    float mX, mY;
    bool mState;
    int point;
public:
    Player();
    Player(float,float,int);
    float getmX();
    float getmY();
    int getPoint();
    void setX(float);
    void setY(float);
    void setPoint(int);
    void movement();
    void DrawPlayer();
    void UpdatePlayer();
    bool isDead();
    bool Collision(Object*);
    ~Player();
};