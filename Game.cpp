#include "Game.hpp"
#include "GameState.hpp"
#include "GameStateSplash.hpp"
#include "GameStatePlaying.hpp"

#include <iostream>

Game::Game() : 	Main_Window(NULL),
				Game_Running(false) {
}

int Game::Execute() {
	// check if everything initialized
	if (Init() == false) {
		return -1;
	}
	
	SDL_Event Event;
	
	// create game states
	GameStateSplash * Splash_Ptr = new GameStateSplash();
	GameStatePlaying * Play_Ptr = new GameStatePlaying();
	
	// insert game states into state map
	Game_States.insert(std::make_pair("Splash", Splash_Ptr ));
	Game_States.insert(std::make_pair("Playing", Play_Ptr ));
	
	
	// load first state
	Change_State("Splash");
	
	
	
	//main game loop
	while (Game_Running) {
	
		// process events
		while(SDL_PollEvent(&Event)) {
			Current_State->Handle_Event(&Event, Game_Running);
		}
	
		Current_State->Update();
		
		Current_State->Render(Main_Window);
	}
	
	Exit();
	
	return 0;
}

void Game::Change_State(const std::string State_Name) {
	if (Current_State != NULL) {
		Current_State->Exit();
	}
	
	// find matching state ptr to state_name
	auto state_itr = Game_States.find(State_Name);
	
	// check if state was found...
	if (state_itr != Game_States.end() ) {
		Current_State = state_itr->second;
		Current_State->Enter();
	}
	else {
		std::cout << "Error, state " << State_Name << " not found." << std::endl;
	}

}

bool Game::Init() {
	// initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
		return false;
	}
		
	// open SDL window
	if((Main_Window = SDL_CreateWindow("Tic Tac Toe",
										SDL_WINDOWPOS_UNDEFINED,
										SDL_WINDOWPOS_UNDEFINED,
										800, 600, 
										SDL_WINDOW_OPENGL)
										) == NULL) {
		return false;
	}
		
	// successfully initialized
	std::cout << "Game initialized." << std::endl;
	Game_Running = true;
	return true;
	
}


void Game::Exit() {

	// exit current state
	Current_State->Exit();
	
	
	// clean up state ptrs
	for (auto state_itr = Game_States.begin(); state_itr != Game_States.end(); ++state_itr) {
		delete state_itr->second;
		std::cout << "Deleted state: " << state_itr->first << std::endl;
	}
	
	
	// clean up SDL related resources
	SDL_DestroyWindow( Main_Window);
	SDL_Quit();
	
	std::cout << "Game exiting." << std::endl;
}

GameState* Game::Current_State = NULL;
std::map<std::string, GameState*> Game::Game_States;