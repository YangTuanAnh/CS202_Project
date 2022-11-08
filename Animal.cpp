#include "Animal.h"
#include "People.h"

void CANIMAL::Random()
{
    int number_ob = rand()%(30%this->size);
    vector<pair<int,int>> a;
    for(int i = 0 ; i < number_ob ; i++)
    {
        int x = rand()%30; 
        a.push_back(make_pair(mx,x));
    }
    animal.push_back(a);
}

void CANIMAL::Move(int x ,int y)
{
    int speed;
    int res = rand() % 2;
    if(res ==1){
        //move left
        y = leftpointofscreen;
        y = y +1*speed;
    }
    else{
        //move right
        y = rightpointofscreen;
        y = y-1*speed;
    }
}