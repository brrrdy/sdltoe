#ifndef _GAMESTATESPLASH_H_
#define _GAMESTATESPLASH_H_

#include <SDL2\SDL.h>
#include "GameState.hpp"

class GameStateSplash : public GameState {
	public:
		GameStateSplash();
		~GameStateSplash();
		
		virtual void Enter();
		virtual bool LoadMedia(SDL_Renderer* RenderWindow);
		virtual void HandleEvent(SDL_Event * Event, bool & Running);
		virtual void Update();
		virtual void Render(SDL_Renderer* RenderWindow);
		virtual void Exit();
		
	private:
		
		SDL_Surface* Splash_Screen;

};

#endif