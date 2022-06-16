#include"comic_collector.h"

using namespace std;

int main()
{
	table tree;
	int count;
	char * item_value = NULL;
	a_comic hold;
	/////////////////
	hold.comic_name = NULL;
	hold.publisher = NULL;
	hold.comic_info = NULL;
	for(int i = 0; i < 3; ++i)
	{
		hold.item[i] = NULL;
	}
	hold.issue = NULL;
	///////////////////////////
	hold.comic_name = new char[SIZE];
	hold.publisher = new char[SIZE];
	hold.comic_info = new char[SIZE];
	for(int i = 0; i < 3; ++i)
	{
		hold.item[i] = new char[SIZE];
	}
	hold.issue = new char[SIZE];


	hold.comic_name = NULL;
	hold.publisher = NULL;
	hold.comic_info = NULL;
	for(int i = 0; i < 3; ++i)
	{
		hold.item[i] = NULL;
	}
	hold.issue = NULL;
	////////////////////////////


	int option = 0;
	do
	{
		cout << "Please enter an option" << endl;
		cout << "#1 - Adding" << endl;
		cout << "#2 - Searching" << endl;
		cout << "#3 - Removing by comic name in the tree" << endl;
		cout << "#4 - Display by item name" << endl;
		cout << "#5 - Display all" << endl;
		cout << "#8 - quit" << endl;

		cin >> option;
		cin.ignore(100, '\n');


		hold.comic_name = new char[SIZE];
		hold.publisher = new char[SIZE];
		hold.comic_info = new char[SIZE];
		for(int i = 0; i < 3; ++i)
		{
			hold.item[i] = new char[SIZE];
		}
		hold.issue = new char[SIZE];


		if(option == 1)
		{
			char answer;
			do
			{
				cout << "Please enter the comic name" << endl;
				cin.get(hold.comic_name, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "Please enter the publisher" << endl;
				cin.get(hold.publisher, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "please enter the information of comic" << endl;
				cin.get(hold.comic_info, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "Please three here of this comic" << endl;
				for(int i = 0; i < 3; ++i)
				{
					cin.get(hold.item[i], SIZE, '\n');
					cin.ignore(100, '\n');
				}

				cout << "Please enter some issue of this comic" << endl;
				cin.get(hold.issue, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "Again y/n" << endl;
				cin >> answer;
				cin.ignore(100, '\n');
				answer = toupper(answer);

			}while(answer == 'Y');

		}
		if(option == 2)
		{
			cout << "Please an item word of the comic for searching" << endl;
			cin.get(item_value, SIZE, '\n');
			cin.ignore(100, '\n');

			if(tree.search(item_value, hold))
			{
				cout << "Found it in the tree." << endl;

				cout << "There are the information :" << endl;
				cout << "Comic name: " << hold.comic_name << endl;
				cout << "Publisher: " << hold.publisher << endl;
				cout << "Comic information: " << hold.comic_info << endl;
				for(int i = 0; i < 3; ++i)
				{
					cout << "The item :" << hold.item[i] << endl;
				}
				cout << "The issue: " << hold.issue << endl;
			}
			else
			{
				cout << "Not in the tree" << endl;
			}
		}
		if(option == 3)
		{
			cout << "Please type the comic name to remove relevant information." << endl;
			cin.get(hold.comic_name, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "Removed successful" << tree.remove(hold.comic_name) << endl;
			cout << "there are " << tree.display_all() << "data in the tree" << endl;
		}
		if(option == 4)
		{
			cout << "type the item's name to display all matched in the tree" << endl;
			cin.get(hold.item[0], SIZE, '\n');
			cin.ignore(100, '\n');
	
			cout << "there are " << tree.display_all() << "data in the tree" << endl;
		}
		if(option == 5)
		{	
			cout << "there are " << tree.display_all() << "data in the tree" << endl;
		}
		if(option == 8)
		{
			cout << "Thank you for using" << endl;
		}




	}while(option < 8);












	return 0;
}
