#include"list.h"


//prototype
void welcome_page();

int main()
{
	char item_name[name_size];
	char item_ctgry[ctgry_size];
	float item_price;
	item an_item;
	list items;

	welcome_page();
	int option = 1;
	cout << "#1 Enter your items" << endl
		<< "#2 Display your items" << endl
		<< "#3 Search your item" << endl
		<< "#4 Exit" << endl;

	do
	{
		cout << "Select one option." << endl;
		cin >> option;
		cin.ignore(100, '\n');
		if(option == 1)
		{	
			int i = 0;
			int read_in_num = 0;
			cout << "How many items do you want to read into the system" << endl;
			cin >> read_in_num;
			cin.ignore(100, '\n');
			while(i < read_in_num)
			{
				++i;
				cout << "Enter the item's name" << endl;
				cin.get(item_name, name_size, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the item's category" << endl;
				cin.get(item_ctgry, ctgry_size, '\n');
				cin.ignore(100, '\n');

				cout << "Enter the item's price" << endl;
				cin >> item_price;
				cin.ignore(100, '\n');

				//an_item.add_item(item_name, item_ctgry, item_price);
				an_item.add_item(item_name, item_ctgry, item_price);
				an_item.display_item();
				items.add(an_item);
				items.display();
				/*
				if(i == read_in_num)
				{
					int response;
					cout << "Do you want to keep storing items into the system? (y/n)";
					cin >> response;
					cin.ignore(100, '\n');
					if(toupper(response) == 'Y')
					{
						cout << "HOw many do you want to store into the system" << endl;
						cin >> read_in_num;
						cin.ignore(100, '\n');
						i = 0;
					}
				}
				*/
			}
		}else if(option == 2)
		{
			cout << "There are all the items to be stored." << endl;
			items.display();
		}else if(option == 3)
		{

		}else if(option == 4)
		{
			cout << "Thank you for using this app." << endl;
		}
	}while(option < 4);

	//an_item.add_item(item_name, item_ctgry, item_price);
	//an_item.display_item();


	//
	//items.add(an_item);
	//items.display();

	return 0;

}

void welcome_page()
{
	char response = 'y';
	cout << "Welcome to use this system" << endl;
	cout << "Do you need any introduction for how to use this system(y/n)." << endl;
	cin >> response;
	cin.ignore(100, '\n');
	if(toupper(response) == 'Y')
	{
		cout << "How to use this app" << endl;
	}else if(toupper(response) == 'N')
	{
		cout << "Begin now." << endl;
	}
}










