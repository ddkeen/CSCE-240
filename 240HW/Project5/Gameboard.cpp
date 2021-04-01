/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: Gameboard.cpp file for Project 5 Simulation
 * Input requirements:   none                               
 * Output: if used in the main function, runs a zombie appocalypse simulation
 * Additional Comments:Inherits from World.h virtual abstract class. Uses a char array, zombie array and human array of 10x10 to complete a simulation of zombies trying to kill and infect humans while humans try to survive
 *                                                                     	
 ***************************************************************************/
 

//constants for size of the game board and chars in Gameboard
const int SIZE = 10;
const char HUMAN = 'H';
const char ZOMBIE = 'Z';
const char SOLDIER = 'S';
const char RADIATION = 'R';

#include <cstdlib>
#include <string>
#include "Gameboard.h"
#include <iostream>
#include <ctime>

//only constructor
Gameboard::Gameboard()
{
	//set the seed
	srand((unsigned) time(0)); 
	//day variable keep track of the round of simulaition
	day = 0; 
	// creates two d array that will be the board, and arrays for humans and zombies
	for (int i =0; i< SIZE; i++)// double loop that fills array to the empty char.
		{
			for(int j = 0; j< SIZE; j++)
			{
				//set all elements in the grid and the object arrays to null
				grid[i][j] = ' ';
				humans[i][j](i,j);//operator overload() to set coordinates of each value, by default they are -1
				zombies[i][j](i,j);
			}
		}
}

void Gameboard::radiation()
{
	//radiation has a 10% chance of appearing on the board each round
	int randomNumber = (rand() % 10) + 1;
	int rad = randomNumber;
	int rcount =  0;
	if(rad == 1)
	{
		while (rcount < 1)
		{
			randomNumber = (rand()%SIZE);
			int CoordX = randomNumber; //random int less than 10 
			randomNumber = (rand()%SIZE);
			int CoordY = randomNumber;
			if(grid[CoordX][CoordY]!= RADIATION && grid[CoordX][CoordY]!= ZOMBIE && grid[CoordX][CoordY]!= SOLDIER && grid[CoordX][CoordY]!= HUMAN)
			{
				grid[CoordX][CoordY] = RADIATION;
				rcount++;
				cout << "A deadly radiation spot has appeared in the town!" << endl;
			}
		}
	}
}
void Gameboard::updateGrid() //might need for World class, would function the same as round
{
	// humans and soldiers move first
	humanMove();
	//zombies move after all humans
	zombieMove();
	radiation(); // add radiation to the board 
	//print grid
	printGrid();
	cout << "The Humans and Zombies have moved! See what they did above!" << endl;
}

bool Gameboard::checkBounds(int,int)
{
	//this function is not used because the checkBounds logic is already contained in the hMove and zMove functions for humans and zombies
	return true;
} 
//everything runs in the sim function
void Gameboard::sim()
{
	//create and fill board
	initGrid();	
	//print original random grid to start
	printGrid();
	//user presses y (for yes) then enter to see next day. 
	cout << "Press y to see the next day, or press any other key to exit ";
	char go = ' ';
	cin >> go;
	if(go != 'y')
	{
		cout << "Ending Simulation, Thanks for Playing!" << endl;
		exit(0);
	}
	cout <<endl;
	//max is 1000 days
	while (day < 1000)
	{	
		//new round = new day
		day++;
		cout<< "Day "; cout << day;  cout << " is starting!" << endl;
		//spwan humans every 30 days, spawn soldiers every 20 days, and eliminate radiation from the board every 60 days
		if(day%20 ==0)
		{
			spawnHuman();
		}
		if(day%30 ==0)
		{
			spawnSoldier();
		}
		if(day%75 == 0)
		{
			elimRadiation();
		}
		//each round is completed in the round() function
		updateGrid();
		cout << "Day "; cout << day; cout << " is now over. " << endl;
		//user presses y to see next day
		if (checkWin())
		{
			exit(0);
		}
		//comment this section out if you want the entire simulation to run 
		cout << "Press y to see the next day, or press any other key to exit ";
		cin >> go;
		if(go != 'y')
		{
			cout << "Ending Simulation, Thanks for Playing" << endl;
			exit(0);
		}
		cout << endl;
	}
}

