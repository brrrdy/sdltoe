#include <iostream>
#include <cmath>

#include "GameStatePlaying.hpp"

GameStatePlaying::GameStatePlaying() : 	GameState("Playing"),
										Board_Size(9),
										To_Win(4),
										XO(NULL),
										Game_Over_Surface(NULL),
										Tile_Size(50),
										Border_Width(5),
										xMargin((SCREEN_W-(Board_Size*Tile_Size))/2),
										yMargin((SCREEN_H-(Board_Size*Tile_Size))/2),
										Player_Num(1),
										Move_Num(Board_Size*Board_Size),
										Game_Over(0),
										Display_Game_Over(false)
{ 
	// rect defs
	O_Rect = {.x = 0, .y = 0, .w = Tile_Size, .h = Tile_Size};
	X_Rect = {.x = Tile_Size, .y = 0, .w = Tile_Size, .h = Tile_Size};
	Yes_Button = { .x = 400, .y = 0, .w = 84, .h = 44};
	No_Button = { .x = 484, .y = 0, .w = 84, .h = 44};
	One_Rect ={ .x = 0, .y = 0, .w = 23, .h = 44};
	Two_Rect = { .x = 23, .y = 0, .w = 18, .h = 44};
	Player_Rect = { .x = 41, .y = 0, .w = 94, .h = 44};
	Wins_Rect = { .x = 135, .y = 0, .w = 85, .h = 44};
	PA_Rect = { .x = 220, .y = 0, .w = 175, .h = 44};
	
	Player_Loc = {.x = 150, .y = 550, .w = 94, .h = 44};
	Num_Loc = {.x = 250, .y = 550, .w = 23, .h = 44};
	Wins_Loc = {.x = 275, .y = 550, .w = 85, .h = 44};
	PA_Loc = {.x = 365, .y = 550, .w = 175, .h = 44};
	Yes_Loc = {.x = 550, .y = 550, .w = 84, .h = 44};
	No_Loc = {.x = 640, .y = 550, .w = 84, .h = 44};
	
	Game_Board_Area = {.x = xMargin, .y = yMargin, .w = Board_Size*Tile_Size, .h = Board_Size*Tile_Size};
}

GameStatePlaying::~GameStatePlaying() 
{
}

/*
*****************************************
First pass at victory checking (resolve adjacent moves into vectors, check vector lengths)
*****************************************
Int_Pair slope(Int_Pair ip1, Int_Pair ip2) {
	int rise = ip2.second - ip1.second;
	int run = ip2.first - ip1.first;
	return std::make_pair(run, rise);
}

bool GameStatePlaying::CheckAdjacents(std::vector<Int_Pair_Vec> & Adjacents, Int_Pair ip) {
	std::vector<Int_Pair_Vec>::iterator AdjIt;

	for (AdjIt = Adjacents.begin(); AdjIt != Adjacents.end(); AdjIt++) {
		bool resolve = false;
		if ((resolve = ResolveAdjacents(Adjacents, ip))) {
			return resolve;
		}
		else if (isAdjacent(AdjIt, ip)){
			AdjIt->push_back(ip);
			
			std::cout << "New int pair: [" << ip.first << "," << ip.second << "] added to adjacent vec: ([" << (*AdjIt).front().first << "," << (*AdjIt).front().second << "] - [" << (*AdjIt).back().first << "," << (*AdjIt).back().second << "]." << std::endl;
			
			if (AdjIt->size() == (size_t)To_Win) {
				return true;
			} else {
				return false;
			}
		}
	}
	
	Int_Pair_Vec newAdj(1, ip);
	Adjacents.push_back(newAdj);
	std::cout << "New adjacent vec created from: [" << ip.first << ", " << ip.second << "]" << std::endl;
	return false;
}

bool GameStatePlaying::ResolveAdjacents(std::vector<Int_Pair_Vec> & Adjacents, Int_Pair ip) {
	std::vector<Int_Pair_Vec>::iterator AdjIt1, AdjIt2;
	
	for (AdjIt1 = Adjacents.begin(); AdjIt1 != Adjacents.end(); AdjIt1++) {
		for (AdjIt2 = Adjacents.begin(); AdjIt2 != Adjacents.end(); AdjIt2++) {
			if ( isAdjacent(AdjIt1, ip) && isAdjacent(AdjIt2,ip) ) {
				// If ip completes two one length vecs
				if ( (AdjIt1->size() == 1) && (AdjIt2->size() == 1) ) {
					if (slope(AdjIt1->front(),ip) == slope(ip,AdjIt2->front())) {
						AdjIt1->push_back(ip);
						AdjIt1->insert(AdjIt1->end(), AdjIt2->begin(), AdjIt2->end());
						std::cout << "Resolving completed adjacent vec: ([" << (*AdjIt1).front().first << "," << (*AdjIt1).front().second << "] - [" << (*AdjIt1).back().first << "," << (*AdjIt1).back().second << "]." << std::endl;
						if (AdjIt1->size() == (size_t)To_Win) {
							return true;
						} else {
							return false;
						}
					}
				}
			}
		}
	}
	
	return false;
}

bool GameStatePlaying::isAdjacent(std::vector<Int_Pair_Vec>::iterator AdjIt, Int_Pair ip) {
	int rise, run;
	
	if (AdjIt->size() == 1) {
		// test for adjacency on any side
		if ( (abs((*AdjIt).front().first - ip.first) <= 1) && (abs((*AdjIt).front().second - ip.second) <= 1) ) {
			return true;
		}
	}
	else {
		// find slope
		rise = (*AdjIt)[1].second - (*AdjIt)[0].second;
		run = (*AdjIt)[1].first - (*AdjIt)[0].first;
		
		// test for adjacency at both ends
		if ( ((((*AdjIt).front().first - run) == ip.first) && (((*AdjIt).front().second - rise) == ip.second )) ||
			((((*AdjIt).back().first + run) == ip.first) && (((*AdjIt).back().second + rise) == ip.second )) ) {
		  
			return true;
		}
	}
	return false;
}
*/

