#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Answer to question 3

Book_ID::Book_ID(string val){
    value=val;
    next=NULL;
}

void Manager::Sort(){
    cout<<endl;

	ifstream load("book_ids.txt");

    if(!load){//if the file can't be opened
        cout<<"can't be open"<<endl;
        load.clear();
        return;
    }

    else{
        string given_value;

        while(!load.eof()){//loops until end of file
            load>>given_value;
            Book_ID *tempNode=new Book_ID(given_value);//creates a new node for another book ID to be inserted
            Book_ID *current=book_head;//so that it may start from the beginning every time

            if(book_head==NULL)//will always be empty on the first try
                book_head=tempNode;

            else if(book_head->value>given_value){//if the first node is greater then the new node the node node needs to go in front
                book_head=tempNode;
                book_head->next=current;
            }

            else{
                Book_ID *previous;

                while((current->next!=NULL)&&(current->value<given_value)){//loops until either the very end is reached or until a value greater then the given value is found.
                    previous=current;
                    current=current->next;
                }

                if((current->value<given_value)&&(current->next==NULL))//if new node needs to go at the end
                    current->next=tempNode;

                else//to insert it into it's proper position
                    tempNode->next=current;
                    previous->next=tempNode;
            }
        }
    }
    Book_ID *walk=book_head;

    while(walk!=NULL){//print the list of sorts book IDs
        cout<<walk->value<<endl;
        walk=walk->next;
    }

    cout<<"Book IDs have been sorted"<<endl;//confirmation message

    load.close();//closes the file
}
