
#include"graph.h"

using namespace std;

int main() 
{
	table graph;
	add_a_contact hold;
	hold.name = NULL;
	hold.phone = NULL;
	char * key_value;

	int answer = 0;
	cout <<"Please type a number" << endl << endl
		<< "#1 - Add" << endl
		<< "#2 - inserting" << endl
		<< "#3 - display all" << endl
		<< "#4 - Quit" << endl;
	cin >> answer;
	cin.ignore(100, '\n');

	while(answer != 4)
	{
		hold.name = new char[SIZE];
		hold.phone = new char[SIZE];
		key_value = new char[SIZE];

		if(answer == 1)
		{
			cout << "type name" << endl;
			cin.get(hold.name, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "type phone" << endl;
			cin.get(hold.phone, SIZE, '\n');
			cin.ignore(100, '\n');

			cout << "we have added " << graph.insert_vertex(hold) << " vertex in the graph" << endl << endl;

			cout << "There are " << endl << graph.display_adjacency(hold.name) << "vertex on the path from " << hold.name << " to " << endl << " other adjacent vertex and those adjacent vertex to its adjacent vertex in the graph." << endl << endl;
		}

		if(answer == 2)
		{
			cout << "type name " << endl;
			cin.get(hold.name, SIZE-1, '\n');
			cin.ignore(100, '\n');

			cout << "type phone " << endl;
			cin.get(hold.phone, SIZE-1, '\n');
			cin.ignore(100, '\n');

			cout << " We have built " << graph.insert_edge(hold.name, key_value) << " connection from " << hold.name << " to " << key_value << endl << endl;

			cout << "There are " << endl << graph.display_adjacency(hold.name) << " vertex on the path from " << hold.name << " to " << endl << " other adjacent vertex and those adjacent vertex in the graph." << endl << endl;
		}

		if(answer == 3)
		{
			cout << "type name to display" << endl;
			cin.get(hold.name, SIZE - 1, '\n');
			cin.ignore(100, '\n');

			cout << "There are " << endl << graph.display_adjacency(hold.name) << " vertex on the path from " << hold.name << " to " << endl << " other adjacent vertex and those adjacent vertex in the graph." << endl << endl;
		}


		cout <<"Please type a number" << endl << endl
			<< "#1 - Add" << endl
			<< "#2 - inserting" << endl
			<< "#3 - display all" << endl
			<< "#4 - Quit" << endl;
		cin >> answer;
		cin.ignore(100, '\n');

		if(hold.name)
		{
			hold.name[0] = '\0';
			delete [] hold.name;
			hold.name = NULL;
		}	

		if(hold.phone)
		{
			hold.phone[0] = '\0';
			delete [] hold.phone;
			hold.phone = NULL;
		}	

		if(key_value)
		{
			key_value[0] = '\0';
			delete [] key_value;
			key_value = NULL;
		}	

	}
	return 0;
}
