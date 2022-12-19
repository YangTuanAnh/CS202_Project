#include "../Lane.h"

class JungleLane : public Lane {
private:
    float speed;
    Objects::ID type;
public:
    JungleLane(float speed, int direction, Objects::ID type);
    ~JungleLane();
    void update(float dt);
    void draw();
};