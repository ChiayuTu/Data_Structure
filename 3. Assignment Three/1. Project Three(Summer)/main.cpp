#include"comic_collector.h"

using namespace std;


int main()
{
	table smallest(6);
	table biggest(50);
	table comic_table(30);

	comic_info hold;
	hold.comic_name = NULL;
	hold.publisher = NULL;
	hold.comic_hero = NULL;
	hold.issue = NULL;
	hold.interested = NULL;

	hold.comic_name = new char[SIZE];
	hold.publisher = new char[SIZE];
	hold.comic_hero = new char[SIZE];
	hold.issue = new char[SIZE];
	hold.interested = new char[SIZE];

	/*
	cout << "Read in " << smallest.read_in_comic(hold) << " data in 6 tables." << endl
		<< "Read in " << biggest.read_in_comic(hold) << " data in 50 tables." << endl;
	*/


	hold.comic_name = NULL;
	hold.publisher = NULL;
	hold.comic_hero = NULL;
	hold.issue = NULL;
	hold.interested = NULL;


	////////////////////////////////////

	char response = 'Y';
	do
	{
		int option;
		cout << "Please enter an option that what you want to do." << endl;
		cout << "#1 - Adding a new comic" << endl
			<< "#2 - Searching" << endl
			<< "#3 - Remove" << endl
			<< "#4 - Display" << endl
			<< "#5 - Quit" << endl;
		cin >> option;
		cin.ignore(100, '\n');

		if(option == 1)
		{
			do
			{
				hold.comic_name = new char[SIZE];
				hold.publisher = new char[SIZE];
				hold.comic_hero = new char[SIZE];
				hold.issue = new char[SIZE];
				hold.interested = new char[SIZE];

				cout << "Please enter the comic's name." << endl;
				cin.get(hold.comic_name, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "PLease enter the publisher." << endl;
				cin.get(hold.publisher, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "PLease enter the name of the hero." << endl;
				cin.get(hold.comic_hero, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "Please enter the issue." << endl;
				cin.get(hold.issue, SIZE, '\n');
				cin.ignore(100, '\n');

				cout << "PLease let us know what you are interested in." << endl;
				cin.get(hold.interested, SIZE, '\n');
				cin.ignore(100, '\n');

				comic_table.read_in_comic(hold);


				cout << "We have added " << comic_table.add(hold) << " data in the size 5 tables" << endl;
				cout << "There is your data " << comic_table.display_all() << endl;
				

				cout << "Again (y/n)?" << endl;
				cin >> response;
				cin.ignore(100, '\n');
			

			}while(response == 'y');
			response = toupper(response);


		}else if(option == 2)
		{

		}else if(option == 3)
		{
			cout << "PLease enter the comic's name for removing the relevant data in the table." << endl;
			cin.get(hold.comic_name, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "There is your data " << comic_table.display_all() << endl;

		response = 'N';	

		}else if(option == 4)
		{
			cout << "There is all of your data." << endl;
			cout << "The table with size 30:" << endl;
			cout << "There are " << comic_table.display_all() << "data in the size 30 tables" << endl;

			response = 'N';

		}else if(option == 5)
		{
			cout << "Are you really want to Quit (Y/N)" << endl;
			cin >> response;
			cin.ignore(100, '\n');

			response = toupper(response);

		}
	}while(response != 'Y');







}
