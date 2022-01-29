/**
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia
University
* Winter semester 2021/2022
*
* @author Antoan Ivaylov
* @idnumber 7MI0600129
* @compiler VC
*
* Main Game - Entry menu
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
		InputValidator(option, 1, 2);

		switch (option) {

			case 1:StartGame(boardPlayerOne, boardPlayerTwo);
			run = false;
				break;
			default: return 0; //case 2 - exit
		}

	}

	return 0;
}