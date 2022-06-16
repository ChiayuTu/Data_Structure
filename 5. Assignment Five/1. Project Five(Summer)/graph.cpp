
#include"graph.h"

using namespace std;

contact::contact()
{
	name = NULL;
	phone = NULL;
}


contact::~contact()
{
	if(name)
	{
		name[0] = '\0';
		delete [] name;
		name = NULL;
	}
	if(phone)
	{
		phone[0] = '\0';
		delete [] phone;
		phone = NULL;
	}
}


int contact::insert(const add_a_contact & to_add)
{
	if(name || phone || !to_add.name || !to_add.phone)
	{
		return 0;
	}
	name = new char[strlen(to_add.name) + 1];
	strcpy(name, to_add.name);
	phone = new char[strlen(to_add.phone) + 1];
	strcpy(phone, to_add.phone);
	return 1;
}


bool contact::compare(char * key_value)
{
	if(!name)
	{
		return false;
	}
	if(strcmp(name, key_value) == 0)
	{
		return true;
	}
	return false;
}


int contact::display(char * key_value)
{
	if(!name || !phone) return 0;
	cout << "Name : " << name << endl;
	cout << "Phone : " << phone << endl;
	return 1;
}


int contact::find_name(char *& found)
{
	if(!name) return 0;
	found = new char[strlen(name) + 1];
	strcpy(found, name);
	return 1;
}


table::table(int size)
{
	adjacency_list = new vertex[size];
	for(int i = 0; i < size; ++i)
	{
		adjacency_list[i].a_contact = NULL;
		adjacency_list[i].head = NULL;
	}
	list_size = size;
}


table::~table()
{
	int count = 0;
	count = delete_all();
	list_size = 0;
}


int table::delete_all()
{
	if(!adjacency_list)
	{
		return 0;
	}
	int count = 0;
	for(int i = 0; i < list_size; ++i)
	{
		/*
		if(adjacency_list[i].a_contact)
		{
			adjacency_list[i].a_contact->~table();
		}
		*/
		if(adjacency_list[i].head)
		{
			count += delete_all(adjacency_list[i].head);
		}
	}
	delete [] adjacency_list;
	adjacency_list = NULL;
	return count;
}


int table::delete_all(node * head)
{
	if(!head) return 0;
	node * hold = head->next;
	head->adjacent = NULL;
	head->next = NULL;
	delete head;
	head = hold;
	if(!head)
	{
		return 1;
	}
	return delete_all(head->next) + 1;
}


int table::insert_vertex(const add_a_contact & to_add)
{
	if(!to_add.name || !to_add.phone)
	{
		return 0;
	}
	if(!adjacency_list)
		return 0;
	int i = 0;
	while(adjacency_list[i].a_contact && i < list_size)
	{
		++i;
	}

	if(i == list_size)
		return 0;
	contact * temp = new contact;
	if(temp->insert(to_add))
	{
		adjacency_list[i].a_contact = temp;
		return 1;
	}
	delete [] temp;
	return 0;
	return i;
}


int table::find_location(char * key)
{
	if(!adjacency_list || !key)
		return -1;
	int index = 0;
	return find_location(index, key);
}


int table::find_location(int index, char * key)
{
	if(index == list_size)
		return -1;
	if(adjacency_list[index].a_contact->compare(key))
		return index;
	++index;
	return find_location(index, key);
}	


int table::insert_edge(char * current_vertex, char * to_attach)
{
	int index1 = find_location(current_vertex);
	int index2 = find_location(to_attach);
	node * temp = new node;
	temp->adjacent = &(adjacency_list[index2]);
	temp->next = adjacency_list[index1].head;
	adjacency_list[index1].head = temp;
	return 1;
}


int table::display_adjacency(char * key_value)
{
	if(!key_value)
		return 0;
	int index = find_location(key_value);
	int count = 0;
	if(!adjacency_list[index].a_contact)
		return 0;
	if(!adjacency_list[index].head)
	{
		count = adjacency_list[index].a_contact->display(key_value);
		return count;
	}
	count = adjacency_list[index].a_contact->display(key_value);
	return display_adjacency(adjacency_list[index].head, key_value);
}


int table::display_adjacency(node * head, char * key_value)
{
	if(!head)
		return 0;
	int count = 1;
	count += head->adjacent->a_contact->display(key_value);
	count += display_adjacency(head->next, key_value);

	char * local_key = NULL;

	if(head->adjacent->a_contact->find_name(local_key))
	{
		count += display_adjacency(local_key);
		--count;
	}
	return count;
}