//function to print contents of grid to standard output
void Gameboard::printGrid()
{
	//should it be checking all elements of the zombie array and human array?
	cout << "   |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |" << endl;
	cout << "----------------------------------------------------------------" << endl;
		for(int i = 0; i< SIZE; i++)
		{
			cout<< i;
			cout<< "  |";
			 for(int j = 0; j<SIZE; j++)
			 {
				 cout<< "  ";
				 cout<< grid[i][j];
				 cout<<  "  |";
			 }
			 cout<< endl;
			 cout<< "----------------------------------------------------------------"<<endl;
		}
}
//fill board (create board is basically the constructor)
void Gameboard::initGrid() 
{
		cout<<endl;
		cout<< "Oh No! Some of the Resident's of CaseyDale have become Zombies! " << endl;
		cout<< "Will the humans survive? Or will Zombies take over?" << endl;
		int randomNumber;
		int HCount = 0;
		int ZCount = 0;
		//fill board with 15 humans randomly placed on board
		while(HCount<15) 
		{
			randomNumber = (rand()%SIZE);
			int CoordX = randomNumber; //random int less than 10 
			randomNumber = (rand()%SIZE);
			int CoordY = randomNumber; //random int less than 10
			//make sure space is empty
			if(grid[CoordX][CoordY] == ' ')
			{
				//activate human in human array by setting its killed variable to false
				humans[CoordX][CoordY].setKilled(false);
				grid[CoordX][CoordY] = HUMAN;
				HCount++;
			}
		}
		//fill board with 3 zombies
		while(ZCount<3)
		{
			randomNumber = (rand()%SIZE);
			int CoordX = randomNumber;
			randomNumber = (rand()%SIZE);
			int CoordY = randomNumber;
			//make sure space is empty
			if(grid[CoordX][CoordY] == ' ') 
			{
				//activate zombie in zombie array by setting its killed variable to false
				zombies[CoordX][CoordY].setKilled(false);
				grid[CoordX][CoordY] = ZOMBIE;
				ZCount++;
			}
		}
}
const bool Gameboard::checkWin() const 
{
		bool win = false;
		int Hcount = 0;
		int Zcount = 0;
		//check every space in the board for any humans and zombies
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j] == HUMAN || grid[i][j] == SOLDIER)
				{
					Hcount++;
				}
				if(grid[i][j] == ZOMBIE)
				{
					Zcount++;
				}
			}
		}
		//if there are no humans remaining, the zombies have won
		if(Hcount == 0)
		{
			cout << "Simulation is over and Zombies win!" << endl;
			win = true;
		}
		//if there are no zombies remaining, the humans have won
		else if(Zcount == 0)
		{
			cout << "Simulation is over and Humans win!" <<endl;
			win = true;
		}
		return win;

}
//this occurs every 20 days
void Gameboard::spawnHuman()
{
	int hcount =  0;
	while (hcount < 1)
		{
			cout << "A human has been spawned in today!" << endl;
			int randomNumber = (rand()%SIZE);
			int CoordX = randomNumber; //random int less than 10 
			randomNumber = (rand()%SIZE);
			int CoordY = randomNumber;
			//only spawn on that space if it is empty
			if(grid[CoordX][CoordY]!= RADIATION && grid[CoordX][CoordY]!= ZOMBIE && grid[CoordX][CoordY]!= SOLDIER && grid[CoordX][CoordY]!= HUMAN)
			{
				grid[CoordX][CoordY] = HUMAN;
				hcount++;
				//since human spawned, the human in the human array should now be active
				humans[CoordX][CoordY].setKilled(false);
			}
		}
	
}
//changes human to soldier every 30 rounds
void Gameboard::spawnSoldier()
{
	
		int randomNumber;
		int SCount = 0;
		int AreHumans = 0;
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j] == HUMAN && humans[i][j].isKilled()==false && humans[i][j].isSoldier() ==false)
				{
					AreHumans++;
				}
			}
		}
		if(AreHumans == 0)
		{
			//all humans on the board are already soliders, so none spawn in
			cout << "All humans in the town are already soldiers!" << endl;
		}
		//if no humans left (only soldiers and zombies, don't add another soldier)
		if(AreHumans != 0)
		{
			while(SCount<1) 
			{
				//get random corrdinates on board, if that space has a human on it, make that human a soldier
				randomNumber = (rand() % 10);
				int CoordX = randomNumber;
				randomNumber = (rand() % 10);
				int CoordY = randomNumber;
				if(grid[CoordX][CoordY] == HUMAN)
				{
					//that human has now become a soldier, so set it's flag to true
					grid[CoordX][CoordY] = SOLDIER;
					humans[CoordX][CoordY].setSoldier(true);
					SCount++;
					cout << "A human has been turned into a soldier!" << endl;
				}
			}
		}
}

