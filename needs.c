# include "structures.h"

int Define_needs(void)
{	
	counter.i = 0;
	
	while(region_selected->pops[counter.i].nb_pops != 0)
	{
		region_selected->pops[counter.i].basic_needs[0].ID = Grain; 
		region_selected->pops[counter.i].basic_needs[0].base_quantity_needed = 5;

		region_selected->pops[counter.i].basic_needs[1].ID = Vegetables; 
		region_selected->pops[counter.i].basic_needs[1].base_quantity_needed = 4;

		region_selected->pops[counter.i].basic_needs[2].ID = Fruits; 
		region_selected->pops[counter.i].basic_needs[2].base_quantity_needed = 4;

		region_selected->pops[counter.i].basic_needs[3].ID = Meat; 
		region_selected->pops[counter.i].basic_needs[3].base_quantity_needed = 2;

		region_selected->pops[counter.i].basic_needs[4].ID = Fish; 
		region_selected->pops[counter.i].basic_needs[4].base_quantity_needed = 3;

		region_selected->pops[counter.i].basic_needs_nb = 5;

		counter.i++;
	}

	return 0;
}

int Basic_needs(void)
{
	counter.i = 0;	// Utile pour passer sur les différentes pops de la région
	
	int buy;	// Afin de calculer le nombre de produits achetés en (en fonction de l'argent ou des produits restants disponibles, en fonction des problèmes)
	float price;	// Afin de calculer le prix de l'achat
	float temp_needs_filled;	// Afin de facilier les calculs finaux
	while(region_selected->pops[counter.i].nb_pops != 0)
	{	
		region_selected->pops[counter.i].basic_needs_filled = 0;
		counter.j = 0;	// Utile pour passer sur les différents needs des pops
		while(counter.j < region_selected->pops[counter.i].basic_needs_nb)
		{
			region_selected->pops[counter.i].basic_needs[counter.j].total_quantity_needed = region_selected->pops[counter.i].basic_needs[counter.j].base_quantity_needed * region_selected->pops[counter.i].nb_pops;
	
			buy = region_selected->pops[counter.i].basic_needs[counter.j].total_quantity_needed;
			price = region_selected->pops[counter.i].basic_needs[counter.j].total_quantity_needed * country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].price;
	
			if(price > region_selected->pops[counter.i].pops_money_owned)	// Si les pops n'ont pas assez d'argent
			{	
				buy = region_selected->pops[counter.i].pops_money_owned / country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].price;
				price = buy * country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].price;
		
				if(country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity < buy)	// Si le marché n'a pas assez de produits
				{
					buy = country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity;	// Calcul en fonction des produits restants
					price = buy * country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].price;

					country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity -= buy;	
					region_selected->pops[counter.i].pops_money_owned -= price;
				}
				else
				{
					country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity -= buy;	
					region_selected->pops[counter.i].pops_money_owned -= price;
				}
			}
			else if(country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity < buy)	// Si le marché n'a pas assez de produits
			{	
				buy = country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity;
				price = buy * country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].price;

				country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity -= buy;	
				region_selected->pops[counter.i].pops_money_owned -= price;
			}
			else	// Si tout est bon
			{
				country_selected->goods_market[region_selected->pops[counter.i].basic_needs[counter.j].ID].quantity -= buy;	
				region_selected->pops[counter.i].pops_money_owned -= price;
			}

			temp_needs_filled = buy; // On calcule si les besoin sont remplis
			temp_needs_filled = temp_needs_filled / region_selected->pops[counter.i].basic_needs[counter.j].total_quantity_needed;	

			region_selected->pops[counter.i].basic_needs[counter.j].filled = temp_needs_filled * 100;	// Pour savoir si ces besoins précis ont été remplis
		
			region_selected->pops[counter.i].basic_needs_filled += temp_needs_filled;	// Pour savoir si les besoins basiques globaux sont remplis

			counter.j++;	// On passe aux prochains besoins
		}	
		region_selected->pops[counter.i].basic_needs_filled = region_selected->pops[counter.i].basic_needs_filled / region_selected->pops[counter.i].basic_needs_nb * 100; // Pour un % sur 100
			
		counter.i++;	// On passe au prochain groupe de pops
	}
	
	return 0;
}


