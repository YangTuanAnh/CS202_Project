#include "../Lane.h"

class PlainLane : public Lane {
private:
    ObjectTypes::ID type;
public:
    PlainLane(ObjectTypes::ID type);
    ~PlainLane();
    void update(float dt);
    void draw();
};