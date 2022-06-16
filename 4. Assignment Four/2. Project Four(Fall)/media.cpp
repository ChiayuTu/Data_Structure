#include "media.h"

using namespace std;

media::media()
{
	name = NULL;
	related = NULL;
	for(int i = 0; i < 3; ++i)
	{
		description[i] = NULL;
	}
	length = NULL;	
}

media::~media()
{
	if(name)
		delete [] name;
	if(related)
		delete [] related;
	if(description[0])
	{
		for(int i = 0; i < 3; ++i)
		{
			delete [] description[i];
			description[i] = NULL;
		}
	}
	if(length)
		delete [] length;

	related = name = length = NULL;
}

int media::add_a_media(hold_a_media & to_add)
{
	if(!to_add.name)
		return 0;
	name = new char[strlen(to_add.name) + 1];
	related = new char[strlen(to_add.related) + 1];
	for(int i = 0; i < 3; ++i)
	{
		description[i] = new char[strlen(to_add.description[i]) + 1];
		strcpy(description[i], to_add.description[i]);
	}
	length = new char[strlen(to_add.length) + 1];
	strcpy(name, to_add.name);
	strcpy(related, to_add.related);
	strcpy(length, to_add.length);

	return 1;
}

int media::search_a_media(char * describe_value, hold_a_media & hold)
{
	if(!describe_value)
		return 0;
	int success = 0;
	int i = 0;
	while(i < 3)
	{
		if(strcmp(describe_value, description[i]) == 0)
		{
			hold.name = new char[strlen(name) + 1];
			strcpy(hold.name, name);
			hold.related = new char[strlen(related) + 1];
			strcpy(hold.related, related);
			for(int i = 0; i < 3; ++i)
			{
				hold.description[i] = new char[strlen(description[i]) + 1];
				strcpy(hold.description[i], description[i]);
			}
			hold.length = new char[strlen(length) + 1];
			strcpy(hold.length, length);
			success = 1;
			i = 3;
		}
		++i;
	}
	return success;
}

int media::remove_a_media(char * media_to_remove)
{
	if(!media_to_remove)
		return 0;
	if(strcmp(name, media_to_remove) == 0)
	{
		delete [] name;
		delete [] related;
		for(int i = 0; i < 3; ++i)
		{
			delete [] description[i];
			description[i] = NULL;
		}
		delete [] length;
		name = related = length = NULL;

		return 1;
	}
	return 0;
}

int media::display()
{
	if(!name || !related || !description[0] || !length)
		return 0;
	cout << "The name of the media         : " << name << endl;
	cout << "Media related to the class    : " << related << endl;
	for(int i = 0; i < 3; ++i)
	{
		if(description[i])
		{		
			cout << "The descriptions of the media : " << description[i] << endl;
		}
	}
	cout << "The length of the media       : " << length << endl;
	return 1;
}

char * media::find_media()
{
	if(!name)
		return NULL;
	return name;
}

char * media::find_description(int i)
{
	if(!description[i])
		return NULL;
	return description[i];
}

table::table()		//constructor
{
	root = NULL;
}

table::~table()		//destructor
{
	int success = 0;
	success = remove_all();
}

int table::remove_all()  //to destroy everything in the tree
{
	if(!root)
		return 0;
	return remove_all(root);
}

int table::remove_all(node *& root)	//recursion part
{
	if(!root)
		return 0;
	int remove = 0;
	remove += remove_all(root->left) + remove_all(root->right);
	if(root)
	{
		root->data->~media();
		delete root->data;
		root->data = NULL;
		delete root;
	}
	root = NULL;
	return 1+remove;
}

