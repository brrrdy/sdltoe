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

bool GameStateSplash::LoadMedia(SDL_Renderer* RenderWindow)
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

}

void GameStateSplash::HandleEvent(SDL_Event * Event, bool & Running)
{
	GameState::HandleEvent(Event, Running);
	
	if (Event->type == SDL_MOUSEBUTTONDOWN) {
		Game::ChangeState("Playing");
	}
}

void GameStateSplash::Update()
{
}

void GameStateSplash::Render(SDL_Renderer* RenderWindow)
{
	// blit the splash screen to the window's surface
	SDL_BlitSurface( Splash_Screen, NULL, SDL_GetWindowSurface(GameWindow), NULL );
	
	// update window's surface (final step after blitting images!!)
	SDL_UpdateWindowSurface( GameWindow );
}

void GameStateSplash::Exit()
{
	SDL_FreeSurface( Splash_Screen );
	std::cout << "Exiting game state \"Splash\"." << std::endl;
}