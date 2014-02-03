#include "GameState.hpp"

GameState::GameState() : Name("") {	
}

GameState::GameState(const std::string& GS_Name) : Name(GS_Name) {
}

GameState::~GameState() {
}

bool GameState::Load_Media() {
	return false;
}

void GameState::Enter() {
}

void GameState::Handle_Event(SDL_Event * Event, bool &Running) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
}

void GameState::Update() {
}

void GameState::Render(SDL_Window* Game_Window) {
}

void GameState::Exit() {
}