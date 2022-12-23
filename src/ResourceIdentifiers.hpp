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
        Car_left,
        Car_right,
        Truck_left,
        Truck_right,
        Bird_left,
        Bird_right,
        Dinosaur_left,
        Dinosaur_right,
        Obstacle,
        // ...
    };
};

namespace Audio {
    enum ID {
        MenuTheme,
        GameTheme,
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
        Car,
        Truck,
        Bird,
        Dinosaur,
        Obstacle,
        // ...
    };
};

namespace Objects {
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

namespace Lanes {
    enum ID {
        None,
        Road,
        Jungle,
        Plain,
        // ...
    };
};