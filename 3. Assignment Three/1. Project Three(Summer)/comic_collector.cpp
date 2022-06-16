#include"comic_collector.h"
/*
	char * comic_name;
	char * publisher;
	char * comic_hero;
	char * issue;
	char * interested;
*/
comic::comic()
{
	comic_name = NULL;
	publisher = NULL;
	comic_hero = NULL;
	issue = NULL;
	interested = NULL;	
}


comic::~comic()
{
	if(comic_name)
		delete [] comic_name;
	if(publisher)
		delete [] publisher;
	if(comic_hero)
		delete [] comic_hero;
	if(issue)
		delete [] issue;
	if(interested)
		delete [] interested;

	comic_name = NULL;
	publisher = NULL;
	comic_hero = NULL;
	issue = NULL;
	interested = NULL;
}


int comic::add_a_comic(comic_info & to_add)
{
	if(!to_add.comic_name) return 0;
	
	comic_name = new char[strlen(to_add.comic_name) + 1];
	publisher = new char[strlen(to_add.publisher) + 1];
	comic_hero = new char[strlen(to_add.comic_hero) + 1];
	issue = new char[strlen(to_add.issue) + 1];
	interested = new char[strlen(to_add.interested) + 1];	
	strcpy(comic_name, to_add.comic_name);
	strcpy(publisher, to_add.publisher);
	strcpy(comic_hero, to_add.comic_hero);
	strcpy(issue, to_add.issue);
	strcpy(interested, to_add.interested);

	return 1;
}


int comic::remove_a_comic(char * to_remove)
{
	if(!to_remove) return 0;
	if(strcmp(comic_name, to_remove) == 0)
	{
		delete [] comic_name;
		delete [] publisher;
		delete [] comic_hero;
		delete [] issue;
		delete [] interested;

		comic_name = NULL;
		publisher = NULL;
		comic_hero = NULL;
		issue = NULL;
		interested = NULL;

		return 1;
	}
	return 0;
}


int comic::display()
{
	if(!comic_name || !publisher || !comic_hero || !issue || interested) return 0;
	cout << "The comic name is " << comic_name << endl;
	cout << "The publisher is " << publisher << endl;
	cout << "The hero in the comic is " << comic_hero << endl;
	cout << "The issue is " << issue << endl;
	cout << "What you interested in is " << interested << endl;
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
			hash_table[i]->data.~comic();
			delete hash_table[i];
			hash_table[i] = temp;
		}
	}
	delete [] hash_table;
	table_size = 0;
}


int table::read_in_comic(comic_info & to_add)
{
	int count = 0;
	ifstream file_in;
	file_in.open(file_name);

	if(file_in)
	{
		file_in.get(to_add.comic_name, SIZE, '|');
		file_in.ignore(100, '|');
		while(!file_in.eof())
		{
			file_in.get(to_add.publisher, SIZE, '|');
			file_in.ignore(100, '|');

			file_in.get(to_add.comic_hero, SIZE, '|');
			file_in.ignore(100, '|');

			file_in.get(to_add.issue, SIZE, '|');
			file_in.ignore(100, '|');

			file_in.get(to_add.interested, SIZE, '|');
			file_in.ignore(100, '|');


			//reset
			if(add(to_add))
			{
				++count;
			}

			if(to_add.comic_name)
			{
				delete [] to_add.comic_name;
				to_add.comic_name = NULL;
			}

			if(to_add.publisher)
			{
				delete [] to_add.publisher;
				to_add.publisher = NULL;
			}

			if(to_add.comic_hero)
			{
				delete [] to_add.comic_hero;
				to_add.comic_hero = NULL;
			}

			if(to_add.issue)
			{
				delete [] to_add.issue;
				to_add.issue = NULL;
			}

			if(to_add.interested)
			{
				delete [] to_add.interested;
				to_add.interested = NULL;
			}

			if(!file_in.eof())
			{
				to_add.comic_name = new char[SIZE];
				to_add.publisher = new char[SIZE];
				to_add.comic_hero = new char[SIZE];
				to_add.issue = new char[SIZE];
				to_add.interested = new char[SIZE];
				file_in.get(to_add.comic_name, SIZE, '|');
				file_in.ignore(100, '|');
			}
		}
		file_in.close();
		file_in.clear();
	}
	return count;
}


int table::hash_table_func(char * key)
{
	if(!key) return 0;
	int len = strlen(key);
	int sum = 0;

	for(int j = 0; j < len; ++j)
	{
		sum += key[j] * key[j] + j * j;
	}

	sum = sum % table_size;

	if(sum < 0)
	{
		sum = -sum;
	}

	return sum;
}


int table::add(comic_info & to_add)
{
	if(!to_add.comic_name || !to_add.publisher || !to_add.comic_hero || !to_add.issue || !to_add.interested)
	{
		return 0;
	}

	node * temp = new node;
	if(temp->data.add_a_comic(to_add))
	{
		delete temp;
		return 0;
	}
	
	int index = hash_table_func(to_add.comic_name);
	temp->next = hash_table[index];
	hash_table[index] = temp;
	
	return 1;
}


int table::remove(char * comic_name)
{
	if(!comic_name) return 0;
	if(!hash_table)	return 0;
	int i =0;
	int count = 0;
	while(i < table_size)
	{
		if(hash_table[i])
		{
			count += remove(hash_table[i], comic_name);
		}
		++i;
	}
	return count;
}


int table::remove(node *& ptr, char * comic_name)
{
	int count = 0;
	if(!ptr) return 0;
	if(ptr->data.remove_a_comic(comic_name))
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
	count += remove(ptr->next, comic_name);
	return count;
}


int table::display_all()
{
	if(!hash_table)
	{
		return 0;
	}
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
	{
		return 0;
	}
	int count = 0; 
	count += ptr->data.display();
	return display_all(ptr->next);
}


























