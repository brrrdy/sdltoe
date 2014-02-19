#include <cmath>

#include "GameBoard.hpp"
#include "Game.hpp"

GameBoard::GameBoard() :
	NoMoves(false),
	_BoardSize(3),
	_ToWin(3),
	_MovesLeft(_BoardSize*_BoardSize)
{
}

GameBoard::GameBoard(int BoardSize, int ToWin) :
	NoMoves(false),
	_BoardSize(BoardSize),
	_ToWin(ToWin),
	_MovesLeft(BoardSize*BoardSize)
{	
}

GameBoard::~GameBoard() {
}

void GameBoard::Update() {
}

void GameBoard::Draw(SDL_Renderer * RenderWindow) {

	// clear render target with white
	SDL_SetRenderDrawColor(RenderWindow, 255, 255, 255, 255);
	SDL_RenderClear(RenderWindow);

	// draw grid lines for tiles in black
	SDL_SetRenderDrawColor(RenderWindow, 0, 0, 0, 255);
	for (int i = 0; i <= _BoardSize; i++) {
		// draw horizontal lines
		SDL_RenderDrawLine(RenderWindow, _BoardArea.x, (_BoardArea.y + (i*_TileSize)), (_BoardArea.x + (_BoardSize*_TileSize)), (_BoardArea.y + (i*_TileSize)));
		
		//draw vertical lines
		SDL_RenderDrawLine(RenderWindow, (_BoardArea.x + (i*_TileSize)), _BoardArea.y, (_BoardArea.x + (i*_TileSize)), (_BoardArea.y + (_BoardSize*_TileSize)));
	}
	
	
	// draw Xs and Is
	for (int i = 0; i < _BoardSize; i++) {
		for (int j = 0; j < _BoardSize; j++) {
			if (Game_Board[i][j] == 1) {
				// Draw an X at i,j
				SDL_RenderDrawLine(RenderWindow, (_BoardArea.x + (j*_TileSize)), (_BoardArea.y + (i*_TileSize)),(_BoardArea.x + ((j+1)*_TileSize)), (_BoardArea.y + ((i+1)*_TileSize)) );
				SDL_RenderDrawLine(RenderWindow, (_BoardArea.x + (j*_TileSize)), (_BoardArea.y + ((i+1)*_TileSize)),(_BoardArea.x + ((j+1)*_TileSize)), (_BoardArea.y + ((i)*_TileSize)) );
			}
			else if (Game_Board[i][j] == 2) {
				// Draw a O at i,j
				SDL_RenderDrawLine(RenderWindow, (_BoardArea.x + (j*_TileSize) + _TileSize/2), (_BoardArea.y + ((i)*_TileSize)),(_BoardArea.x + ((j)*_TileSize) + _TileSize/2), (_BoardArea.y + ((i+1)*_TileSize)) );
			}
		}
	
	}
	
	// draw rendered images!!
	SDL_RenderPresent(RenderWindow);
}

//**********************************
// Initializes the game board object with no argument
//**********************************
void GameBoard::Initialize() {

	InitVec(_BoardSize);
	InitBoardSize(_BoardSize);
	
	std::cout << "Game board initialized." << std::endl;
}

//**********************************
// Initializes the game board object with given board size
//**********************************
void GameBoard::Initialize(int bSize) {

	InitVec(bSize);
	InitBoardSize(bSize);
	
	std::cout << "Game board initialized." << std::endl;
}

//**********************************
// Initializes the game_board 2d vector that
// holds game board information
//**********************************
void GameBoard::InitVec(int bSize) {
	// erase elements from game_board if it is not empty
	if (!Game_Board.empty()) {
		Game_Board.erase(Game_Board.begin(), Game_Board.end());
	}
	
	std::vector<int> row(bSize, 0);
	Game_Board.assign(bSize, row);
} 

