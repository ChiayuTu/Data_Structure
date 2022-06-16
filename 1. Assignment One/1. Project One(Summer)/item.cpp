#include"item.h"
using namespace std;

item::item()
{
	item_name = NULL;
	item_ctgry = NULL;
	item_price = 0.0;
}

item::~item()
{
	if(item_name)
		delete [] item_name;
	if(item_ctgry)
		delete [] item_ctgry;
	item_name = item_ctgry = NULL;
	item_price = 0.0;
}

//Add new item
int item::add_item(char name_add_in[], char ctgry_add_in[], float price_add_in)
{
	if(name_add_in == NULL || ctgry_add_in == NULL)
	{
		return 0;
	}

	item_name = new char[strlen(name_add_in) + 1];
	strcpy(item_name, name_add_in);
	
	item_ctgry = new char[strlen(ctgry_add_in) + 1];
	strcpy(item_ctgry , ctgry_add_in);

	item_price = price_add_in;
	return 1;
}

//Add a new item all at once
int item::add_item(const item & new_item)
{
	return add_item(new_item.item_name, new_item.item_ctgry, new_item.item_price);
}

//Display an item
int item::display_item()
{
	cout << "The item's name: " <<  item_name << '\n' 
		<< "The item's categoty: " << item_ctgry << '\n'
		<< "The item's price: " << item_price << '\n';
}	




