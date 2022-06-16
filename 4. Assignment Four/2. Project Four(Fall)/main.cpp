#include "media.h"

using namespace std;


int main()
{
	table tree;
	char * describe_value = NULL;
	int counter = 0;
	hold_a_media hold;	//representing to_add or retrieve as the argument what we have searched
	hold.name = NULL;
	hold.related = NULL;
	for(int i=0;i<3;++i)
	{
		hold.description[i] = NULL;
	}
	hold.length = NULL;


	hold.name = new char[SIZE];
	hold.related = new char[SIZE];
	for(int i=0;i<3;++i)
	{	
		hold.description[i] = new char[SIZE];
	}
	hold.length = new char[SIZE];


	hold.name = NULL;
	hold.related = NULL;
	for(int i=0;i<3;++i)
	{
		hold.description[i] = NULL;
	}
	hold.length = NULL;

	int answer = 0;
	cout << "Please enter a number to choose what you want to do next." << endl << endl;
	cout << "#1 - Add." << endl
		<< "#2 - Search" << endl
		<< "#3 - Remove" << endl 
		<< "#4 - Display" << endl
		<< "#5 - Display all" << endl
		<< "#6 - Get height of the tree" << endl
		<< "#7 - Quit" << endl;
	cin>>answer;
	cin.ignore(100,'\n');

	while(answer != 7)
	{
		hold.name = new char[SIZE];
		hold.related = new char[SIZE];
		for(int i=0;i<3;++i)
		{
			hold.description[i] = new char[SIZE];
		}
		hold.length = new char[SIZE];
		describe_value = new char[SIZE];

		if(answer == 1)
		{
			cout << "Please enter the name of this media." << endl;
			cin.get(hold.name, SIZE, '\n');
			cin.ignore(100, '\n');

			cout<<"Please enter the class which related to this media."<<endl;
			cin.get(hold.related, SIZE, '\n');
			cin.ignore(100,'\n');

			cout<<"Please enter three descriptions of this media."<<endl;
			for(int i=0; i<3; ++i)
			{
				cin.get(hold.description[i], SIZE, '\n');
				cin.ignore(100,'\n');
			}

			cout<<"Please enter the length of this media"<<endl;
			cin.get(hold.length, SIZE, '\n');
			cin.ignore(100,'\n');

			cout<<"We have added "<<tree.add(hold)<<" data in the tree."<<endl;

			cout<<"There are "<<tree.display_all()<<" data in the tree."<<endl;
		}

		if(answer == 2)
		{
			cout<<"Please enter a description for searching."<<endl;
			cin.get(describe_value, SIZE, '\n');
			cin.ignore(100, '\n');

			if(tree.search(describe_value, hold))
			{
				cout<<"We find it in the tree !!"<<endl;

				cout<<"The information we have searched for the description is : "<<endl;
				cout<<"The name of the media      : "<< hold.name <<endl;
				cout<<"The related class of media : "<< hold.related <<endl;
				for(int i=0;i<3;++i)
				{
					cout<<"The descriptions of media  : "<< hold.description[i] <<endl;
				}
				cout<<"The length of media        : "<< hold.length <<endl<<endl;
			}
			else
			{
				cout<<"We didn't find it in the tree !!"<<endl;
			}
		}

		if(answer == 3)
		{
			cout<<"Please enter a media name for removing the related data in the tree."<<endl;
			cin.get(hold.name, SIZE, '\n');
			cin.ignore(100, '\n');

			cout<<"We have removed "<<tree.remove(hold.name)<<" data in the tree."<<endl;

			cout<<"There are "<<tree.display_all()<<" data in the tree."<<endl;
		}

		if(answer == 4)
		{
			cout<<"Please enter a description to display all matched in the tree."<<endl;
			cin.get(hold.description[0], SIZE, '\n');
			cin.ignore(100, '\n');

			cout<<"There are "<< tree.display_match(hold.description[0]) <<" matches in the tree." << endl;
		}

		if(answer == 5)
		{
			cout<<"There are "<< tree.display_all() <<" data in the tree."<<endl;
		}

		if(answer == 6)
		{
			cout<<"The height of the tree is : "<<tree.get_height()<<endl;
		}

		cout << "Please enter a number to choose what you want to do next." << endl << endl;
		cout << "#1 - Add." << endl
			<< "#2 - Search" << endl
			<< "#3 - Remove" << endl 
			<< "#4 - Display" << endl
			<< "#5 - Display all" << endl
			<< "#6 - Get height of the tree" << endl
			<< "#7 - Quit" << endl;
		cin>>answer;
		cin.ignore(100,'\n');

		if(hold.name)			//reset
		{
			delete [] hold.name;
			hold.name = NULL;
		}
		if(hold.related)
		{
			delete [] hold.related;
			hold.related = NULL;
		}
		for(int i=0;i<3;++i)
		{
			if(hold.description[i])
			{
				delete [] hold.description[i];
				hold.description[i] = NULL;
			}
		}
		if(hold.length)
		{
			delete [] hold.length;
			hold.length = NULL;
		}
		if(describe_value)
		{
			delete [] describe_value;
			describe_value = NULL;
		}

		if(counter != 0)
		{
			counter = 0;
		}
	}
	return 0;
}
