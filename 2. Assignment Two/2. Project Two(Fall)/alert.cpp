#include "alert.h"

using namespace std;

stack::stack()
{
	top_index = 0;
	head = NULL;	
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
				delete [] head->data[top_index - 1].orig;
				delete [] head->data[top_index - 1].date;
				delete [] head->data[top_index - 1].time;
				delete [] head->data[top_index - 1].mess;
				delete [] head->data[top_index - 1].other;
				head->data[top_index - 1].orig = NULL;
				head->data[top_index - 1].date = NULL;
				head->data[top_index - 1].time = NULL;
				head->data[top_index - 1].mess = NULL;
				head->data[top_index - 1].other = NULL;
				head = head->next;
				delete [] hold->data;
				hold->data = NULL;
				top_index = 5;
			}else
			{
				delete [] head->data[top_index - 1].orig;
				delete [] head->data[top_index - 1].date;
				delete [] head->data[top_index - 1].time;
				delete [] head->data[top_index - 1].mess;
				delete [] head->data[top_index - 1].other;
				head->data[top_index - 1].orig = NULL;
				head->data[top_index - 1].date = NULL;
				head->data[top_index - 1].time = NULL;
				head->data[top_index - 1].mess = NULL;
				head->data[top_index - 1].other = NULL;
				head = head->next;
				delete [] head->data;
				head->data = NULL;
				top_index = 0;
			}
		}else
		{
			delete [] head->data[top_index - 1].orig;
			delete [] head->data[top_index - 1].date;
			delete [] head->data[top_index - 1].time;
			delete [] head->data[top_index - 1].mess;
			delete [] head->data[top_index - 1].other;
			head->data[top_index - 1].orig = NULL;
			head->data[top_index - 1].date = NULL;
			head->data[top_index - 1].time = NULL;
			head->data[top_index - 1].mess = NULL;
			head->data[top_index - 1].other = NULL;
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
		head->data = new alert[Max];
		head->data[top_index].orig = new char[strlen(to_add->orig) + 1];
		head->data[top_index].date = new char[strlen(to_add->date) + 1];
		head->data[top_index].time = new char[strlen(to_add->time) + 1];
		head->data[top_index].mess = new char[strlen(to_add->mess) + 1];
		head->data[top_index].other = new char[strlen(to_add->other) + 1];
		strcpy(head->data[top_index].orig, to_add->orig);
		strcpy(head->data[top_index].date, to_add->date);
		strcpy(head->data[top_index].time, to_add->time);
		strcpy(head->data[top_index].mess, to_add->mess);
		strcpy(head->data[top_index].other, to_add->other);
		for(int i = 1; i < 5; ++i)
		{
			head->data[i].orig = NULL;
			head->data[i].date = NULL;
			head->data[i].time = NULL;
			head->data[i].mess = NULL;
			head->data[i].other = NULL;
		}
		head->next = NULL;
		++top_index;
		return 1;
	}
	if(top_index == 5)
	{
		s_node * temp = new s_node;
		temp->data = new alert[Max];
		temp->data[0].orig = new char[strlen(to_add->orig) + 1];
		temp->data[0].date = new char[strlen(to_add->date) + 1];
		temp->data[0].time = new char[strlen(to_add->time) + 1];
		temp->data[0].mess = new char[strlen(to_add->mess) + 1];
		temp->data[0].other = new char[strlen(to_add->other) + 1];
		strcpy(temp->data[0].orig, to_add->orig);
		strcpy(temp->data[0].date, to_add->date);
		strcpy(temp->data[0].time, to_add->time);
		strcpy(temp->data[0].mess, to_add->mess);
		strcpy(temp->data[0].other, to_add->other);
		for(int i = 1; i < 5; ++i)
		{
			temp->data[i].orig = NULL;
			temp->data[i].date = NULL;
			temp->data[i].time = NULL;
			temp->data[i].mess = NULL;
			temp->data[i].other = NULL;
		}
		temp->next = head;
		head = temp;
		top_index = 1;
		return 1;
	}
	else if(top_index < 5)
	{
		head->data[top_index].orig = new char[strlen(to_add->orig) + 1];
		head->data[top_index].date = new char[strlen(to_add->date) + 1];
		head->data[top_index].time = new char[strlen(to_add->time) + 1];
		head->data[top_index].mess = new char[strlen(to_add->mess) + 1];
		head->data[top_index].other = new char[strlen(to_add->other) + 1];
		strcpy(head->data[top_index].orig, to_add->orig);
		strcpy(head->data[top_index].date, to_add->date);
		strcpy(head->data[top_index].time, to_add->time);
		strcpy(head->data[top_index].mess, to_add->mess);
		strcpy(head->data[top_index].other, to_add->other);
		++top_index;
		return 1;
	}
	return 0;
}

int stack::pop()
{
	if(!head) return 0;
	return pop(head);
}

