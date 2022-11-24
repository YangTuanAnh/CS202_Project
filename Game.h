#include "Global.h"
#include "People.h"
#include "Vehicle.h"
vector<pair<int,Object>>ob;
vector<Object> animal;
vector<Object> vehicle;
class Game
{
    Truck* axt;
    Car* axh;
    Dinausor* akl;
    Bird* ac;
    Player cn;
    public:
    Game(); //Chuẩn bị dữ liệu cho tất cả các đối tượng
    void drawGame(); //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
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