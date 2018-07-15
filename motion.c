# include "structures.h"

float Motion_rand(void)
{	
	counter.random = rand() % 100;
	
	if(counter.random <= 32)
	{
		Motion_target_weight();
	}
	
	return 0;
}

float Motion_target_weight(void)
{
	float capitalist_weight = 0;
	float noble_weight = 0;
	
	float intellectual_weight = 0;
	float bureaucrat_weight = 0;

	float soldier_weight = 0;

	float worker_weight = 0;
	float artisan_weight = 0;

	float miner_weight = 0;
	float laborer_weight = 0;
	
	int destination;
	int numbers;

	//float weight_tab[9] = {capitalist_weight, noble_weight, intellectual_weight, bureaucrat_weight, soldier_weight, worker_weight, artisan_weight, miner_weight, laborer_weight};

	/*
		les possibilités des pops
		
		capitalist -> noble, intellectual, bureaucrat, artisan || -/> soldier, miner, laborer, worker
		noble -> capitalist, intellectual, bureaucrat, soldier, worker || -> artisan, miner, laborer

		intellectual -> capitalist, noble, bureaucrat, soldier, worker, miner, laborer || -/> artisan
		bureaucrat -> capitalist, intellectual, soldier, worker, miner, laborer || -/> noble, artisan

		soldier -> capitalist, noble, intellectual, bureaucrat, worker, artisan, miner, laborer

		worker -> capitalist, bureaucrat, soldier, artisan, miner, laborer || -/> noble, intellectual
		artisan -> capitalist, bureaucrat, soldier, worker, miner, laborer || -/> noble, intellectual

		miner -> capitalist, bureaucrat, soldier, worker, artisan || -/> noble, intellectual, laborer
		laborer -> capitalist, bureaucrat, soldier, worker, artisan || -/> noble, intellectual, miner

		
		les pops qui peuvent migrer vers...

		capitalist <- tous le monde - 8
		noble <- capitalist, intellectual, soldier - 3
		
		intellectual <- capitalist, noble, bureaucrat, soldier - 4
		bureaucrat <- tous le monde - 8
		
		soldier <- tous sauf capitalist - 7
		
		worker <- tous sauf capitalist - 7
		artisan <- capitalist, soldier, worker, miner, laborer - 5

		miner <- intellectual, bureaucrat, soldier, worker, artisan - 5
		laborer	<- intellectual, bureaucrat, soldier, worker, artisan - 5
	*/

	if(region_selected->pops[counter.i].profession == Capitalist)
	{
		capitalist_weight = 2;
	}
	else if(region_selected->pops[counter.i].profession == Noble)
	{
		noble_weight = 2;	

		if(region_selected->pops[counter.i].basic_needs_filled == 100)
		{	
			noble_weight += 2;
			laborer_weight -= 3;
		}
		else if(region_selected->pops[counter.i].basic_needs_filled <= 50)
		{
			noble_weight -= 3;
			laborer_weight += 2;
		}	
	}
	else if(region_selected->pops[counter.i].profession == Intellectual)
	{
		intellectual_weight = 3;	
		
	}
	else if(region_selected->pops[counter.i].profession == Bureaucrat)
	{
		bureaucrat_weight = 3;
		
	}
	else if(region_selected->pops[counter.i].profession == Soldier)
	{
		soldier_weight = 3;
		
	}
	else if(region_selected->pops[counter.i].profession == Worker)
	{
		worker_weight = 3;	
		
	}
	else if(region_selected->pops[counter.i].profession == Artisan)
	{
		artisan_weight = 3;
		
	}
	else if(region_selected->pops[counter.i].profession == Miner)
	{
		miner_weight = 3;

		laborer_weight -= 100;
		
	}
	else if(region_selected->pops[counter.i].profession == Laborer)
	{	
	
		laborer_weight = 1;

		miner_weight -= 100;

		if(region_selected->pops[counter.i].basic_needs_filled >= 90)
		{	
			noble_weight += 1;
			laborer_weight -= 2;
		}
		else if(region_selected->pops[counter.i].basic_needs_filled <= 50)
		{
			noble_weight -= 2;
			laborer_weight += 1;
		}

		if(region_selected->pops[counter.i].litteracy >= 25)
		{	
			noble_weight += 1;
		}		
	}



	if(
	capitalist_weight >= noble_weight 
	&& capitalist_weight >= intellectual_weight 
	&& capitalist_weight >= bureaucrat_weight
	&& capitalist_weight >= soldier_weight
	&& capitalist_weight >= worker_weight
	&& capitalist_weight >= artisan_weight
	&& capitalist_weight >= miner_weight
	&& capitalist_weight >= laborer_weight
	&& capitalist_weight != 0)
	{
		destination = Capitalist;
		numbers = capitalist_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	noble_weight >= capitalist_weight 
	&& noble_weight >= intellectual_weight 
	&& noble_weight >= bureaucrat_weight
	&& noble_weight >= soldier_weight
	&& noble_weight >= worker_weight
	&& noble_weight >= artisan_weight
	&& noble_weight >= miner_weight
	&& noble_weight >= laborer_weight
	&& noble_weight != 0)
	{	
		destination = Noble;
		numbers = noble_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	intellectual_weight >= capitalist_weight 
	&& intellectual_weight >= noble_weight 
	&& intellectual_weight >= bureaucrat_weight
	&& intellectual_weight >= soldier_weight
	&& intellectual_weight >= worker_weight
	&& intellectual_weight >= artisan_weight
	&& intellectual_weight >= miner_weight
	&& intellectual_weight >= laborer_weight
	&& intellectual_weight != 0)
	{
		destination = Intellectual;
		numbers = intellectual_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	bureaucrat_weight >= capitalist_weight 
	&& bureaucrat_weight >= noble_weight 
	&& bureaucrat_weight >= intellectual_weight 
	&& bureaucrat_weight >= soldier_weight
	&& bureaucrat_weight >= worker_weight
	&& bureaucrat_weight >= artisan_weight
	&& bureaucrat_weight >= miner_weight
	&& bureaucrat_weight >= laborer_weight
	&& bureaucrat_weight != 0)
	{
		destination = Bureaucrat;	
		numbers = bureaucrat_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	soldier_weight >= capitalist_weight 
	&& soldier_weight >= noble_weight 
	&& soldier_weight >= intellectual_weight 
	&& soldier_weight >= bureaucrat_weight
	&& soldier_weight >= worker_weight
	&& soldier_weight >= artisan_weight
	&& soldier_weight >= miner_weight
	&& soldier_weight >= laborer_weight
	&& soldier_weight != 0)
	{
		destination = Soldier;
		numbers = soldier_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	worker_weight >= capitalist_weight 
	&& worker_weight >= noble_weight 
	&& worker_weight >= intellectual_weight 
	&& worker_weight >= bureaucrat_weight
	&& worker_weight >= soldier_weight
	&& worker_weight >= artisan_weight
	&& worker_weight >= miner_weight
	&& worker_weight >= laborer_weight
	&& worker_weight != 0)
	{
		destination = Worker;
		numbers = worker_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	artisan_weight >= capitalist_weight 
	&& artisan_weight >= noble_weight 
	&& artisan_weight >= intellectual_weight 
	&& artisan_weight >= bureaucrat_weight
	&& artisan_weight >= soldier_weight
	&& artisan_weight >= worker_weight
	&& artisan_weight >= miner_weight
	&& artisan_weight >= laborer_weight
	&& artisan_weight != 0)
	{
		destination = Artisan;
		numbers = artisan_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	miner_weight >= capitalist_weight 
	&& miner_weight >= noble_weight 
	&& miner_weight >= intellectual_weight 
	&& miner_weight >= bureaucrat_weight
	&& miner_weight >= soldier_weight
	&& miner_weight >= worker_weight
	&& miner_weight >= artisan_weight
	&& miner_weight >= laborer_weight
	&& miner_weight != 0)
	{
		destination = Miner;
		numbers = miner_weight;
		Motion_migration(&destination, &numbers);
	}
	else if(
	laborer_weight >= capitalist_weight 
	&& laborer_weight >= noble_weight 
	&& laborer_weight >= intellectual_weight 
	&& laborer_weight >= bureaucrat_weight
	&& laborer_weight >= soldier_weight
	&& laborer_weight >= worker_weight
	&& laborer_weight >= artisan_weight
	&& laborer_weight >= miner_weight
	&& laborer_weight != 0)
	{
		destination = Laborer;
		numbers = laborer_weight;
		Motion_migration(&destination, &numbers);
	}	

	return 0;
}

