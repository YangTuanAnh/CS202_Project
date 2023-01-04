#pragma once 

#include <vector>
#include <memory>

class SceneNode {
public:
    typedef std::unique_ptr<SceneNode> Ptr;
    SceneNode();
    virtual ~SceneNode() {};
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode &node);
    void detachFirstChild();
    void detachLastChild();
    void detachAllChildren();
    virtual void drawThis() = 0;
    virtual void draw();
    virtual void updateThis(float dt);
    virtual void update(float dt);
protected:
    std::vector<Ptr> mChildren;
    SceneNode *mParent;
};