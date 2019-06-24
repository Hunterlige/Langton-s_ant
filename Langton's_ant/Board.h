
#ifndef H_GAME
#define H_GAME
#include <SDL.h>
#include "Cell.h"

const size_t WIDTH = 900;
const size_t HEIGHT = 1000;
const size_t iterations = 12500;
const size_t cell_size = 6;


enum direction
{
	Basse,
	Gauche,
	Droite,
	Haute
};
class Board
{
private:
	int current_y;
	int current_x;
	direction current_dir;
	SDL_Renderer *renderer;
	Cell* plateau[WIDTH / cell_size][HEIGHT / cell_size];

public:
	Board();
	void run();


};

#endif