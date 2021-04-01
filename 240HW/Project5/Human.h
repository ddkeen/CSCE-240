/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: Human.h file for Project 5 Simulation
 * Input requirements:      none                            
 * Output: none 
 * Additional Comments: Header file for the Human class for the zombie apocalypse simulation.  If a human is a soldier, it can kill zombies. If not, it can be killed by or turned into a zombie
 * All humans can be killed by radiation
 *                                                                     	
 ***************************************************************************/
#include <iostream>
#include <string> 
using namespace std;

class Human {
	
	public:
		Human();//default constructor sets coordinates to -1,-1
		Human(int,int);//all humans will be given coordinates on the board
		
		void Hmove();
		//second operator overload
		void operator()(int,int);//sets location on board to a new location
		
		const bool isSoldier() const;
		const bool isKilled() const;
		const bool isMoved() const;
		
		void hasMoved(bool);
		void setSoldier(bool); //if they are a soldier, they will appear as an S and can kill Zombies they land on
		void setKilled(bool); //if they are killed, they will not appear on the board at all
		
		const int getX() const; // get X coordinate
		const int getY() const; //get Y coordinate
		void setX(int);
		void setY(int);
		
	private:
		int x;
		int y;
		bool soldier;
		bool killed;
		bool moved;
};
