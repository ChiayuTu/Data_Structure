#include<iostream>
#include<cctype>
#include<cstring>

const int Max = 5;

struct alert
{
	char * orig;
	char * date;
	char * time;
	char * mess;
	char * other;
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
		int push(s_node *& head, alert * to_add);
		int pop(s_node *& head);
		int display(s_node * head);
		int top_index;
		s_node * head;	
};

struct q_node
{
	char * origination;
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
		int enqueue(q_node *& rear, alert * to_add);
		int display_queue(q_node * rear, q_node * front);
		q_node * front;
		q_node * rear;
};






















