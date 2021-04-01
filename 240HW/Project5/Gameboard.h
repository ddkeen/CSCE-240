/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: Gameboard.h file for Project 5 Simulation
 * Input requirements:     none                             
 * Output: none
 * Additional Comments:Header for the Gameboard object that runs a zombie simulation. It inherits methods from the virtual world class but also has many more functions for the simulation
 *                       Compile Main.cpp, Zombie.cpp, Human.cpp, and Gameboard.cpp together                                    	
 ***************************************************************************/
#include <iostream>
#include <string> 
#include <cstdlib>
#include <fstream>
#include "World.h"
#include "Human.h"
#include "Zombie.h"
using namespace std;

class Gameboard : public World { //: public World (must inherit from world)
	
	public:
	
		Gameboard();
		//default methods from world class
		void printGrid(); 
		void updateGrid();
	
		void sim();
		//move all humans on grid and in human array
		void humanMove();
		//check whether there are no zombies left or no humans left
		const bool checkWin() const;
		//move all zombies on grid and in human array
		void zombieMove();
		//soldier is spawned every 30 roundsds
		void spawnSoldier();
		//human is spawned every 20 rounds
		void spawnHuman();
		//eliminate radiation from board every 75 days
		void elimRadiation();
		//each turn there is a 10% chance of radiation
		void radiation();
		
	protected:
		//all from world class
		void initGrid();
		//not used in Gameboard class
		bool checkBounds(int,int);
		//keep track of the round of simulations
		int day; 
		
		//char array to print output and human and zombie arrays to keep track and move objects
		char grid[10][10]; 
		Human humans[10][10];
		Zombie zombies[10][10];
		
		
	
};

