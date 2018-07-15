# include "structures.h"

int Init(void)
{	
	TAG.init_tag = YES;

	Init_goods_market();
	Init_countries();
	Init_regions();

	Country_finder();

	TAG.init_tag = NO;

	return 0;
}

int Init_countries(void)
{	
	counter.i = 0;

	country_tab[0] = &austria;

	austria.ID = Austria;
	strcpy(austria.name, "Austria");
	austria.religion = Catholic;
	austria.culture = Austrian;
	austria.ideology = Liberal;

	austria.poor_tax = 25;
	austria.middle_tax = 25;
	austria.rich_tax = 25;

	while(counter.i < NB_GOODS)
	{
		austria.goods_market[counter.i] = goods_market[counter.i];
		counter.i++;
	}



	counter.i = 0;
	
	country_tab[1] = &italy;

	italy.ID = Italy;
	strcpy(italy.name, "Italy");
	italy.religion = Catholic;
	italy.culture = Italian;
	italy.ideology = Conservative;

	italy.poor_tax = 25;
	italy.middle_tax = 25;
	italy.rich_tax = 15;

	while(counter.i < NB_GOODS)
	{
		italy.goods_market[counter.i] = goods_market[counter.i];
		counter.i++;
	}


	
	counter.i = 0;

	country_tab[2] = &hungary;

	hungary.ID = Hungary;
	strcpy(hungary.name, "Hungary");
	hungary.religion = Catholic;
	hungary.culture = Hungarian;
	hungary.ideology = Reactionary;

	hungary.poor_tax = 35;
	hungary.middle_tax = 35;
	hungary.rich_tax = 50;

	while(counter.i < NB_GOODS)
	{
		hungary.goods_market[counter.i] = goods_market[counter.i];
		counter.i++;
	}

	return 0;
}

int Init_regions(void)
{
	Init_regionA();
	Init_regionB();
	Init_regionC();
	Init_regionD();

	return 0;
}

int Init_goods_market(void)
{			
	goods_market[Grain].ID = Grain;
	strcpy(goods_market[Grain].name, "Grain");
	goods_market[Grain].min_price = 2;
	goods_market[Grain].price = 3;
	goods_market[Grain].max_price = 4;
	goods_market[Grain].quantity = 100000;

	goods_market[Rice].ID = Rice;
	strcpy(goods_market[Rice].name, "Rice");
	goods_market[Rice].min_price = 3;
	goods_market[Rice].price = 5;
	goods_market[Rice].max_price = 7;
	goods_market[Rice].quantity = 1000000;

	goods_market[Vegetables].ID = Vegetables;
	strcpy(goods_market[Vegetables].name, "Vegetables");
	goods_market[Vegetables].min_price = 3;
	goods_market[Vegetables].price = 4;
	goods_market[Vegetables].max_price = 5;
	goods_market[Vegetables].quantity = 100000;
	
	goods_market[Fruits].ID = Fruits;
	strcpy(goods_market[Fruits].name, "Fruits");
	goods_market[Fruits].min_price = 3;
	goods_market[Fruits].price = 4;
	goods_market[Fruits].max_price = 5;
	goods_market[Fruits].quantity = 100000;

	goods_market[Meat].ID = Meat;
	strcpy(goods_market[Meat].name, "Meat");
	goods_market[Meat].min_price = 5;
	goods_market[Meat].price = 7;
	goods_market[Meat].max_price = 10;
	goods_market[Meat].quantity = 100000;

	goods_market[Fish].ID = Fish;
	strcpy(goods_market[Fish].name, "Fish");
	goods_market[Fish].min_price = 5;
	goods_market[Fish].price = 6;
	goods_market[Fish].max_price = 9;
	goods_market[Fish].quantity = 100000;

	goods_market[Cacao].ID = Cacao;
	strcpy(goods_market[Cacao].name, "Cacao");
	goods_market[Cacao].min_price = 7;
	goods_market[Cacao].price = 9;
	goods_market[Cacao].max_price = 11;
	goods_market[Cacao].quantity = 100000;

	goods_market[Coffee].ID = Coffee;
	strcpy(goods_market[Coffee].name, "Coffee");
	goods_market[Coffee].min_price = 6;
	goods_market[Coffee].price = 8;
	goods_market[Coffee].max_price = 10;
	goods_market[Coffee].quantity = 100000;
	
	goods_market[Tea].ID = Tea;
	strcpy(goods_market[Tea].name, "Tea");
	goods_market[Tea].min_price = 7;
	goods_market[Tea].price = 9;
	goods_market[Tea].max_price = 11;
	goods_market[Tea].quantity = 100000;

	goods_market[Sugar].ID = Sugar;
	strcpy(goods_market[Sugar].name, "Sugar");
	goods_market[Sugar].min_price = 8;
	goods_market[Sugar].price = 10;
	goods_market[Sugar].max_price = 12;
	goods_market[Sugar].quantity = 100000;

	goods_market[Metal].ID = Metal;
	strcpy(goods_market[Metal].name, "Metal");
	goods_market[Metal].min_price = 4;
	goods_market[Metal].price = 6;
	goods_market[Metal].max_price = 8;
	goods_market[Metal].quantity = 100000;

	goods_market[Oil].ID = Oil;
	strcpy(goods_market[Oil].name, "Oil");
	goods_market[Oil].min_price = 8;
	goods_market[Oil].price = 10;
	goods_market[Oil].max_price = 12;
	goods_market[Oil].quantity = 100000;

	return 0;
}
