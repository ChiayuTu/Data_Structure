#include"comic_collector.h"

comic::comic()
{
	comic_name = NULL;
	publisher = NULL;
	comic_info = NULL;
	for(int i = 0; i < 3; ++i)
	{
		item[i] = NULL;
	}
	issue = NULL;
}


comic::~comic()
{
	if(comic_name)
		delete [] comic_name;
	if(publisher)
		delete [] publisher;
	if(comic_info)
		delete [] comic_info;
	if(item[0])
	{
		for(int i = 0; i < 3; ++i)
		{
			delete [] item[i];
			item[i] = NULL;
		}
	}
	if(issue)
		delete [] issue;
	comic_name = publisher = comic_info = issue = NULL;
}


int comic::add_a_comic(a_comic & to_add)
{
	if(!to_add.comic_name)
		return 0;
	comic_name = new char[strlen(to_add.comic_name) + 1];
	strcpy(comic_name, to_add.comic_name);
	publisher = new char[strlen(to_add.publisher) + 1];
	strcpy(publisher, to_add.publisher);
	comic_info = new char[strlen(to_add.comic_info) + 1];
	strcpy(comic_info, to_add.comic_info);
	for(int i = 0; i < 3; ++i)
	{
		item[i] = new char[strlen(to_add.item[i])+ 1];
		strcpy(item[i], to_add.item[i]);
	}
	issue = new char[strlen(to_add.issue) + 1];
	strcpy(issue, to_add.issue);

	return 1;
}


int comic::search_a_comic(char * item_value, a_comic & hold)
{
	if(!item_value)
	{
		return 0;
	}
	int success = 0;
	int i = 0;
	while(i < 3)
	{
		if(strcmp(item_value, item[i]) == 0)
		{
			hold.comic_name = new char[strlen(comic_name) + 1];
			strcpy(hold.comic_name, comic_name);
			hold.publisher = new char[strlen(publisher) + 1];
			strcpy(hold.publisher, publisher);
			hold.comic_info = new char[strlen(comic_info) + 1];
			strcpy(hold.comic_info, comic_info);
			for(int i = 0; i < 3; ++i)
			{
				hold.item[i] = new char[strlen(item[i]) + 1];
				strcpy(hold.item[i], item[i]);
			}
			hold.issue = new char[strlen(issue) + 1];
			strcpy(hold.issue, issue);
			success = 1;
			i = 3;
		}
		++i;
	}
	return success;
}


int comic::remove_a_comic(char * comic_to_remove)
{
	if(!comic_to_remove)
	{
		return 0;
	}
	if(strcmp(comic_name, comic_to_remove) == 0)
	{
		delete [] comic_name;
		delete [] publisher;
		delete [] comic_info;
		for(int i = 0; i < SIZE; ++i)
		{
			delete [] item[i];
			item[i] = NULL;
		}
		delete [] issue;
		comic_name = publisher = comic_info = issue = NULL;

		return 1;
	}
	return 0;
}


int comic::display_a_comic()
{
	if(!comic_name || !publisher || !comic_info || !item[0] || !issue)
	{
		return 0;
	}
	cout << "Comic name is :" << comic_name << endl;
	cout << "The publisher is :" << publisher << endl;
	cout << "Comic information is :" << comic_info << endl;
	for(int i = 0; i < 3; ++i)
	{
		if(item[i])
		{
			cout << "the item is :" << item[i] << endl;
		}
	}
	cout << "The issue is :" << issue << endl;

	return 1;
}


char* comic::find_comic()
{
	if(!comic_name)
	{
		return NULL;
	}
	return comic_name;
}


char* comic::find_item(int i)
{
	if(!item[i])
	{
		return NULL;
	}
	return item[i];
}

/////////////////////

table::table()
{
	root = NULL;
}


table::~table()
{
	int success = 0;
	success = remove_all();
}


int table::remove_all()
{
	if(!root)
	{
		return 0;
	}
	return remove_all(root);
}


int table::remove_all(node *& root)
{
	if(!root)
	{
		return 0;
	}
	int remove = 0;
	remove += remove_all(root->left) + remove_all(root->right);

	if(root)
	{
		root->data->~comic();
		delete root->data;
		root->data = NULL;
		delete root;
	}
	root = NULL;
	return 1 + remove;
}


int table::add(a_comic & to_add)
{
	if(!to_add.comic_name || !to_add.publisher || !to_add.comic_info || !to_add.item[0] || !to_add.issue)
	{
		return 0;
	}
	if(!root)
	{
		node * temp = new node;
		temp->data = new comic;
		if(!temp->data->add_a_comic(to_add))
		{
			delete temp->data;
			delete temp;
			return 0;
		}
		temp->left = temp->right = NULL;
		root = temp;
		return 1;
	}

	return add(root, to_add);
}


