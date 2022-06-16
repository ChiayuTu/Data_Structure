#include"project.h"

using namespace std;

int main()
{	
	list in_list;
	proj_to_add to_add;
	char matching_name[30] = {'\0'};
	char info_to_add[30] = {'\0'};

	//Interface
	int ans = 0;
	cout << "Please enter the number to choose what you want to do." << endl
		<< "#1 - Add a new project." << endl
		<< "#2 - Remove a project." << endl
		<< "#3 - Display." << endl
		<< "#4 - Quit the system." << endl;

	cin >> ans;
	cin.ignore(100, '\n');

	while(ans != 5)
	{
		matching_name[30] = {'\0'};
		info_to_add[30] = {'\0'};

		if(ans == 1)
		{
			cout << "Please enter the name of this project." << endl;
			cin.get(to_add.proj_name, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Please estimate how much you will cost." << endl;
			cin.get(to_add.proj_cost, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Please estimate how long this project will be finish." << endl;
			cin.get(to_add.proj_time, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Please enter the name of the company to be hired." << endl;
			cin.get(to_add.proj_hire, 30, '\n');
			cin.ignore(100, '\n');

			cout << "Please estimate the time when you expect the prokect to be done." << endl;
			cin.get(to_add.proj_done, 30, '\n');
			cin.ignore(100, '\n');

			if(in_list.add(to_add))
			{
				cout << "There are information about your project" << endl << in_list.display() << " in the list." << endl;
			}
		}
		if(ans == 2)
		{
			cout << "There are information about your project" << endl << in_list.display() << " in the list." << endl;
			cout << "Please enter the name of your project for removing" << endl;
			cin.get(matching_name, 30, '\n');
			cin.ignore(100, '\n');

			cout << "The project is removed " << in_list.remove(matching_name) << endl;
			cout << "The project in the list, there still have " << endl << in_list.display() << endl;
		}
		if(ans == 3)
		{
			cout << "There are all of the project in your list" << endl << endl  << in_list.display() << endl << endl;

		}
	

	////////////////////////////////////////////////////////////////////////
	cout << "Please enter the number to choose what you want to do." << endl
		<< "#1 - Add a new project." << endl
		<< "#2 - Remove a project." << endl
		<< "#3 - Display." << endl
		<< "#4 - Quit the system." << endl;

	cin >> ans;
	cin.ignore(100, '\n');
	}
	return 0;
}
