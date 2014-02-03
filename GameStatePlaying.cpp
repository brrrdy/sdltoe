#include <iostream>

#include "GameStatePlaying.hpp"

GameStatePlaying::GameStatePlaying() : 	GameState("Playing"),
										Background(NULL),
										Board(NULL),
										XO(NULL),
										Game_Over_Surface(NULL),
										Tile_Size(165),
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
}

GameStatePlaying::~GameStatePlaying() 
{
}

void GameStatePlaying::Init_Board()
{
	// initialize Game_Board array
	for (int i = 0; i < BOARD_SIZE; i++) {		
		for (int j = 0; j < BOARD_SIZE; j++) {
			Game_Board[i][j] = 0;
		}
	}
	
	
	for (int i = 0; i < BOARD_SIZE; i++) {		
		for (int j = 0; j < BOARD_SIZE; j++) {
			Board_Rect[i][j] = { .x = (150 + (i*(Tile_Size+10))), .y = (44 + (j*(Tile_Size+10))), .w = Tile_Size, .h = Tile_Size};
		}
	} 

}

bool GameStatePlaying::Load_Media()
{
	bool success = true;
	
	// load bg image
	Background = SDL_LoadBMP( "gfx/lion.bmp" );
	
	// test if bg image was loaded
	if (Background == NULL)
	{
		std::cout << "Unable to load BG image." << std::endl;
		success = false;
	}
	
	
	// load board image
	Board = SDL_LoadBMP( "gfx/toeboard.bmp" );
	// test if board image was loaded
	if (Board == NULL)
	{
		std::cout << "Unable to load board image." << std::endl;
		success = false;
	}
	else
	{
		// set transparency 
		SDL_SetColorKey( Board, SDL_TRUE, SDL_MapRGB ( Board->format, 255, 0, 255 ) );
	}
	
	
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

int GameStatePlaying::Check_Win() {
	
	// check cols
	for (int i = 0; i < BOARD_SIZE; i++) {
		if ((Game_Board[i][0] == Game_Board[i][1]) && (Game_Board[i][0] == Game_Board[i][2]) ) {
			return Game_Board[i][0];
		}
	}
	
	// check rows
	for (int i = 0; i < BOARD_SIZE; i++) {
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

void GameStatePlaying::Restart_Game() {
	Init_Board();
	Player_Num = 1;
	Move_Num = 9;
	Game_Over = 0;
	Display_Game_Over = false;
	std::cout << "Game restarting!" << std::endl;

}


void GameStatePlaying::Enter()
{
	std::cout << "Entered game state \"Playing\"." << std::endl;

	Init_Board();
	
	for (int i = 0; i < BOARD_SIZE; i++) {		
		for (int j = 0; j < BOARD_SIZE; j++) {
			std::cout << "Board Rect [" << i << "][" << j << "] = " << Board_Rect[i][j].x << ", " << Board_Rect[i][j].y << ", " << Board_Rect[i][j].w << ", " << Board_Rect[i][j].h << std::endl;
		}
	}
	
	// load media, exit state if failed
	if ( !Load_Media() ) 
	 {
		std::cout << "Error loading media. Exiting..." << std::endl;
		Exit();
	 }

}



void GameStatePlaying::Handle_Event(SDL_Event * Event, bool & Running)
{
	GameState::Handle_Event(Event, Running);
	
	if (Event->type == SDL_MOUSEBUTTONDOWN) {
	
		int x, y;
		SDL_GetMouseState( &x, &y );
		SDL_Rect mPos = { x, y, 1, 1 };
		std::cout << "mouse click at "<< x <<", " << y << std::endl;
			
		if ( !(Display_Game_Over) ) {
			// Game is in play
			
			for (int i = 0; i < BOARD_SIZE; i++) {		
				for (int j = 0; j < BOARD_SIZE; j++) {
					if (SDL_HasIntersection(&Board_Rect[i][j], &mPos)) {
						std::cout << "Click detected in tile " << i << ", " << j << std::endl;
						
						if (Game_Board[i][j] == 0) {
							Game_Board[i][j] = Player_Num;
							
							if (Player_Num == 1)
								Player_Num = 2;
							else
								Player_Num = 1;
								
							Move_Num--;
							
							// set boolean value to check if game is over
							Game_Over = Check_Win();
	
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
				}
			}
		} else if (Display_Game_Over) {
			// Game is over
			// check mPos for clicks on Yes/No buttons
			if (SDL_HasIntersection(&Yes_Loc, &mPos)) {
				// Restart game
				std::cout << "Player clicked yes" << std::endl;
				Restart_Game();
			}
			else if (SDL_HasIntersection(&No_Loc, &mPos)) {
				// Exit game
				std::cout << "Player clicked no" << std::endl;
				Running = false;
			}
		}
	}
	
}

void GameStatePlaying::Update()
{
	
}

void GameStatePlaying::Render(SDL_Window* Game_Window)
{

	// blit the bg, board and xo screen to the window's surface
	SDL_BlitSurface( Background, NULL, SDL_GetWindowSurface(Game_Window), NULL );
	SDL_BlitSurface( Board, NULL, SDL_GetWindowSurface(Game_Window), NULL );

	
	for (int i = 0; i < BOARD_SIZE; i++) {		
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (Game_Board[i][j] == 1) {
				SDL_Rect Move_Rect = { Board_Rect[i][j].x, Board_Rect[i][j].y , Tile_Size, Tile_Size };
				SDL_BlitSurface( XO, &O_Rect , SDL_GetWindowSurface(Game_Window), &Move_Rect  );
			}
			
			if (Game_Board[i][j] == 2) {
				SDL_Rect Move_Rect = { Board_Rect[i][j].x, Board_Rect[i][j].y , Tile_Size, Tile_Size };
				SDL_BlitSurface( XO, &X_Rect , SDL_GetWindowSurface(Game_Window), &Move_Rect );
			}
		}
	}
	
	if (Display_Game_Over) {
		SDL_BlitSurface ( Game_Over_Surface, &PA_Rect, SDL_GetWindowSurface(Game_Window), &PA_Loc );
		SDL_BlitSurface ( Game_Over_Surface, &Yes_Button, SDL_GetWindowSurface(Game_Window), &Yes_Loc );
		SDL_BlitSurface ( Game_Over_Surface, &No_Button, SDL_GetWindowSurface(Game_Window), &No_Loc ); 
		
		if (Game_Over != 0){
			SDL_BlitSurface ( Game_Over_Surface, &Player_Rect, SDL_GetWindowSurface(Game_Window), &Player_Loc );
			SDL_BlitSurface ( Game_Over_Surface, &Wins_Rect, SDL_GetWindowSurface(Game_Window), &Wins_Loc );

		}
		
		if (Game_Over == 1) {
			SDL_BlitSurface ( Game_Over_Surface, &One_Rect, SDL_GetWindowSurface(Game_Window), &Num_Loc );
		} else if (Game_Over == 2) {
			SDL_BlitSurface ( Game_Over_Surface, &Two_Rect, SDL_GetWindowSurface(Game_Window), &Num_Loc );
		}
	}
	
	
	// update window's surface (final step after blitting images!!)
	SDL_UpdateWindowSurface( Game_Window );
}

void GameStatePlaying::Exit()
{
	SDL_FreeSurface( Background );
	SDL_FreeSurface( Board );
	SDL_FreeSurface ( XO );
	SDL_FreeSurface ( Game_Over_Surface );
	std::cout << "Exiting game state \"Playing\"." << std::endl;
}