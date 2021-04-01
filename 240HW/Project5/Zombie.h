/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: Zombie.h file for Project 5 Simulation
 * Input requirements:     none                         
 * Output: none
 * Additional Comments:Header file for the Zombie object for the zombie apocalypse simulation. Zombies can only be killed by soldiers, zombies infect or kill humans when they move
 *                                                                     	
 ***************************************************************************/
#include <iostream>
#include <string> 
using namespace std;

class Zombie{
	
	public:
		Zombie(); //default constructor
		Zombie(int,int);

		void Zmove();//can move any direction
		//first operator overload
		void operator()(int,int);//sets location on board to a new location
		
		const int getX() const; // get X coordinate
		const int getY() const; //get Y coordinate
		
		//check if zombie has moved already or has been killed
		bool isMoved() const;
		bool isKilled() const;
		
		//set moved and killed values
		void hasMoved(bool);
		void setKilled(bool); //if they are killed, they will not appear on the board at all and won't move
		
		void setX(int);
		void setY(int);
	
	private:
		bool killed;
		int x;
		int y;
		bool moved;
		
};
