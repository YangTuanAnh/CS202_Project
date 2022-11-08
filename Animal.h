#include "Global.h"
class CANIMAL{
public :
    float speed;
    int mx,my;
    int size;
public:
    virtual void Move(int ,int);
    virtual void Tell(); //sound effect
    void Random();
};

vector<vector<pair<int,int >>> animal;

class CDINAUSOR:public CANIMAL{
public:
    size = 2;
    
};
class CBIRD:public CANIMAL{
public:
    size = 1;
};