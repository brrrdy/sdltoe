#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include <SDL2\SDL.h>

#include <vector>

#include "GameObject.hpp"

class GameBoard : GameObject {
	public:
		GameBoard();
		GameBoard(int BoardSize, int ToWin);
		virtual ~GameBoard();
		
		virtual void Update();
		virtual void Draw(SDL_Renderer * RenderWindow);
		
		void Initialize();
		void Initialize(int bSize);
		void HandleClick(SDL_Rect & mPos, int pNum);
		bool CheckWin();
		bool NoMoves;
		
	private:
		void InitVec(int bSize);
		void InitBoardSize(int bSize);
		bool CheckXbyX(int row, int col);
	
		std::vector<std::vector<int> > Game_Board;
	
		int _BoardSize;
		int _ToWin;
		int _TileSize;
		int _BorderWidth;
		int _MovesLeft;
		SDL_Rect _BoardArea;
};

#endif