//**********************************
// Initializes the tile size and margins based on
// board size and screen size
//**********************************
void GameBoard::InitBoardSize(int bSize) {
	int scrWidth, scrHeight;
	SDL_GetWindowSize(Game::MainWindow, &scrWidth, &scrHeight);
	
	_TileSize = (4*scrHeight)/(5*bSize);
	int xMargin = (scrWidth-(bSize*_TileSize))/2;
	int yMargin = (scrHeight-(bSize*_TileSize))/2;
	_BoardArea = { .x = xMargin, .y = yMargin, .w = bSize*_TileSize, .h = bSize*_TileSize};
}

void GameBoard::HandleClick(SDL_Rect & mPos, int pNum) {
	
	if ( SDL_HasIntersection(&mPos, &_BoardArea) ) {
		int row = (mPos.y - _BoardArea.y)/_TileSize;
		int col = (mPos.x - _BoardArea.x)/_TileSize;
				
				
		if (Game_Board[row][col] == 0) {
			Game_Board[row][col] = pNum;
			_MovesLeft--;
			
			if (_MovesLeft == 0) {
				NoMoves = true;
			}
		}
	}
}

//**************************
// Check each X by X square for winning conditions
// where X is defined by number of squares needed to win.
//**************************
bool GameBoard::CheckWin() {
	int col, row;
	
	for (col = 0; col <= (_BoardSize - _ToWin); col++) {
		for (row = 0; row <= (_BoardSize - _ToWin); row++) {
			bool check = CheckXbyX(col, row);
			if (check != 0) {
				return check;
			}
		}
	}
	
	return false;
}


//**************************
// Check for winning conditions in an X by X vector
// by checking rows, columns, up left to down right diags and
// down left to up right diags.
//**************************
bool GameBoard::CheckXbyX(int row, int col) {
	// check rows
	int checkRow = 0;
	for (int i = row; i < (row+_ToWin); i++) {
		for (int j = col; j < (col+_ToWin); j++) {
			if (Game_Board[i][j] == 1) {
				checkRow++;
			} else if (Game_Board[i][j] == 2) {
				checkRow--;
			}
		}
		if ( abs(checkRow) == _ToWin ) {
			std::cout << "Row victory at " << row << "," << col << std::endl;
			return true;
		}
		checkRow = 0;
	}
	
	// check cols
	int checkCol = 0;
	for (int i = row; i < (row+_ToWin); i++) {
		for (int j = col; j < (col+_ToWin); j++) {
			if (Game_Board[j][i] == 1) {
				checkCol++;
			} else if (Game_Board[j][i] == 2) {
				checkCol--;
			}
		}
		if ( abs(checkCol) == _ToWin ) {
			std::cout << "Col victory at " << row << "," << col << std::endl;
			return true;
		}
		checkCol = 0;
	}
	
	// check up left to down right diag
	int checkUpLDiag = 0;
	//std::cout << "Checking diags at " << col << "," << row << std::endl;
	for (int i = row, j = col; (i < (row+_ToWin)) && (j < (col+_ToWin)); i++, j++) {
		 //std::cout << "Checked: " << i << "," << j << std::endl;
		 
		if (Game_Board[i][j] == 1) {
			checkUpLDiag++;
		} else if (Game_Board[i][j] == 2) {
			checkUpLDiag--;
		}
	}
	if ( abs(checkUpLDiag) == _ToWin ) {
		std::cout << "Diag victory at " << row << "," << col << std::endl;
		return true;
	}
	
	// check down left and up right
	int checkDLDiag = 0;
	//std::cout << "Checking diags at " << col << "," << row << std::endl;
	for (int i = row + (_ToWin - 1), j = col; (i >= row) && (j < (col+_ToWin)); i--, j++) {
		 //std::cout << "Checked: " << i << "," << j << std::endl;
		 
		if (Game_Board[i][j] == 1) {
			checkDLDiag++;
		} else if (Game_Board[i][j] == 2) {
			checkDLDiag--;
		}
	}
	if ( abs(checkDLDiag) == _ToWin ) {
		std::cout << "Diag victory at " << row << "," << col << std::endl;
		return true;
	}
	
	return false;
}
