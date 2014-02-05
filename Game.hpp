#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <map>

#include <SDL2\SDL.h>

#include "GameState.hpp"

class Game {
	public:
		Game();
		int Execute();
		static void ChangeState(const std::string State_Name);
		
		bool Init();
		void Exit();

		static SDL_Window* MainWindow;
		static SDL_Renderer* RenderWindow;
		
	private:	
		bool GameRunning;
		
		static GameState* CurrentState;
		
		static std::map<std::string, GameState*> GameStates;
		
};
	
#endif