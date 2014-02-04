#include "AssetManager.hpp"
#include <iostream>

AssetManager::AssetManager() {
}

AssetManager::~AssetManager() {
}

bool AssetManager::LoadTexture(const std::string FileName, const std::string TextureName){
	
	bool success = true;
	
	// load surface from image file
	SDL_Surface* Texture = SDL_LoadBMP( FileName.c_str() );
	
	// test if image was loaded
	if (Texture == NULL)
	{
		std::cout << "Unable to load image: " << FileName << "." << std::endl;
		success = false;
	}
	Textures.insert(std::make_pair(TextureName, Texture));
	
	return success;
}

bool AssetManager::GetTexture(std::string TextureName, SDL_Surface& Texture){
	std::map<std::string, SDL_Surface*>::iterator it = Textures.find(TextureName);
	
	if (it == Textures.end()) {
		return false;
	}
	Texture = *(it->second);
	return true;
}

std::map<std::string, SDL_Surface*> AssetManager::Textures;