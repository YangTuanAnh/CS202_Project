#include "Game.h"

Object* Game::getAnimal(){
    for(int i=0; i < ob.size();i++){
        if(ob[i].first == 2){
            animal.push_back(ob[i].second);
        }
    }
}
Object* Game::getVehicle(){
    for(int i=0; i < ob.size();i++){
        if(ob[i].first == 1){
            animal.push_back(ob[i].second);
        }
    }
}
Player Game::getPeople(){
    return cn;
}
void Game::startGame()//setting a 30x30 map
{
    //set position of player
    cn.mX =rand()%30;
    cn.mY= 0;
    //set obstacle
    for(int i = 0 ; i < 30 ; i++){
        int s = rand()%4;//random types
        int pos = rand()%30;//random position in column
        if(s==1){
            Car obe(s,pos,((rand()%2)-1),0);
            ob.push_back(make_pair(1,obe));
        }
        if(s==2){
            Truck obe(s,pos,((rand()%2)-1),0);
            ob.push_back(make_pair(1,obe));
        }
        if(s==3){
            Bird obe(s,pos,((rand()%2)-1),0);
            ob.push_back(make_pair(2,obe));
        }
        else{
            Dinausor obe(s,pos,((rand()%2)-1),0);
            ob.push_back(make_pair(2,obe));
        }  
    }
    drawGame();
}

void Game::drawGame(){
    for(int i  =ob.size()-1 ; i>=0;i-- ){
        for(int j  = 0 ; j < 30 ; j++){
            if (ob[i].second.getmX() == j||ob[i].second.getmX() + ob[i].second.getsize()-1 ==j){
                cout << "*";
            }
            else
                cout<<"_";
        }
    }
}
void Game::resetGame(){
    startGame();
}
void Game::updatePos(){
    for(int i = 0; i < ob.size() ;i++){
        ob[i].second.move(&cn);
    }
}

void Game::saveGame(ostream fout){
    for(int i  =0 ;  i < ob.size() ; i++){
        fout <<  ob[i].first<<'\n';
        fout<<ob[i].second.getmX()<<'\n';
        fout<<ob[i].second.getmY()<<'\n';
        fout<<ob[i].second.getDirect()<<'\n'; 
    }

    fout<<cn.getmX()<<'\n';
    fout<<cn.getmY()<<'\n';
    fout<<cn.getPoint()<<'\n';
}

void Game::loadGame(istream fin){
    int a;
    for(int i  =0 ;  i < ob.size() ; i++){
        fin>>ob[i].first;
        fin>>a;
        ob[i].second.setmX(a);
        fin>>a;
        ob[i].second.setmY(a);
        fin>>a;
        ob[i].second.setsize(a);
        fin>>a;
        ob[i].second.setDirect(a);
    }
    fin>>a;
    cn.setX(a);
    fin>>a;
    cn.setY(a);
    fin>>a;
    cn.setPoint(a);
}