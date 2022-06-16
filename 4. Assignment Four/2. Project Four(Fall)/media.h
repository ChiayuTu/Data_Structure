#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

const int SIZE = 301;

struct hold_a_media
{
	char * related;
	char * name;
	char * description[3];
	char * length;
};

class media
{
	public:
		media();
		~media();
		int add_a_media(hold_a_media & to_add);
		int search_a_media(char * describe_value, hold_a_media & hold);
		int remove_a_media(char * media_to_remove);
		int display();
		char * find_media();
		char * find_description(int i);
	private:
		char * name;
		char * related;
		char * description[3];
		char * length;
};

struct node
{
	media * data;
	node * left;
	node * right;
};

class table
{
	public:
		table();
		~table();
		int remove_all();
		int add(hold_a_media & to_add);
		int search(char * describe_value, hold_a_media & hold);
		node * find_ios(node * previous, media *& hold_data);
		int remove(char * name);
		int display_match(char * description);
		int get_height();
		int display_all();
	private:	
		int remove_all(node *& root);
		int add(node *& root, hold_a_media & to_add);
		int search(node * root, char * describe_value, hold_a_media & hold);
		node * find_ios(node * root, node * previous, media *& hold_data);
		int remove(node *& root, char * name);
		int display_match(node * root, char * description);
		int get_height(node * root);
		int display_all(node * root);
		node * root;
};














