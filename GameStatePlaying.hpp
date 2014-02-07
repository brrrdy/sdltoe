#ifndef _GAMESTATEPLAYING_H_
#define _GAMESTATEPLAYING_H_

#include <SDL2\SDL.h>

#include <vector>

#include "GameState.hpp"

#define SCREEN_W 800
#define SCREEN_H 600

typedef std::pair<int,int> Int_Pair;
typedef std::vector<Int_Pair> Int_Pair_Vec;

class GameStatePlaying : public GameState {
	public:
		GameStatePlaying();
		~GameStatePlaying();
		
		virtual void Enter();
		virtual bool LoadMedia(SDL_Renderer* RenderWindow);
		virtual void HandleEvent(SDL_Event* Event, bool & Running);
		virtual void Update();
		virtual void Render(SDL_Renderer* RenderWindow);
		virtual void Exit();
		
	private:
		void InitBoard();
		int CheckWin();
		int CheckXbyX(int x, int col, int row);
		void RestartGame();	
		//bool CheckAdjacents(std::vector<Int_Pair_Vec> & Adjacents, Int_Pair ip);
		//bool ResolveAdjacents(std::vector<Int_Pair_Vec> & Adjacents, Int_Pair ip);
		//bool isAdjacent(std::vector<Int_Pair_Vec>::iterator AdjIt, Int_Pair ip);
		
		int Board_Size;
		int To_Win;
		//std::vector<Int_Pair_Vec> P1Adjacents;
		//std::vector<Int_Pair_Vec> P2Adjacents;
		
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
		
		SDL_Rect Game_Board_Area;
	
		std::vector<std::vector<int> > Game_Board;
		int Tile_Size;
		int Border_Width;
		int xMargin;
		int yMargin;
		int Player_Num;
		int Move_Num;
		int Game_Over;
		bool Display_Game_Over;

};

#endif