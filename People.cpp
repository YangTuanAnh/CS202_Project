#include "People.h"

void CPEOPLE::Up(int& x)
{
    x++;
}
void CPEOPLE::Left(int& y)
{
    y++;
}
void CPEOPLE::Right(int&y)
{
    y--;
}
void CPEOPLE::movement()
{
    char n='e';
    while(!this->isDead())
    {
        n = _getch();
        if(n=='w')
            Up(this->mX);
        if(n=='a')
            Left(this->mY);
        if(n=='d')
            Right(this->mY);
    }
}

bool CPEOPLE::isDead()
{
    for(int i = 0 ; i < animal[mX].size();i++)
    {
        if (mY == animal[mX][i].second)
            return true;
    }
    return false;
}