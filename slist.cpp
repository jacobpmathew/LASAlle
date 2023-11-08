#include "slist.h"
#include <iostream>

/*
Class Library File
*/


// Constructor
LinkedList::LinkedList() {head = nullptr;}



// clear()					//Removes all elements from this list.
void LinkedList::clear()
{
  while(head!=nullptr)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
}

// size()					//Returns the number of elements in this list.
int LinkedList::size()
{
  int count = 0;
  Node *current = head;
  while(current!=nullptr) //go till end
    {
      count++;
      current = current->next; //update
    }
  return count;
}

// Destructor
LinkedList::~LinkedList(){
  clear();
}
// add(value)				//Adds a new value to the end of this list.
void LinkedList::add(Airport &a)
{
  Node *newNode = new Node(a); //temp node
  if(head==nullptr) //for size 0
  {
    head = newNode;
  }
  else
  {
    Node *current = head;
    while(current->next!=nullptr)
      {
          current = current->next;
      }
      current->next = newNode;
  }
}
// equals(list)				//Returns true if the two lists contain the same elements in the same order.
bool LinkedList::equals(LinkedList l)
{
  Node *current = head;
  Node *oCurrent = l.head;
  while(current!=nullptr && oCurrent!=nullptr)
    {
      if(current->data.longitude != oCurrent->data.longitude || current->data.latitude != oCurrent->data.latitude)
      {
        return false;
      }
      for(int i=0;i<5;i++)
        {
          if(current->data.code[i] != oCurrent->data.code[i])
          {
            return false;
          }
        }
      current = current->next;
      oCurrent = oCurrent->next;
    }
  if(current==nullptr&&oCurrent==nullptr)
  {
    return true;
  }
  else{
    return false;
  }
}
//get(index)	//Returns the element at the specified index in this list.
Node* LinkedList::get(int i)
{
  if(i<0)
  {
    return nullptr;
  }
  Node* current = head;
  for(int j=0; j<i && current!=NULL;j++)
    {
      current = current->next;
    }
  if(current==NULL)
  {
    return nullptr; //edge cases for <0 and end
  }
  return current;
}

//insert(index, value)		//Inserts the element into this list before the specified index.
void LinkedList::insert(int index, Airport &a)
{
  Node *newNode = new Node(a); //creating new node from input
  if(index==0)
  {
    newNode->next = head;
    head = newNode; //head is now a
  }
  else if(index>=size())
  {
    add(a);
  }
  else
  {
    Node *current = head; //h
    for(int i=0; i<index-1 && current!=nullptr; i++)
      {
        current = current->next;
      }
    newNode->next=current->next; //bc current is -1
    current->next = newNode; //head is now a
  }
}
//exchg(index1, index2)		//Switches the payload data of specified indexex.
void LinkedList::exchg(int index1, int index2)
{
  if(index1>0 && index2>0 && index1<size() && index2 <size() && index1!=index2)
  {
    Node *current1= get(index1);
    Node *current2= get(index2);
    Airport temp=current1->data;
    current1->data=current2->data;
    current2->data = temp;
  }
}

//swap(index1,index2)		//Swaps node located at index1 with node at index2//
void LinkedList::swap(int index1, int index2)
{
  if(index1>0 && index2>0 && index1<size() && index2 <size() && index1!=index2)
  {
    Node *current1= get(index1);
    Node *current2= get(index2);
    Airport temp=current1->data;
    current1->data=current2->data;
    current2->data = temp;
  }
}
// isEmpty()				//Returns true if this list contains no elements.
bool LinkedList::isEmpty()
{
  return head==nullptr;
}
// remove(index)			//Removes the element at the specified index from this list.
void LinkedList::remove(int index)
{
  if(index==0)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
  else{
  Node *current = head;
  Node *before;
  for(int i=0;i<index && current!=NULL;i++)
    {
      before = current;
      current = current->next; //one I want to remove
    }
  before->next = current->next;
  delete current;}
}
// set(index, value)		//Replaces the element at the specified index in this list with a new value.
void LinkedList::set(int index, Airport &a)
{
  Node *n = get(index);
  if(n!=nullptr){
    n->data = a;
  }
}





// DO NOT IMPLEMENT >>> subList(start, length)	//Returns a new list containing elements from a sub-range of this list.

// DO NOT IMPLEMENT >>> toString()				//Converts the list to a printable string representation.