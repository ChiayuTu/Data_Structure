#include"item.h"

using namespace std;

item::item()
{
	item_name = NULL;
	location = NULL;
	for(int i = 0; i < 3; ++i)
	{
		hint[i] = NULL;
	}
}

item::~item()
{
	if(item_name)
		delete [] item_name;
	if(location)
		delete [] location;
	if(hint[0])
	{
		for(int i = 0; i < 3; ++i)
		{
			delete [] hint[i];
			hint[i] = NULL;
		}
	}
	item_name = location = NULL;
}

int item::add_an_item(hold_an_item & to_add)
{
	if(!to_add.item_name)
		return 0;
	item_name = new char[strlen(to_add.item_name) + 1];
	location = new char[strlen(to_add.location) + 1];
	strcpy(item_name, to_add.item_name);
	strcpy(location, to_add.location);
	for(int i = 0; i < 3; ++i)
	{
		hint[i] = new char[strlen(to_add.hint[i]) + 1];
		strcpy(hint[i], to_add.hint[i]);
	}

	return 1;
}

int item::search_an_item(hold_an_item & hold)
{
	if(!hold.hint[0])
		return 0;
	int success = 0;
	int i = 0;
	while(i < 3)
	{
		if(strcmp(hold.hint[0], hint[i]) == 0)
		{
			hold.item_name = new char[strlen(item_name) + 1];
			strcpy(hold.item_name, item_name);
			hold.location = new char[strlen(location) + 1];
			strcpy(hold.location, location);
			for(int i = 0; i < 3; ++i)
			{
				hold.hint[i] = new char[strlen(hint[i]) + 1];
				strcpy(hold.hint[i], hint[i]);
			}
			success = 1;
			i = 3;
		}
		++i;
	}
	return success;
}

int item::remove_an_item(char * item_to_remove)
{
	if(!item_to_remove)
		return 0;
	if(strcmp(item_name, item_to_remove) == 0)
	{
		delete [] item_name;
		delete [] location;
		for(int i = 0; i < 3; ++i)
		{
			delete [] hint[i];
			hint[i] = NULL;
		}
		item_name = NULL;
		location = NULL;
		return 1;
	}
	return 0;
}

int item::display()
{
	if(!item_name || !location || !hint[0])
		return 0;
	cout << "item_name : " << item_name << endl;
	cout << "location  : " << location  << endl;
	for(int i = 0; i < 3; ++i)
	{
		cout << "Hints are : " << hint[i] << endl;
	}
	return 1;
}

table::table(int size)
{
	hash_table = new node * [size];
	for(int i = 0; i < size; ++i)
	{
		hash_table[i] = NULL;
	}
	table_size = size;
}

table::~table()
{
	int size = table_size;
	for(int i = 0; i < size; ++i)
	{
		while(hash_table[i])
		{
			node * temp = hash_table[i]->next;
			hash_table[i]->data.~item();
			delete hash_table[i];
			hash_table[i] = temp;
		}
	}
	delete [] hash_table;
	table_size = 0;
}

int table::read_in(hold_an_item & to_add)
{
	int count = 0;
	ifstream file_in;
	file_in.open(file_name);

	while(!file_in.eof())
	{
		if(file_in)
		{
			file_in.get(to_add.item_name, SIZE, '|');
			file_in.ignore(100, '|');

			file_in.get(to_add.location, SIZE, '|');
			file_in.ignore(100, '|');

			for(int i = 0; i < 3; ++i)
			{
				file_in.get(to_add.hint[i], SIZE, '|');
				file_in.ignore(100, '|');
			}

			if(add(to_add))
			{
				++count;
			}

			if(to_add.item_name)
			{
				delete [] to_add.item_name;
				to_add.item_name = NULL;
			}

			if(to_add.location)
			{
				delete [] to_add.location;
				to_add.location = NULL;
			}

			for(int i = 0; i < 3; ++i)
			{
				if(to_add.hint[i])
				{
					delete [] to_add.hint[i];
					to_add.hint[i] = NULL;
				}
			}

			if(!file_in.eof())
			{
				to_add.item_name = new char[SIZE];
				to_add.location = new char[SIZE];
				for(int i = 0; i < 3; ++i)
				{
					to_add.hint[i] = new char[SIZE];
				}
				file_in.get(to_add.item_name, SIZE, '|');
				file_in.ignore(100, '|');
			}
		}
		file_in.close();
		file_in.clear();
	}	
	return count;
}

int table::hash_function(char * hint)
{
	if(!hint)
		return 0;
	int i = strlen(hint);
	int sum = 0;
	for(int j = 0; j < i; ++j)
	{
		sum += hint[j] * hint[j] + j * j;
	}
	sum = sum % table_size;
	if(sum < 0)
	{
		sum = -sum;
	}
	return sum;
}

int table::add(hold_an_item & to_add)
{
	if(!to_add.item_name || !to_add.location || !to_add.hint[0])
		return 0;
	node * temp = new node;
	if(!temp->data.add_an_item(to_add))
	{
		delete temp;
		return 0;
	}
	int index = hash_function(to_add.hint[0]);
	temp->next = hash_table[index];
	hash_table[index] = temp;

	return 1;
}

int table::search(hold_an_item & hold)
{
	if(hold.hint[0])
		return 0;
	int index = hash_function(hold.hint[0]);
	if(!hash_table[index])
		return 0;
	return search(hash_table[index], hold);
}

int table::search(node * ptr, hold_an_item & hold)
{
	if(!ptr)
		return 0;
	if(ptr->data.search_an_item(hold))
		return 1;
	return search(ptr->next, hold);
}

int table::remove(char * item_name)
{
	if(!item_name)
		return 0;
	if(!hash_table)
		return 0;
	int i = 0;
	int count = 0;
	while(i < table_size)
	{
		if(hash_table[i])
		{
			count += remove(hash_table[i], item_name);
		}
		++i;
	}
	return count;
}

int table::remove(node *& ptr, char * item_name)
{
	if(!ptr)
		return 0;
	int count = 0;
	if(ptr->data.remove_an_item(item_name))
	{
		node * temp = ptr->next;
		ptr->next = NULL;
		delete ptr;
		ptr = temp;
		++count;
		if(!ptr)
		{
			return 0;
		}
	}
	count += remove(ptr->next, item_name);
	return count;
}

int table::display_match(char * hint)
{
	if(!hint)
		return 0;
	int index = hash_function(hint);
	if(!hash_table[index])
	{
		return 0;
	}
	return display_match(hash_table[index], hint);
}

int table::display_match(node * ptr, char * hint)
{
	if(!ptr)
		return 0;
	int count = 0;
	count += ptr->data.display();
	return display_match(ptr->next, hint) + count;
}

int table::display_all()
{
	if(!hash_table)
		return 0;
	int i = 0;
	int count = 0;
	while(i < table_size)
	{
		count += display_all(hash_table[i]);
		++i;
	}
	return count;
}

int table::display_all(node * ptr)
{
	if(!ptr)
		return 0;
	int count = 0;
	count += ptr->data.display();
	return display_all(ptr->next);
}
































































































