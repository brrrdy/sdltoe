#include "GameObject.hpp"

GameObject::GameObject() {
}

GameObject::GameObject(unsigned int id, Gfx* gfx) : 	
	ObjectId(id),
	Graphics(gfx) {
}


GameObject::~GameObject() {
}

void GameObject::Update() {
}

void GameObject::Draw(SDL_Renderer * RenderWindow) {
}