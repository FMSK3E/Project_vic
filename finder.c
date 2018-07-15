# include "structures.h"

int Country_finder(void)
{
	char country_to_find[25];

	counter.country_list = 0;

	while(counter.country_list < NB_COUNTRIES)
	{
		strcpy(country_to_find, country_tab[counter.country_list]->name);
		country_selected = find_country(country_to_find, country_tab);

		Reset_country();
		
		counter.region_list = 0;
		while(counter.region_list < NB_REGIONS)
		{
			Region_finder();
			counter.region_list++;
		}
		counter.country_list++;
	}
	
	return 0;
}

int Country_finder_manual(void)
{
	char country_to_find[25];

	//scanf("%s", country_to_find);	
	strcpy(country_to_find, "Hungary");

	country_selected = find_country(country_to_find, country_tab);


	
	return 0;
}	
	

int Region_finder(void)
{
	char region_to_find[35];

	strcpy(region_to_find, region_tab[counter.region_list]->name);
	region_selected = find_region(region_to_find, region_tab);

	if(country_selected->ID == region_selected->owner)
	{	
		if(TAG.init_tag == YES)
		{
			Define_needs();
		}

		if(TAG.end_turn_tag == YES)
		{
			End_turn();
		}
		Reset_region();
		Actualisation_region();
		Actualisation_country();
	}

	return 0;
}

int Region_finder_manual(void)
{
	char region_to_find[35];

	scanf("%s", region_to_find);

	region_selected = find_region(region_to_find, region_tab);

	return 0;
}



country		*find_country(char *country_to_find, country **country_tab)
{
	counter.i = 0;
	
	while(country_tab[counter.i])
	{
		if(!strcmp(country_to_find, country_tab[counter.i]->name))
			return (country_tab[counter.i]);
		counter.i++;
	}

	return (NULL);
}

region		*find_region(char *region_to_find, region **region_tab)
{
	counter.i = 0;
	
	while(region_tab[counter.i])
	{
		if(!strcmp(region_to_find, region_tab[counter.i]->name))
			return (region_tab[counter.i]);
		counter.i++;
	}

	return (NULL);
}
