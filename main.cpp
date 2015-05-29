#include <iostream>
#include <string>
#include <fstream>
#include "classes.hpp"
#include "linkedList.cpp"
#include "nthElement.cpp"
#include "bookIDSort.cpp"
#include "below1000.cpp"
#include "basicStack.cpp"

Manager::Manager(){//constructor for anb instance of basic linked list
	head=NULL;
	book_head=NULL;
	nth_node_head=NULL;

	int i;
	for(i=0;i<5;i++)
        stack_array[i]=0;

    place=0;


}

int main(void){

	Manager man;
	man.Menus();

	return 0;
}

using namespace std;



void Manager::Menus(){
		int choice=0;

	while(choice!=6){
		cout<<"Please type the number of your desired "<<endl;
		cout<<"1. Implemented basic linked list (answer to number 1)"<<endl;
		cout<<"2. The n'th element (answer to number 2)"<<endl;
		cout<<"3. 1000 book ID's ordered (answer to number 3)"<<endl;
		cout<<"4. Sum of all the multiples of 3 or 5 below 1000 (answer to question 4)"<<endl;
		cout<<"5. Implemented a basic stack (Answer to question 5)"<<endl;
		cout<<"6. Quit"<<endl;

		cin>>choice;

		if(cin.fail()){//fail safe
			cout<<"\nError: Invalid input"<<endl;
			cin.clear();
		}

		switch(choice){
//if use chooses number 1 it will go to the basic linked list menu and allow the user to insert or remove nodes
			case 1:LinkedListMenu();cout<<endl;break;
//will allow the user to load a file and the program will determine the nth element
			case 2:NthElementMenu();cout<<endl;break;
//loads the provided file and sorts it least to greatest
			case 3:Sort();cout<<endl;break;
//determines the sum of all the multiples of 3 or 5 below 1000
			case 4:Sum();cout<<endl;break;
//implements a basic stack
			case 5:StackMenu();cout<<endl;break;
			case 6:return;break;
			default:{
				cout<<"Invalid option"<<endl;
				break;
			}

		}
	}

}
