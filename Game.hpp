#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <map>

#include <SDL2\SDL.h>

#include "GameState.hpp"

class Game {
	public:
		Game();
		int Execute();
		static void Change_State(const std::string State_Name);
		
		bool Init();
		void Exit();

	private:
		SDL_Window* Main_Window;		
		bool Game_Running;
		
		static GameState* Current_State;
		
		static std::map<std::string, GameState*> Game_States;
		
};
	
#endif