#include<iostream>
#include<cctype>
#include<cstring>
#include<fstream>

using namespace std;

const char file_name[] = "Comic_Collector.txt";
const int SIZE = 301;

struct comic_info
{
	char * comic_name;
	char * publisher;
	char * comic_hero;
	char * issue;
	char * interested;
};


class comic
{
	public:
		comic();
		~comic();
		int add_a_comic(comic_info & to_add);
		int remove_a_comic(char * to_remove);
		int display();
	private:
		char * comic_name;
		char * publisher;
		char * comic_hero;
		char * issue;
		char * interested;	
};


struct node
{
	comic data;
	node * next;
};


class table
{
	public:
		table(int size);
		~table();
		int read_in_comic(comic_info & to_add);
		int hash_table_func(char * key);
		int add(comic_info & to_add);
		int remove(char * comic_name);		
		int display_all();
	private:
		int remove(node *& ptr, char * comic_name);
		int display_all(node * ptr);
		node ** hash_table;
		int table_size;
};

















