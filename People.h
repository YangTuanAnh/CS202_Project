#include "Global.h"
#include "Vehicle.h"
#include "Animal.h"
    class CPEOPLE{
    public:
        int mX, mY;
        bool mState;
    public:
        CPEOPLE();
        void Up(int);
        void Left(int);
        void Right(int);
        void Down(int);
        bool isImpact(const CVEHICLE*&);
        bool isImpact(const CANIMAL*&);
        bool isFinish();
        bool isDead();
    };