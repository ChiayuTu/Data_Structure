#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

const int MAX = 5;

struct alert
{
	char * person_name;
	char * cellphone;
	char * place;
};


struct s_node
{
	alert * data;
	s_node * next;
};


class stack
{
	public:
		stack();
		~stack();
		int push(alert * to_add);
		int pop();
		int display();
		int peek(alert & at_top)const;
		
	private:
		int top_index;
		s_node * head;
		int push(s_node *& head, alert * to_add);
		int pop(s_node *& head);
		int display(s_node * head);
};


struct q_node
{
	char * address;
	stack stack_object;
	q_node * next_queue;
};


class queue
{
	public:
		queue();
		~queue();
		int enqueue(alert * to_add);
		int dequeue();
		int peek(alert & at_top)const;
		int display_queue();
	
	private:
		q_node * front;
		q_node * rear;
		int enqueue(q_node *& rear, alert * to_add);
		int display_queue(q_node * rear, q_node * temp);
};













