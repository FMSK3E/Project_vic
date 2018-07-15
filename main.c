# include "structures.h"

int main(int argc, char **argv)
{	
	srand(time(NULL));	
	
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS);
	//TTF_Init();	

	Init();

	SDL_Window *main_window = NULL;
	
	main_window = SDL_CreateWindow("Game",
				SDL_WINDOWPOS_CENTERED,   
				SDL_WINDOWPOS_CENTERED,    
			  	WINDOW_WIDTH, 		   
			 	WINDOW_HEIGHT, 			
				SDL_WINDOW_BORDERLESS);
	if (main_window == NULL)
	{
		SDL_exit_with_error("Texture window fail");
	} 
	
	counter.map_x = 0;
	counter.map_y = 0; 
	
	counter.interface_x = 0;
	counter.interface_y = 0;
	
	//////////////////////////////////////	MAP //

	SDL_Rect map_rect = {0, BAR_HEIGHT, MAP_WIDTH, MAP_HEIGHT};

	SDL_Surface * map = SDL_LoadBMP("pictures/map.bmp");
    	SDL_Renderer * renderer = SDL_CreateRenderer(main_window, -1, 0);
   	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, map);
	
	if (texture == NULL)
	{
		SDL_exit_with_error("Texture map fail");
	}  
	
	SDL_RenderCopy(renderer, texture, NULL, &map_rect);
   	SDL_RenderPresent(renderer);

	SDL_FreeSurface(map);
	SDL_DestroyTexture(texture);

	//////////////////////////////////////	INTERFACE //

	SDL_Rect interface_rect = {WINDOW_MAP_WIDTH, BAR_HEIGHT, INTERFACE_WIDTH, INTERFACE_HEIGHT};

	SDL_Surface * interface = SDL_LoadBMP("pictures/main_screen.bmp");
   	texture = SDL_CreateTextureFromSurface(renderer, interface);
	
	if (texture == NULL)
	{
		SDL_exit_with_error("Texture interface fail");
	}  
	
	SDL_RenderCopy(renderer, texture, NULL, &interface_rect);
   	SDL_RenderPresent(renderer);

	SDL_FreeSurface(interface);
	SDL_DestroyTexture(texture);

	//////////////////////////////////////	BAR //

	SDL_Rect bar_rect = {0, 0, BAR_WIDTH, BAR_HEIGHT};

	SDL_Surface * bar = SDL_LoadBMP("pictures/bar.bmp");
   	texture = SDL_CreateTextureFromSurface(renderer, bar);
	
	if (texture == NULL)
	{
		SDL_exit_with_error("Texture bar fail");
	}  
	
	SDL_RenderCopy(renderer, texture, NULL, &bar_rect);
   	SDL_RenderPresent(renderer);

	SDL_FreeSurface(bar);
	SDL_DestroyTexture(texture);

	//////////////////////////////////////

	Main_menu(main_window, bar, map, interface, renderer, texture);
	
	SDL_DestroyRenderer(renderer);
	//TTF_Quit();
	SDL_Quit();
	
	return 0;
}

void SDL_exit_with_error(const char *message)
{
	SDL_Log("Erreur : %s -> %s\n", message, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}
/*
gcc -o myprogram myprogram.c `sdl2-config --cflags --libs`
gcc -o projet *.c `sdl2-config --cflags --libs` -lSDL2main -lSDL2 -lSDL2_ttf
./projet
*/
