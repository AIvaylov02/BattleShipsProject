#include <iostream>
#include  "Board.h"
#include "ShipPlacer.h"

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
		for (unsigned int k = 0; k < 10; k++) {
			boardOfPlayer[i][k] = '-';
		}
}

void PresetBoard(char boardOfPlayer[10][10], unsigned int numOfBoard) {
	switch (numOfBoard) {
	case 0:
		break;//I have changed my mind about using presets
	case 1: // As in the example - manually put - bad idea..
		boardOfPlayer[0][0] = 'S';
		boardOfPlayer[0][1] = 'S';
		boardOfPlayer[0][3] = 'S';
		boardOfPlayer[1][3] = 'S';
		boardOfPlayer[2][3] = 'S';
		boardOfPlayer[0][6] = 'S';
		boardOfPlayer[0][7] = 'S';
		boardOfPlayer[0][8] = 'S';
		boardOfPlayer[0][9] = 'S';
		boardOfPlayer[2][0] = 'S';
		boardOfPlayer[3][0] = 'S';
		boardOfPlayer[4][0] = 'S';
		boardOfPlayer[5][0] = 'S';
		boardOfPlayer[2][5] = 'S';
		boardOfPlayer[2][6] = 'S';
		boardOfPlayer[2][7] = 'S';
		boardOfPlayer[2][9] = 'S';
		boardOfPlayer[3][9] = 'S';
		boardOfPlayer[5][5] = 'S';
		boardOfPlayer[6][5] = 'S';
		boardOfPlayer[5][9] = 'S';
		boardOfPlayer[6][9] = 'S';
		boardOfPlayer[7][9] = 'S';
		boardOfPlayer[7][0] = 'S';
		boardOfPlayer[7][1] = 'S';
		boardOfPlayer[9][4] = 'S';
		boardOfPlayer[9][5] = 'S';
		boardOfPlayer[9][6] = 'S';
		boardOfPlayer[9][7] = 'S';
		boardOfPlayer[9][8] = 'S';
		boardOfPlayer[9][9] = 'S';

		break;
	case 2:
		ShipPlacer(boardOfPlayer, 0, 0, LENGTHofSmallShip, 'D'); //row - column - length - direction
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

	default:
		break;
	}
}