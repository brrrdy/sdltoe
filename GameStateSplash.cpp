#include <iostream>

#include "Game.hpp"
#include "GameStateSplash.hpp"

GameStateSplash::GameStateSplash() : 	GameState("Splash"),
										Screen_Texture(NULL)
{ 

}

GameStateSplash::~GameStateSplash() 
{
}

bool GameStateSplash::LoadMedia(SDL_Renderer* RenderWindow)
{
	bool success = true;
	
	// load splash image
	SDL_Surface * Splash_Screen = SDL_LoadBMP( "gfx/splash.bmp" );
	// test if splash image was loaded
	if (Splash_Screen == NULL)
	{
		std::cout << "Unable to load Splash screen image.\n" << SDL_GetError() << std::endl;
		success = false;
	}

	// create screen texture from splash screen surface
	Screen_Texture = SDL_CreateTextureFromSurface(RenderWindow, Splash_Screen);	
	// test if texture was created
	if (Screen_Texture == NULL) {
		std::cout << "Unable to generate screen texture.\n" << SDL_GetError() << std::endl;
		success = false;
	}

	SDL_FreeSurface(Splash_Screen);
	
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
	// clear renderer
	SDL_RenderClear(RenderWindow);
	// copy the screen texture to the renderer
	SDL_RenderCopy(RenderWindow, Screen_Texture, NULL, NULL);
	// present rendered changes
	SDL_RenderPresent(RenderWindow);

}

void GameStateSplash::Exit()
{
	std::cout << "Exiting game state \"Splash\"." << std::endl;
}