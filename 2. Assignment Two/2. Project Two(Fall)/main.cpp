#include "alert.h"

using namespace std;

int main()
{
	queue list;
	//stack info;
	alert * to_add;
	alert at_top;
	to_add = NULL;
	at_top.orig = NULL;
	at_top.date = NULL;
	at_top.time = NULL;
	at_top.mess = NULL;
	at_top.other = NULL;

	int answer = 0;
	cout << "Please enter the number to choose what you want to do. If the" << endl
		<< " 1 : push a new alert in the list" << endl
		<< " 2 : pop the first alert in the list" << endl
		<< " 3 : peek the messages of the first alert" << endl
		<< " 4 : display the information of the alert in the list" << endl
		<< " 5 : quit the progtram" << endl << endl;

	cin >> answer;
	cin.ignore(100, '\n');

	while(answer != 5)
	{
		if(answer == 1)
		{
			to_add = new alert;
			to_add->orig = new char[31];
			to_add->date = new char[31];
			to_add->time = new char[31];
			to_add->mess = new char[31];
			to_add->other = new char[31];

			cout << "Plaese form the message of the alert you want to add in the system" << endl;
			cout << "Please type in the origination of the alert" << endl;
			cin.get(to_add->orig, 30, '\n');
			cin.ignore(100, '\n');
			cout << "Please type in the date" << endl;
			cin.get(to_add->date, 30, '\n');
			cin.ignore(100, '\n');
			cout << "Please type in the time" << endl;
			cin.get(to_add->time, 30, '\n');
			cin.ignore(100, '\n');
			cout << "Please type in the message" << endl;
			cin.get(to_add->mess, 30, '\n');
			cin.ignore(100, '\n');
			cout << "Please type in other message" << endl;
			cin.get(to_add->other, 30, '\n');
			cin.ignore(100, '\n');

			cout << "You have pushed " << list.enqueue(to_add) << " alert from the list" << endl;
			cout << "There are " << endl << list.display_queue() << " in the list" << endl;
		}

		if(answer == 2)
		{
			cout << "You have popped " << list.dequeue() << "alert from the list" << endl;
			cout << "There are " << endl << list.display_queue() << " in the list" << endl;	
		}

		if(answer == 3)
		{
			at_top.orig = new char[31];
			at_top.date = new char[31];
			at_top.time = new char[31];
			at_top.mess = new char[31];
			at_top.other = new char[31];
			if(list.peek(at_top))
			{
				cout << "There are at least one alert in the list" << endl << endl;

				cout << "The alert of the top package is : " << endl;
				cout << "The origination :" << at_top.orig << endl;
				cout << "The date        :" << at_top.date << endl;
				cout << "The time        :" << at_top.time << endl;
				cout << "The message     :" << at_top.mess << endl;
				cout << "Other message   :" << at_top.other << endl;
			}else
			{
				cout << "There is no any alert in the list" << endl;
			}
		}

		if(answer == 4)
		{
			if(!list.display_queue())
			{
				cout << "There is an empty in the list" << endl;
			}
		}


		cout << "Please enter the number to choose what you want to do. If the" << endl
			<< " 1 : push a new alert in the list" << endl
			<< " 2 : pop the first alert in the list" << endl
			<< " 3 : peek the messages of the first alert" << endl
			<< " 4 : display the information of the alert in the list" << endl
			<< " 5 : quit the progtram" << endl << endl;

		cin >> answer;
		cin.ignore(100, '\n');

		if(to_add)
		{
			delete [] to_add->orig; 
			delete [] to_add->date; 
			delete [] to_add->time; 
			delete [] to_add->mess; 
			delete [] to_add->other; 
			to_add->orig = NULL;
			to_add->date = NULL;
			to_add->time = NULL;
			to_add->mess = NULL;
			to_add->other = NULL;
			delete to_add;
			to_add = NULL;
		}

		if(at_top.orig)
		{
			delete [] at_top.orig;
			delete [] at_top.date;
			delete [] at_top.time;
			delete [] at_top.mess;
			delete [] at_top.other;
			at_top.orig = NULL;
			at_top.date = NULL;
			at_top.time = NULL;
			at_top.mess = NULL;
			at_top.other = NULL;
		}
	}

	return 0;
}
























