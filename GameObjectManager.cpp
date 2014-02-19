#include "GameObjectManager.hpp"

GameObjectManager::GameObjectManager() {
}

GameObjectManager::~GameObjectManager() {
}

void GameObjectManager::Insert(GameObject& NewObject) {
	VisibleObjects.push_back(NewObject);
}

void GameObjectManager::Update(double ElapsedTime) {
	// call update for each game object
}

void GameObjectManager::DrawAll(SDL_Renderer * RenderWindow) {
	std::vector<GameObject>::iterator it;
	for (it = VisibleObjects.begin(); it != VisibleObjects.end(); it++) {
		it->Draw(RenderWindow);
	}
}