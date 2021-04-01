#include <stdio.h>
#include <ctime>
#include <iostream> 

using namespace std;

int main()
{
	
	int startTime, stopTime;
	startTime=clock();
	int sum1(0);
	for(int i=0;i<1000000;i++)
	{
		sum1 += i; 
	}
	cout << "sum: " << sum1 << endl;
	stopTime=clock();
	cout << "Time w/o openMP " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
	
	
	startTime=clock();
	
	int sum2(0); 
	
	//How it used to be done:
	//~ int local_sum(0); 
	//~ #pragma omp parallel private(local_sum) shared(sum2) 
	//~ { 
		//~ local_sum =0; 
    
    
	//~ #pragma omp for schedule(static) 
		//~ for (int i=0; i< 1000000; i++) {
			//~ local_sum += i; 
		//~ }
	//~ //area where calculation needs to go one thread at a time
	//~ #pragma omp critical 
		//~ sum2 += local_sum;
	//~ } 
	
	//~ //new way: reduction -- basically does all the steps above
	//~ //but just fewer lines (map reduce) 

	#pragma omp parallel for reduction (+:sum2)
	for(int i=0;i<1000000000000000000;i++)
	{
		sum2 += i; 
		
	}
	
	cout << "sum: " << sum2 << endl;
	stopTime=clock();
	cout << "Time w/ openMP " << (stopTime - startTime)/double(CLOCKS_PER_SEC)*1000 << endl;
	

  
  
  return 0;
}
