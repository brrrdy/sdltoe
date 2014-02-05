#include <iostream>

#include "GameStatePlaying.hpp"

GameStatePlaying::GameStatePlaying() : 	GameState("Playing"),
										Board_Size(3),
										XO(NULL),
										Game_Over_Surface(NULL),
										Tile_Size(165),
										Border_Width(5),
										xMargin((SCREEN_W-(Board_Size*Tile_Size))/2),
										yMargin((SCREEN_H-(Board_Size*Tile_Size))/2),
										Player_Num(1),
										Move_Num(9),
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

void GameStatePlaying::InitBoard()
{
	// initialize Game_Board vector
	for (int i = 0; i < Board_Size; i++) {
	
		// create temp vector for each column
		std::vector<int> Col;
		
		// fill each col
		for (int j = 0; j < Board_Size; j++) {
			Col.push_back(0);
		}
		
		// push each column onto game board
		Game_Board.push_back(Col);
	}

	std::cout << "Game board initialized." << std::endl;
}

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

int GameStatePlaying::CheckWin() {
	
	// check cols
	for (int i = 0; i < Board_Size; i++) {
		if ((Game_Board[i][0] == Game_Board[i][1]) && (Game_Board[i][0] == Game_Board[i][2]) ) {
			return Game_Board[i][0];
		}
	}
	
	// check rows
	for (int i = 0; i < Board_Size; i++) {
		if ((Game_Board[0][i] == Game_Board[1][i]) && (Game_Board[0][i] == Game_Board[2][i]) ) {
			return Game_Board[0][i];
		}
	}
	
	// check diagonals
	if ( (Game_Board[0][0] == Game_Board[1][1]) && (Game_Board[0][0] == Game_Board [2][2]) )
		return Game_Board[0][0];
	
	if ( (Game_Board[2][0] == Game_Board[1][1]) && (Game_Board[2][0] == Game_Board[0][2]) )
		return Game_Board[2][0];
	
	return 0;
}

void GameStatePlaying::RestartGame() {
	InitBoard();
	Player_Num = 1;
	Move_Num = 9;
	Game_Over = 0;
	Display_Game_Over = false;
	std::cout << "Game restarting!" << std::endl;

}


void GameStatePlaying::Enter()
{
	std::cout << "Entered game state \"Playing\"." << std::endl;

	InitBoard();

}



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
					
					if (Player_Num == 1)
						Player_Num = 2;
					else
						Player_Num = 1;
						
					Move_Num--;
					
					// set boolean value to check if game is over
					Game_Over = CheckWin();

					std::cout << "Moves left: " << Move_Num << std::endl;
											
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

void GameStatePlaying::Update()
{
	
}

void GameStatePlaying::Render(SDL_Renderer* RenderWindow)
{


	// draw grid lines for tiles
	
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
	}
	
	
	// clear render target
	SDL_SetRenderDrawColor(RenderWindow, 255, 255, 255, 255);
	SDL_RenderClear(RenderWindow);
	
	// draw rendered images!!
	SDL_RenderPresent(RenderWindow);
	
}

void GameStatePlaying::Exit()
{
	SDL_FreeSurface ( XO );
	SDL_FreeSurface ( Game_Over_Surface );
	std::cout << "Exiting game state \"Playing\"." << std::endl;
}