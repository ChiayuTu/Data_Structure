#include"list.h"

list::list()
{
	head = tail = NULL;
}

list::~list()
{
	node * temp = NULL;
	while(head)
	{
		temp = head->next;
		delete head;
		head = temp;
	}

	tail = NULL;
}

int list::add(const item & new_item)
{
	node * temp = new node;
	if(!temp)
	{
		return 0;
	}
	temp->one_item.add_item(new_item);
	temp->next = NULL;

	if(!head)
	{
		head = tail = temp;
	}else
	{
		tail->next = temp;
		tail = tail->next;
	}
	return 1;
}

int list::display()
{
	if(!head)
	{
		return 0;
	}

	node * current = head;
	while(current)
	{
		current->one_item.display_item();
		current = current->next;
	}
	return 1;
}








