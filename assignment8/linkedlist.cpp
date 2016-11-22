#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class LinkedList
{

private:

	typedef struct node
	{
		int value;
		node *next;

		node(int value)
		{
			this->value = value;// this pointer is an implicit parameter to all member functions
			this->next = NULL;
		}


	}node;
	
	node *head;
	
	LinkedList::LinkedList()
	{
		head = 0;
		return;
	}

	void  LinkedList::addToListAtPosition(int position, int value)
	{
		if (position == 0)
		{
			addToHead(value);
			return;
		}

		if (position > getListLength())
			return;

		if (0 < position <= getListLength())
		{
			node *temp1 = new node(value);
			node *temp3 = head;
			node *temp4;
			while ((position - 1) != 0)
			{
				temp3 = temp3->next;
				position = position - 1;
			}
			if (position == getListLength())
			{
				temp3->next = temp1;
				temp1->value = value;
				temp1->next = NULL;
				return;
			}

			else
			{
				temp4 = temp3->next;
				temp3->next = temp1;
				temp1->value = value;
				temp1->next = temp4;
				return;
			}
		}
		return;
	}

	void LinkedList::addToHead(int value)
	{
		node *temp1 = new node(value);

		if (head != NULL)
		{
			temp1->next = head;
		}
		else
		{
			temp1->next = NULL;
		}

		head = temp1;
		return;
	}

	int LinkedList::getListLength()
	{
		int i = 0;// i used as index and counter
		node *temp1 = head;
		while (temp1 != NULL)
		{
			i = i + 1;
			temp1 = temp1->next;
		}
		return i;
	}


	void LinkedList::appendToList(int value)
	{
		if (head == NULL)
		{
			addToHead(value);
			return;
		}

		node *temp1 = new node(value);
		node *temp3 = head;

		while (temp3->next != NULL)
		{
			temp3 = temp3->next;
		}
		temp1->value = value;
		temp1->next = NULL;
		temp3->next = temp1;
		return;
	}

	void LinkedList::removeFromListAtPosition(int position)
	{
		
		if (position >= getListLength())
			return;
		
		if (position == 0)
		{
			removeFromHead();
			return;
		}
		
		if (position == (getListLength() - 1))
		{
			node *temp1 = head;
			node *temp3 = temp1->next;

			while (temp3->next != NULL)
			{
				temp1 = temp3;
				temp3 = temp3->next;
			}
			delete (temp3);
			temp1->next = NULL;
			return;
		}

		if (0 < position < (getListLength() - 1))
		{

			node *temp1 = head;
			node *temp3 = temp1->next;
			while ((position - 1) != 0)
			{
				temp1 = temp3;
				temp3 = temp3->next;

				position = position - 1;
			}
			temp1->next = temp3->next;
			delete temp3;
			return;
		}
		return;
	}

	void LinkedList::removeFromHead()
	{
		node *temp1 = head;
		if (head != NULL)
		{
			head = temp1->next;
			delete temp1;
		}

		return;
	}

	void LinkedList::removeFromEnd()
	{
		node *temp1 = head;
		node *temp3 = head;
	
		if (temp1->next == NULL)
		{
			delete temp1;
			head = NULL;
			return;
		}

		if (temp1 == NULL)
		{
			return;
		}
	
		temp3 = temp1->next;

		while (temp3->next != NULL)
		{
			temp1 = temp3;
			temp3 = temp3->next;
		}

		temp1->next = temp3->next;
		delete temp3;

		return;
	}

	int LinkedList::find(int value)
	{
		node *temp1 = head;
		while (temp1 != NULL)
		{
			if (temp1->value == value)
				return 1;
			else
				temp1 = temp1->next;
		}
		return 0;
	}

	void LinkedList::reverseList()
	{
		if (getListLength() < 2)
			return;

		node *temp1 = head;
		node *temp2 = head->next;
		node *temp3;
		node *temp4;
		node *temp5;

		while (temp2 != NULL)
		{
			temp3 = temp1;
			temp4 = temp2;
			temp5 = temp2->next;
			temp2->next = temp1;
			temp1 = temp4;
			temp2 = temp5;
		}

		head->next = NULL;
		head = temp1;
		return;
	}
	LinkedList::~LinkedList()
	{
		node *temp1 = head;
		node *temp3;
		while (temp1 != NULL)
		{
			temp3 = temp1;
			temp1 = temp1->next;
			delete (temp3);
		}

		return;
	}

	LinkedList::node *LinkedList::getHead()
	{
		return head;
	}

	
};
