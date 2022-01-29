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
* Source code for board creation, board presets and manual placement of ships
*
*/

#include <iostream>
#include "Board.h"
#include "ShipPlacer.h"
#include "Menus.h"

void ShowBoard(const char boardOfPlayer[10][10]) {
	for (unsigned int i = 0; i < 10; i++)
	{
		for (unsigned int k = 0; k < 10; k++)
			std::cout << boardOfPlayer[i][k];
		std::cout << '\n';
	}
}
void BoardCreator(char boardOfPlayer[10][10]) {
	for (unsigned int i = 0; i < 10; i++)
		for (unsigned int k = 0; k < 10; k++)
			boardOfPlayer[i][k] = '-';
}

/*void AttackedBoardCreator(char boardToBeSeen[22][22]) { //We already have 22 by 22 board
	unsigned int rowDigit = 0;
	unsigned int columnDigit = 0;

	for (unsigned int i = 0; i < 22; i++) {
		if(i==0) //top row
			for (unsigned int k = 0; k < 22; k++) {
				if (k == 0)
					boardToBeSeen[i][k] = ' ';
				else if (k % 2 == 1)
					boardToBeSeen[i][k] = '|';
				else {
					boardToBeSeen[i][k] = columnDigit;
					columnDigit++;
				}
			}

		else if (i % 2 == 1) // row is odd, we need a separator
			for (unsigned int k = 0; k < 22; k++)
				boardToBeSeen[i][k] = '-';
		else { // row is a playable one
			for (unsigned int k = 0; k < 22; k++)
				if (k == 0) {
					boardToBeSeen[i][k] = rowDigit;
					rowDigit++;
				}
				else if (k % 2 == 1)
					boardToBeSeen[i][k] = '|';
				else {
					boardToBeSeen[i][k] = ' '; //have not guessed at this spot
				}
		}
	}
}


void ShowAttackedBoard(const char boardToBeSeen[22][22]) {
	for (unsigned int i = 0; i < 22; i++)
	{
		for (unsigned int k = 0; k < 22; k++)
			std::cout << boardToBeSeen[i][k];
		std::cout << std::endl;
	}
	std::cout << boardToBeSeen[0][2];
}
*/

void PresetBoard(char boardOfPlayer[10][10], unsigned int numOfBoard) {
	switch (numOfBoard) {
	case 0: //row - column - length - direction
		ShipPlacer(boardOfPlayer, 0, 0, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 3, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 6, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 2, 0, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 2, 5, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 2, 9, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 5, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 9, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 7, 0, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 9, 4, LENGTHofCruiser, 'R');
		break;
	case 1:
		ShipPlacer(boardOfPlayer, 1, 1, LENGTHofCruiser, 'R');
		ShipPlacer(boardOfPlayer, 0, 8, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 9, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 3, 2, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 4, 6, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 5, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 3, 0, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 6, 1, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 8, 3, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 4, LENGTHofSmallShip, 'D');
		break;
	case 2:
		ShipPlacer(boardOfPlayer, 0, 0, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 4, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 9, LENGTHofSmallShip, 'L');
		ShipPlacer(boardOfPlayer, 2, 2, LENGTHofCruiser, 'D');
		ShipPlacer(boardOfPlayer, 3, 4, LENGTHofSmallShip, 'U');
		ShipPlacer(boardOfPlayer, 2, 8, LENGTHofMediumShip, 'L');
		ShipPlacer(boardOfPlayer, 5, 0, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 6, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 9, 0, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 7, 4, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 9, LENGTHofLargeShip, 'L');
		break;
	case 3:
		ShipPlacer(boardOfPlayer, 1, 8, LENGTHofCruiser, 'D');
		ShipPlacer(boardOfPlayer, 2, 0, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 6, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 5, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 6, 2, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 9, 0, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 2, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 3, 2, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 4, 6, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 4, LENGTHofSmallShip, 'D');
		break;
	case 4:
		ShipPlacer(boardOfPlayer, 4, 1, LENGTHofCruiser, 'R');
		ShipPlacer(boardOfPlayer, 3, 9, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 2, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 6, 1, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 2, 3, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 7, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 1, 0, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 6, 6, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 7, 4, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 9, 7, LENGTHofSmallShip, 'R');
		break;
	case 5:
		ShipPlacer(boardOfPlayer, 4, 3, LENGTHofCruiser, 'D');
		ShipPlacer(boardOfPlayer, 1, 2, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 6, 5, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 7, 0, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 2, 9, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 7, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 3, 5, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 0, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 8, 5, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 8, LENGTHofSmallShip, 'R');
		break;
	case 6:
		ShipPlacer(boardOfPlayer, 1, 5, LENGTHofCruiser, 'D');
		ShipPlacer(boardOfPlayer, 1, 0, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 4, 2, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 9, 0, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 7, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 8, 6, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 3, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 2, 8, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 4, 7, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 9, LENGTHofSmallShip, 'D');
		break;
	case 7:
		ShipPlacer(boardOfPlayer, 8, 0, LENGTHofCruiser, 'R');
		ShipPlacer(boardOfPlayer, 4, 4, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 2, 9, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 7, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 1, 3, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 6, 7, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 3, 1, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 1, 0, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 8, 9, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 6, 2, LENGTHofSmallShip, 'R');
		break;
	case 8:
		ShipPlacer(boardOfPlayer, 3, 9, LENGTHofCruiser, 'D');
		ShipPlacer(boardOfPlayer, 2, 4, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 9, 4, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 1, 0, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 1, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 4, 5, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 6, 5, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 6, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 6, 7, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 9, LENGTHofSmallShip, 'D');
		break;
	case 9:
		ShipPlacer(boardOfPlayer, 2, 4, LENGTHofCruiser, 'R');
		ShipPlacer(boardOfPlayer, 6, 1, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 1, 2, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 4, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 5, 6, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 5, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 2, 0, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 2, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 8, 0, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 7, 9, LENGTHofSmallShip, 'D');
		break;
	default: // like preset 0 - example
		ShipPlacer(boardOfPlayer, 0, 0, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 0, 3, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 0, 6, LENGTHofLargeShip, 'R');
		ShipPlacer(boardOfPlayer, 2, 0, LENGTHofLargeShip, 'D');
		ShipPlacer(boardOfPlayer, 2, 5, LENGTHofMediumShip, 'R');
		ShipPlacer(boardOfPlayer, 2, 9, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 5, LENGTHofSmallShip, 'D');
		ShipPlacer(boardOfPlayer, 5, 9, LENGTHofMediumShip, 'D');
		ShipPlacer(boardOfPlayer, 7, 0, LENGTHofSmallShip, 'R');
		ShipPlacer(boardOfPlayer, 9, 4, LENGTHofCruiser, 'R');
	}
}

