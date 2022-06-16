#include"project.h"

using namespace std;

list::list()
{
	head = NULL;
	proj_head = NULL;
}

list::~list()
{
	if(head)
		delete head;
	if(proj_head)
		delete proj_head;
	head = NULL;
	proj_head = NULL;
}

int list::add(proj_to_add & to_add)
{
	if(!to_add.proj_name || !to_add.proj_cost || !to_add.proj_time || !to_add.proj_hire || !to_add.proj_done)
	{
		return 0;
	}
	return add(head, to_add);
}

int list::add(node *& head, proj_to_add & to_add)
{
	if(!head)
	{
		head = new node;
		head->next = NULL;
		head->data.proj_name = new char [strlen(to_add.proj_name) + 1];
		strcpy(head->data.proj_name, to_add.proj_name);
		head->data.proj_cost = new char [strlen(to_add.proj_cost) + 1];
		strcpy(head->data.proj_cost, to_add.proj_cost);
		head->data.proj_time = new char [strlen(to_add.proj_time) + 1];
		strcpy(head->data.proj_time, to_add.proj_time);
		head->data.proj_hire = new char [strlen(to_add.proj_hire) + 1];
		strcpy(head->data.proj_hire, to_add.proj_hire);
		head->data.proj_done = new char [strlen(to_add.proj_done) + 1];
		strcpy(head->data.proj_done, to_add.proj_done);

		return 1;
	}
	return add(head->next, to_add);
}

int list::remove(char matching_name[])
{
	if(!head || !matching_name) return 0;
	return remove(head, matching_name);
}

int list::remove(node *& head, char matching_name[])
{
	if(!head) return 0;
	if(strcmp(head->data.proj_name, matching_name) == 0)
	{
		node * temp = head->next;
		delete head;
		head = temp;
		return 1;
	}
	return remove(head->next, matching_name);
}

int list::display()
{
	if(!head) return 0;
	return display(head);
}

int list::display(node * head)
{
	if(!head) return 0;
	cout << "The project name: " << head->data.proj_name << endl
		<< "The project cost: " << head->data.proj_cost << endl
		<< "The time will spend: " << head->data.proj_time << endl
		<< "The hire company: " << head->data.proj_hire << endl
		<< "The estimated finish time: " << head->data.proj_done << endl;

	return display(head->next) + 1;
}

int list::add_info(char matching_name[], char info_to_add[])
{
	if(!head || !matching_name || !info_to_add) return 0;
	return add_info(head, proj_head, matching_name, info_to_add);
}

int list::add_info(node *& head, proj_node *& proj_head, char matching_name[], char info_to_add[])
{
	if(!head) return 0;
	if(strcmp(head->data.proj_name, matching_name) == 0)
	{
		if(!proj_head)
		{
			proj_head = new proj_node;
			proj_head->next_proj = NULL;
			proj_head->proj_data = new char [strlen(info_to_add) + 1];
			strcpy(proj_head->proj_data, info_to_add);
			return 1;
		}
		proj_node * temp = proj_head;
		while(temp->next_proj)
		{
			temp = temp->next_proj;
		}
		temp->next_proj = new proj_node;
		temp = temp->next_proj;
		temp->next_proj = NULL;
		temp->proj_data = new char [strlen(info_to_add) + 1];
		strcpy(temp->proj_data, info_to_add);
		return 1;
	}
	return add_info(head->next, proj_head, matching_name, info_to_add);
}


































