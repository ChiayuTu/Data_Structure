#include<iostream>
#include<cctype>
#include<cstring>

using namespace std;

const int SIZE = 201;
struct vertex;

struct add_a_contact
{
	char * name;
	char * phone;
};

class contact
{
	public:
		contact();
		~contact();
		int insert(const add_a_contact & to_add);
		bool compare(char * key_value);
		int display(char * key_value);
		int find_name(char *& found);

	private:
		char * name;
		char * phone;
};


struct node
{
	vertex * adjacent;
	node * next;
};


struct vertex
{
	contact * a_contact;
	node * head;
};


class table
{
	public:
		table(int size = 10);
		~table();
		int delete_all();
		int insert_vertex(const add_a_contact & to_add);
		int find_location(char * key);
		int insert_edge(char * current_vertex, char * to_attach);
		int display_adjacency(char * key_value);

	private:
		int delete_all(node * head);
		int find_location(int index, char * key);
		int display_adjacency(node * head, char * key_value);
		vertex * adjacency_list;
		int list_size;
};












