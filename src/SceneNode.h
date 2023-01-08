#pragma once 

#include <vector>
#include <memory>

class SceneNode {
public:
    typedef std::shared_ptr<SceneNode> Ptr;
    SceneNode();
    virtual ~SceneNode() {};
    void attachChild(Ptr child);
    Ptr detachChild(const SceneNode &node);
    void detachFirstChild();
    void detachLastChild();
    void detachAllChildren();
    std::vector<Ptr> &getChildren();
    virtual void drawThis() = 0;
    virtual void draw();
    virtual void updateThis(float dt);
    virtual void update(float dt);
    virtual void load(std::ifstream&);
    virtual void save(std::ofstream&);
    virtual void saveThis(std::ofstream&);
protected:
    std::vector<Ptr> mChildren;
    SceneNode *mParent;
};