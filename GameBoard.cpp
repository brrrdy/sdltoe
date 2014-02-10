#include "GameBoard.hpp"
#include "Game.hpp"

GameBoard::GameBoard() :
	_BoardSize(3),
	_ToWin(3),
	_MovesLeft(BoardSize*BoardSize)
{
}

GameBoard::GameBoard(int BoardSize, int ToWin) :
	_BoardSize(BoardSize),
	_ToWin(ToWin),
	_MovesLeft(BoardSize*BoardSize) 
{
	int scrWidth, scrHeight;
	SDL_GetWindowSize(Game::MainWindow, scrWidth, scrHeight);
	
	
}

GameBoard::~GameBoard() {
}

void GameBoard::Update() {
}

void GameBoard::Draw(SDL_Renderer * RenderWindow) {
}

//**********************************
// Initializes the game board object
//**********************************
void GameBoard::Initialize(int _BoardSize) {

	InitVec();
	InitBoardSize();
	
	std::cout << "Game board initialized." << std::endl;
}

//**********************************
// Initializes the game_board 2d vector that
// holds game board information
//**********************************
void GameBoard::InitVec() {
	
	std::vector<int> row(_BoardSize, 0);
	Game_Board.assign(_BoardSize, row);
} 

//**********************************
// Initializes the tile size and margins based on
// board size and screen size
//**********************************
void GameBoard::InitBoardSize() {
	
}

void GameBoard::HandleClick(SDL_Rect & mPos) {
}

bool GameBoard::IsGameOver() {
}


//**************************
// Check each X by X square for winning conditions
// where X is defined by number of squares needed to win.
//**************************
bool GameBoard::CheckWin() {
	int col, row;
	
	for (col = 0; col <= (BoardSize - ToWin); col++) {
		for (row = 0; row <= (BoardSize - ToWin); row++) {
			bool check = CheckXbyX(ToWin, col, row);
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
bool GameBoard::CheckXbyX(int x, int row, int col) {
	// check rows
	int checkRow = 0;
	for (int i = row; i < (row+x); i++) {
		for (int j = col; j < (col+x); j++) {
			if (GameBoard[i][j] == 1) {
				checkRow++;
			} else if (GameBoard[i][j] == 2) {
				checkRow--;
			}
		}
		if ( abs(checkRow) == To_Win ) {
			std::cout << "Row victory at " << row << "," << col << std::endl;
			return true;
		}
		checkRow = 0;
	}
	
	// check cols
	int checkCol = 0;
	for (int i = row; i < (row+x); i++) {
		for (int j = col; j < (col+x); j++) {
			if (GameBoard[j][i] == 1) {
				checkCol++;
			} else if (GameBoard[j][i] == 2) {
				checkCol--;
			}
		}
		if ( abs(checkCol) == To_Win ) {
			std::cout << "Col victory at " << row << "," << col << std::endl;
			return true;
		}
		checkCol = 0;
	}
	
	// check up left to down right diag
	int checkUpLDiag = 0;
	//std::cout << "Checking diags at " << col << "," << row << std::endl;
	for (int i = row, j = col; (i < (row+x)) && (j < (col+x)); i++, j++) {
		 //std::cout << "Checked: " << i << "," << j << std::endl;
		 
		if (GameBoard[i][j] == 1) {
			checkUpLDiag++;
		} else if (GameBoard[i][j] == 2) {
			checkUpLDiag--;
		}
	}
	if ( abs(checkUpLDiag) == To_Win ) {
		std::cout << "Diag victory at " << row << "," << col << std::endl;
		return true;
	}
	
	// check down left and up right
	int checkDLDiag = 0;
	//std::cout << "Checking diags at " << col << "," << row << std::endl;
	for (int i = row + (x - 1), j = col; (i >= row) && (j < (col+x)); i--, j++) {
		 //std::cout << "Checked: " << i << "," << j << std::endl;
		 
		if (GameBoard[i][j] == 1) {
			checkDLDiag++;
		} else if (GameBoard[i][j] == 2) {
			checkDLDiag--;
		}
	}
	if ( abs(checkDLDiag) == To_Win ) {
		std::cout << "Diag victory at " << row << "," << col << std::endl;
		return true;
	}
}