//**********************************
// Initializes the game_board 2d vector that
// holds game board information
//**********************************

void GameStatePlaying::InitBoard()
{
	// initialize Game_Board vector
	
	std::vector<int> row(Board_Size, 0);
	Game_Board.assign(Board_Size, row);

	std::cout << "Game board initialized." << std::endl;
}


//**********************************
// Initializes the game_board 2d vector that
// holds game board information
//**********************************
bool GameStatePlaying::LoadMedia(SDL_Renderer* RenderWindow)
{
	bool success = true;
	
	
	// load xo image
	XO = SDL_LoadBMP( "gfx/xo.bmp" );
	// test if xo image was loaded
	if (XO == NULL)
	{
		std::cout << "Unable to load xo image." << std::endl;
		success = false;
	}
	else
	{
		// set transparency 
		SDL_SetColorKey( XO, SDL_TRUE, SDL_MapRGB ( XO->format, 255, 0, 255 ) );
	}
	
	// load gameover image
	Game_Over_Surface = SDL_LoadBMP( "gfx/gameover.bmp" );
	// test if gameover image was loaded
	if (Game_Over_Surface == NULL)
	{
		std::cout << "Unable to load gameover image." << std::endl;
		success = false;
	}
	else
	{
		// set transparency 
		SDL_SetColorKey( Game_Over_Surface, SDL_TRUE, SDL_MapRGB ( Game_Over_Surface->format, 255, 0, 255 ) );
	}
	
	
	return success;
	
}

//**************************
// Check each X by X square for winning conditions
// where X is defined by number of squares needed to win.
//**************************

int GameStatePlaying::CheckWin() {
	int col, row;
	
	for (col = 0; col <= (Board_Size - To_Win); col++) {
		for (row = 0; row <= (Board_Size - To_Win); row++) {
			int check = CheckXbyX(To_Win, col, row);
			if (check != 0) {
				return check;
			}
		}
	}
	
	return 0;
}

//**************************
// Check for winning conditions in an X by X vector
// by checking rows, columns, up left to down right diags and
// down left to up right diags.
//**************************

