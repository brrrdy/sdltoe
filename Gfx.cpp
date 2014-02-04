#include "Gfx.hpp"
#include "Game.hpp"
#include "AssetManager.hpp"
#include <iostream>

Gfx::Gfx(std::string tname, SDL_Rect src, SDL_Rect dest):
	Src(src),
	Dest(dest),
	TextureName(tname)
{
}

Gfx::~Gfx() {
}

void Gfx::DrawImage() {
	SDL_Surface Texture; 
	if ( AssetManager::GetTexture(TextureName, Texture) ) {
		SDL_BlitSurface( &Texture, &Src, SDL_GetWindowSurface(Game::MainWindow), &Dest);
	} else {
		std::cout << "Error retrieving texture: " << TextureName << "." << std::endl;
	}
}
