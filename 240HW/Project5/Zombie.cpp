/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: Zomibie.h file for Project 5 Simulation
 * Input requirements:   none                               
 * Output: none
 * Additional Comments: .cpp file for the Zombie object. Behaves similarly to a human. An array of zombies is used in the Gameboard.cpp class for the zombies simulation
 *                                                                     	
 ***************************************************************************/
#include "Zombie.h"
//default constructor
Zombie::Zombie()
{
	x = -1;
	y= -1;
	killed = true;
	moved = false;
}
//alternate constructor
Zombie::Zombie(int i, int j)
{
	int x = i;
	int y = j;
	killed = true;
	moved = false;
}
//move individual zombie
void Zombie::Zmove() 
{
		int randomNumber;
		//90% chance for zombie to move
		randomNumber = (rand() % 10) +1;
		int val = randomNumber;
		//can move
		if(val > 1)
		{
			//zombies can move all directions
			randomNumber = (rand() % 8) + 1;
			int dir = randomNumber;
			if(dir == 1)//moves right if space is empty
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(y != 9 )
				{	
					setY(getY()+1);
				}
			}
	
			else if(dir == 2)//moves down
			{
				if(x != 9)
				{
					setX(getX()+1);
				}
			}
			else if(dir == 3)//moves left
			{
				if(y != 0)
				{
					setY(getY()-1);
				}
			}
			else if(dir ==4) // moves up
			{
				if(x != 0)
				{
					setX(getX()-1); 
				}
			}
			else if(dir == 5)//moves down and right
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(y != 9 && x !=9)
				{
					setX(getX()+1);
					setY(getY()+1); 
				}
			}
			else if(dir == 6)//moves down and left
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(x != 9 && y!=0 )
				{
					setX(getX()+1);
					setY(getY()-1); 
				}
			}
			else if(dir == 7)//moves up and right
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(x != 0 && y!=9)
				{
					setX(getX()-1);
					setY(getY()+1); 
					
				}
			}
			else if(dir == 8)//moves up and left
			{
			//if we are on the rightmost row or the space to the right is already going to be changed to a human, go to the next loop.
				if(y != 0  && x!=0)
				{
					setX(getX()-1);
					setY(getY()-1); 
				}
			}
		}
}
//first operator overload, set coordinates of the zombie in the array
void Zombie::operator()(const int a,const int b)
{
	//check if valid
	if(a>=0 && a<10 && b>=0 && b<10)
	{
		x = a;
		y = b;
	}
}
//return x coordinate
const int Zombie::getX() const
{
	return x;
}
//return y coordinate
const int Zombie::getY() const
{
	return y;
}
//set killed value
void Zombie::setKilled(bool a)
{
	killed = a;
}
//return value of killed, if true, it won't appear in the grid becasue the zombie is not alive
bool Zombie::isKilled() const
{
	return killed;
}
//set x coordinate
void Zombie::setX(int a)
{
	if(a>=0 && a<10)
		{
			x = a;
		}
}
//set y coordinate
void Zombie::setY(int b)
{
	if(b>= 0 && b<10)
		y = b;
}
//return whether zombie has already moved that day
bool Zombie::isMoved() const
{
	return moved;
}
//set whether zombie has moved that day.
void Zombie::hasMoved(bool a)
{
	moved = a;
}