void ManualPlace(char boardOfPlayer[10][10])
{
	const int MAXSHIPS = 10;
	const int LENGTHofSmallShip = 2;
	const int LENGTHofMediumShip = 3;
	const int LENGTHofLargeShip = 4;
	const int LENGTHofCruiser = 6;

	int NumberofSmallShips = 4;
	int NumberofMediumShips = 3;
	int NumberofLargeShips = 2;
	int NumberofCruisers = 1;
	int placedShips = 0;


	while (placedShips <= MAXSHIPS)
	{
		int shipOption = 0;
		int directionOption = 0;
		int currentShipLength = 0;
		char direction = '0';
		int column = 0;
		int row = 0;

		std::cout << "What kind of ship do you want to place ? " << std::endl;
		std::cout << "1) Small ship   -	2 blocks length " << std::endl;
		std::cout << "2) Medium ship  -	3 blocks length " << std::endl;
		std::cout << "3) Large ship   -	4 blocks length " << std::endl;
		std::cout << "4) Cruiser ship - 4 blocks length " << std::endl;
		std::cout << "Your choice: ";

		std::cin >> shipOption;
		InputValidator(shipOption, 1, 4);
		std::cout << std::endl;

		switch (shipOption)
		{

			case 1:
				if (NumberofSmallShips > 0)
				{
					currentShipLength = LENGTHofSmallShip;
					NumberofSmallShips--;
				}
				else
				{
					std::cout << "There are no more small ships left to place! " << std::endl;
					std::cout << "Try again! " << std::endl;
					std::cout << std::endl;
					continue;
				}
				break;
			case 2:
				if (NumberofMediumShips > 0)
				{
					currentShipLength = LENGTHofMediumShip;
					NumberofMediumShips--;
				}
				else
				{
					std::cout << "There are no more medium ships left to place! " << std::endl;
					std::cout << "Try again! " << std::endl;
					std::cout << std::endl;
					continue;
				}
				break;
			case 3:
				if (NumberofLargeShips > 0)
				{
					currentShipLength = LENGTHofLargeShip;
					NumberofLargeShips--;
				}
				else
				{
					std::cout << "There are no more large ships left to place! " << std::endl;
					std::cout << "Try again! " << std::endl;
					std::cout << std::endl;
					continue;
				}
				break;
			default: //case 4
				if (NumberofCruisers > 0) {
				currentShipLength = LENGTHofCruiser;
				NumberofCruisers--;
				}
				else
				{
				std::cout << "There are no more cruiser ships left to place! " << std::endl;
				std::cout << "Try again! " << std::endl;
				std::cout << std::endl;
				continue;
				}
				break;
		}
		std::cout << "Coordinates of the starting point: " << std::endl;
		std::cout << "*Row (between [0 ; 9]): ";
		std::cin >> row;
		InputValidator(row, 0, 9);

		std::cout << "*Column (between [0 ; 9]): ";
		std::cin >> column;
		InputValidator(column, 0, 9);

		std::cout << "Direction of placement ? " << std::endl;
		std::cout << "1) Up" << std::endl;
		std::cout << "2) Down " << std::endl;
		std::cout << "3) Left" << std::endl;
		std::cout << "4) Right " << std::endl;
		std::cout << "Your choice: ";
		std::cin >> directionOption;
		InputValidator(directionOption, 1, 4);

		switch (directionOption) {

			case 1: direction = 'U';
				break;
			case 2: direction = 'D';
				break;
			case 3: direction = 'L';
				break;
			default: direction = 'R'; //case 4
				break;
		}

		if (!ShipPlacer(boardOfPlayer, row, column, currentShipLength, direction))
		{
			std::cout << "Invalid placement !" << std::endl;
			std::cout << "Please try again ! " << std::endl;
			std::cout << std::endl;
			continue;
		}

		placedShips++;

		ShowBoard(boardOfPlayer);
		std::cout << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << "Number of ships remaining: " << 10 - placedShips << std::endl;
		std::cout << "-----------------------------" << std::endl;
		std::cout << std::endl;

		int changeOption = 0;

		std::cout << "Do you want to change your ship position ? " << std::endl;
		std::cout << "1) Yes " << std::endl;
		std::cout << "2) No " << std::endl;
		std::cout << "Your choice: ";
		std::cin >> changeOption;
		InputValidator(changeOption, 1, 2);

		switch (changeOption)
		{
			case 1: RemoveShip(boardOfPlayer, row, column, currentShipLength, direction);
				std::cout << "Enter your new ship position: " << std::endl;
				std::cout << std::endl;
				placedShips--;
				break;
			default:
				continue;
		}
	}
}