int table::add(hold_a_media & to_add)	//to add a node into the tree
{
	if(!to_add.name || !to_add.related || !to_add.description[0] || !to_add.length)
		return 0;
	if(!root)
	{
		node * temp = new node;
		temp->data = new media; 
		if(!temp->data->add_a_media(to_add))
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

int table::add(node * & root, hold_a_media & to_add)	//recursion part
{
	if(!root)
	{
		node * temp = new node;
		temp->data = new media;
		if(!temp->data->add_a_media(to_add))
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
	if(strcmp(to_add.name, root->data->find_media()) < 0)
	{
		success = add(root->left, to_add);
	}	
	else if(strcmp(to_add.name, root->data->find_media()) >= 0)
	{
		success = add(root->right, to_add);
	}
	return success;
}

int table::search(char * describe_value, hold_a_media & hold)
{
	if(!describe_value)
	{
		return 0;
	}
	return search(root, describe_value, hold);
}

int table::search(node * root, char * describe_value, hold_a_media & hold)	//recursion part
{
	if(!root)
		return 0;
	if(root->data->search_a_media(describe_value, hold))
		return 1;
	return search(root->left, describe_value, hold) + search(root->right, describe_value, hold);
}

node* table::find_ios(node * previous, media *& hold_data)	//return a current pointer pointing to the ios with the pointer pointing to the ios data
{
	if(!root->right)
		return NULL;
	return find_ios(root->right, hold_data);
}
node* table::find_ios(node * root, node * previous, media *& hold_data)	//also get the previous pointer to delete the ios
{
	node* current = NULL;
	if(!root->left)
	{
		hold_data = root->data; 	//share the data by the pointer
		return root;
	}
	previous = root;
	current = find_ios(root->left, hold_data);
	return current;
}

int table::remove(char * name)	
{
	if(!name)
		return 0;
	if(!root)
		return 0;
	return remove(root, name);
}

int table::remove(node * & root, char * name)	//recursion part
{
	if(!root)
		return 0;
	int count = 0;
	if(root->data->remove_a_media(name))
	{
		if(!root->left && !root->right)		//delete leaf
		{
			delete root->data;
			root->data = NULL;
			delete root;
			root = NULL;
			return 1;
		}
		else if(root->left && !root->right)	//delete the node with only one child : left
		{
			node * hold = root->left;
			delete root->data;
			root->data = NULL;
			delete root;
			root = hold;
			return 1;
		}
		else if(!root->left && root->right)	//delete the node with only one child : right
		{
			node * hold = root->right;
			delete root->data;
			root->data = NULL;
			delete root;
			root = hold;
			return 1;
		}
		else					//delete the node with 2 children
		{
			delete root->data;
			node * previous = root;
			node * current = find_ios(previous, root->data);		//current points to the ios node and previous is behind the current, and copy the data from ios
			if(current)
			{
				if(current->right)
				{
					node * hold = current->right;	//hold for ios
					current->data = new media;	//avoid affecting the data which the matching node is pointing to
					delete current->data;
					current->data = NULL;
					current->right = NULL;
					if(!previous->right->data)	//determine which way we should connect to the hold data
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
					current->data = new media;	//avoid affecting the data which the matching node is pointing to
					delete current->data;
					current->data = NULL;
					if(!previous->right->data)	//determine the ios was on which way
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

	count = remove(root->left, name);
	count += remove(root->right, name);
	return count;
}

int table::display_match(char * description)	//to display a matching data
{
	if(!root)
		return 0;
	if(!description)
		return 0;
	return display_match(root, description);
}

int table::display_match(node * root, char * description)	//recursion part
{
	if(!root)
		return 0;
	int count = 0;
	int i = 0;
	while(i<3)
	{
		if(strcmp(root->data->find_description(i), description) == 0)
		{
			count += root->data->display();
			i = 3;
		}
		++i;
	}
	i = 0;
	count += display_match(root->left, description) + display_match(root->right, description);
	return count;
}

int table::get_height()		//to get the height of the tree
{
	if(!root)
		return 0;
	return get_height(root);
}

int table::get_height(node * root)	//recursion part
{
	if(!root)
		return 0;
	int left_height, right_height = 0;
	left_height += get_height(root->left) + 1;
	right_height += get_height(root->right) + 1;
	return max(left_height,right_height);
}

int table::display_all()	//to display all information in the tree
{
	if(!root)
		return 0;
	return display_all(root);
}

int table::display_all(node * root)	//recursion part
{
	if(!root)
		return 0;
	int count = 0;
	count += root->data->display();
	count += display_all(root->left) + display_all(root->right);
	return count;
}

















