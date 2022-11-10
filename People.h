#include "Global.h"
#include "Vehicle.h"
    class Player{
    public:
        int mX, mY;
        bool mState;
    public:
        Player(int,int);
        int getmX();
        int getmY();
        void Up();
        void Down();
        void Left();
        void Right();
        void movement();
        bool isFinish();
        bool isDead();
        bool Collision(Object*);
    };