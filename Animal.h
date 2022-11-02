#include "Global.h"
class CANIMAL{
public :
    float speed;
    int mx,my;
public:
    virtual void Move(int ,int);
    virtual void Tell();//sound effect
};