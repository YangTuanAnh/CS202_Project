#include "../Lane.h"

class PlainLane : public Lane {
private:
    Objects::ID type;
public:
    PlainLane(Objects::ID type);
    ~PlainLane();
    void update(float dt);
    void draw();
};