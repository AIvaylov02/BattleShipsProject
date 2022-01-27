/**
*
* Solution to course project
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia
University
* Winter semester 2021/2022
*
* @author Antoan Ivaylov
* @idnumber 7MI0600129
* @compiler VC
*
* Main Game (in progress..)
*
*/

#include <iostream>

#include "ShipPlacer.h"
#include "Menus.h"
#include "MainGameMechanics.h"
#include "Board.h"


int main()
{
	char boardPlayerOne[10][10];
	char boardPlayerTwo[10][10];

	BoardCreator(boardPlayerOne);
	BoardCreator(boardPlayerTwo);

	bool run = true;

	while (run)
	{
		int option;

		ShowWelcomeMenuMessage();

		std::cin >> option;


		switch (option) {

		case 1:StartGame(boardPlayerOne, boardPlayerTwo);
			run = false;
			break;
		case 2: return 0;
		default:
			InputValidator(option, 1, 2);
		}

	}

	return 0;
}