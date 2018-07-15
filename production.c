# include "structures.h"

int Production(void)
{
	region_selected->goods.productivity = 1 + (region_selected->stats.noble * 3) / region_selected->stats.laborer;	// Calcul de la productivité
	region_selected->goods.quantity_produced = region_selected->stats.laborer * region_selected->goods.productivity * 15;	// Calcul de la quantité produite
	
	country_selected->goods_market[region_selected->goods.ID].quantity += region_selected->goods.quantity_produced;	// On peut désormais ajouter les produits au marché
	
	region_selected->global_income = region_selected->goods.quantity_produced * country_selected->goods_market[region_selected->goods.ID].price;	// Calcul de lu salaire global

	Salary();
	


	return 0;
}

int Salary(void)
{	
	region_selected->noble_income = region_selected->global_income * 2 * region_selected->stats.noble / region_selected->stats.laborer;	// Calcul du salaire des nobles puis des laboureurs
	region_selected->laborer_income = region_selected->global_income - region_selected->noble_income;


	region_selected->collected_tax_rich = region_selected->noble_income * country_selected->rich_tax / 100;	// Calcul des taxes engrangées par le pays
	region_selected->collected_tax_poor = region_selected->laborer_income * country_selected->poor_tax / 100;	
	

	region_selected->noble_income -= region_selected->collected_tax_rich;	// Soustraction des taxes sur le salaire
	region_selected->laborer_income -= region_selected->collected_tax_poor;


	region_selected->noble_income = region_selected->noble_income / region_selected->stats.noble;	// Division du salaire par le nombre de participants
	region_selected->laborer_income = region_selected->laborer_income / region_selected->stats.laborer;
	

	country_selected->state_money_owned += region_selected->collected_tax_rich + region_selected->collected_tax_poor;	// Ajout l'argent dans les caisses de l'Etat
	
	counter.i = 0;
	while(region_selected->pops[counter.i].nb_pops != 0)	// On donne le salaire aux pops, salaire personnel * le nombre de pops dans la case, à la fin tout est normalement donné
	{
		if(region_selected->pops[counter.i].profession == Noble)
		{
			region_selected->pops[counter.i].pops_money_owned += region_selected->noble_income * region_selected->pops[counter.i].nb_pops;
		}
		else if(region_selected->pops[counter.i].profession == Laborer)
		{
			region_selected->pops[counter.i].pops_money_owned += region_selected->laborer_income * region_selected->pops[counter.i].nb_pops;
		}

		counter.i++;
	}
	

	return 0;
}
