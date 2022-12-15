#include "Global.h"
#include "Player.h"
#include "Object.h"

// Object velocity define
#define V_OBSTACLE 0.0f
// normal mode
#define V_CAR_N 2.0f
#define V_TRUCK_N 2.5f
#define V_BIRD_N 3.5f
#define V_DINAUSOR_N 1.5f

class Game
{
    vector<Object*>map;
	Player *a;
    Player cn;
    TextureHolder* mTextures;
    public:
    Game(TextureHolder* mTextures); //Chuẩn bị dữ liệu cho tất cả các đối tượng
    void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
    void Random();
    ~Game(); // Hủy tài nguyên đã cấp phát
    Player getPeople();//Lấy thông tin người
    Object* getVehicle();//Lấy danh sách các xe
    Object* getAnimal(); //Lấy danh sách các thú
    void resetGame(); // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
    //void exitGame(HANDLE); // Thực hiện thoát Thread
    void startGame(); // Thực hiện bắt đầu vào trò chơi
    void loadGame(istream); // Thực hiện tải lại trò chơi đã lưu
    void saveGame(ostream); // Thực hiện lưu lại dữ liệu trò chơi
    //void pauseGame(HANDLE); // Tạm dừng Thread
    //void resumeGame(HANDLE); //Quay lai Thread
    void updatePosPeople(char); //Thực hiện điều khiển di chuyển của CPEOPLE
    void updatePos(); //Thực hiện cho CTRUCK & CCAR di chuyển
};