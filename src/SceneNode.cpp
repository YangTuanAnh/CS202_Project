#include "SceneNode.h"

#include <cassert>
#include <queue>
#include <algorithm>
#include <iostream>

SceneNode::SceneNode() {
    mParent = nullptr;
}

void SceneNode::attachChild(Ptr child) {
    child->mParent = this;
    mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode &node) {
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&] (Ptr &p) -> bool {
        return p.get() == &node;
    });
    assert(found != mChildren.end());
    Ptr result = std::move(*found);
    result->mParent = nullptr;
    mChildren.erase(found);
    return result;
}

void SceneNode::detachFirstChild() {
    mChildren.erase(mChildren.begin());
}

void SceneNode::detachLastChild() {
    mChildren.pop_back();
}

void SceneNode::detachAllChildren() {
    mChildren.clear();
}

std::vector<SceneNode::Ptr> &SceneNode::getChildren() {
    return mChildren;
}

void SceneNode::draw() {
    std::queue<SceneNode*> nodes;
    nodes.push(this);
    while (!nodes.empty()) {
        SceneNode *node = nodes.front();
        nodes.pop();
        node->drawThis();
        for (auto it = node->mChildren.rbegin(); it != node->mChildren.rend(); ++it) {
            nodes.push(it->get());
        }
    }
}

void SceneNode::update(float dt) {
    updateThis(dt);
    for (auto &child : mChildren) {
        child->update(dt);
    }
}

void SceneNode::updateThis(float dt) {}

void SceneNode::load(std::ifstream &in) {}

void SceneNode::save(std::ofstream &out) {
    saveThis(out);
    for (auto &child : mChildren) {
        child->save(out);
    }
}

void SceneNode::saveThis(std::ofstream &out) {}