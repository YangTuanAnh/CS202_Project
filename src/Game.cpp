#include "Game.h"

Game::Game(TextureHolder* mTextures) {
    this->mTextures = mTextures;
}

// Object* Game::getAnimal(){
//     for(int i=0; i < obstacle.size();i++){
//         if(obstacle[i]->type() == 2||obstacle[i]->type()==3){
//             animal.push_back(*obstacle[i]);
//         }
//     }
// }
// Object* Game::getVehicle(){
//     for(int i=0; i < obstacle.size();i++){
//         if(obstacle[i]->type() == 1||obstacle[i]->type() == 0){
//             animal.push_back(*obstacle[i]);
//         }
//     }
// }
Player Game::getPeople(){
    return cn;
}
void Game::startGame()//setting a 30x30 map
{
    //set position of player
    cn.mX =rand()%30;
    cn.mY= 0;
    //set obstacle
    for (int j = 0; j < 30; j++) {
        int s = rand() % 5;
        int pos = rand() % 30;
        if (s == 2) {
            map.push_back(new Car(j, pos, rand() % 2, mTextures));
            continue;
        }
        if (s == 3) {
            map.push_back(new Truck(j,pos,  rand() % 2, mTextures));
            continue;
        }
        if (s == 4) {
            map.push_back(new Bird(j,pos,  rand() % 2, mTextures));
            continue;
        }
        if (s == 5) {
            map.push_back(new Dinausor(j,pos, rand() % 2, mTextures));
            continue;
        }
        else
        {
            map.push_back(new Obstacle(j, pos, rand() % 2, mTextures));
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
    int s = rand() % 4;
    int pos = rand() % 30;
    map.erase(map.begin());
    if (s == 2) {
        map.push_back(new Car(map[map.size()-1]->getX()+1,pos, rand() % 2, mTextures));
        return;
    }
    if (s == 3) {
        map.push_back(new Truck( map[map.size() - 1]->getX()+1, pos, rand() % 2, mTextures));
        return;
    }
    if (s == 4) {
        map.push_back(new Bird(map[map.size() - 1]->getX()+1, pos, rand() % 2, mTextures));
        return;
    }
    if (s == 5) {
        map.push_back(new Dinausor(map[map.size() - 1]->getX()+1, pos, rand() % 2, mTextures));
        return;
    }
    else
    {
        map.push_back(new Obstacle(map[map.size() - 1]->getX()+1,pos, rand() % 2, mTextures));
        return;
    }  
}
void Game::resetGame(){
    startGame();
}
void Game::updatePos(){
    for(int i = 0; i < map.size() ;i++){
        map[i]->move();
    }
}

void Game::saveGame(ostream fout){
    for(int i  =0 ;  i < map.size() ; i++){
        fout << map[i]->type()<<'\n';
        fout << map[i]->getX()<<'\n';
        fout << map[i]->getY()<<'\n';
        fout << map[i]->getDirect()<<'\n'; 
    }

    fout<<cn.getmX()<<'\n';
    fout<<cn.getmY()<<'\n';
    fout<<cn.getPoint()<<'\n';
}

void Game::loadGame(istream fin){
    int a;
    int x,y,dir,point;
    while(!fin.eof()){
        fin>>a;
        switch(a){
        case 2:
            fin>>x>>y>>dir;
            map.push_back(new Car (x, y, dir, mTextures));
            break;
        case 3:
            fin>>x>>y>>dir;
            map.push_back(new Truck (x, y, dir, mTextures));
            break;
        case 4:
            fin>>x>>y>>dir;         
            map.push_back(new Bird (x, y, dir, mTextures));
            break;
        case 5:
            fin>>x>>y>>dir;
            map.push_back(new Dinausor (x, y, dir, mTextures));
            break;
        case 1:
            fin>>x>>y>>dir;
            map.push_back(new Obstacle (x, y, dir, mTextures));
            break;
        }

    }
    fin>>x>>y>>point;
    Player A(x,y,point);
}
Game::~Game(){
    map.clear();
}