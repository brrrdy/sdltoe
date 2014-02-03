#ifndef _GAMESTATE_HPP_
#define _GAMESTATE_HPP_

#include <SDL2\SDL.h>

#include <iostream>


class GameState 
{	
	public:
		GameState();
		virtual ~GameState();
	
		std::string Get_Name();
	
		virtual void Enter();
		virtual void Handle_Event(SDL_Event * Event, bool & Running);
		virtual void Update();
		virtual void Render(SDL_Window* Game_Window);
		virtual void Exit();

	protected:
		GameState(const std::string& GS_Name);
	
		std::string Name;
		
	private:
		virtual bool Load_Media();
				
		
};
#endif