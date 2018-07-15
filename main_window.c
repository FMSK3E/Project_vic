# include "structures.h"

void Main_menu(SDL_Window *main_window, SDL_Surface *black_screen, SDL_Surface *map, SDL_Surface *interface, SDL_Renderer *renderer, SDL_Texture *texture)
{

    	SDL_bool window = SDL_TRUE;
    	SDL_Event event;

    	int quit = 0;
	int move_order; // 1 INTERFACE - 0 MAP	
	int mouse_x; int mouse_y;
 
	while (window)
	{
		TAG.end_turn_tag = NO;	
		SDL_WaitEvent(&event);
        	switch(event.type)
       		{
            		case SDL_QUIT:
                	window = SDL_FALSE;
                	quit = 1;
                	break;
			
            		case SDL_KEYDOWN:       
				SDL_PumpEvents();
				SDL_GetMouseState(&mouse_x, &mouse_y);

              			switch(event.key.keysym.sym)
                		{
                			case SDLK_ESCAPE:
                       			window = SDL_FALSE;
                        		quit = 1;
                       			break;

                    			case SDLK_DOWN: 
						if(mouse_x < WINDOW_MAP_WIDTH)
						{
							move_order = 0;
							counter.map_y -= 125;  

							if(counter.map_y < WINDOW_MAP_HEIGHT - MAP_HEIGHT)
							{
								counter.map_y += 125;
							} 
						}
						else
						{ 
							move_order = 1;
							counter.interface_y -= 125;  

							if(counter.interface_y < WINDOW_INTERFACE_HEIGHT - INTERFACE_HEIGHT)
							{
								counter.interface_y += 125;
							} 
		                                }   
					  
                        		break;

                    			case SDLK_UP: 
						if(mouse_x < WINDOW_MAP_WIDTH)
						{
							move_order = 0;
							counter.map_y += 125;  

							if(counter.map_y > 0)
							{
								counter.map_y -= 125;
							}  
						}
						else
						{ 
							move_order = 1;
							counter.interface_y += 125;  

							if(counter.interface_y > 0)
							{
								counter.interface_y -= 125;
							}  
		       				}
					
                        		break;

                    			case SDLK_LEFT: 
						if(mouse_x < WINDOW_MAP_WIDTH)
						{
							move_order = 0;
							counter.map_x += 100;

							if(counter.map_x > 0)
							{
								counter.map_x -= 100;
							}
						}
						else
						{   
							move_order = 1;
							counter.interface_x -= 200; 

							if(counter.interface_x < WINDOW_WIDTH - INTERFACE_WIDTH)
							{
								counter.interface_x += 200;
							}   
						}   
					                            
                       			break;
	
                    			case SDLK_RIGHT:
						if(mouse_x < WINDOW_MAP_WIDTH)
						{
							move_order = 0;
							counter.map_x -= 100; 

							if(counter.map_x < WINDOW_MAP_WIDTH - MAP_WIDTH)
							{
								counter.map_x += 100;
							} 
						}
						else
						{
							move_order = 1;
							counter.interface_x += 200;

							if(counter.interface_x > WINDOW_WIDTH - WINDOW_INTERFACE_WIDTH)
							{
								counter.interface_x -= 200;
							}    
						}  
					                                
                        		break;
               			}
			case SDL_MOUSEBUTTONDOWN: 
				SDL_PumpEvents();
				SDL_GetMouseState(&mouse_x, &mouse_y);

				if(mouse_x < WINDOW_MAP_WIDTH && mouse_y > BAR_HEIGHT)
				{
					event.motion.x -= counter.map_x;
					event.motion.y -= BAR_HEIGHT;

					if(event.motion.x <= 100)
					{
						//printf("KEKO\t");
						//printf("%d\n", event.motion.x);
					}
					else if(event.motion.x >= 100 && event.motion.x <= 200)
					{
						//printf("KEK\t");
						//printf("%d\n", event.motion.x);
					}
				}
				else
				{	
					event.motion.x -= WINDOW_MAP_WIDTH - counter.interface_x;
					event.motion.y -= BAR_HEIGHT;

					if(event.motion.x <= 200)	//COUNTRIES
					{	
						if(event.motion.y <= 250)
						{
							country_selected = &austria;
						}
						else if(event.motion.y >= 250 && event.motion.y <= 500)
						{
							country_selected = &hungary;
						}
						else if(event.motion.y >= 500 && event.motion.y <= 750)	
						{
							country_selected = &italy;
						}
					}
					else if(event.motion.x <= 400)	// REGIONS
					{	
						if(event.motion.y <= 250)
						{
							region_selected = &regionA;
						}
						else if(event.motion.y >= 250 && event.motion.y <= 500)
						{
							printf("regionE\n");
						}
						else if(event.motion.y >= 500 && event.motion.y <= 750)	
						{
							printf("%d pops\n", region_selected->pops[counter.i].nb_pops);
							printf("%g lit\n", region_selected->pops[counter.i].litteracy);
							printf("%g mil\n", region_selected->pops[counter.i].militancy);
							printf("%g money\n", region_selected->pops[counter.i].pops_money_owned);
							printf("%g needs\n\n", region_selected->pops[counter.i].basic_needs_filled);
						}				
					}
					else if(event.motion.x <= 600)
					{	
						if(event.motion.y <= 250)
						{
							region_selected = &regionB;
						}
						else if(event.motion.y >= 250 && event.motion.y <= 500)
						{
							printf("regionF\n");
						}
						else if(event.motion.y >= 500 && event.motion.y <= 750)
						{	
							if(event.motion.x <= 900 && event.motion.y <= 625)
							{
								counter.i = 0;
								printf("%d\n", counter.i);
							}
							else if(event.motion.x >= 900 && event.motion.y <= 625)
							{
								counter.i = 1;
								printf("%d\n", counter.i);
							}
							else if(event.motion.x <= 900 && event.motion.y >= 625)
							{
								counter.i = 2;
								printf("%d\n", counter.i);
							}
							else if(event.motion.x <= 900 && event.motion.y <= 625)
							{
								counter.i = 3;
								printf("%d\n", counter.i);
							}
						}
					}
					else if(event.motion.x <= 800)
					{	
						if(event.motion.y <= 250)
						{
							region_selected = &regionC;
						}
						else if(event.motion.y >= 250 && event.motion.y <= 500)
						{
							printf("regionG\n");
						}
						else if(event.motion.y >= 500 && event.motion.y <= 750)
						{	
							if(event.motion.x <= 900)
							{
								Print_country_stats();
								printf("%f state money\n", country_selected->state_money_owned);
							}
							else if(event.motion.x >= 900)
							{
								Print_region_stats();
							}
						}
					}
					else if(event.motion.x <= 1000)
					{	
						if(event.motion.y <= 250)
						{
							region_selected = &regionD;
						}
						else if(event.motion.y >= 250 && event.motion.y <= 500)
						{
							printf("regionH\n");
						}
						else if(event.motion.y >= 500 && event.motion.y <= 750)
						{	
							if(event.motion.x <= 900)
							{
								TAG.end_turn_tag = YES;
								counter.turns++;	
								Country_finder();
								TAG.end_turn_tag = NO;
							}
							else if(event.motion.x >= 900)
							{
								SDL_DestroyRenderer(renderer);
								SDL_Quit();
								exit(0);
							}
						}
					}
				}
  
				if (quit == 0)
				{	
					Move_order(main_window, black_screen, map, interface, renderer, texture, &move_order);
					//printf("%dx, %dy MAP\n", counter.map_x, counter.map_y);
					//printf("%dx, %dy INTERFACE\n", counter.interface_x, counter.interface_y);

				    	// Mettre les autres trucs qui arrivent ici  
				}  	    
		}       
	}
}

