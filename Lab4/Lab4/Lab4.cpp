#include <iostream>

using namespace std;

struct node
{
	int data;
	node *next;
};

class linked_list
{
private:
	node *head, *tail;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}

	void add_node(int n)
	{
		node *tmp = new node;
		tmp->data = n;
		tmp->next = NULL;

		if (head == NULL)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tail->next;
		}
	}
	void InsertElement(node* &first, int name)
	{
		// create node
		node* temp = new node;
		temp->data = name;
		temp->next = NULL;

		if (!first)
		{ // empty list becomes the new node
			first = temp;
			return;
		}
		else
		{ // find last and link the new node
			node* last = first;
			while (last->next) last = last->next;
			last->next = temp;
		}
	}
	bool SearchElement(struct node *head, int key)
	{
		while (head != NULL)
		{
			if (head->data == key)
			{
				return true;
			}
			head = head->next;
		}
		return false;
	}
	void PrintTree(node* head)
	{
		node* temp = head;

		cout << temp->next << endl;
	}

};

int main()
{
	linked_list a;
	a.add_node(1);
	a.add_node(2);
	return 0;
}