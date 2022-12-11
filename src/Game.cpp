#include "Game.h"

Object* Game::getAnimal(){
    for(int i=0; i < obstacle.size();i++){
        if(obstacle[i]->type() == 2||obstacle[i]->type()==3){
            animal.push_back(*obstacle[i]);
        }
    }
}
Object* Game::getVehicle(){
    for(int i=0; i < obstacle.size();i++){
        if(obstacle[i]->type() == 1||obstacle[i]->type() == 0){
            animal.push_back(*obstacle[i]);
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
        Object * base;
        if(s==1){
            Car obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }
        if(s==2){
            Truck obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }
        if(s==3){
            Bird obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }
        else{
            Dinausor obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }  
    }
    drawGame();
    int tmp = cn.getPoint();
    while(!cn.isDead()){
        cn.movement();
        if (cn.getPoint()>tmp) {
            this->Random();
            tmp = cn.getPoint();
        }
    }
    
}

void Game::drawGame(){
    //draw UI
}
void Game::Random(){
    int s = rand()%4;
    int pos = rand()%30;
    obstacle.pop_back();
    Object * base;
        if(s==1){
            Car obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }
        if(s==2){
            Truck obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }
        if(s==3){
            Bird obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }
        else{
            Dinausor obe(s,pos,((rand()%2)-1),0);
            base  =&obe;
            obstacle.push_back(base);
        }   
}
void Game::resetGame(){
    startGame();
}
void Game::updatePos(){
    for(int i = 0; i < obstacle.size() ;i++){
        obstacle[i]->move(&cn);
    }
}

void Game::saveGame(ostream fout){
    for(int i  =0 ;  i < obstacle.size() ; i++){
        fout << obstacle[i]->type()<<'\n';
        fout << obstacle[i]->getmX()<<'\n';
        fout << obstacle[i]->getmY()<<'\n';
        fout << obstacle[i]->getDirect()<<'\n'; 
    }

    fout<<cn.getmX()<<'\n';
    fout<<cn.getmY()<<'\n';
    fout<<cn.getPoint()<<'\n';
}

void Game::loadGame(istream fin){
    int a;
    int x,y,dir;
    Object*base;
    while(!fin.eof()){
        fin>>a;
        switch(a){
        case 0:
            fin>>x>>y>>dir;
            Car obe(x,y,dir,0);
            base = &obe;
            obstacle.push_back(base);
            break;
        case 1:
            Truck obe(x,y,dir,0);
            base = &obe;
            obstacle.push_back(base);
            break;
        case 2:
            Bird obe(x,y,dir,0);
            base = &obe;
            obstacle.push_back(base);
            break;
        case 3:
            int x,y,dir;
            fin>>x>>y>>dir;
            Dinausor obe(x,y,dir,0);
            base = &obe;
            obstacle.push_back(base);
            break;
        }
    }
    fin>>x>>y>>point;
    Player A(x,y,Point);
}
Game::~Game(){
    obstacle.clear();
}