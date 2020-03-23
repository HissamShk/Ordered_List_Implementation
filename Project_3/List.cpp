//CSCI 301
//List.cpp
//List Class: A Class to implement an Ordered List type, through a Linked List
//Hissamuddin Shaikh
#include <iostream>
#include "List.h"
#include <assert.h>
using namespace std;
//Constructor
List::List()
{
    first = NULL;
}
//Copy Constructor
List::List(const List& Source)
{
    Node *p;
    Node *last;
    if (Source.first == NULL)
        first = NULL;
    else
    {
        first = Get_Node(Source.first -> Data, NULL);
        last = first;
        p = Source.first -> next;
        while (p!=NULL)
        {
            last -> next = Get_Node(p -> Data,NULL);
            last = last -> next;
            p = p -> next;
        }
    }
}
//Destructor
List::~List()
{
    Node *temp;
    while (first != NULL)
    {
        temp = first;
        first = first -> next;
        delete temp;
    }
}
//Function to make the list empty
void List::Make_Empty()
{
    Node *temp;
    while (first != NULL)
    {
        temp = first;
        first = first -> next;
        delete temp;
    }
}
//Assigns a copy of an existing list (Source) to an invoking list.
void List::operator = (const List& Source)
{
    Node *p, *last;
    if (&Source != this)
    {
        Make_Empty();
        if (Source.first != NULL)
        {
            Node *p;
            Node *last;
            if (Source.first == NULL)
            first = NULL;
            else
                {
                    first = Get_Node(Source.first -> Data, NULL);
                    last = first;
                    p = Source.first -> next;
                    while (p!=NULL)
                        {
                            last -> next = Get_Node(p -> Data,NULL);
                            last = last -> next;
                            p = p -> next;
                        }
                }
        }
    }
}
//Function to check if a certain value is present or not
bool List::Present(Item Target)
{
    Node *p;
    p = first;
    while (p != NULL && p -> Data != Target)
        p = p->next;
    return p!=NULL;
}
//Function to Insert a value into the list, if it isn't already present.
void List::Insert (const Item& Entry)
  {
    Node *prev;

    //assert ( ! Present(Entry) );
    if (!Present(Entry)){
    if ( first == NULL || Entry < first->Data )
      first = Get_Node(Entry,first);
    else
    {
      prev = first;
      while ( prev->next != NULL && prev->next->Data < Entry )
        prev = prev->next;
      prev->next = Get_Node(Entry,prev->next);
    }}
    else
    {
        cout << endl;
        cout << "   Value Already Exists in the List." << endl;
    }
  }
//Function to Remove a value into the list, if is present.
void List::Remove ( const Item& Target )
  {
    Node *temp;
    Node *prev;

    //assert ( Present(Target) );
    if(Present(Target)){
    prev = first;
    if ( prev->Data == Target )
    {
      first = first->next;
      delete prev;
    }
    else
    {
      while ( prev->next != NULL && prev->next->Data < Target )
        prev = prev->next;
      temp = prev->next;
      prev->next = temp->next;
      delete temp;
    }}
    else
    {
        cout << endl;
        cout << "   Value Doesn't Exist in the List." << endl;
    }
  }
//Function to return the length of the list.
size_t List::Length( ) const
  {
    Node *cursor;
    int count = 0;

    for ( cursor=first; cursor != NULL; cursor=cursor->next )
      ++count;
    return count;
  }
//Function to return a specific value, based on the position entered(k).
int List::kth ( size_t k ) const
  {
    List L;
    Node *cursor;
    size_t count;

        assert ( 1 <= k && k <= Length() );

        cursor = first;
        for (count=1; count<k; ++count)
        cursor = cursor->next;
        return cursor->Data;

  }
//Friend Function
//Function to allow the contents of a list to be written out
ostream& operator << ( ostream& out_s, const List& l )
  {
    List::Node *cursor;

    out_s << '(';
    for ( cursor=l.first;
          cursor != NULL && cursor->next != NULL;
          cursor=cursor->next )
      out_s << cursor->Data << ", ";
    if ( cursor != NULL )
      out_s << cursor->Data;
    out_s << ')';

    return out_s;
  }
//Private function
//Involved in the creation of the list,
List::Node* List::Get_Node ( const Item& Entry, Node* link )
  {
    Node *temp;

    temp = new Node;
    temp->Data = Entry;
    temp->next = link;
    return temp;
  }


