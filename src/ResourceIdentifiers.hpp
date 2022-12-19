#pragma once
// List of states
namespace States {
    enum ID {
        None,
        Menu,
        Game,
        Loading,
        Pause,
        Settings,
        GameOver,
        // ...
    };
};

// List of textures
namespace Textures {
    enum ID {
        None,
        GameBackground,
        PausedBackground,
        Player,
        // ...
    };
};

// List of player states
namespace PlayerStates {
    enum ID {
        None,
        Idle,
        Jumping,
        Dead,
        // ...
    };
};

namespace Directions {
    enum ID {
        Left,
        Right,
        Up,
        Down,
        // ...
    };
};

namespace ObjectTypes {
    enum ID {
        None,
        Obstacle,
        Car,
        Truck,
        Bird,
        Dinosaur,
        // ...
    };
};

namespace LaneTypes {
    enum ID {
        None,
        RoadLane,
        JungleLane,
        PlainLane,
        // ...
    };
};