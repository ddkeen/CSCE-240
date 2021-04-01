/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: Human.cpp file for Project 5 Simulation
 * Input requirements:  none                  
 * Output: none
 * Additional Comments:.cpp file for the Human object. Behaves similarly to a Zombie. An array of Humans is used in the Gameboard.cpp class for the zombies simulation
 *                                                                     	
 ***************************************************************************/
#include "Human.h"
//default constuctor
Human::Human()
{
	x = -1;
	y = -1;
	soldier = false;
	killed = true;
	moved = false;
}
//alternate constructor
Human::Human(int i, int j)
{
	x = i;
	y = j;
	soldier = false;
	killed = true;
	moved = false;
}

//2nd operator overload. sets coordinates for the human in the array
void Human::operator()(int a,int b)
{
	//check bounds
	if(a>=0 && a<10 && b>=0 && b<10)
	{
		x = a;
		y = b;
	}
}
//returns x value
const int Human::getX() const
{
	return x;
}
//returns y value
const int Human::getY() const
{
	return y;
}
//move the individual human object
void Human::Hmove()
{ 
		int randomNumber;
		randomNumber = (rand() % 3);
		int val = randomNumber;
		//human will move 2/3 times (66%)
		if(val > 0)
		{
			//humans can move up, down, left, or right. So 4 possible outcomes
			randomNumber = (rand() % 4) + 1;
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
			else if(dir ==4)
			{
				if(x != 0)
				{
					setX(getX()-1);
				}
			}
		}
}
//returns whether human object is a soldier
const bool Human::isSoldier() const
{
	return soldier;
}
//returns whether human object is killed
const bool Human::isKilled() const
{
	return killed;
}
//set whether the human is a soldier, if its a soldier it can kill zombies and can only die from radiation
void Human::setSoldier(bool a)
{
	soldier = a;
}
//set whetehre human object is killed, if so it won't appear in the grid, it is deactivated
void Human::setKilled(bool a)
{
	killed = a;
}
//set x coordinate of human
void Human::setX(int a)
{
	if(a>=0 && a<10)
		{
			x = a;
		}
}
//set y coordinate of human
void Human::setY(int b)
{
	if(b>=0 && b<10)
		{
			y = b;
		}
}
//return whether human has moved that day
const bool Human::isMoved() const
{
	return moved;
}
//set whether human has moved that day, it can only move once per day.
void Human::hasMoved(bool a)
{
	moved = a;
}

