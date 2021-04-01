/***************************************************************************
 * Name: David Keen and Cort Miles
 * Date and Time: 11/15 10:10PM
 * Function: Main.cpp file for Project 5 Simulation
 * Input requirements:    none                              
 * Output: A zombie apocalypse simulation
 * Additional Comments: Everything is run in the sim function of Gameboard.cpp. It has many functions called inside it.
 * see the attached project 5 description document for rules of the simulation. User must press y to see each round of the simulation
 *                                                                     	
 ***************************************************************************/
 
#include <cstdlib>
#include <iostream>
#include <string>
#include "Gameboard.h"


int main(int argc, char** argv) 
{
	Gameboard game; 
	game.sim();
}