int GameStatePlaying::CheckXbyX(int x, int col, int row) {

	// check rows
	int checkRow = 0;
	for (int i = row; i < (row+x); i++) {
		for (int j = col; j < (col+x); j++) {
			if (Game_Board[i][j] == 1) {
				checkRow++;
			} else if (Game_Board[i][j] == 2) {
				checkRow--;
			}
		}
		if ( abs(checkRow) == To_Win ) {
			std::cout << "Row victory at " << row << "," << col << std::endl;
			return Player_Num;
		}
		checkRow = 0;
	}
	
	// check cols
	int checkCol = 0;
	for (int i = row; i < (row+x); i++) {
		for (int j = col; j < (col+x); j++) {
			if (Game_Board[j][i] == 1) {
				checkCol++;
			} else if (Game_Board[j][i] == 2) {
				checkCol--;
			}
		}
		if ( abs(checkCol) == To_Win ) {
			std::cout << "Col victory at " << row << "," << col << std::endl;
			return Player_Num;
		}
		checkCol = 0;
	}
	
	// check up row to down right diag
	int checkUpLDiag = 0;
	//std::cout << "Checking diags at " << col << "," << row << std::endl;
	for (int i = row, j = col; (i < (row+x)) && (j < (col+x)); i++, j++) {
		 //std::cout << "Checked: " << i << "," << j << std::endl;
		 
		if (Game_Board[i][j] == 1) {
			checkUpLDiag++;
		} else if (Game_Board[i][j] == 2) {
			checkUpLDiag--;
		}
	}
	if ( abs(checkUpLDiag) == To_Win ) {
		std::cout << "Diag victory at " << row << "," << col << std::endl;
		return Player_Num;
	}
	
	// check down row and up right
	int checkDLDiag = 0;
	//std::cout << "Checking diags at " << col << "," << row << std::endl;
	for (int i = row + (x - 1), j = col; (i >= row) && (j < (col+x)); i--, j++) {
		 //std::cout << "Checked: " << i << "," << j << std::endl;
		 
		if (Game_Board[i][j] == 1) {
			checkDLDiag++;
		} else if (Game_Board[i][j] == 2) {
			checkDLDiag--;
		}
	}
	if ( abs(checkDLDiag) == To_Win ) {
		std::cout << "Diag victory at " << row << "," << col << std::endl;
		return Player_Num;
	}
	
	return 0;
}

//**************************
// Reset the game board and all variables to prepare
// for another game
//**************************
void GameStatePlaying::RestartGame() {
	InitBoard();
	Player_Num = 1;
	Move_Num = Board_Size*Board_Size;
	Game_Over = 0;
	Display_Game_Over = false;
	std::cout << "Game restarting!" << std::endl;

}


//**************************
// Enter state "Playing"
//**************************
void GameStatePlaying::Enter()
{
	std::cout << "Entered game state \"Playing\"." << std::endl;

	InitBoard();

}


//**************************
// Handle events in "Playing"
//**************************
void GameStatePlaying::HandleEvent(SDL_Event * Event, bool & Running)
{
	GameState::HandleEvent(Event, Running);
	
	if (Event->type == SDL_MOUSEBUTTONDOWN) {
	
		int x, y;
		SDL_GetMouseState( &x, &y );
		SDL_Rect mPos = { x, y, 1, 1 };
		std::cout << "mouse click at "<< x <<", " << y << std::endl;
		 
			
		if ( !(Display_Game_Over) ) {
			// Game is in play
			
			// check if click was in game board area
			if (SDL_HasIntersection(&Game_Board_Area, &mPos)) {
			
				int row = (mPos.y - yMargin)/Tile_Size;
				int col = (mPos.x - xMargin)/Tile_Size;
				
				std::cout << "Click detected in tile " << row << ", " << col << std::endl;
				
				if (Game_Board[row][col] == 0) {
					Game_Board[row][col] = Player_Num;
					
					// check if move just won game
					Game_Over = CheckWin();
					
					// switch player turn
					if (Player_Num == 1)
						Player_Num = 2;
					else
						Player_Num = 1;
					
					// decrement # of moves left
					Move_Num--;
					std::cout << "Moves left: " << Move_Num << std::endl;
											
					// output console messages for game end
					if (Move_Num == 0 && Game_Over == 0) {
						std::cout << "Game tied!" << std::endl;
						Display_Game_Over = true;
					}
					else if (Game_Over == 1) {
						std::cout << "Player 1 wins!" << std::endl;
						Display_Game_Over = true;
					}
					else if (Game_Over == 2) {
						std::cout << "Player 2 wins!" << std::endl;
						Display_Game_Over = true;
					}
					else {
						std::cout << "Player " << Player_Num << "\'s turn." << std::endl;
					}
				}
			}
			else if (Display_Game_Over) {
				// Game is over
				// check mPos for clicks on Yes/No buttons
				if (SDL_HasIntersection(&Yes_Loc, &mPos)) {
					// Restart game
					std::cout << "Player clicked yes" << std::endl;
					RestartGame();
				}
				else if (SDL_HasIntersection(&No_Loc, &mPos)) {
					// Exit game
					std::cout << "Player clicked no" << std::endl;
					Running = false;
				}
			}
		}
	}
	
}

