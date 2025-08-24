#include "scoredisplay.h"

ScoreDisplay::ScoreDisplay() { gameObjects.push_back(this); }

void ScoreDisplay::Update() {}

void ScoreDisplay::Render() {
    DrawText(TextFormat("Score: %01i", score), 100, 25, 32, WHITE);
}

ScoreDisplay::~ScoreDisplay() {}
