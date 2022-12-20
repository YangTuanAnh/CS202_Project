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
        Car,
        Truck,
        Bird,
        Dinosaur,
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