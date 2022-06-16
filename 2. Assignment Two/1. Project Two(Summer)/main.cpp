#include"alert.h"

using namespace std;

int main()
{
	stack my_alert;
	queue my_alert_queue;
	alert to_add, at_top;
	char person_name[20];
	char cellphone[11];
	char place[50];


	//Add a person's information
	char response;
	do
	{
		//char response;
		cout << "Enter your full name : " << endl;
		cin.get(to_add.person_name, 20, '\n'); cin.ignore(100, '\n');
		cout << "Enter the place where you want to go : " << endl;
		cin.get(to_add.place, 50, '\n'); cin.ignore(100, '\n');
		cout << "Enter your cellphone : " << endl;
		cin.get(to_add.cellphone, 11, '\n'); cin.ignore(100, '\n');

		my_alert.push(to_add.person_name, to_add.place);
		my_alert_queue.enqueue(to_add.cellphone);


		cout << "Again (Y/N)" << endl;
		cin >> response; cin.ignore(100, '\n');
		response = toupper(response);

	}while(response = 'Y');

	cout << "\n\nThis is the contents of the stack: " << endl;
	my_alert.display();
	my_alert_queue.display_queue();
	return 0;


	if( my_alert.pop())
	{
		cout << "removing the contents in the stack" << endl;
		my_alert.display();
	}
	else cout << "nothing could be removed, the stack is empty" << endl;
	
	if(my_alert_queue.dequeue())
	{
		cout << "removing the contents in the queue" << endl;
		my_alert_queue.display_queue();
	}
	else cout << "Nothing could be removed, the queue is empty" << endl;

	return 0;
}



















