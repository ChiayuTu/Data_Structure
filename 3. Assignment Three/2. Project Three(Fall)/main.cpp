#include"item.h"

using namespace std;

int main()
{
	table smaller(5);
	table bigger(37);

	hold_an_item hold;
	hold.item_name = NULL;
	hold.location = NULL;
	for(int i = 0; i < 3; ++i)
	{
		hold.hint[i] = NULL;
	}

	hold.item_name = new char[SIZE];
	hold.location = new char[SIZE];
	for(int i = 0; i < 3; ++i)
	{
		hold.hint[i] = new char[SIZE];
	}

	cout << "we have read in " << smaller.read_in(hold) << " data in the size 5 table" << endl;
	cout << "we have read in " << bigger.read_in(hold) << " data in the size 37 table" << endl;

	hold.item_name = NULL;
	hold.location = NULL;
	for(int i = 0; i < 3; ++i)
	{
		hold.hint[i] = NULL;
	}


	int answer = 0;
	cout << "Enter the number to choose what you want to do" << endl << endl
		<< "#1 - Add" << endl
		<< "#2 - Search" << endl
		<< "#3 - Remove" << endl
		<< "#4 - Display" << endl
		<< "#5 - Display all" << endl
		<< "#6 - Quit" << endl;

	cin >> answer;
	cin.ignore(100, '\n');

	while(answer != 6)
	{
		hold.item_name = new char[SIZE];
		hold.location = new char[SIZE];
		for(int i = 0; i < 3; ++i)
		{
			hold.hint[i] =  new char[SIZE];
		}

		if(answer == 1)
		{
			cout << "Please enter the item's name" << endl;
			cin.get(hold.item_name, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "Please enter the location of item" << endl;
			cin.get(hold.location, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "Please enter the hints of this item" << endl;
			for(int i = 0; i < 3; ++i)
			{
				cin.get(hold.hint[i], SIZE, '\n');
				cin.ignore(100, '\n');
			}

			cout << "We have added " << smaller.add(hold) << " data in the size 5 table" << endl;
			cout << "We have added " << bigger.add(hold) << " data in the size 37 table" << endl;
		}

		if(answer == 2)
		{
			cout << "Please enter hints for searching the item" << endl;
			cin.get(hold.hint[0], SIZE, '\n');
			cin.ignore(100, '\n');

			if(smaller.search(hold))
			{
				cout << "We find it in the table" << endl;

				cout << "The information we have searched for the hint is :" << endl;
				cout << "Item name : " << hold.item_name << endl;
				cout << "Location  : " << hold.location << endl;
				for(int i = 0; i < 3; ++i)
				{
					cout << "Hint      : " << hold.hint[i] << endl;	
				}
			}

			if(hold.item_name)
			{
				delete [] hold.item_name;
				hold.item_name = NULL;
			}

			if(hold.location)
			{
				delete [] hold.location;
				hold.location = NULL;
			}

			for(int i = 0; i < 3; ++i)
			{
				if(hold.hint[i])
				{
					delete [] hold.hint[i];
					hold.hint[i] = NULL;
				}
			}

			if(bigger.search(hold))
			{
				cout << "We find it in the table" << endl;

				cout << "The information we have searched for the hint is :" << endl;
				cout << "Item name : " << hold.item_name << endl;
				cout << "Location  : " << hold.location << endl;
				for(int i = 0; i < 3; ++i)
				{
					cout << "Hint      : " << hold.hint[i] << endl;	
				}
			}
		}

		if(answer == 3)
		{
			cout << "Please type in an item's name for removing the item in the table" << endl;
			cin.get(hold.item_name, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "We have removed " << smaller.remove(hold.item_name) << " data in the size 5 table" << endl;
			cout << "We have removed " << bigger.remove(hold.item_name) << " data in the size 37 table" << endl;

			cout << "There are " << smaller.display_all() << " data in the size 5 table" << endl;
			cout << "There are " << bigger.display_all() << " data in the size 37 table" << endl;
		}

		if(answer == 4)
		{
			cout << "Please enter the hint of display all matched in the table" << endl;
			cin.get(hold.hint[0], SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "There are " << smaller.display_match(hold.hint[0]) << " matched in the size 5 table";
			cout << "There are " << bigger.display_match(hold.hint[0]) << " matched in the size 37 table";
		}

		if(answer == 5)
		{
			cout << "The smaller table with size 5 : " << endl;
			cout << "There are " << smaller.display_all() << " data in the size 5 table" << endl;

			cout << "The bigger table with size 37 : " << endl;
			cout << "There are " << bigger.display_all() << " data in the size 37 table" << endl;
		}


		int answer = 0;
		cout << "Enter the number to choose what you want to do" << endl << endl
			<< "#1 - Add" << endl
			<< "#2 - Search" << endl
			<< "#3 - Remove" << endl
			<< "#4 - Display" << endl
			<< "#5 - Display all" << endl
			<< "#6 - Quit" << endl;

		cin >> answer;
		cin.ignore(100, '\n');

		if(hold.item_name)
		{
			delete [] hold.item_name;
			hold.item_name = NULL;
		}

		if(hold.location)
		{
			delete [] hold.location;
			hold.location = NULL;
		}

		for(int i = 0; i < 3; ++i)
		{
			if(hold.hint[i])
			{
				delete [] hold.hint[i];
				hold.hint[i] = NULL;
			}
		}
	}
	return 0;

}
