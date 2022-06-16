#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

using namespace std;

const char file_name[] = "comic.txt";
const int SIZE = 50;

struct a_comic
{
	char * comic_name;
	char * publisher;
	char * comic_info;
	char * item[3];
	char * issue;
};


class comic
{
	public:
		comic();
		~comic();
		int add_a_comic(a_comic & to_add);
		int search_a_comic(char * item_value, a_comic & hold);
		int remove_a_comic(char * comic_to_remove);
		int display_a_comic();
		char* find_comic();
		char* find_item(int i);


	private:
		char * comic_name;
		char * publisher;
		char * comic_info;
		char * item[3];
		char * issue;
};


struct node
{
	comic * data;
	node * left;
	node * right;	
};


class table
{
	public:
		table();
		~table();
		int remove_all();
		int add(a_comic & to_add);
		int read_in(a_comic & to_add);
		int search(char * item_value, a_comic & hold);
		node* find_ios(node * previous, comic *& hold_data);
		int remove(char * comic_name);
		int dispaly_match(char * item);
		int display_all();

	private:
		int remove_all(node *& root);
		int add(node *& root, a_comic & add);
		int search(node * root, char * item_value, a_comic & hold);
		node* find_ios(node * root, node * previous, comic *& hold_data);
		int remove(node * root, char * comic_name);
		int display_match(node * root, char * item);
		int display_all(node * root);
		node * root;

};


























