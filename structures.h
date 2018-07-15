#ifndef structures_H
#define structures_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <math.h>

# include <SDL.h>
//# include <SDL_ttf.h>

# include "prototypes.h"

// GAME //
#define NB_GOODS			100
#define NB_REGIONS			4
#define NB_COUNTRIES			3

#define SIZE_POP_TAB   			1000

// SDL //
#define WINDOW_WIDTH			1000	// TAILLE GLOBALE DE LA FENETRE
#define WINDOW_HEIGHT 			950


#define BAR_WIDTH			1000	// TAILLE DE LA BARRE DU HAUT
#define BAR_HEIGHT			200


#define MAP_WIDTH			1200	// TAILLE DE LA MAP
#define MAP_HEIGHT 			1000

#define WINDOW_MAP_WIDTH		800	// TAILLE AFFICHEE DE LA MAP
#define WINDOW_MAP_HEIGHT 		750


#define INTERFACE_WIDTH			1000	// TAILLE DE L'INTERFACE
#define INTERFACE_HEIGHT		750

#define WINDOW_INTERFACE_WIDTH		200	// TAILLE AFFICHEE DE L'INTERFACE
#define WINDOW_INTERFACE_HEIGHT 	750

/*COUNTRIES*/enum{Austria, Italy, Hungary};

/*RELIGIONS*/enum{No_religion, Catholic, Protestant, Jew};
/*CULTURE*/enum{No_culture, Austrian, Hungarian, Italian};
/*IDEOLOGIES*/enum{No_ideology, Liberal, Conservative, Reactionary};

/*STRATA*/enum{No_stata, Rich, Middle, Poor};
/*PROFESSIONS*/enum{No_profession, Capitalist, Noble, Intellectual, Bureaucrat, Soldier, Worker, Artisan, Miner, Laborer};

/*GOODS*/enum{Grain, Rice, Vegetables, Fruits, Meat, Fish, Cacao, Coffee, Tea, Sugar, Metal, Oil};

enum{NO, YES};



typedef struct GOODS_MARKET
{
	char name[25];
	int ID;
	float min_price;
	float price;
	float max_price;
	int quantity;	
}GOODS_MARKET;

GOODS_MARKET goods_market[NB_GOODS];



typedef struct GOODS
{
	char name[25];
	int ID;
	float productivity;
	int quantity_produced;	
}GOODS;

GOODS goods;



typedef struct COMPANIES
{
	int size;
	int workers_capacity;
	int workers_nb;

	GOODS goods;
}COMPANIES;

COMPANIES companies;

	



typedef struct statistics
{
	// RELIGIONS //
	int catholic;
	int protestant;
	int jew;

	// CULTURES //
	int hungarian;
	int austrian;
	int italian;

	// IDEOLOGY //
	int liberal;
	int conservative;
	int reactionary;

	// STRATA //
	int rich_strata;
	int middle_strata;
	int poor_strata;
	
	// PROFESSIONS //
	int capitalist;
	int noble;
	
	int intellectual;
	int bureaucrat;

	int soldier;

	int worker;
	int artisan;

	int miner;
	int laborer;

	// OTHERS //
	int nb_pops;
}statistics;

statistics stats;

typedef struct needs
{
	int ID;
	int base_quantity_needed;
	int total_quantity_needed;
	float filled;
}needs;

needs basic_needs[6];
needs important_needs[9];
needs luxury_needs[6];




typedef struct population
{
	int nb_pops;

	int religion;
	int culture;
	int ideology;

	int strata;
	int profession;
	
	float litteracy;
	float militancy;

	float pops_money_owned;

	// STRUCT NEEDS //
	int basic_needs_nb;
	float basic_needs_filled;

	int important_needs_nb;
	float important_needs_filled;
	
	int luxury_needs_nb;
	float luxury_needs_filled;
	
	needs basic_needs[6];
	needs important_needs[9];
	needs luxury_needs[6];
	
}population;

population pops[SIZE_POP_TAB];



typedef struct country
{
	int ID;
	char name[25];
	
	// MAIN STATS //
	int religion;
	int culture;
	int ideology;

	// MONEY //
	float state_money_owned;
	
	float poor_tax;
	float middle_tax;
	float rich_tax;

	// STRUCT GOODS_MARKET //
	GOODS_MARKET goods_market[NB_GOODS];

	// STRUCT STATS //
	statistics stats;
}country;

country *country_tab[100];
country *country_selected;

country austria;
country hungary;
country italy;

country		*find_country(char *country_to_find, country **country_tab);



typedef struct region
{	
	int ID;
	char name[35];	
	int owner;

	// INFOS //
	int religion;
	int culture;
	
	// MONEY //
	int collected_tax_poor;
	int collected_tax_middle;
	int collected_tax_rich;


	int global_income;

	int capitalist_income;
	int noble_income;
	
	int intellectual_income;
	int bureaucrat_income;

	int soldier_income;

	int worker_income;
	int artisan_income;

	int miner_income;
	int laborer_income;

	// STRUCT POPULATION //
	population pops[SIZE_POP_TAB];

	// STRUCT STATS //
	statistics stats;

	// STRUCT GOODS //
	GOODS goods;

	// STRUCT COMPANIES //
	COMPANIES companies;
}region;

region *region_tab[100];
region *region_selected;

region regionA;
region regionB;
region regionC;
region regionD;

region		*find_region(char *region_to_find, region **region_tab);



typedef struct compteur
{
	int i;
	int j;
	
	int map_x;
	int map_y;
	
	int interface_x;
	int interface_y;
	
	int country_list;
	int region_list;

	int random;
	int turns;
}compteur;

compteur counter;



typedef struct tag
{
	int init_tag;
	int end_turn_tag;
}tag;

tag TAG;

#endif
