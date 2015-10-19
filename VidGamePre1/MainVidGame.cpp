#include "MainVidGame.h"

#include <iostream>



MainVidGame::MainVidGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;

}


MainVidGame::~MainVidGame()
{
}


void MainVidGame::run() {
	initSystems();

	gameLoop();

}

void MainVidGame::initSystems(){

	// Init everything
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);

}

void MainVidGame::gameLoop() {

	while (_gameState != GameState::EXIT) {
		processInput();
	}

}

void MainVidGame::processInput() {

	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
			case SDL_QUIT:
				_gameState = GameState::EXIT;
				break;

			case SDL_MOUSEMOTION:
				std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
				break;
		}
	}
	

}
