# include "structures.h"

int Init_regionA(void)
{	
	region_tab[0] = &regionA;
	regionA.ID = 1;
	strcpy(regionA.name, "regionA");	
	regionA.owner = Austria;

	strcpy(regionA.goods.name, "Grain");
	regionA.goods.ID = Grain;



	regionA.pops[0].nb_pops = 10000;
	regionA.pops[0].religion = Catholic;
	regionA.pops[0].culture = Austrian;
	regionA.pops[0].ideology = Conservative;

	regionA.pops[0].strata = Poor;
	regionA.pops[0].profession = Laborer;

	regionA.pops[0].pops_money_owned = 20 * regionA.pops[0].nb_pops;
	
	regionA.pops[0].litteracy = 20;
	regionA.pops[0].militancy = 5;	
		


	regionA.pops[1].nb_pops = 100;
	regionA.pops[1].religion = Catholic;
	regionA.pops[1].culture = Austrian;
	regionA.pops[1].ideology = Conservative;

	regionA.pops[1].strata = Rich;
	regionA.pops[1].profession = Noble;

	regionA.pops[1].pops_money_owned = 125 * regionA.pops[1].nb_pops;
	
	regionA.pops[1].litteracy = 50;
	regionA.pops[1].militancy = 0;	
		
	return 0;
}

int Init_regionB(void)
{
	region_tab[1] = &regionB;
	regionB.ID = 2;
	strcpy(regionB.name, "regionB");	
	regionB.owner = Austria;

	strcpy(regionB.goods.name, "Grain");
	regionB.goods.ID = Grain;



	regionB.pops[0].nb_pops = 10000;
	regionB.pops[0].religion = Catholic;
	regionB.pops[0].culture = Austrian;
	regionB.pops[0].ideology = Conservative;

	regionB.pops[0].strata = Poor;
	regionB.pops[0].profession = Laborer;

	regionB.pops[0].pops_money_owned = 20 * regionB.pops[0].nb_pops;
	
	regionB.pops[0].litteracy = 20;
	regionB.pops[0].militancy = 5;	
		


	regionB.pops[1].nb_pops = 100;
	regionB.pops[1].religion = Catholic;
	regionB.pops[1].culture = Austrian;
	regionB.pops[1].ideology = Liberal;

	regionB.pops[1].strata = Rich;
	regionB.pops[1].profession = Noble;

	regionB.pops[1].pops_money_owned = 125 * regionB.pops[1].nb_pops;
	
	regionB.pops[1].litteracy = 50;
	regionB.pops[1].militancy = 0;	
	return 0;
}

int Init_regionC(void)
{
	region_tab[2] = &regionC;
	regionC.ID = 3;
	strcpy(regionC.name, "regionC");	
	regionC.owner = Austria;

	strcpy(regionC.goods.name, "Fruits");
	regionC.goods.ID = Fruits;



	regionC.pops[0].nb_pops = 10000;
	regionC.pops[0].religion = Catholic;
	regionC.pops[0].culture = Hungarian;
	regionC.pops[0].ideology = Conservative;

	regionC.pops[0].strata = Poor;
	regionC.pops[0].profession = Laborer;

	regionC.pops[0].pops_money_owned = 15 * regionC.pops[0].nb_pops;
	
	regionC.pops[0].litteracy = 15;
	regionC.pops[0].militancy = 5;	
		


	regionC.pops[1].nb_pops = 100;
	regionC.pops[1].religion = Catholic;
	regionC.pops[1].culture = Austrian;
	regionC.pops[1].ideology = Reactionary;

	regionC.pops[1].pops_money_owned = 125 * regionC.pops[1].nb_pops;

	regionC.pops[1].strata = Rich;
	regionC.pops[1].profession = Noble;
	
	regionC.pops[1].litteracy = 50;
	regionC.pops[1].militancy = 0;	

	return 0;
}

int Init_regionD(void)
{

	region_tab[3] = &regionD;
	regionD.ID = 4;
	strcpy(regionD.name, "regionD");
	regionD.owner = Hungary;

	strcpy(regionD.goods.name, "Meat");
	regionD.goods.ID = Meat;



	regionD.pops[0].nb_pops = 9000;
	regionD.pops[0].religion = Catholic;
	regionD.pops[0].culture = Hungarian;
	regionD.pops[0].ideology = Conservative;

	regionD.pops[0].strata = Poor;
	regionD.pops[0].profession = Laborer;

	regionD.pops[0].pops_money_owned = 15 * regionD.pops[0].nb_pops;
	
	regionD.pops[0].litteracy = 15;
	regionD.pops[0].militancy = 3;	
		


	regionD.pops[1].nb_pops = 100;
	regionD.pops[1].religion = Catholic;
	regionD.pops[1].culture = Hungarian;
	regionD.pops[1].ideology = Conservative;

	regionD.pops[1].strata = Rich;
	regionD.pops[1].profession = Noble;

	regionD.pops[1].pops_money_owned = 110 * regionD.pops[1].nb_pops;
	
	regionD.pops[1].litteracy = 40;
	regionD.pops[1].militancy = 0;	
	
		

	regionD.pops[2].nb_pops= 1000;
	regionD.pops[2].religion = Jew;
	regionD.pops[2].culture = Hungarian;
	regionD.pops[2].ideology = Liberal;

	regionD.pops[2].strata = Poor;
	regionD.pops[2].profession = Laborer;

	regionD.pops[2].pops_money_owned = 10 * regionD.pops[2].nb_pops;
	
	regionD.pops[2].litteracy = 12;
	regionD.pops[2].militancy = 7;	
	return 0;
}


