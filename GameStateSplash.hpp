#ifndef _GAMESTATESPLASH_H_
#define _GAMESTATESPLASH_H_

#include <SDL2\SDL.h>
#include "GameState.hpp"

class GameStateSplash : public GameState {
	public:
		GameStateSplash();
		~GameStateSplash();
		
		virtual void Enter();
		virtual void Handle_Event(SDL_Event * Event, bool & Running);
		virtual void Update();
		virtual void Render(SDL_Window* Game_Window);
		virtual void Exit();
		
	private:
		virtual bool Load_Media();
		
		SDL_Surface* Splash_Screen;

};

#endif