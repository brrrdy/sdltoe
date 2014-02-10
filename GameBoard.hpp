#ifndef _GAMEBOARD_H_
#define _GAMEBOARD_H_

#include "GameObject.hpp"

class GameBoard : GameObject {
	public:
		GameBoard();
		GameBoard(int BoardSize, int ToWin, int TileSize, int BorderWidth, int xMargin, int yMargin);
		virtual ~GameBoard();
		
		virtual void Update();
		virtual void Draw(SDL_Renderer * RenderWindow);
		
		void Initialize();
		void HandleClick(SDL_Rect & mPos);
		bool IsGameOver();
		bool CheckWin();
		bool CheckXbyX(int x, int row, int col);
		SDL_Rect GetArea();
		
	private:
		void InitVec();
		void InitBoardSize();
	
		std::vector<std::vector<int> > Game_Board;
	
		int _BoardSize;
		int _ToWin;
		int _TileSize;
		int _BorderWidth;
		int _xMargin;
		int _yMargin;
		int _MovesLeft;
};

#endif