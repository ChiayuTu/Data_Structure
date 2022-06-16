//Chiayu Tu CS163 program#2 Assignment
#include"alert.h"

stack::stack()
{
	head = NULL;
	top_index = 0;	
}

stack::~stack()
{
	while(head)
	{
		if(top_index == 1)
		{
			if(head->next)
			{
				s_node * hold = head;
				delete [] head->data[top_index - 1].person_name;
				head->data[top_index - 1].person_name = NULL;
				delete [] head->data[top_index - 1].place;
				head->data[top_index - 1].place = NULL;
				head = head->next;
				delete [] head->data;
				head->data = NULL;
				top_index = 5;
			}
			else
			{
				delete [] head->data[top_index - 1].person_name;
				head->data[top_index - 1].person_name = NULL;
				delete [] head->data[top_index - 1].place;
				head->data[top_index - 1].place = NULL;
				head = head->next;
				delete [] head->data;
				head->data = NULL;
				top_index = 0;
			}
		}
		else
		{
			delete [] head->data[top_index - 1].person_name;
			head->data[top_index - 1].person_name = NULL;
			delete [] head->data[top_index - 1].place;
			head->data[top_index - 1].place = NULL;
			head = head->next;
			delete [] head->data;
			head->data = NULL;
			--top_index;
		}
	}
	head = NULL;
	top_index = 0;
}


int stack::push(alert * to_add)
{
	if(!to_add) return 0;

	return push(head, to_add);
}


int stack::push(s_node *& head, alert * to_add)
{
	if(!head)
	{
		head = new s_node;
		head->data = new alert[MAX];
		head->data[top_index].person_name = new char[strlen(to_add->person_name) + 1];
		strcpy(head->data[top_index].person_name, to_add->person_name);
		head->data[top_index].place = new char[strlen(to_add->place) + 1];
		strcpy(head->data[top_index].place, to_add->place);

		for(int i = 0; i < 5; ++i)
		{
			head->data[i].person_name = NULL;
			head->data[i].place = NULL;
		}

		head->data = NULL;
		++top_index;
		return 1;
	}
	if(top_index == 5)
	{
		s_node * temp = new s_node;
		temp->data = new alert[MAX];
		temp->data[0].person_name = new char[strlen(to_add->person_name) + 1];
		strcpy(temp->data[0].person_name, to_add->person_name);
		temp->data[0].place = new char[strlen(to_add->place) + 1];
		strcpy(temp->data[0].place, to_add->place);

		for(int i = 0; i < 5; ++i)
		{
			temp->data[i].person_name = NULL;
			temp->data[i].place = NULL;
		}
		temp->next = head;
		head = temp;
		top_index = 1;
		return 1;
	}
	else if(top_index < 5)
	{

		head->data[top_index].person_name = new char[strlen(to_add->person_name) + 1];
		strcpy(head->data[top_index].person_name, to_add->person_name);
		head->data[top_index].place = new char[strlen(to_add->place) + 1];
		strcpy(head->data[top_index].place, to_add->place);
		++top_index;
		return 1;
	}
}


int stack::pop()
{
	if(!head)
		return 0;
	return pop(head);
}


int pop(s_node * head)
{
	if(top_index == 1)
	{
		if(head->next)
		{
			s_node * hold = head;
			delete [] head->data[top_index - 1].person_name;
			head->data[top_index - 1].person_name = NULL;
			delete [] head->data[top_index - 1].place;
			head->data[top_index - 1].place = NULL;
			head = head->next;
			hold->data = NULL;
			top_index = 5;
			return 1;
		}
		else
		{
			delete [] head->data[top_index - 1].person_name;
			head->data[top_index - 1].person_name = NULL;
			delete [] head->data[top_index - 1].place;
			head->data[top_index - 1].place = NULL;
			delete [] head->data;
			head->data = NULL;
			delete head;
			head = NULL;
			top_index = 0;
			return 0;
		}
	}
	delete [] head->data[top_index - 1].person_name;
	head->data[top_index - 1].person_name = NULL;
	delete [] head->data[top_index - 1].place;
	head->data[top_index - 1].place = NULL;
	--top_index;
	return 1;
}


int stack::peek(alert & at_top)
{
	if(!head) return 0;
	strcpy(at_top.person_name, head->data[top_index - 1].person_name);
	strcpy(at_top.place, head->data[top_index - 1].place);
	return 1;
}


int stack::display()
{
	if(!head) return 0;
	int i = 0;
	if(i == 5)
	{
		return MAX * display(head);
	}
	else
	{
		int count = 0;
		int after_first_node = 0;
		while(i < top_index)
		{
			cout << "Person's information :" << head->data[i].person_name << endl;
			cout << "Alert place :" << head->data[i].place << endl;
			++i;
			++count;
		}

		if(head->next)
		{
			after_first_node = display(head->next);
		}
		return count + MAX * after_first_node;
	}
}


int stack::display(s_node * head)
{
	if(!head) return 0;
	int i = 0;
	while(i < 5)
	{
		cout << "Person's information :" << head->data[i].person_name << endl;
		cout << "Alert place :" << head->data[i].place << endl;
		++i;
	}	
	return display(head->next) + 1;
}


queue::queue()
{
	front = NULL;
	rear = NULL;
}


queue::~queue()
{
	while(front)
	{
		if(front == front->next_queue)
		{
			front->stack_object.~stack();
			delete [] front->address;
			front->address = NULL;
			front->next_queue = NULL;
			delete front;
			front = rear = NULL;
		}	
		else
		{
			front->stack_object.~stack();
			delete [] front->address;
			front->address = NULL;
			rear->next_queue = front->next_queue;
			front->next_queue = NULL;
			delete front;
			front = rear->next_queue;
		}
	}
	front = rear = NULL;
}


int queue::enqueue(alert * to_add)
{
	if(!to_add) return 0;
	return dequeue(rear, to_add);
}


int queue::enqueue(q_node * & rear, alert * to_add)
{
	if(!front || !rear)
	{
		rear = new q_node;
		rear->stack_object.push(to_add);
		rear->address = new char[strlen(to_add->cellphone) + 1];
		strcpy(rear->address, to_add->cellphone);
		rear->next_queue = rear;
		front = rear;
		return 1;
	}
}


int queue::dequeue()
{
	if(!front) return 0;
	if(!front->next_queue == front)
	{
		if(!front->stack_object.pop())
		{
			delete [] front->address;
			front->address = NULL;
			front->next_queue = NULL;
			delete front;
			front = rear = NULL;
			return 1;
		}
		
	}
	else
	{
		if(!front->stack_object.pop())
		{
			delete [] front->address;
			front->address = NULL;
			rear->next_queue = front->next_queue;
			front->next_queue = NULL;
			delete front;
			front = rear->next_queue;
			return 1;
		}
	}
}


int queue::peek(alert & at_top)
{
	if(!front) return 0;
	return front->stack_object.peek(at_top);
}


int queue::display_queue()
{
	if(!front)
	{
		return 0;
	}
	if(front == front->next_queue)
	{
		int success;
		success = front->stack_object.display();
		return success;	
	}
	return display_queue(front, rear);
}


int queue::display_queue(q_node * front, q_node * rear)
{
	int success = 0;
	if(!front == rear)
	{
		success = front->stack_object.display();
		return 1;
	}
	success = front->stack_object.display();
	return display_queue(front->next_queue, rear) + 1;
}



















