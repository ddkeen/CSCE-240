/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: World.h file for Project 5 Simulation
 * Input requirements:    none                        
 * Output: none
 * Additional Comments: Abstract class used for the Project simulation, it is the parent of the Gameboard.h class
 *                                                                     	
 ***************************************************************************/
 
#ifndef WORLD_H
#define WORLD_H
#include <cstdlib>

using namespace std; 

class World
{
	
	public: 
	//default constructor (can't actually make it becasue its virtual
		World() {};
		//gameboard must have a print grid and update grid
		virtual void printGrid() = 0;
		virtual void updateGrid() = 0;
		
	protected:
	//day is the round of the simulation
		int day; 
		//grid will always be 10x10
		char grid[10][10];
		//must initialize the grid and be able to check whether a move is out of bounds
		virtual void initGrid() = 0;
		virtual bool checkBounds(int,int) = 0;
	
};

#endif /* WORLD_H */
