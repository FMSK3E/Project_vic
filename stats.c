# include "structures.h"

int Reset_country(void)
{	
	// RELIGIONS //
	country_selected->stats.catholic = 0;
	country_selected->stats.protestant = 0;
	country_selected->stats.jew = 0;

	// CULTURES //
	country_selected->stats.hungarian = 0;
	country_selected->stats.austrian = 0;
	country_selected->stats.italian = 0;

	// IDEOLOGY //
	country_selected->stats.liberal = 0;
	country_selected->stats.conservative = 0;
	country_selected->stats.reactionary = 0;

	// STRATA //
	country_selected->stats.rich_strata = 0;
	country_selected->stats.middle_strata = 0;
	country_selected->stats.poor_strata = 0;
	
	// PROFESSIONS //
	country_selected->stats.capitalist = 0;
	country_selected->stats.noble = 0;
	
	country_selected->stats.intellectual = 0;
	country_selected->stats.bureaucrat = 0;

	country_selected->stats.soldier = 0;

	country_selected->stats.worker = 0;
	country_selected->stats.artisan = 0;

	country_selected->stats.miner = 0;
	country_selected->stats.laborer = 0;

	// OTHERS //
	country_selected->stats.nb_pops = 0;

	return 0;
}

int Actualisation_country(void)
{	
	// RELIGIONS //
	country_selected->stats.catholic += region_selected->stats.catholic;
	country_selected->stats.protestant += region_selected->stats.protestant;
	country_selected->stats.jew += region_selected->stats.jew;

	// CULTURES //
	country_selected->stats.hungarian += region_selected->stats.hungarian;
	country_selected->stats.austrian += region_selected->stats.austrian;
	country_selected->stats.italian += region_selected->stats.italian;

	// IDEOLOGY //
	country_selected->stats.liberal += region_selected->stats.liberal;
	country_selected->stats.conservative += region_selected->stats.conservative;
	country_selected->stats.reactionary += region_selected->stats.reactionary;

	// STRATA //
	country_selected->stats.rich_strata += region_selected->stats.rich_strata;
	country_selected->stats.middle_strata += region_selected->stats.middle_strata;
	country_selected->stats.poor_strata += region_selected->stats.poor_strata;
	
	// PROFESSIONS //
	country_selected->stats.capitalist += region_selected->stats.capitalist;
	country_selected->stats.noble += region_selected->stats.noble;
	
	country_selected->stats.intellectual += region_selected->stats.intellectual;
	country_selected->stats.bureaucrat += region_selected->stats.bureaucrat;

	country_selected->stats.soldier += region_selected->stats.soldier;

	country_selected->stats.worker += region_selected->stats.worker;
	country_selected->stats.artisan += region_selected->stats.artisan;

	country_selected->stats.miner += region_selected->stats.miner;
	country_selected->stats.laborer += region_selected->stats.laborer;

	// OTHERS //
	country_selected->stats.nb_pops += region_selected->stats.nb_pops;

	
	return 0;
}

int Print_country_stats(void)
{
	// RELIGIONS //
	printf("%d catholics\n", country_selected->stats.catholic);
	printf("%d protestants\n", country_selected->stats.protestant);
	printf("%d jews\n\n", country_selected->stats.jew);

	// CULTURES //
	printf("%d hungarians\n", country_selected->stats.hungarian);
	printf("%d austrians\n", country_selected->stats.austrian);
	printf("%d italians\n\n", country_selected->stats.italian);

	// IDEOLOGY //
	printf("%d liberals\n", country_selected->stats.liberal);
	printf("%d conservatives\n", country_selected->stats.conservative);
	printf("%d reactionaries\n\n", country_selected->stats.reactionary);

	// STRATA //
	printf("%d rich\n", country_selected->stats.rich_strata);
	printf("%d middle class\n", country_selected->stats.middle_strata);
	printf("%d poor\n\n", country_selected->stats.poor_strata);
	
	// PROFESSIONS //
	printf("%d capitalists\n", country_selected->stats.capitalist);
	printf("%d nobles\n", country_selected->stats.noble);
	
	printf("%d intellectuals\n", country_selected->stats.intellectual);
	printf("%d bureaucrats\n", country_selected->stats.bureaucrat);

	printf("%d soldiers\n", country_selected->stats.soldier);

	printf("%d workers\n", country_selected->stats.worker);
	printf("%d artisans\n", country_selected->stats.artisan);

	printf("%d miners\n", country_selected->stats.miner);
	printf("%d laborers\n\n", country_selected->stats.laborer);

	// OTHERS //
	printf("%d people in the country\n\n", country_selected->stats.nb_pops);

	return 0;
}

