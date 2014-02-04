#include "GameObject.hpp"

GameObject::GameObject(unsigned int id, Gfx& gfx) : 	
	ObjectId(id),
	Graphics(gfx) {
}

GameObject::~GameObject() {
}

void GameObject::Draw() {
	Graphics.DrawImage();
}