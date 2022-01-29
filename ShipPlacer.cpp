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
* Source code for ship placement/ removal
*
*/


#include <iostream>
#include "ShipPlacer.h"

bool IsNearbyShipUp(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (unsigned int k = 0; k < LengthOfShipType; k++) {

		if (k == 0)
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipUp(boardOfPlayer, row, column)) return true;
			if (IsShipDown(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipDownLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipUpLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
			}
			if (column != 9)
			{
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipUpRightDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipDownRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		else
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipUp(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipUpLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
			}
			if (column != 9)
			{
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipUpRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		row--;
	}
	return  false;
}

bool IsNearbyShipDown(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (unsigned int k = 0; k < LengthOfShipType; k++) {

		if (k == 0)
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipUp(boardOfPlayer, row, column)) return true;
			if (IsShipDown(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipUpLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
				if (IsShipDownLeftDiagonal(boardOfPlayer, row, column)) return true;
			}

			if (column != 9)
			{
				if (IsShipUpRightDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipDownRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		else
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipDown(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipDownLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
			}
			if (column != 9)
			{
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipDownRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		row++;
	}
	return  false;
}

bool IsNearbyShipLeft(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (unsigned int k = 0; k < LengthOfShipType; k++) {

		if (k == 0)
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipUp(boardOfPlayer, row, column)) return true;
			if (IsShipDown(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipUpLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
				if (IsShipDownLeftDiagonal(boardOfPlayer, row, column)) return true;
			}
			if (column != 9)
			{
				if (IsShipUpRightDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipDownRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		else
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipDown(boardOfPlayer, row, column)) return true;
			if (IsShipUp(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipUpLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
				if (IsShipDownLeftDiagonal(boardOfPlayer, row, column)) return true;
			}
			if (column != 9)
			{
				if (IsShipUpRightDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipDownRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		column--;
	}
	return  false;
}
bool IsNearbyShipRight(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (unsigned int k = 0; k < LengthOfShipType; k++) {

		if (k == 0)
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipUp(boardOfPlayer, row, column)) return true;
			if (IsShipDown(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipUpLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
				if (IsShipDownLeftDiagonal(boardOfPlayer, row, column)) return true;
			}
			if (column != 9)
			{
				if (IsShipUpRightDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipDownRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		else
		{
			if (IsShip(boardOfPlayer, row, column)) return true;
			if (IsShipDown(boardOfPlayer, row, column)) return true;
			if (IsShipUp(boardOfPlayer, row, column)) return true;

			if (column != 0)
			{
				if (IsShipUpLeftDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipLeft(boardOfPlayer, row, column)) return true;
				if (IsShipDownLeftDiagonal(boardOfPlayer, row, column)) return true;
			}
			if (column != 9)
			{
				if (IsShipUpRightDiagonal(boardOfPlayer, row, column)) return true;
				if (IsShipRight(boardOfPlayer, row, column)) return true;
				if (IsShipDownRightDiagonal(boardOfPlayer, row, column)) return true;
			}
		}
		column++;
	}
	return  false;
}




bool IsShip(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row][col] == 'S';
}
bool IsShipUp(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row - 1][col] == 'S';
}
bool IsShipDown(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row + 1][col] == 'S';
}
bool IsShipLeft(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row][col - 1] == 'S';
}
bool IsShipRight(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row][col + 1] == 'S';
}
bool IsShipUpLeftDiagonal(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row - 1][col - 1] == 'S';
}
bool IsShipUpRightDiagonal(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row - 1][col + 1] == 'S';
}
bool IsShipDownLeftDiagonal(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row + 1][col - 1] == 'S';
}
bool IsShipDownRightDiagonal(char boardOfPlayer[10][10], int row, int col)
{
	return boardOfPlayer[row + 1][col + 1] == 'S';
}


bool ShipPlacer(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType, const char direction) {
	int remLength = LengthOfShipType;
	if (direction == 'D') {

		if (10 - row >= LengthOfShipType)
		{
			if (IsNearbyShipDown(boardOfPlayer, row, column, LengthOfShipType))
			{
				std::cout << "Invalid placement" << std::endl;
				return false;
			}

			for (unsigned int i = 0; i < LengthOfShipType; i++) {
				boardOfPlayer[row][column] = 'S'; // Go down
				row++;
			}
			return  true;
		}
		else
			return false;
	}
	else if (direction == 'U') {
		if (row + 1 >= LengthOfShipType)
		{
			if (IsNearbyShipUp(boardOfPlayer, row, column, LengthOfShipType))
			{
				std::cout << "Invalid placement" << std::endl;
				return false;
			}

			for (unsigned int i = 0; i < LengthOfShipType; i++) {
				boardOfPlayer[row][column] = 'S'; // Go up
				row--;
			}
			return  true;
		}
		else
			return false;
	}
	else if (direction == 'L')
	{
		if (column + 1 >= LengthOfShipType)
		{
			if (IsNearbyShipLeft(boardOfPlayer, row, column, LengthOfShipType))
			{
				std::cout << "Invalid placement" << std::endl;

				return false;
			}
			for (unsigned int i = 0; i < LengthOfShipType; i++) {
				boardOfPlayer[row][column] = 'S'; //Go left
				column--;
			}
			return  true;
		}
		else
			return false;
	}
	else
	{
		if (IsNearbyShipRight(boardOfPlayer, row, column, LengthOfShipType))
		{
			std::cout << "Invalid placement" << std::endl;
			return false;
		}
		if (10 - column >= LengthOfShipType)
		{
			for (unsigned int i = 0; i < LengthOfShipType; i++) {
				boardOfPlayer[row][column] = 'S'; //Go right
				column++;
			}
			return  true;
		}
		else
			return false;
	}

}

void RemoveShipUp(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (int i = 0; i < LengthOfShipType; i++)
	{
		boardOfPlayer[row][column] = '-';
		row--;
	}
}
void RemoveShipDown(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (int i = 0; i < LengthOfShipType; i++)
	{
		boardOfPlayer[row][column] = '-';
		row++;
	}
}
void RemoveShipLeft(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (int i = 0; i < LengthOfShipType; i++)
	{
		boardOfPlayer[row][column] = '-';
		column--;
	}
}
void RemoveShipRight(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType)
{
	for (int i = 0; i < LengthOfShipType; i++)
	{
		boardOfPlayer[row][column] = '-';
		column++;
	}
}

void RemoveShip(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType, const char direction)
{
	if (direction == 'U') RemoveShipUp(boardOfPlayer, row, column, LengthOfShipType);
	if (direction == 'D') RemoveShipDown(boardOfPlayer, row, column, LengthOfShipType);
	if (direction == 'L') RemoveShipLeft(boardOfPlayer, row, column, LengthOfShipType);
	if (direction == 'R') RemoveShipRight(boardOfPlayer, row, column, LengthOfShipType);
}