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
	case 1:
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