#pragma once

#include <vector>
#include <functional>
#include <map>

#include "State.h"
#include "ResourceIdentifiers.hpp"

class StateStack {
public:
    enum Action {
        Push,
        Pop,
        Clear
    };

public:
    explicit StateStack(State::Context context);
    template <typename T>
    void registerState(States::ID stateID) {
        mFactories[stateID] = [this] () {
            return State::Ptr(new T(this));
        };
    }
    void update(float dt);
    void draw();
    // void handleEvent(Event event);
    void pushState(States::ID stateID);
    void popState();
    void clearStates();
    bool isEmpty() const;

private:
    struct PendingChange {
        explicit PendingChange(Action action, States::ID stateID = States::None);
        Action action;
        States::ID stateID;
    };
    std::vector<State::Ptr> mStack;
    std::vector<PendingChange> mPendingList;
    State::Context mContext;
    std::map<States::ID, std::function<State::Ptr()>> mFactories;
    State::Ptr createState(States::ID stateID);
    void applyPendingChanges();
};
