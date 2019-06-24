#include "Board.h"

Board::Board()
{
	this->current_x = WIDTH / 2;
	this->current_y = HEIGHT / 2;
	this->current_dir = Haute;
	SDL_Window *window = SDL_CreateWindow("Langton's_ant", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
	SDL_RenderClear(renderer);

	for (int i = 0;i < WIDTH / cell_size;i++)
	{
		for (int j = 0;j < HEIGHT / cell_size;j++)
		{
			plateau[i][j] = new Cell(i * cell_size + 1, j * cell_size + 1);
		}
	}

	SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
	for (size_t i = 0; i < WIDTH; i++)
	{
		SDL_Point point_horizontal[WIDTH];
		for (size_t j = 0; j < HEIGHT; j += cell_size)
		{
			{
				point_horizontal[j].x = i;
				point_horizontal[j].y = j;
			}

		}
		SDL_RenderDrawPoints(renderer, point_horizontal, HEIGHT);

	}
	for (size_t i = 0; i < HEIGHT; i++)
	{
		SDL_Point point_vertical[HEIGHT];
		for (size_t j = 0; j < WIDTH; j += cell_size)
		{

			point_vertical[j].x = j;
			point_vertical[j].y = i;
		}

		SDL_RenderDrawPoints(renderer, point_vertical, WIDTH);

	}

}

void Board::run()
{
	size_t current_iter = iterations;
	while (current_iter > 0)
	{
		SDL_Rect rect = { current_x, current_y,cell_size - 1,cell_size - 1 };
		switch (current_dir)
		{
		case Basse:
			if ((plateau[current_x / cell_size][current_y / cell_size])->couleur == 0)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 255;
				current_x += cell_size;

				current_dir = Droite;
			}

			else
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 0;
				current_x -= cell_size;
				current_dir = Gauche;
			}

			break;
		case Gauche:
			if ((plateau[current_x / cell_size][current_y / cell_size])->couleur == 0)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 255;
				current_y += cell_size;
				current_dir = Basse;
			}

			else
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 0;
				current_y -= cell_size;
				current_dir = Haute;
			}

			break;
		case Droite:
			if ((plateau[current_x / cell_size][current_y / cell_size])->couleur == 0)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 255;
				current_y -= cell_size;
				current_dir = Haute;

			}

			else
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 0;
				current_y += cell_size;
				current_dir = Basse;
			}
			break;
		case Haute:
			if ((plateau[current_x / cell_size][current_y / cell_size])->couleur == 0)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 255;
				current_x -= cell_size;
				current_dir = Gauche;
			}

			else
			{
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
				plateau[current_x / cell_size][current_y / cell_size]->couleur = 0;
				current_x += cell_size;
				current_dir = Droite;

			}
			break;

		default:
			break;
		}
		SDL_RenderFillRect(renderer, &rect);
		SDL_RenderPresent(renderer);
		SDL_Delay(1);
		current_iter--;
	}
}