//eliminate all radiation from the board every 75 days
void Gameboard::elimRadiation()
{
	cout << "The powerful rays of the sun has eliminated all radiation spots from the board!" << endl;
	//check board for any radiation spots and make them empty
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				if(grid[i][j] == RADIATION)
					grid[i][j] = ' ';
			}
		}
}
//move all humans on the board (not soldiers)
void Gameboard::humanMove()
{
	//at the start of each round, each human will not have moved, so change its moved flag to false
	for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
					humans[i][j].hasMoved(false);
			}
		}
		//loop through entire grid and look for humans
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{	//check both the grid and the human array to see if there is a soldier or human at that index, and make sure that human object has not already moved
				if((grid[i][j] == HUMAN || grid[i][j] == SOLDIER) && (humans[i][j].isKilled() == false && humans[i][j].isMoved() == false))
				{
					//move the individual human in the array
					humans[i][j].Hmove();
					int x = humans[i][j].getX();
					int y  = humans[i][j].getY();
					humans[i][j].hasMoved(true); //set its moved value to true
					humans[i][j].setKilled(true);//assume that the human moved to a new spot, so set it to killed to innactivate it
					humans[i][j](i,j);//set coordinates back because we already have the new coordinates in x and y values
					//if that space currently has another human, or soldier in it, or if the previous object in the grid was a human and the new spot has a zombie, move the object back to the previous spot
					if(grid[x][y] == HUMAN || grid[x][y] == SOLDIER || (grid[i][j] == HUMAN && grid[x][y] == ZOMBIE))
					{
						//it moved back, so it is still alive
						humans[i][j].setKilled(false);
					}
					//a soldier moves onto a zombie space
					else if(grid[x][y] == ZOMBIE && grid[i][j] == SOLDIER)
					{
							//zombie has been killed by soldier
							grid[i][j] = ' ';
							grid[x][y] = SOLDIER;
							zombies[x][y].setKilled(true);
							humans[x][y].setKilled(false);
							//soldier moved
							humans[x][y].setSoldier(true);
							humans[i][j].setSoldier(false);
							humans[x][y].hasMoved(true); //don't let the soldier at the new spot move again
						
					}
					//human object is killed by radiation
					else if(grid[x][y] == RADIATION)
					{
						//make that human object in the array null because it has been killed by radiation
						grid[i][j] = ' ';
					}
					//moved to an open space
					else if(grid[x][y] == ' ')
					{
						//since the human has moved to new coordinates, delete the old human and create a new human in the new spot
						humans[x][y].setKilled(false);
						//check if human that moved was a soldier
						if(humans[i][j].isSoldier() == true && grid[i][j] == SOLDIER)
						{
							//new spot has a soldier but the old spot no longer has one
							humans[x][y].setSoldier(true);
							humans[i][j].setSoldier(false);
							grid[x][y] = SOLDIER;
						}
						else
						{
							grid[x][y] = HUMAN;
						}
						grid[i][j] = ' ';
						//object in new spot has moved already
						humans[x][y].hasMoved(true);
					}
				}
			}
		}
	}
//zombies move after humans
void Gameboard::zombieMove()
{
		//at the start of each round, each zombie will not have moved, so change its moved flag to false
		for (int i = 0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{
				zombies[i][j].hasMoved(false);
				
			}
		}
		for (int i =0; i< SIZE; i++)
		{
			for(int j = 0; j< SIZE; j++)
			{	//make sure grid at that spot has a Z and the zombie in the zombie array is not dead and hasn't moved already
				if(grid[i][j] == ZOMBIE && (zombies[i][j].isKilled() == false && zombies[i][j].isMoved() == false))
				{
					//move the individual zombie in the array
					zombies[i][j].Zmove();
					int x = zombies[i][j].getX();
					int y = zombies[i][j].getY();
					zombies[i][j](i,j); //have the new coordinates so we can reset the old ones
					zombies[i][j].setKilled(true); //asumes it moved to a new spot, so deaactivate it
					zombies[i][j].hasMoved(true); //this object has moved now
					//can't move onto a zombie, soldier, or radiation
					if(grid[x][y] == ZOMBIE || grid[x][y] == RADIATION || grid[x][y] == SOLDIER)
					{
						//move zombie back to original spot
						zombies[i][j].setKilled(false);
					}
					else if(grid[x][y] == HUMAN)
					{
						//human dies becasue it was either eaten or tunred into a zombie
						humans[x][y].setKilled(true);
						int randomNumber = (rand() % 10) + 1;
						int choice = randomNumber; //50% chance to kill human and 50% chance to infect them
						if(choice > 5)//infect human, original zombie stays in same spot
						{
							//new zombie isn't allowed to move this turn
							zombies[x][y].setKilled(false);
							grid[x][y] = ZOMBIE;
							zombies[i][j].setKilled(false);
						}
						else//kill and move into their place
						{
							zombies[x][y].setKilled(false);
							grid[i][j] = ' ';
							grid [x][y] = ZOMBIE;
						}
						zombies[x][y].hasMoved(true);
					}
					else if (grid[x][y] == ' ') //moves to a new spot if nothing in it
					{
						zombies[x][y].setKilled(false);
						grid[x][y] = ZOMBIE;
						grid[i][j] = ' ';
						zombies[x][y].hasMoved(true);
					}
				}
			}
		}
	}		
				
			
