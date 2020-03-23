//CSCI 301
//PROJECT 3
//List Constructor
//Hissamuddin Shaikh
//This program utilizes the class, List, to offer the User a variety of options to create an ordered list. The options
//include allowing a user to insert, remove, check the length, check if a certain value is present, look up a value
//based on a position, and to write out the list constructed, as well as to make it empty if desired.
#include <fstream>
#include <iostream>
#include "List.h"
using namespace std;
int main()
{   //Data Variables
    List L;
    int Value;
    char Option = 'A';
    //Displaying the Menu for Options Available
    cout << endl;
    cout << "   |List Constructor|" << endl;
    cout << endl;
    cout << "   This Program responds to commands the user enters to" <<endl;
    cout << "   manipulate an ordered list of integers, which is " << endl;
    cout << "   initially empty. In the following commands, 'V' is any "<<endl;
    cout << "   integer, and 'P' is a position in the list." << endl;
    cout << endl;
    cout << "   Available Options:" << endl;
    cout << endl;
    cout << "   E -- Re-Initialize the List to be Empty." << endl;
    cout << "   I V -- Insert the Value 'V' into the List." << endl;
    cout << "   R V -- Remove the Value 'V' from the List." << endl;
    cout << "   L -- Report the Length of the List" << endl;
    cout << "   P V-- Is the Value 'V' present in the List?" << endl;
    cout << "   K P -- Report the Pth Value of the List." << endl;
    cout << "   W -- Write out the List." << endl;
    cout << "   H -- See this Menu." << endl;
    cout << "   Q -- Quit." << endl;
    //Switch statement within a while loop to allow the user freedom
    //to manipulate the ordered list for as long as desired.
    while (Option != 'Q' && Option != 'q')
    {
        //Input for User-Selected Option
        cout << endl;
        cout << "   Enter Option Here --> ";
        cin >> Option;
        switch (Option)
        {
            //Case to make the List empty.
            case 'E':
            case 'e':
               L.Make_Empty();
            break;
            //Case to Insert as value into the list.
            case 'I':
            case 'i':
               {cin >> Value;
               L.Insert(Value);}
            break;
            //Case to Remove a value from the list.
            case 'R':
            case 'r':
               {cin >> Value;
               L.Remove(Value);}
            break;
            //Case to check if a certain value is present in the list.
            case 'P':
            case 'p':
               {cin >> Value;
                    if (L.Present(Value))
                        {
                            cout << endl;
                            cout << "   The Value " << Value << " is PRESENT in the List.";
                            cout << endl;
                        }
                    else
                        {
                            cout << endl;
                            cout << "   The Value " << Value << " is NOT PRESENT in the List.";
                            cout << endl;
                        }
                }
            break;
            //Case to locate a certain value based on the position entered.
            case 'K':
            case 'k':
               {
                    cin >> Value;
                    if (Value <= L.Length())
                    {
                        cout << endl;
                        cout << "   The " << Value << " element of the List is " << L.kth(Value) << ".";
                        cout << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "   The list doesn't contain " << Value << " values.";
                        cout << endl;
                    }
                break;
               }
            //Case to Write out the List.
            case 'W':
            case 'w':
               cout << endl;
               cout << "   List: " << L;
               cout << endl;
                break;
            //Case to check the length of the List
            case 'L':
            case 'l':
                cout << endl;
                cout << "   The Length of the List is " <<L.Length()<< " Elements.";
                cout << endl;
                break;
            //Case to print out the menu for the user to view.
            case 'H':
            case 'h':
                cout << endl;
                cout << "   Available Options:" << endl;
                cout << endl;
                cout << "   E -- Re-Initialize the List to be Empty." << endl;
                cout << "   I V -- Insert the Value 'V' into the List." << endl;
                cout << "   R V -- Remove the Value 'V' from the List." << endl;
                cout << "   L -- Report the Length of the List" << endl;
                cout << "   P V-- Is the Value 'V' present in the List?" << endl;
                cout << "   K P -- Report the Pth Value of the List." << endl;
                cout << "   W -- Write out the List." << endl;
                cout << "   H -- See this Menu." << endl;
                cout << "   Q -- Quit." << endl;
            break;
            //Case to Quite the loop, and in turn the program entirely.
            case 'Q':
            case 'q':
                break;
            //Error Control for Invalid Inputs.
            default:
                {
                    cout<<endl;
                    cout << "   Invalid Entry"<<endl;
                }
                break;
        }

    }
    return 0;
}

