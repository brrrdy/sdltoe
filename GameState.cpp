#include "GameState.hpp"

GameState::GameState() : Name("") {	
}

GameState::GameState(const std::string& GS_Name) : Name(GS_Name) {
}

GameState::~GameState() {
}

bool GameState::LoadMedia(SDL_Renderer* RenderWindow) {
	bool success = true;
	
	
	return success;
}

void GameState::Enter() {
}

void GameState::HandleEvent(SDL_Event * Event, bool &Running) {
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
}

void GameState::Update() {
}

void GameState::Render(SDL_Renderer* RenderWindow) {
}

void GameState::Exit() {
}