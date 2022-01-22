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
const int LENGTHofSmallShip = 2;
const int LENGTHofMediumShip = 3;
const int LENGTHofLargeShip = 4;
const int LENGTHofCruiser = 6;
const int NUMBERofSmallShips = 4;
const int NUMBERofMediumShips = 3;
const int NUMBERofLargeShips = 2;
const int NUMBERofCruisers = 1;
const int MAXSHIPS = 10;

// StartGame - SETUP
// MainGame - Checker
// Menu ?? (with predefined configs)
//void MenuSelect();
void ShowBoard(const char boardOfPlayer[10][10]);
void PresetBoard(char boardOfPlayer[10][10], unsigned int numOfBoard);
void BoardCreator(char boardOfPlayer[10][10]);
void ShipPlacer(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType, const char direction);
bool Attack(char boardOfPlayer[10][10], int rowCoordinate, int columnCoordinate);
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

	return 0;
}

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
void ShipPlacer(char boardOfPlayer[10][10] , int row, int column , const int LengthOfShipType, const char direction) {
	// 5 - 4 - right - small, i -rows / k - columns
	int remLength = LengthOfShipType;
	if (direction == 'D')
		do {
			boardOfPlayer[row][column] = 'S'; // Go down
			row++;

		} while (remLength > 1);
	else if (direction == 'U')
		do {
			boardOfPlayer[row][column] = 'S'; // Go up
			row--;

		} while (remLength > 1);
	else if (direction == 'L')
		do {
			boardOfPlayer[row][column] = 'S'; //Go left
			column--;

		} while (remLength > 1);
	else 
		do {
			boardOfPlayer[row][column] = 'S'; //Go right
			column++;

		} while (remLength > 1);
	
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
bool Attack(char boardOfPlayer[10][10], int rowCoordinate, int columnCoordinate) {
	if (boardOfPlayer[rowCoordinate][columnCoordinate] == 'S') {
		boardOfPlayer[rowCoordinate][columnCoordinate] = 'H';
		return 1; // You have hit the target
	}
	else {
		boardOfPlayer[rowCoordinate][columnCoordinate] = 'X';
		return 0;
	}
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
