#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Answer to question 4
void Manager::Sum(){//sum of all the multiples of 3 or 5 below 1000
    cout<<endl;

	int sum=0,i;

//checks every number from 0 to 999 to see if they are divisible by 3 or 5.
//If they are add it to the sum
	for(i=0;i<1000;i++){
		if((i%3==0)||(i%5==0))
			sum=sum+i;
	}

	cout<<sum<<endl;

	return;
}
