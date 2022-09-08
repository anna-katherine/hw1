#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* head = new Node(0, NULL);
  Node* start = head;
  for (int i = 0; i < 10; i++)
  {
      head->next = new Node(i+1, NULL);
      head = head->next;
  }
  Node *o = NULL;
  Node *e = NULL;
  split(start, o, e);

  while (o!=NULL)
  {
    cout << "odds " << o->value << endl;
    o = o->next;
  }
  while (e!=NULL)
  {
    cout << "evens " << e->value << endl;
    e = e->next;
  }
}