int Reset_region(void)
{	
	// RELIGIONS //
	region_selected->stats.catholic = 0;
	region_selected->stats.protestant = 0;
	region_selected->stats.jew = 0;

	// CULTURES //
	region_selected->stats.hungarian = 0;
	region_selected->stats.austrian = 0;
	region_selected->stats.italian = 0;

	// IDEOLOGY //
	region_selected->stats.liberal = 0;
	region_selected->stats.conservative = 0;
	region_selected->stats.reactionary = 0;

	// STRATA //
	region_selected->stats.rich_strata = 0;
	region_selected->stats.middle_strata = 0;
	region_selected->stats.poor_strata = 0;
	
	// PROFESSIONS //
	region_selected->stats.capitalist = 0;
	region_selected->stats.noble = 0;
	
	region_selected->stats.intellectual = 0;
	region_selected->stats.bureaucrat = 0;

	region_selected->stats.soldier = 0;

	region_selected->stats.worker = 0;
	region_selected->stats.artisan = 0;

	region_selected->stats.miner = 0;
	region_selected->stats.laborer = 0;

	// OTHERS //
	region_selected->stats.nb_pops = 0;

	return 0;
}

int Actualisation_region(void)
{	
	counter.i = 0;
	while(region_selected->pops[counter.i].nb_pops != 0)
	{
		// RELIGIONS //
		if(region_selected->pops[counter.i].religion == Catholic)
			region_selected->stats.catholic += region_selected->pops[counter.i].nb_pops;
	
		else if(region_selected->pops[counter.i].religion == Protestant)
			region_selected->stats.protestant += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].religion == Jew)
			region_selected->stats.jew += region_selected->pops[counter.i].nb_pops;

		// CULTURES //
		if(region_selected->pops[counter.i].culture == Hungarian)
			region_selected->stats.hungarian += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].culture == Austrian)
			region_selected->stats.austrian += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].culture == Italian)
			region_selected->stats.italian += region_selected->pops[counter.i].nb_pops;

		// IDEOLOGY //
		if(region_selected->pops[counter.i].ideology == Liberal)
			region_selected->stats.liberal += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].ideology == Conservative)
			region_selected->stats.conservative += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].ideology == Reactionary)
			region_selected->stats.reactionary += region_selected->pops[counter.i].nb_pops;

		// STRATA //
		if(region_selected->pops[counter.i].strata == Rich)
			region_selected->stats.rich_strata += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].strata == Middle)
			region_selected->stats.middle_strata += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].strata == Poor)
			region_selected->stats.poor_strata += region_selected->pops[counter.i].nb_pops;
	
		// PROFESSIONS //
		if(region_selected->pops[counter.i].profession == Capitalist)
			region_selected->stats.capitalist += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].profession == Noble)
			region_selected->stats.noble += region_selected->pops[counter.i].nb_pops;
		
		else if(region_selected->pops[counter.i].profession == Intellectual)
			region_selected->stats.intellectual += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].profession == Bureaucrat)
			region_selected->stats.bureaucrat += region_selected->pops[counter.i].nb_pops;	

		else if(region_selected->pops[counter.i].profession == Soldier)
			region_selected->stats.soldier += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].profession == Worker)
			region_selected->stats.worker += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].profession == Artisan)
			region_selected->stats.artisan += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].profession == Miner)
			region_selected->stats.miner += region_selected->pops[counter.i].nb_pops;

		else if(region_selected->pops[counter.i].profession == Laborer)
			region_selected->stats.laborer += region_selected->pops[counter.i].nb_pops;

		region_selected->stats.nb_pops += region_selected->pops[counter.i].nb_pops;

		counter.i++;
	}

	return 0;
}

int Print_region_stats(void)
{	
	// RELIGIONS //
	printf("%d catholics\n", region_selected->stats.catholic);
	printf("%d protestants\n", region_selected->stats.protestant);
	printf("%d jews\n\n", region_selected->stats.jew);

	// CULTURES //
	printf("%d hungarians\n", region_selected->stats.hungarian);
	printf("%d austrians\n", region_selected->stats.austrian);
	printf("%d italians\n\n", region_selected->stats.italian);

	// IDEOLOGY //
	printf("%d liberals\n", region_selected->stats.liberal);
	printf("%d conservatives\n", region_selected->stats.conservative);
	printf("%d reactionaries\n\n", region_selected->stats.reactionary);

	// STRATA //
	printf("%d rich\n", region_selected->stats.rich_strata);
	printf("%d middle class\n", region_selected->stats.middle_strata);
	printf("%d poor\n\n", region_selected->stats.poor_strata);
	
	// PROFESSIONS //
	printf("%d capitalists\n", region_selected->stats.capitalist);
	printf("%d nobles\n", region_selected->stats.noble);
	
	printf("%d intellectuals\n", region_selected->stats.intellectual);
	printf("%d bureaucrats\n", region_selected->stats.bureaucrat);

	printf("%d soldiers\n", region_selected->stats.soldier);

	printf("%d workers\n", region_selected->stats.worker);
	printf("%d artisans\n", region_selected->stats.artisan);

	printf("%d miners\n", region_selected->stats.miner);
	printf("%d laborers\n\n", region_selected->stats.laborer);

	// OTHERS //
	printf("%d people in the region\n\n", region_selected->stats.nb_pops);

	return 0;
}




