int stack::pop(s_node *& head)
{
	if(top_index == 1)
	{
		if(head->next)
		{
			s_node * hold = head;
			delete [] head->data[top_index - 1].orig;
			delete [] head->data[top_index - 1].date;
			delete [] head->data[top_index - 1].time;
			delete [] head->data[top_index - 1].mess;
			delete [] head->data[top_index - 1].other;
			head->data[top_index - 1].orig = NULL;
			head->data[top_index - 1].date = NULL;
			head->data[top_index - 1].time = NULL;
			head->data[top_index - 1].mess = NULL;
			head->data[top_index - 1].other = NULL;
			head = head->next;
			hold->data = NULL;
			top_index = 5;
			return 1;
		}else
		{
			delete [] head->data[top_index - 1].orig;
			delete [] head->data[top_index - 1].date;
			delete [] head->data[top_index - 1].time;
			delete [] head->data[top_index - 1].mess;
			delete [] head->data[top_index - 1].other;
			head->data[top_index - 1].orig = NULL;
			head->data[top_index - 1].date = NULL;
			head->data[top_index - 1].time = NULL;
			head->data[top_index - 1].mess = NULL;
			head->data[top_index - 1].other = NULL;
			delete [] head->data;
			head->data = NULL;
			delete head;
			head = NULL;
			top_index = 0;
			return 0;
		}
	}
	delete [] head->data[top_index - 1].orig;
	delete [] head->data[top_index - 1].date;
	delete [] head->data[top_index - 1].time;
	delete [] head->data[top_index - 1].mess;
	delete [] head->data[top_index - 1].other;
	head->data[top_index - 1].orig = NULL;
	head->data[top_index - 1].date = NULL;
	head->data[top_index - 1].time = NULL;
	head->data[top_index - 1].mess = NULL;
	head->data[top_index - 1].other = NULL;
	--top_index;
	return 1;
}

int stack::peek(alert & at_top)const
{
	if(!head) return 0;
	strcpy(at_top.orig, head->data[top_index - 1].orig);
	strcpy(at_top.date, head->data[top_index - 1].date);
	strcpy(at_top.time, head->data[top_index - 1].time);
	strcpy(at_top.mess, head->data[top_index - 1].mess);
	strcpy(at_top.other, head->data[top_index - 1].other);
	return 1;
}

int stack::display()
{
	if(!head) return 0;
	int i = 0;
	if(i == 5) 
		return Max * display(head);
	else
	{
		int count = 0;
		int after_first_node = 0;
		while(i < top_index)
		{
			cout << "The alert information : " << endl;
			cout << "The origination       : " << head->data[i].orig << endl;
			cout << "The date              : " << head->data[i].date << endl;
			cout << "The time              : " << head->data[i].time << endl;
			cout << "The message           : " << head->data[i].mess << endl;
			cout << "Other message         : " << head->data[i].other << endl;
			++i;
			++count;
		}
		if(head->next)
		{
			after_first_node = display(head->next);
		}
		return count + Max * after_first_node;
	}
}

int stack::display(s_node * head)
{
	if(!head) return 0;
	int i = 0;
	while(i < 5)
	{
		cout << "The alert information : " << endl;
		cout << "The origination       : " << head->data[i].orig << endl;
		cout << "The date              : " << head->data[i].date << endl;
		cout << "The time              : " << head->data[i].time << endl;
		cout << "The message           : " << head->data[i].mess << endl;
		cout << "Other message         : " << head->data[i].other << endl;
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
			delete [] front->origination;
			front->origination = NULL;
			front->next_queue = NULL;
			delete front;
			front = rear->next_queue;
		}else
		{
			front->stack_object.~stack();
			delete [] front->origination;
			front->origination = NULL;
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
	return enqueue(rear, to_add);
}

int queue::enqueue(q_node *& rear, alert * to_add)
{
	if(!front || !rear)
	{
		rear = new q_node;
		rear->stack_object.push(to_add);
		rear->origination = new char[strlen(to_add->orig) + 1];
		strcpy(rear->origination, to_add->orig);
		rear->next_queue = rear;
		front = rear;
		return 1;
	}
	if(strcmp(to_add->orig, rear->origination) == 0)
	{
		return rear->stack_object.push(to_add);
	}
	q_node * hold = rear;
	rear = new q_node;
	rear->stack_object.push(to_add);
	rear->origination = new char[strlen(to_add->orig) + 1];
	strcpy(rear->origination, to_add->orig);
	rear->next_queue = front;
	hold->next_queue = rear;
	return 1;
}

int queue::dequeue()
{
	if(!front) return 0;
	if(front->next_queue == front)
	{
		if(!front->stack_object.pop())
		{
			delete [] front->origination;
			front->origination = NULL;
			front->next_queue = NULL;
			delete front;
			front = rear = NULL;
			return 1;
		}
	}else
	{
		if(!front->stack_object.pop())
		{
			delete [] front->origination;
			front->origination = NULL;
			rear->next_queue = front->next_queue;
			front->next_queue = NULL;
			delete front;
			front = rear->next_queue;
			return 1;
		}
	}
	return 0;
}

int queue::peek(alert & at_top)const
{
	if(!front) return 0;
	return front->stack_object.peek(at_top);
}

int queue::display_queue()
{
	if(!front) return 0;
	if(front == front->next_queue)
	{
		int success = front->stack_object.display();
		return success;
	}
	return display_queue(front, rear);
}

int queue::display_queue(q_node * front, q_node * rear)
{
	int success = 0;
	if(front == rear)
	{
		success = front->stack_object.display();
		return 1;
	}
	success = front->stack_object.display();
	return display_queue(front->next_queue, rear) + 1;
}

































