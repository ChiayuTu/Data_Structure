#include<iostream>
#include<cctype>
#include<cstring>

//Chiayu Tu (Louis Tu)
//In this file, I will create a class for item

using namespace std;

//Size
const int name_size = 30;
const int ctgry_size = 50;


class item
{
	public:
		item();
		~item();
		int add_item(char item_name[], char item_ctgry[], float item_price);
		int add_item(const item & new_item);	
		int display_item();

	private:
		char * item_name;
		char * item_ctgry;
		float item_price;

};
