#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Answer to question 5
//allows the user to:
//      push a value onto the stack
//      pop the top one off the stack
//      print the stack to view it
void Manager::StackMenu(){
    cout<<endl;

    int choice=0;

    while(choice!=4){
        cout<<"Please type the number of your desired "<<endl;//prints the menu
        cout<<"1. Push onto the stack"<<endl;
        cout<<"2. Pop off the stack"<<endl;
        cout<<"3. Print Stack"<<endl;
        cout<<"4. Return to main menu"<<endl;

        cin>>choice;

		if(cin.fail()){//fail safe
			cout<<"\nError: Invalid input"<<endl;
			cin.clear();
		}

        switch(choice){//calls the proper function
            case 1: Push();cout<<endl;break;
            case 2: Pop();cout<<endl;break;
            case 3: Show();cout<<endl;break;
            case 4: return;break;
            default: cout<<"Invalid option"<<endl;break;
        }
    }
}

void Manager::Push(){//pushes the given value onto the top of the stack

    if(place==5){//So there is no stack overflow
        cout<<"Stack is full"<<endl;
        return;
    }
    else{
        cout<<"Please type a number you wish you push onto the stack, must be greater then 0"<<endl;

        int num;

        cin>>num;

        if(cin.fail()){//fail safe
			cout<<"\nError: Invalid input"<<endl;
			cin.clear();
		}

        if(num<=0){//error message
            cout<<"Invalid value, please enter a number greater then 0"<<endl;
            return;
        }

        else{//adds the given number to the top of the stack
            stack_array[place]=num;
            place++;
        }
    }
}

void Manager::Pop(){//pops the top value off

    if(place==0)//checks if the stack is empty
        cout<<"stack is empty"<<endl;

    else{
    cout<<stack_array[place-1]<<" Was popped off the stack"<<endl;
    stack_array[place-1]=0;
    place--;
    }
}

void Manager::Show(){

    cout<<endl;

    if(place==0){//checks if the stack is empty
        cout<<"stack is empty"<<endl;
        return;
    }
    else{
        cout<<"Top of the stack ->"<<"\t";//shows where the top of the stack is
        cout<<stack_array[place-1]<<endl;

        int i;
        for(i=place-2;i>=0;i--){//prints the rest of the stack from the top of the stack down
            cout<<"\t\t\t";
            if(stack_array[i]!=0)
                cout<<stack_array[i]<<endl;
        }
    }
}
