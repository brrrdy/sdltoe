#include <iostream>

#include "Game.hpp"
#include "GameStateSplash.hpp"

GameStateSplash::GameStateSplash() : 	GameState("Splash"),
										Splash_Screen(NULL)
{ 

}

GameStateSplash::~GameStateSplash() 
{
}

bool GameStateSplash::Load_Media()
{
	bool success = true;
	
	// load splash image
	Splash_Screen = SDL_LoadBMP( "gfx/splash.bmp" );
	
	// test if splash image was loaded
	if (Splash_Screen == NULL)
	{
		std::cout << "Unable to load Splash screen image." << std::endl;
		success = false;
	}
	
	return success;
	
}

void GameStateSplash::Enter()
{
	std::cout << "Entered game state \"Splash\"." << std::endl;

	// load media, exit state if failed
	if ( !Load_Media() ) 
	 {
		std::cout << "Error loading media." << std::endl;
		Exit();
	 }

}

void GameStateSplash::Handle_Event(SDL_Event * Event, bool & Running)
{
	GameState::Handle_Event(Event, Running);
	
	if (Event->type == SDL_MOUSEBUTTONDOWN) {
		Game::Change_State("Playing");
	}
}

void GameStateSplash::Update()
{
}

void GameStateSplash::Render(SDL_Window* Game_Window)
{
	// blit the splash screen to the window's surface
	SDL_BlitSurface( Splash_Screen, NULL, SDL_GetWindowSurface(Game_Window), NULL );
	
	// update window's surface (final step after blitting images!!)
	SDL_UpdateWindowSurface( Game_Window );
}

void GameStateSplash::Exit()
{
	SDL_FreeSurface( Splash_Screen );
	std::cout << "Exiting game state \"Splash\"." << std::endl;
}