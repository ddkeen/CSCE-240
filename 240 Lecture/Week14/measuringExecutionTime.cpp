#include <cstdlib>
#include <iostream>
#include <ctime>


//Introduce Project 2!

using namespace std;

int main(int argc, char **argv)
{
	int startTime, stopTime;

	startTime=clock();
	
	//code to time goes here. 
	
	stopTime=clock();
	cout << "time: " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	return 0;
}

