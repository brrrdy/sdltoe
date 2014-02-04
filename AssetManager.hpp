#ifndef _ASSETMANAGER_HPP_
#define _ASSETMANAGER_HPP_

#include <SDL2\SDL.h>
#include <string>
#include <map>

class AssetManager {
	public:
		AssetManager();
		~AssetManager();
		
		static bool LoadTexture(std::string FileName, std::string TextureName);
		static bool GetTexture(std::string TextureName, SDL_Surface& Texture);
		
	private:
		static std::map<std::string, SDL_Surface*> Textures;
		
		
};
#endif