int table::add(node *& root, a_comic & to_add)
{
	if(!root)
	{
		node * temp = new node;
		temp->data = new comic;
		if(!temp->data->add_a_comic(to_add))
		{
			delete temp->data;
			delete temp;
			return 0;
		}
		temp->left = temp->right = NULL;
		root = temp;
		return 1;
	}
	int success = 0;
	if(strcmp(to_add.comic_name, root->data->find_comic()) < 0)
	{
		success = add(root->left, to_add);
	}
	else if(strcmp(to_add.comic_name, root->data->find_comic()) >= 0)
	{
		success = add(root->right, to_add);
	}
	return success;
}


int table::read_in(a_comic & to_add)
{
	int count;
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

			file_in.get(to_add.comic_info, SIZE, '|');
			file_in.ignore(100, '|');

			for(int i = 0; i < 3; ++i)
			{
				file_in.get(to_add.item[i], SIZE, '|');
				file_in.ignore(100, '|');
			}

			file_in.get(to_add.issue, SIZE, '|');
			file_in.ignore(100, '|');

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

			if(to_add.comic_info)
			{
				delete [] to_add.comic_info;
				to_add.comic_info = NULL;
			}

			for(int i = 0; i < 3; ++i)
			{
				if(to_add.item[i])
				{
					delete [] to_add.item[i];
					to_add.item[i] = NULL;
				}
			}

			if(to_add.issue)
			{
				delete [] to_add.issue;
				to_add.issue =NULL;
			}

			if(!file_in.eof())
			{
				to_add.comic_name = new char[SIZE];
				to_add.publisher = new char[SIZE];
				to_add.comic_info = new char[SIZE];
				for(int i = 0; i < 3; ++i)
				{
					to_add.item[i] = new char[SIZE];
				}
				to_add.issue = new char[SIZE];
				file_in.get(to_add.comic_name, SIZE, '|');
				file_in.ignore(100, '|');
			}
		}
		file_in.close();
		file_in.clear();
	}
	return count;
}


int table::search(char * item_value, a_comic & hold)
{
	if(!item_value)
	{
		return 0;
	}
	return search(root, item_value, hold);
}


int table::search(node * root, char * item_value, a_comic & hold)
{
	if(!root)
	{
		return 0;
	}
	if(root->data->search_a_comic(item_value, hold))
	{
		return 1;
	}
	return search(root->left, item_value, hold) + search(root->left, item_value, hold);
}


node* table::find_ios(node * previous, comic *& hold_data)
{
	if(!root->right)
	{
		return NULL;
	}
	return find_ios(root->right, hold_data);
}


node* table::find_ios(node * root, node * previous, comic *& hold_data)
{
	node * current = NULL;
	if(!root->left)
	{
		hold_data = root->data;
		return root;
	}
	previous = root;
	current = find_ios(root->left, hold_data);
	return current;
}


int table::remove(char * comic_name)
{
	if(!comic_name)
	{
		return 0;
	}
	if(!root)
	{
		return 0;
	}
	return remove(root, comic_name);
}


int table::remove(node * root, char * comic_name)
{
	if(!root)
	{
		return 0;
	}

	int count;

	if(root->data->remove_a_comic(comic_name))
	{
		if(!root->left && !root->right)
		{
			delete root->data;
			root->data = NULL;
			delete root;
			root = NULL;
			return 1;
		}
		else if(root->left && !root->right)
		{
			node * hold = root->left;
			delete root->data;
			root->data = NULL;
			delete root;
			root = hold;
			return 1;
		}
		else if(!root->left && root->right)
		{
			node * hold = root->right;
			delete root->data;
			root->data = NULL;
			delete root;
			root = hold;
			return 1;
		}
		else
		{
			delete root->data;
			node * previous =root;
			node * current = find_ios(previous, root->data);

			if(current)
			{
				if(current->right)
				{
					node * hold = current->right;
					current->data = new comic;
					delete current->data;
					current->data = NULL;
					current->right = NULL;
					if(!previous->right->data)
					{
						previous->right = hold;
					}
					else if(!previous->left->data)
					{
						previous->left = hold;
					}
					return 1;
				}
				else
				{
					current->data = new comic;
					delete current->data;
					current->data = NULL;
					if(!previous->right->data)
					{
						previous->right = NULL;
					}
					else if(!previous->left->data)
					{
						previous->left = NULL;
					}

					return 1;
				}
			}
		}
	}

	count = remove(root->left, comic_name);
	count += remove(root->right, comic_name);
	return count;
}


int table::dispaly_match(char * item)
{
	if(!root)
	{
		return 0;
	}
	if(!item)
	{
		return 0;
	}
	return display_match(root, item);
}


int table::display_match(node * root, char * item)
{
	if(!root)
	{
		return 0;
	}
	int count = 0;
	int i = 0;
	while(i < 3)
	{
		if(strcmp(root->data->find_item(i), item) == 0)
		{
			count += root->data->display_a_comic();
			i = 3;
		}
		++i;
	}
	i = 0;
	count += display_match(root->left, item) + display_match(root->right, item);
	return count;
}


int table::display_all()
{
	if(!root)
	{
		return 0;
	}
	return display_all(root);
}


int table::display_all(node * root)
{
	if(!root)
	{
		return 0;
	}
	int count = 0;
	count += root->data->display_a_comic();
	count += display_all(root->left) + display_all(root->right);
	return count;
}

















































































































