int Motion_migration(int *profession, int *pops_to_migrate)
{
	int migration_ok = 0;	// Pour savoir si le transfert est bon
	int strata_pops;
	float money_to_move;
	float litteracy_pops;
	float militancy_pops;

	counter.j = 0;	// Pour passer sur d'autres pops

	*pops_to_migrate = *pops_to_migrate / 2;

	*pops_to_migrate = region_selected->pops[counter.i].nb_pops * *pops_to_migrate / 100;	// Calcul du nombre de pops à bouger, en fonction du "weight / 2, %"
	money_to_move = region_selected->pops[counter.i].pops_money_owned / region_selected->pops[counter.i].nb_pops * *pops_to_migrate; // Calcul de l'argent a bougé 
	litteracy_pops = region_selected->pops[counter.i].litteracy;
	militancy_pops = region_selected->pops[counter.i].militancy;


	region_selected->pops[counter.i].nb_pops -= *pops_to_migrate;	// On retire les pops
	region_selected->pops[counter.i].pops_money_owned -= money_to_move;	// On retire l'argent

	if(*profession == Capitalist || *profession == Noble)
	{
		strata_pops = Rich;
	}
	else if(*profession == Intellectual || *profession == Bureaucrat)
	{
		strata_pops = Middle;
	}
	else if(*profession == Soldier || *profession == Worker || *profession == Artisan || *profession == Miner || *profession == Laborer)
	{
		strata_pops = Poor;
	}


	while(migration_ok == 0)
	{
		if(region_selected->pops[counter.i].religion == region_selected->pops[counter.j].religion
		&& region_selected->pops[counter.i].culture == region_selected->pops[counter.j].culture
		&& region_selected->pops[counter.i].ideology == region_selected->pops[counter.j].ideology
		&& strata_pops == region_selected->pops[counter.j].strata
		&& *profession == region_selected->pops[counter.j].profession)
		{
			migration_ok = 1;
			
			// Calcul des deux stats, on laisse une grosse masse qu'on divisera ensuite par les pops totales de la région (on pouvait faire autrement, mais la ligne aurait sautée)
			region_selected->pops[counter.j].litteracy = (region_selected->pops[counter.j].litteracy * region_selected->pops[counter.j].nb_pops) + (*pops_to_migrate * litteracy_pops);
			region_selected->pops[counter.j].militancy = (region_selected->pops[counter.j].militancy * region_selected->pops[counter.j].nb_pops) + (*pops_to_migrate * militancy_pops);
			
			region_selected->pops[counter.j].nb_pops += *pops_to_migrate;
		
			region_selected->pops[counter.j].litteracy = region_selected->pops[counter.j].litteracy / region_selected->pops[counter.j].nb_pops; // On change les deux stats
			region_selected->pops[counter.j].militancy = region_selected->pops[counter.j].militancy / region_selected->pops[counter.j].nb_pops;

			region_selected->pops[counter.j].pops_money_owned += money_to_move;			
		}
		else if(region_selected->pops[counter.j].nb_pops == 0)
		{		
			migration_ok = 1;			
			
			region_selected->pops[counter.j].nb_pops += *pops_to_migrate;
			
			region_selected->pops[counter.j].religion = region_selected->pops[counter.i].religion;
			region_selected->pops[counter.j].culture = region_selected->pops[counter.i].culture;
			region_selected->pops[counter.j].ideology = region_selected->pops[counter.i].ideology;

			region_selected->pops[counter.j].strata = region_selected->pops[counter.i].strata;
			region_selected->pops[counter.j].profession = *profession;

			region_selected->pops[counter.j].litteracy = region_selected->pops[counter.i].litteracy;
			region_selected->pops[counter.j].militancy = region_selected->pops[counter.i].militancy;

			region_selected->pops[counter.j].pops_money_owned = money_to_move;
		}
		counter.j++;
	}
	


	return 0;
}

