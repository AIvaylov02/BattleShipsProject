/**
*
* Solution to course project # <номер на вариант>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia
University
* Winter semester 2021/2022
*
* @author Antoan Ivaylov
* @idnumber 7MI0600129
* @compiler VC
*
* Main Game - will be reconstruced to different structure files tomorrow...
*
*/

#include <iostream>
#include <iomanip>
#include "BoardSetup.h"
#include "GuessingPart.h"
#include "Transition.h"


// StartGame - SETUP
// MainGame - Checker
// Menu ?? (with predefined configs)
//void MenuSelect();


int main()
{
	unsigned int preset = 0;
	std::cin >> preset;
	char boardPlayerOne[10][10];
	char boardPlayerTwo[10][10];
	BoardCreator(boardPlayerOne);
	PresetBoard(boardPlayerOne, preset);
	ShowBoard(boardPlayerOne);
	std::cout << "Hello and welcome to Battleships!" << std::endl;
	std::cout << "Sorry, but my input function doesn't work properly";

	return 0;
}



/*void MenuSelect() {
	int pos;
	std::cin >> pos;
	if (pos==1) { //use predefined schemes
		int schemeNum;
			switch (schemeNum)
			{
			case 1:

			}

	}
}*/
