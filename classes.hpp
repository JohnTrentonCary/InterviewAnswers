#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Node;
class Book_ID;

class Node{//used for answer 1
	public:
	Node(int var);//constructor
	int num;//num for number
	Node *next;//pointer to the next node in the list
};

class Book_ID{//used in answer 3
    public:
        Book_ID(string val);//constructor
        string value;
        Book_ID *next;//refer to comment on line 14

};

class Nth_Element_Node{//used in answer 2
    public:
        Nth_Element_Node(int value);
        int num;
        Nth_Element_Node *next;//refer to comment on line 14

};

class Manager{
//variables and functions for answer 1
    private:
        Node *head;//first node in the linked list
    public:
		void Insert();//inserts a node into the linked list
		void Remove();//removes nodes from the linked list
		void Print();//prints the linked list


		void LinkedListMenu();//used to access the linked list implementation.

//Misc functions that are used to linked everything together
		Manager();//constructor
		void Menus();//allows the user to select which answer they would like to view

//variables and functions for answer 2
    private:
        Nth_Element_Node *nth_node_head;
    public:
		void NthElementMenu();
		void OpenFile(int &length);
		void NthPosition(int length);

//variables and functions for answer 3
    private:
   		Book_ID *book_head;
    public:
		void Sort();//sorts and then prints the sorted list of book IDs

//function for answer 4
		void Sum();//calculates the sum

//variables and functions for answer 5
    private:
        int stack_array[5];
        int place;
    public:
		void StackMenu();//allows the user to select wether they wish to push or pop something onto the stack
		void Push();//lets the user push something onto the stack if it isn't full
		void Pop();//lets the user pop the top value off the top of the stack
		void Show();
};
