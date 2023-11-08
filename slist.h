#include <string>
#include <iostream>
using namespace std;
class Airport{
public:
  char code[5];
  double longitude;
  double latitude;
  string name;
  string status;
};

class Node
{
public:
  Airport data;
  Node* next;
  Node (Airport aD)
  {
    data = aD;
    next = nullptr;
  }
};

class LinkedList
{
public:
  Node *head;
  LinkedList();
  ~LinkedList();
  void add(Airport &a);
  void clear();
  bool equals(LinkedList l);
  Node* get(int index);
  void insert(int index, Airport &a);
  void exchg(int index1, int index2);
  void swap(int index1, int index2);
  bool isEmpty();
  void remove(int index);
  void set(int index, Airport &a);
  int size();
  //LinkedList subList(int start, int length); <- am not implementing
  //char toString(); <- am not implementing
};