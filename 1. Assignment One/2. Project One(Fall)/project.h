#include<iostream>
#include<cctype>
#include<cstring>

struct project
{
	char * proj_name;
	char * proj_cost;
	char * proj_time;
	char * proj_hire;
	char * proj_done;
};

struct proj_node
{
	char * proj_data;
	proj_node * next_proj;
};

struct node
{
	project data;
	node * next;
	proj_node * next_proj;
};

struct proj_to_add
{
	char proj_name[30];
	char proj_cost[10];
	char proj_time[10];
	char proj_hire[30];
	char proj_done[10];
};

class list
{
	public:
		list();
		~list();
		int add(proj_to_add & to_add);
		int remove(char matching_name[]);
		int display();
		int add_info(char matching_name[], char info_to_add[]);

	private:
		int add(node *& head, proj_to_add & to_add);
		int remove(node *& head, char matching_name[]);
		int display(node * head);
		int add_info(node *& head, proj_node *& proj_head, char matching_name[], char info_to_add[]);
		node * head;
		proj_node * proj_head;
};









