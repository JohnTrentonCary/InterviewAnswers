#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Answer to question 1
Node::Node(int var){//Constructor for node
	num=var;
	next=NULL;
}

void Manager::LinkedListMenu(){
    cout<<endl;

	int choice=0;

	while(choice!=4){//this works the menu for the basic linked list
		cout<<"please type the number of your desired option then press enter"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Remove"<<endl;
		cout<<"3. Print"<<endl;
		cout<<"4. Return to main menu"<<endl;

		cin>>choice;

		if(cin.fail()){//fail safe
			cout<<"\nError: Invalid input"<<endl;
			cin.clear();
		}

		switch(choice){//called the function the user asked for
			case 1: Insert();cout<<endl;break;
			case 2: Remove();cout<<endl;break;
			case 3: Print();cout<<endl;break;
			case 4: return;break;
			default: cout<<"Invalid option"<<endl;break;
		}
	}
}

void Manager::Insert(){
	int var;

	cout<<endl<<"Please enter the number you wish to store in the node"<<endl;

	cin>>var;

	if(cin.fail()){//fail safe
		cout<<"\nError: Invalid input"<<endl;
		cin.clear();
	}

	Node *tempNode=new Node(var);//the temporary node used to insert into the linked list

	if(head==NULL)//checks to see if the list is empty
		head=tempNode;
	else{//adds the node to the end of the linked list
		Node *current=head;
		while(current->next!=NULL){//finds the end of the list
			current=current->next;
		}
		current->next=tempNode;//inserts it at the end here
	}

}

void Manager::Remove(){
	int var;

	cout<<endl<<"Please type the number of the node you wish to remove"<<endl;

	cin>>var;//gets the number the user wishes to remove

	if(cin.fail()){//fail safe
        cout<<"\nError: Invalid input"<<endl;
		cin.clear();
	}

	Node *tempNode;//will be used to store the node the user wishes to remove

	if(head->num==var){//if the first node in the list is the node that the user wants to remove
		tempNode=head;
		if(head->next!=NULL)
			head=head->next;//sets head to the new head
		else
			head=NULL;
		delete tempNode;//deletes the node
	}
	else{
		Node *current=head;
		Node *previous;
		while((current!=NULL)&&(current->num!=var)){//loops until either the end of the list is reached or the correct node is found
			previous=current;
			current=current->next;
		}
		if((current!=NULL)&&(current->num==var)){//double checks to make sure it is the right node and not just the end of the list
			tempNode=current;
			if(current->next==NULL)//if the last node is the correct node the node pointing to it needs to be set to NULL
				previous->next=NULL;
			else{
				previous->next=current->next;//sets the node pointing to the correct node to the node the correct node is pointing to
				current->next=NULL;
				delete tempNode;//deletes the node
			}
		}
		else//if the number given is not found within the list
			cout<<"Number not found"<<endl;
	}
}

void Manager::Print(){

	Node *current=head;
	if(head!=NULL){//checks if the list is empty
		while(current!=NULL){//loops until the end of the list
			cout<<current->num;
			if(current->next!=NULL)//checks if the current node is the last node
				cout<<"-";
			current=current->next;//goes to the next node
		}
	}
	else//if list is empty
        cout<<"List is empty"<<endl;
}
