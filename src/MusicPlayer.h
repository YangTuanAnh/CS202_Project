#pragma once
#include "ResourceIdentifiers.hpp"
#include <raylib.h>
#include <map>

class MusicPlayer {
public:
    MusicPlayer();
    void play(Audio::ID theme);
    void update();
    void stop();
    void setPaused(bool paused);
    void setVolume(float volume);
    float getVolume();
    ~MusicPlayer();

private:
    Music mMusic;
    std::map<Audio::ID, std::string> mFilenames;
    float mVolume;
};