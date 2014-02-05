#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include <SDL2\SDL.h>

#include <iostream>
#include <string>

#include "GameObjectManager.hpp"

class GameState 
{	
	public:
		GameState();
		virtual ~GameState();
	
		std::string GetName();
	
		virtual void Enter();
		virtual bool LoadMedia(SDL_Renderer* RenderWindow, std::string Files);
		virtual void HandleEvent(SDL_Event * Event, bool & Running);
		virtual void Update();
		virtual void Render(SDL_Renderer* RenderWindow);
		virtual void Exit();

	protected:
		GameState(const std::string& GS_Name);
		
		std::string Name;
		GameObjectManager GMO;
		
	private:
				
		
};
#endif