#include "musicplayer.h"

#include "globals.h"

MusicPlayer::MusicPlayer() {
    gameObjects.push_back(this);

    InitAudioDevice();

    music = LoadMusicStream(ASSET_PATH "Music.mp3");
    PlayMusicStream(music);
    music.looping = true;
}

void MusicPlayer::Update() { UpdateMusicStream(music); }

void MusicPlayer::Render() {}

MusicPlayer::~MusicPlayer() { UnloadTexture(texture); }
