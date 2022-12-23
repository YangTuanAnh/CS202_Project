#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() : mMusic(), mFilenames(), mVolume(1.f)
{
    mFilenames[Audio::MenuTheme] = "../asset/sfx/MenuTheme.mp3";
    mFilenames[Audio::GameTheme] = "../asset/sfx/GameTheme.mp3";
}

void MusicPlayer::play(Audio::ID theme)
{
    std::string filename = mFilenames[theme];
    mMusic = LoadMusicStream(filename.c_str());
    SetMusicVolume(mMusic, mVolume);
    PlayMusicStream(mMusic);
}

void MusicPlayer::stop()
{
    StopMusicStream(mMusic);
}
void MusicPlayer::setPaused(bool paused)
{
    if (paused)
        PauseMusicStream(mMusic);
    else
        PlayMusicStream(mMusic);
}

MusicPlayer::~MusicPlayer() {
    UnloadMusicStream(mMusic);
}

void MusicPlayer::update() {
    UpdateMusicStream(mMusic);
}

void MusicPlayer::setVolume(float volume) {
    mVolume = volume;
    SetMusicVolume(mMusic, mVolume);
}

float MusicPlayer::getVolume() {
    return mVolume;
}