//**************************
// Make updates to state "Playing"
//**************************
void GameStatePlaying::Update()
{
	
}

//**************************
// Render state "Playing"
//**************************
void GameStatePlaying::Render(SDL_Renderer* RenderWindow)
{
	// clear render target with white
	SDL_SetRenderDrawColor(RenderWindow, 255, 255, 255, 255);
	SDL_RenderClear(RenderWindow);

	// draw grid lines for tiles in black
	SDL_SetRenderDrawColor(RenderWindow, 0, 0, 0, 255);
	for (int i = 0; i <= Board_Size; i++) {
		// draw horizontal lines
		SDL_RenderDrawLine(RenderWindow, xMargin, (yMargin + (i*Tile_Size)), (xMargin + (Board_Size*Tile_Size)), (yMargin + (i*Tile_Size)));
		
		//draw vertical lines
		SDL_RenderDrawLine(RenderWindow, (xMargin + (i*Tile_Size)), yMargin, (xMargin + (i*Tile_Size)), (yMargin + (Board_Size*Tile_Size)));
	}
	
	
	// draw Xs and Is
	for (int i = 0; i < Board_Size; i++) {
		for (int j = 0; j < Board_Size; j++) {
			if (Game_Board[i][j] == 1) {
				// Draw an X at i,j
				SDL_RenderDrawLine(RenderWindow, (xMargin + (j*Tile_Size)), (yMargin + (i*Tile_Size)),(xMargin + ((j+1)*Tile_Size)), (yMargin + ((i+1)*Tile_Size)) );
				SDL_RenderDrawLine(RenderWindow, (xMargin + (j*Tile_Size)), (yMargin + ((i+1)*Tile_Size)),(xMargin + ((j+1)*Tile_Size)), (yMargin + ((i)*Tile_Size)) );
			}
			else if (Game_Board[i][j] == 2) {
				// Draw a O at i,j
				SDL_RenderDrawLine(RenderWindow, (xMargin + (j*Tile_Size) + Tile_Size/2), (yMargin + ((i)*Tile_Size)),(xMargin + ((j)*Tile_Size) + Tile_Size/2), (yMargin + ((i+1)*Tile_Size)) );
			}
		}
	
	}

	
	
	/*
	// display game over messages
	if (Display_Game_Over) {
		SDL_BlitSurface ( Game_Over_Surface, &PA_Rect, SDL_GetWindowSurface(GameWindow), &PA_Loc );
		SDL_BlitSurface ( Game_Over_Surface, &Yes_Button, SDL_GetWindowSurface(GameWindow), &Yes_Loc );
		SDL_BlitSurface ( Game_Over_Surface, &No_Button, SDL_GetWindowSurface(GameWindow), &No_Loc ); 
		
		if (Game_Over != 0){
			SDL_BlitSurface ( Game_Over_Surface, &Player_Rect, SDL_GetWindowSurface(GameWindow), &Player_Loc );
			SDL_BlitSurface ( Game_Over_Surface, &Wins_Rect, SDL_GetWindowSurface(GameWindow), &Wins_Loc );

		}
		
		if (Game_Over == 1) {
			SDL_BlitSurface ( Game_Over_Surface, &One_Rect, SDL_GetWindowSurface(GameWindow), &Num_Loc );
		} else if (Game_Over == 2) {
			SDL_BlitSurface ( Game_Over_Surface, &Two_Rect, SDL_GetWindowSurface(GameWindow), &Num_Loc );
		}
	}*/
	
	// draw rendered images!!
	SDL_RenderPresent(RenderWindow);
	
}

//**************************
// Exit state "Playing"
//**************************
void GameStatePlaying::Exit()
{
	SDL_FreeSurface ( XO );
	SDL_FreeSurface ( Game_Over_Surface );
	std::cout << "Exiting game state \"Playing\"." << std::endl;
}