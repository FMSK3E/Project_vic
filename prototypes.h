#ifndef prototypes_H
#define prototypes_H

# include "structures.h"


void SDL_exit_with_error(const char *message);

// FINDER //
int Country_finder(void);
int Country_finder_manual(void);
int Region_finder(void);
int Region_finder_manual(void);

// INIT //
int Init(void);
	int Init_countries(void);
	int Init_goods_market(void);
	int Init_regions(void);
		int Init_regionA(void);
		int Init_regionB(void);
		int Init_regionC(void);
		int Init_regionD(void);

// NEEDS //
int Define_needs(void);
int Basic_needs(void);

// SDL //	
void Main_menu(SDL_Window *main_window, SDL_Surface *black_screen, SDL_Surface *map, SDL_Surface *interface, SDL_Renderer *renderer, SDL_Texture *texture);
void Move_order(SDL_Window *main_window, SDL_Surface *bar, SDL_Surface *map, SDL_Surface *interface, SDL_Renderer *renderer, SDL_Texture *texture, int *move_order);
	void Move_map(SDL_Window *main_window, SDL_Surface *map, SDL_Renderer *renderer, SDL_Texture *texture);
	void Move_interface(SDL_Window *main_window, SDL_Surface *interface, SDL_Renderer *renderer, SDL_Texture *texture);
	void Move_bar(SDL_Window *main_window, SDL_Surface *bar, SDL_Renderer *renderer, SDL_Texture *texture);

// STATS //
int Reset_country(void);
int Actualisation_country(void);

int Reset_region(void);
int Actualisation_region(void);

// AFFICHAGE //
int Print_region_stats(void);
int Print_country_stats(void);

// TURN //
int End_turn(void);

int Production(void);
int Salary(void);
float Pop_growth(void);
float Militancy(void);

// MOTION // 

float Motion_rand(void);
	float Motion_target_weight(void);
	int Motion_migration(int *profession, int *pops_to_migrate);


#endif
