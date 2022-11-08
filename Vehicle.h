#include "Global.h"
class CVEHICLE{
public :
    int mx,my;
public:
    virtual void Move(int ,int);
};
class CCAR:public CVEHICLE{
    public:

};
class CTRUCK :public CVEHICLE{
    public:
};