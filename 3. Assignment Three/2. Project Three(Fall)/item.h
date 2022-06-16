#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

const char file_name[] = "item.txt";
const int SIZE = 301;

struct hold_an_item
{
	char * item_name;
	char * location;
	char * hint[3];
};

class item
{
	public:
		item();
		~item();
		int add_an_item(hold_an_item & to_add);
		int search_an_item(hold_an_item & hold);
		int remove_an_item(char * item_to_remove);
		int display();
	private:
		char * item_name;
		char * location;
		char * hint[3];
};

struct node
{
	item data;
	node * next;
};

class table
{
	public:
		table(int size);
		~table();
		int read_in(hold_an_item & to_add);
		int hash_function(char * hint);
		int add(hold_an_item & to_add);
		int search(hold_an_item & hold);
		int remove(char * item_name);
		int display_match(char * hint);
		int display_all();
	private:
		int search(node * ptr, hold_an_item & hold);
		int remove(node *& ptr, char * item_name);
		int display_match(node * ptr, char * hint);
		int display_all(node * ptr);
		node ** hash_table;
		int table_size;
};
















