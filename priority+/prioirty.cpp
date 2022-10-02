#include<iostream>
using namespace std;

class Node
{
  public:
  int data;
  int priority;
  Node * next;
};

Node * front = NULL;

void insert (int data, int priority)
{

 Node * temp, *curr, *pre = NULL;

 temp = new Node;
 temp->data = data;
 temp->priority = priority;

 if (front == NULL || priority >= front->priority)
  {
    temp->next = front;
    front = temp;
  }

 else
  {
    curr = front;

    while (curr && priority <= curr->priority)
	{
	  pre = curr;
	  curr = curr->next;
	}

    temp->next = pre->next;
    pre->next = temp;
  }
}

void Delete ()
{
  if (front == NULL)
  {
    cout << "Priority Queue is underflow" << endl;
    return;
  }

  else
    {
      Node * temp;
      temp = front;

      cout << "Deleted item is " << temp->data << endl;

      front = temp->next;
      free (temp);
    }
}

void display ()
{
  if (front == NULL)
    cout << "Priority-Queue is empty" << endl;

  Node * curr = front;

  cout<<"\nPriority-Queue elements are : ";

  while (curr)
    {
      cout << curr->data << " ";
      curr = curr->next;
    }

  cout << endl;

  return;
}

void peak ()
{
  cout << "Peak element is :" << front->data << endl;
}

int main ()
{
  insert (2, 2);
  insert (3, 3);
  insert (6, 6);
  insert(11,11);

  display ();

  peak();

  Delete ();
  Delete ();
  display ();

  return 0;

}