/*
 * C++ program to implement doubly link list
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//Node declaration
struct node
{
	int info;
	struct node* next;
	struct node* prev;
}*start;

//Class declaration
class double_llist
{
	public:
		void create_list(int value);
		void add_begin(int value);
		void add_after(int value, int position);
		void delete_element(int value);
		void display_dlist();
		void count();
		void reverse();
		double_llist()
		{
			start = NULL;
		}
};

int main()
{
	int choice, element, position;
	double_llist dl;
	
	while (1)
	{
		cout << endl << "--------------------------------" << endl;
		cout << endl << "Operations on Doubly linked list" << endl;
		cout << endl << "--------------------------------" << endl;
		cout << "1. Create Node" << endl;
		cout << "2. Add at beginning" << endl;
		cout << "3. Add after position" << endl;
		cout << "4. Delete" << endl;
		cout << "5. Display" << endl;
		cout << "6. Count" << endl;
		cout << "7. Reverse" << endl;
		cout << "8. Quit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter the element: ";
			cin >> element;

			dl.create_list(element);
			cout << endl;
			break;

		case 2:
			cout << "Enter the element: ";
			cin >> element;

			dl.add_begin(element);
			cout << endl;
			break;

		case 3:
			cout << "Enter the element: " << endl;
			cin >> element;
			cout << "Insert the position after which element is to be added: ";
			cin >> position;

			dl.add_after(element, position);
			cout << endl;
			break;

		case 4:
			if (start == NULL)
			{
				cout << "The list is empty, nothing to delete" << endl;
				break;
			}
			cout << "Enter the element to delete: ";
			cin >> element;
			dl.delete_element(element);
			cout << endl;
			break;

		case 5:
			dl.display_dlist();
			cout << endl;
			break;

		case 6:
			dl.count();
			break;

		case 7:
			if (start == NULL)
			{
				cout << "The list is empty, nothing to reverse" << endl;
				break;
			}

			dl.reverse();
			cout << endl;
			break;

		case 8:
			exit(1);

		default:
			cout << "Wrong choice!" << endl;
		}
	}

	return 0;
}

//Create doubly linked list
void double_llist::create_list(int value)
{
	struct node *s, *temp;

	temp = new(struct node);
	temp->info = value;
	temp->next = NULL;
	
	if (start == NULL)
	{
		temp->prev = NULL;
		start = temp;
	}
	else
	{
		s = start;

		while (s->next != NULL)
		{
			s = s->next;
		}

		s->next = temp;
		temp->prev = s;
	}
}

//Insert the node at the beginning
void double_llist::add_begin(int value)
{
	if (start == NULL)
	{
		cout << "No list found. Please create a list." << endl;
		return;
	}

	struct node* temp;
	
	temp = new(struct node);
	temp = new (struct node);
	temp->prev = NULL;
	temp->info = value;
	temp->next = start;
	start->prev = temp;
	start = temp;

	cout << "Element inserted at the beginning!" << endl;
}

//Insert the element at a particular position
void double_llist::add_after(int value, int pos)
{
	if (start == NULL)
	{
		cout << "No list found. Please create a list." << endl;
		return;
	}

	struct node *temp, *q;
	int i;
	q = start;

	for (i = 0; i < pos - 1; i++)
	{
		q = q->next;
		if (q == NULL)
		{
			cout << "There are less than " << pos << " elements" << endl;
			return;
		}
	}

	temp = new(struct node);
	temp->info = value;

	if (q->next == NULL)
	{
		q->next = temp;
		temp->next = NULL;
		temp->prev = q;
	}
	else
	{
		temp->next = q->next;
		temp->next->prev = temp;
		q->next = temp;
		temp->prev = q;
	}

	cout << "Element Inserted" << endl;
}

//Delete an element from the list
void double_llist::delete_element(int value)
{
	struct node *temp, *q;

	if (start->info == value)
	{
		temp = start;
		start = start->next;
		start->prev = NULL;
		cout << "Element deleted" << endl;
		free(temp);
		return;
	}

	q = start;

	while (q->next->next != NULL)
	{
		if (q->next->info == value)
		{
			temp = q->next;
			q->next = temp->next;
			temp->next->prev = q;
			cout << "Element deleted!" << endl;
			free(temp);
			return;
		}

		q = q->next;
	}

	if (q->next->info == value)
	{
		temp = q->next;
		free(temp);
		q->next = NULL;
		cout << "Element deleted" << endl;
		return;
	}
	
	cout << "Element " << value << " not today" << endl;
}

void double_llist::display_dlist()
{
	struct node *q;
	if (start == NULL)
	{
		cout << "The list is empty, nothing to display" << endl;
		return;
	}

	q = start;
	cout << "The doubly link list is: " << endl;

	while (q != NULL)
	{
		cout << q->info << "<->";
		q = q->next;
	}

	cout << "NULL" << endl;
}

void double_llist::count()
{
	struct node *q = start;
	int cnt = 0;

	while (q != NULL)
	{
		q = q->next;
		cnt++;
	}

	cout << "The number of elements in the list are: " << cnt << endl;
}

void double_llist::reverse()
{
	struct node *p1, *p2;
	p1 = start;
	p2 = p1->next;
	p1->next = NULL;
	p1->prev = p2;
	while (p2 != NULL)
	{
		p2->prev = p2->next;
		p2->next = p1;
		p1 = p2;
		p2 = p2->prev;
	}
	start = p1;
	cout << "List Reversed" << endl;
}