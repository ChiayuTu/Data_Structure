#include"item.h"

struct node
{
	item one_item;
	node * next;
};

class list
{
	public:
		list();
		~list();
		int add(const item & new_item);
		int display();

	private:
		node * head;
		node * tail;

};
