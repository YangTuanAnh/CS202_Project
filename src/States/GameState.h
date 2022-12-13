#pragma once

#include "../State.h"
#include "../Player.h"
#include "../Object.h"

#include <iostream>
#include <vector>

class GameState : public State {
private:
    std::vector<Object*> map;
    Player* player;
    Texture2D* mBackgroundTexture;
public:
    GameState(StateStack* stack, Context context);
    ~GameState();
    virtual void draw();
    virtual bool update(float dt);
    // virtual bool handleEvent(Event event);
    void random();
    Player getPeople();//Lấy thông tin người
    Object* getVehicle();//Lấy danh sách các xe
    Object* getAnimal(); //Lấy danh sách các thú
    void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
    //void exitGame(HANDLE); // Thực hiện thoát Thread
    void startGame(); // Thực hiện bắt đầu vào trò chơi
    void loadGame(std::istream); // Thực hiện tải lại trò chơi đã lưu
    void saveGame(std::ostream); // Thực hiện lưu lại dữ liệu trò chơi
    //void pauseGame(HANDLE); // Tạm dừng Thread
    //void resumeGame(HANDLE); //Quay lai Thread
    void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
    void updatePos(); //Thực hiện cho CTRUCK & CCAR di chuyển
};