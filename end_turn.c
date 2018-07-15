# include "structures.h"

int End_turn(void)
{	
	Production();	// On lance d'abord la production
	Basic_needs();

	counter.i = 0;

	while(region_selected->pops[counter.i].nb_pops != 0) // Puis les formules de croissance pour toutes les pops de la région
	{	
		Pop_growth();
		Militancy();
		Motion_rand();
		counter.i++;
	}
	return 0;
}

float Pop_growth(void)
{	
	float growth = 0.0002;	// Croissance de base
	
	
	/*
		vic2

		0.0068 par mois France
			0.000226 par jour

		0.013 par mois Japon
			0.000433 par jour

		0.0075 par mois suède
			0.00025 par jour

		0.0195 par mois bavière
			0.00065 par jour

		0.012 par mois iran
			0.0004 par jour

		0.0138 par mois iran
			0.00046 par jour
		
	*/


	/*
		Modif possibles

		si pauvres +
		si pays pauvres +

		si continents + / -

		si musulman + ?

		selon condition de vie (non implémenté)

	*/
	// Calcul de la croissance

	if(region_selected->pops[counter.i].strata == Rich)
	{
		growth += 0.0001;
	}
	else if(region_selected->pops[counter.i].strata == Middle)
	{
		growth += 0.00005;
	}

	if(region_selected->pops[counter.i].basic_needs_filled == 100)
	{
		growth += 0.0001;
	}
	else if(region_selected->pops[counter.i].basic_needs_filled >= 80)
	{
		growth += 0.00005;	
	}
	else if(region_selected->pops[counter.i].basic_needs_filled <= 50)
	{
		growth -= 0.00005;
	}
	else if(region_selected->pops[counter.i].basic_needs_filled <= 30)
	{
		growth -= 0.0001;
	}
	else if(region_selected->pops[counter.i].basic_needs_filled <= 10)
	{	
		growth -= 0.00015;
	}


	counter.random = rand() % 5;	// Lancement d'un rand pour donner un peu d'aléatoire à la croissance

	if(counter.random == 0)
		growth *= 0.8;	
	else if(counter.random == 1)
		growth *= 0.9;	
	else if(counter.random == 3)
		growth *= 1.1;	
	else if(counter.random == 4)
		growth *= 1.2;	
	
	growth *= 15;	// Si on fait par mois et pas par jour
	growth += 1;	// On ajoute 1 pour avoir un vrai multiplicateur

	region_selected->pops[counter.i].nb_pops = region_selected->pops[counter.i].nb_pops * growth;
	return 0;
}

float Militancy(void)
{
	
	if(region_selected->pops[counter.i].basic_needs_filled < 10)
	{
		region_selected->pops[counter.i].militancy += 1;
	}
	else if(region_selected->pops[counter.i].basic_needs_filled < 25)
	{
		region_selected->pops[counter.i].militancy += 0.5;
	}
	else if(region_selected->pops[counter.i].basic_needs_filled < 50)
	{
		region_selected->pops[counter.i].militancy += 0.3;
	}
	else if(region_selected->pops[counter.i].basic_needs_filled < 75)
	{
		region_selected->pops[counter.i].militancy += 0.1;
	}


	if(country_selected->culture != region_selected->pops[counter.i].culture)
	{
		region_selected->pops[counter.i].militancy += 0.1;
	}
	if(country_selected->religion != region_selected->pops[counter.i].religion)
	{
		region_selected->pops[counter.i].militancy += 0.1;
	}
	if(country_selected->ideology != region_selected->pops[counter.i].ideology)
	{
		region_selected->pops[counter.i].militancy += 0.1;
	}


	if(region_selected->pops[counter.i].strata == Rich && country_selected->rich_tax >= 50)
	{
		region_selected->pops[counter.i].militancy += 0.1;
	}
	if(region_selected->pops[counter.i].strata == Middle && country_selected->middle_tax >= 50)
	{
		region_selected->pops[counter.i].militancy += 0.1;
	}
	if(region_selected->pops[counter.i].strata == Poor && country_selected->poor_tax >= 50)
	{
		region_selected->pops[counter.i].militancy += 0.1;
	}
		
	return 0;

}
