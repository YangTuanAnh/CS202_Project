#include "../Lane.h"

class JungleLane : public Lane {
private:
    float speed;
    ObjectTypes::ID type;
public:
    JungleLane(float speed, int direction, ObjectTypes::ID type);
    ~JungleLane();
    void update(float dt);
    void draw();
};