#ifndef _GAMESTATEPLAYING_H_
#define _GAMESTATEPLAYING_H_

#include <SDL2\SDL.h>

#include <vector>

#include "GameState.hpp"

#define BOARD_SIZE 3

typedef std::pair<int,int> int_pair;

class GameStatePlaying : public GameState {
	public:
		GameStatePlaying();
		~GameStatePlaying();
		
		virtual void Enter();
		virtual void Handle_Event(SDL_Event* Event, bool & Running);
		virtual void Update();
		virtual void Render(SDL_Window* Game_Window);
		virtual void Exit();
		
	private:
		virtual bool Load_Media();
		void Init_Board();
		int Check_Win();
		void Restart_Game();
		
		SDL_Surface* Background;
		SDL_Surface* Board;
		SDL_Surface* XO;
		SDL_Surface* Game_Over_Surface;
		
		SDL_Rect O_Rect;
		SDL_Rect X_Rect;		
		SDL_Rect Yes_Button;
		SDL_Rect No_Button;
		SDL_Rect One_Rect;
		SDL_Rect Two_Rect;
		SDL_Rect Player_Rect;
		SDL_Rect Wins_Rect;
		SDL_Rect PA_Rect;
		
		SDL_Rect Player_Loc;
		SDL_Rect Num_Loc;
		SDL_Rect Wins_Loc;
		SDL_Rect PA_Loc;
		SDL_Rect Yes_Loc;
		SDL_Rect No_Loc;
	
		int Game_Board[BOARD_SIZE][BOARD_SIZE];
		SDL_Rect Board_Rect[BOARD_SIZE][BOARD_SIZE];
		int Tile_Size;
		int Player_Num;
		int Move_Num;
		int Game_Over;
		bool Display_Game_Over;

};

#endif