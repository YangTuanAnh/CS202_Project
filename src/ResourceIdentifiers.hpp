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
        Road,
        Jungle_1,
        Jungle_2,
        Jungle_3,
        Plain,
        Player_right,
        Player_left,
        Player_up,
        Player_down,
        Car_left,
        Car_right,
        Truck_left,
        Truck_right,
        Bird_left,
        Bird_right,
        Dinosaur_left,
        Dinosaur_right,
        Obstacle,
        TrafficLamp_green,
        TrafficLamp_yellow,
        TrafficLamp_red,
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

// List of Traffic lamp states
namespace TrafficLampStates {
    enum ID {
        Green,
        Yellow,
        Red,
        // ...
    };
};

namespace Directions {
    enum ID {
        None,
        Left,
        Right,
        Up,
        Down
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
        TrafficLamp
        // ...
    };
};

namespace Lanes {
    enum ID {
        None,
        Car,
        Truck,
        Jungle,
        Forest,
        BirdJungle,
        Plain,
        // ...
    };
};