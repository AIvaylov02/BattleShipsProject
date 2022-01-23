#include <iostream>
#include "BoardSetup.h"

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
void ShipPlacer(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType, const char direction) {
	// 5 - 4 - right - small, i -rows / k - columns
	int remLength = LengthOfShipType;
	if (direction == 'D') {

		if (10 - row >= LengthOfShipType)
		{

			for (unsigned int i = 0; i < LengthOfShipType; i++) {



				if ((i == 0) && ((boardOfPlayer[row][column] == 'S') || (boardOfPlayer[row - 1][column] == 'S') || (boardOfPlayer[row - 1][column - 1] == 'S') || (boardOfPlayer[row - 1][column + 1] == 'S') || (boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S'))) {

					//if (column != 0) { Seems to not like comparing empty? arr[] slots

					//}

					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						row--;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i != LengthOfShipType - 1)) && ((boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						row--;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i == LengthOfShipType - 1)) && ((boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S') || (boardOfPlayer[row + 1][column - 1] == 'S') || (boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row + 1][column + 1] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						row--;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else {
					boardOfPlayer[row][column] = 'S'; // Go down
					row++;
				}


			}
		}
		else
		{
			std::cout << "Invalid placement";
		}

	}
	else if (direction == 'U') {
		if (row + 1 >= LengthOfShipType)
		{
			for (unsigned int i = 0; i < LengthOfShipType; i++) {

				if ((i == 0) && ((boardOfPlayer[row][column] == 'S') || (boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row + 1][column - 1] == 'S') || (boardOfPlayer[row + 1][column + 1] == 'S') || (boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S'))) {

					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						row++;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i != LengthOfShipType - 1)) && ((boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						row++;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i == LengthOfShipType - 1)) && ((boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S') || (boardOfPlayer[row - 1][column - 1] == 'S') || (boardOfPlayer[row - 1][column] == 'S') || (boardOfPlayer[row - 1][column + 1] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						row++;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else
				{
					boardOfPlayer[row][column] = 'S'; // Go up
					row--;

				}
			}

		}
		else
		{
			std::cout << "Invalid placement";

		}
	}

	else if (direction == 'L')
	{
		if (column + 1 >= LengthOfShipType)
		{
			for (unsigned int i = 0; i < LengthOfShipType; i++) {

				if ((i == 0) && ((boardOfPlayer[row][column] == 'S') || (boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row - 1][column] == 'S') || (boardOfPlayer[row + 1][column + 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S') || (boardOfPlayer[row - 1][column + 1] == 'S'))) {

					if ((boardOfPlayer[row + 1][column + 1] == 'S'))
					{
						std::cout << "Here";
					}

					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						column++;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i != LengthOfShipType - 1)) && ((boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row - 1][column] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						column++;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i == LengthOfShipType - 1)) && ((boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row - 1][column] == 'S') || (boardOfPlayer[row - 1][column - 1] == 'S') || (boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row + 1][column - 1] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						column++;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else
				{
					boardOfPlayer[row][column] = 'S'; //Go left
					column--;
				}

			}
		}
		else
		{
			std::cout << "Invalid placement";

		}
	}

	else //R
	{
		if (10 - column >= LengthOfShipType)
		{
			for (unsigned int i = 0; i < LengthOfShipType; i++) {

				if ((i == 0) && ((boardOfPlayer[row][column] == 'S') || (boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row - 1][column] == 'S') || (boardOfPlayer[row + 1][column - 1] == 'S') || (boardOfPlayer[row][column - 1] == 'S') || (boardOfPlayer[row - 1][column - 1] == 'S'))) {

					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						column--;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i != LengthOfShipType - 1)) && ((boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row - 1][column] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						column--;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else if (((i == LengthOfShipType - 1)) && ((boardOfPlayer[row + 1][column] == 'S') || (boardOfPlayer[row - 1][column] == 'S') || (boardOfPlayer[row - 1][column + 1] == 'S') || (boardOfPlayer[row][column + 1] == 'S') || (boardOfPlayer[row + 1][column + 1] == 'S')))
				{
					std::cout << "Invalid placement" << std::endl;

					for (unsigned int y = i; y > 0; y--)
					{
						column--;
						boardOfPlayer[row][column] = '-'; // nullify
					}

					break;
				}
				else
				{
					boardOfPlayer[row][column] = 'S'; //Go right
					column++;
				}

			}
		}
		else
		{
			std::cout << "Invalid placement" << std::endl;

		}
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
		boardOfPlayer[0][1] = 'S';
		boardOfPlayer[1][1] = 'S';
		boardOfPlayer[2][1] = 'S';
		boardOfPlayer[3][1] = 'S';
		boardOfPlayer[5][0] = 'S';
		boardOfPlayer[6][0] = 'S';
		boardOfPlayer[8][0] = 'S';
		boardOfPlayer[8][1] = 'S';
		boardOfPlayer[8][2] = 'S';
		boardOfPlayer[1][3] = 'S';
		boardOfPlayer[1][4] = 'S';
		boardOfPlayer[1][5] = 'S';
		boardOfPlayer[3][4] = 'S';
		boardOfPlayer[4][4] = 'S';
		boardOfPlayer[5][4] = 'S';
		boardOfPlayer[6][4] = 'S';
		boardOfPlayer[7][4] = 'S';
		boardOfPlayer[8][4] = 'S';
		boardOfPlayer[5][2] = 'S';
		boardOfPlayer[6][2] = 'S';
		boardOfPlayer[1][7] = 'S';
		boardOfPlayer[2][7] = 'S';
		boardOfPlayer[0][7] = 'S';
		boardOfPlayer[0][9] = 'S';
		boardOfPlayer[1][9] = 'S';
		boardOfPlayer[0][9] = 'S';
		boardOfPlayer[9][6] = 'S';
		boardOfPlayer[9][7] = 'S';
		boardOfPlayer[9][8] = 'S';
		boardOfPlayer[9][9] = 'S';
		boardOfPlayer[4][8] = 'S';
		boardOfPlayer[5][8] = 'S';
		break;

	default:
		break;
	}
}