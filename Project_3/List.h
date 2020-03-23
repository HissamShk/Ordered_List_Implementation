//CSCI 301
//List.h
//List Class: A Class to implement an Ordered List type, through a Linked List
//Hissamuddin Shaikh
//This class contains a variety of functions, that allows for the creation of an ordered list that can be manipulated
//during runtime. This is done through dynamically allocating memory space, and linking it through the use of pointers.
//This allows for operation such as insertion and removal, to occur without the hindrances that would be faced in other
//common methods.
#ifndef LIST_H
#define LIST_H
#include <fstream>
using namespace std;
//The Class List, which contains all the functions.
class List
{
    public:
        //An Alias for the type assignment, to make it easier to change the type of list
        //such as double, int...
        typedef int Item;
        //Constructor
        List();
        //Copy Constructor
        List(const List& Source);
        //Destructor - Give back a List's Nodes
        ~List();
        /*Modification Number Functions*/
        void Make_Empty();
        //Post-Condition: Make the respective list empty.
        void Insert(const Item& Entry);
        //Pre-Condition: Takes in the value, which is to be inserted into the list.
        //Post-Condition: Places the value in the list, in the appropraite position,
        //                so as to main the lists ordered nature. If the value already exists in the list,
        //                then does nothing and informs user.
        void Remove(const Item& Traget);
        //Pre-Condition: Takes in the value, which is to be removed from the list.
        //Post-Condition: Removes the value in the list, from the appropraite position,
        //                so as to main the lists ordered nature. If the value doesnt exist in the list,
        //                then does nothing and infroms the user.
        void operator = (const List& Source);
        //Post-Condition: Assigns a copy of an existing list (Source) to an invoking list.
        /*Constant Member Functions*/
        bool Empty() const { return first == NULL; };
        //Post-Condition: Returns true if the respective list is empty, or false if not.
        size_t Length() const;
        //Post-Condition: Returns the length of the respective list.
        bool Present(Item Target);
        //Pre-Condition: Takes in the value, which is to be searched for in the list.
        //Post-Condition: Return true if value is present, false if not.
        int kth(size_t k) const;
        //Pre-Condition: Takes in the postion from which the value is to be retreived.
        //Post-Condition: Returns the value from the k postion.
        /*Friend Function*/
        friend ostream& operator << (ostream& out_s, const List& l);
        //Post-Condition: Allows for the contents of the respective list to be written out,
        //                through the output stream out_s.
    private:
        //Data Members for the Class
        struct Node
        {
            Item Data;
            Node *next;
        };
        Node *first;
        //private Function
        Node *Get_Node(const Item& Entry, Node *link);
        //Post-Condition: Involved in the creation of the list,
        //                as it creates new Nodes and links them to the List.
        //                This is a pointer to the struct Node.,
};
#endif // LIST_H

