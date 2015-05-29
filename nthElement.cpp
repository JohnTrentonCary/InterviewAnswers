#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Answer to question 2

Nth_Element_Node::Nth_Element_Node(int value){//constructor for the Nth_Element_Node
    num=value;
    next=NULL;
}

void Manager::NthElementMenu(){

    static bool first_time=true;//used to know if this is the first time it has been called or not.
    static int length;//used to measure the length of the list that was given


    if(first_time==true){//if this is the first time equation has been called
        length=0;//if it is the first time the length needs to be reset instead of possibly added onto
        OpenFile(length);
        first_time=false;
    }

    int choice=0;

    while(choice!=2){//lets the user decide what they wish to do
        cout<<endl;
        cout<<"please type the number of your desired option then press enter"<<endl;
		cout<<"1. Get value at provided position"<<endl;
		cout<<"2. Quit"<<endl;

        cin>>choice;

		if(cin.fail()){//fail safe
			cout<<"\nError: Invalid input"<<endl;
			cin.clear();
		}

		switch(choice){//calls the appropriate function
            case 1: NthPosition(length);break;
            case 2: return;break;
            defailt: cout<<"Invalid option"<<endl;break;
		}
    }
}

void Manager::OpenFile(int &length){
    cout<<endl;

    string txt_file;//used to store the name of the file

    cout<<"Please type the name of the file you wish to load including file extension"<<endl;

    cin>>txt_file;

	if(cin.fail()){//fail safe
		cout<<"\nError: Invalid input"<<endl;
		cin.clear();
	}

    ifstream load;

    load.open(txt_file.c_str());//opens the file

    if(!load){
        cout<<"can't be open"<<endl;
        load.clear();
        return;
    }

    int num;
    char dump;

        while(load.eof()==false){
            load>>num;//loads the value to num
            load>>dump;//loads the "," that isn't needed into the dump

            Nth_Element_Node *tempNode=new Nth_Element_Node(num);//creates a node to add to the list

            if(nth_node_head==NULL){//checks if the list is empty
                nth_node_head=tempNode;
                length++;//to measure the list's length
            }
            else{
                Nth_Element_Node *current=nth_node_head;

                while(current->next!=NULL)//loops until the end of the list is reached
                    current=current->next;

                current->next=tempNode;//adds the new node to the end of the list
                length++;//to measure the list's length
            }
        }

    load.close();//closes the file
}

void Manager::NthPosition(int length){
    cout<<endl;
    int position;

    cout<<"Please enter which position you wish to attain the value of"<<endl;

    cin>>position;

	if(cin.fail()){//fail safe
		cout<<"\nError: Invalid input"<<endl;
		cin.clear();
	}

    if((position>length)||(position<0)){//error message
        cout<<endl<<"Invalid number please choose a number between 0 and up to "<<length<<endl;
        return;
    }
    else{
        int i;
        Nth_Element_Node *current=nth_node_head;

        for(i=0;i<position-1;i++)//loops to the correct position
            current=current->next;

        cout<<"Value in position: "<<position<<" is "<<current->num<<endl;
        }
}