void Move_order(SDL_Window *main_window, SDL_Surface *bar, SDL_Surface *map, SDL_Surface *interface, SDL_Renderer *renderer, SDL_Texture *texture, int *move_order)
{
	if(*move_order == 1)	// INTERFACE
	{
		Move_interface(main_window, interface, renderer, texture);
	}
	else if(*move_order == 0)	// MAP
	{	
		Move_map(main_window, map, renderer, texture);		
		Move_interface(main_window, interface, renderer, texture);		
	}
}

void Move_map(SDL_Window *main_window, SDL_Surface *map, SDL_Renderer *renderer, SDL_Texture *texture)
{	
	//SDL_Rect map_rect = {counter.map_x, BAR_HEIGHT + counter.map_y, MAP_WIDTH, MAP_HEIGHT};
	SDL_Rect map_rect = {0 - counter.map_x, 0 - counter.map_y, MAP_WIDTH, MAP_HEIGHT};
	SDL_Rect new_rect = {0, BAR_HEIGHT, MAP_WIDTH + counter.map_x, MAP_HEIGHT + counter.map_y};
	

	map = SDL_LoadBMP("pictures/map.bmp");
   	texture = SDL_CreateTextureFromSurface(renderer, map);
	
	if (texture == NULL)
	{
		SDL_exit_with_error("Texture map fail");
	} 
 
	SDL_RenderCopyEx(renderer, texture, &map_rect, &new_rect, 0, NULL, SDL_FLIP_NONE);

	//SDL_RenderCopy(renderer, texture, NULL, &map_rect);
   	SDL_RenderPresent(renderer);

	SDL_FreeSurface(map);	
	SDL_DestroyTexture(texture);
}

void Move_interface(SDL_Window *main_window, SDL_Surface *interface, SDL_Renderer *renderer, SDL_Texture *texture)
{	
	SDL_Rect interface_rect = {counter.interface_x, 0, INTERFACE_WIDTH, INTERFACE_HEIGHT};
	SDL_Rect new_rect = {WINDOW_MAP_WIDTH, BAR_HEIGHT, INTERFACE_WIDTH - counter.interface_x, INTERFACE_HEIGHT};
	
	interface = SDL_LoadBMP("pictures/main_screen.bmp");
   	texture = SDL_CreateTextureFromSurface(renderer, interface);
	
	if (texture == NULL)
	{
		SDL_exit_with_error("Texture interface fail");
	}  	
	
	SDL_RenderCopyEx(renderer, texture, &interface_rect, &new_rect, 0, NULL, SDL_FLIP_NONE);
   	SDL_RenderPresent(renderer);

	SDL_FreeSurface(interface);
	SDL_DestroyTexture(texture);
}

void Move_bar(SDL_Window *main_window, SDL_Surface *bar, SDL_Renderer *renderer, SDL_Texture *texture)
{      
	SDL_Rect bar_rect = {0, 0, BAR_WIDTH, BAR_HEIGHT};

    	bar = SDL_LoadBMP("pictures/bar.bmp");
    	texture = SDL_CreateTextureFromSurface(renderer, bar);

	if (texture == NULL)
	{
		SDL_exit_with_error("Texture bar fail");
	}

   	SDL_RenderCopy(renderer, texture, NULL, &bar_rect);
    	SDL_RenderPresent(renderer);

	SDL_FreeSurface(bar);
	SDL_DestroyTexture(texture);
}







