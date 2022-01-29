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
* Source code for the main game mechanics (the so called brain of the programme) - the startgame function, the attack enemy board function and one to keep track of the player who is on turn
*
*/

#include <iostream>
#include "MainGameMechanics.h"
#include "Menus.h"
#include "Board.h"
#include "ShipPlacer.h"

void StartGame(char boardPlayerOne[10][10], char boardPlayerTwo[10][10])
{
	bool run1 = true;
	bool run2 = true;
	int option;

	int unhitSpotsPlayerOne = 31;
	int unhitSpotsPlayerTwo = 31;

	char boardToShowToOpponentPlayerOne[10][10];
	char boardToShowToOpponentPlayerTwo[10][10];
	//char boardToBeAttacked[22][22];
	BoardCreator(boardToShowToOpponentPlayerOne);
	BoardCreator(boardToShowToOpponentPlayerTwo);
	//AttackedBoardCreator(boardToBeAttacked); Bugged for now
	//ShowAttackedBoard(boardToBeAttacked);

	// Setup board of player 1
	while (run1)
	{
		ShowPlayerMenuMessage(1);
		std::cin >> option;
		InputValidator(option, 1, 2);
		int presetNum = 0;

		switch (option)
		{
			case 1: ManualPlace(boardPlayerOne);
				run1 = false;
					break;

			default: InstructPresetNum(); //case 2
				std::cin >> presetNum;
				InputValidator(presetNum, 0, 10);
				PresetBoard(boardPlayerOne, presetNum);
				run1 = false;
					break;
		}
	}

	ShowBoard(boardPlayerOne);
	std::cout << std::endl;
	SkipFiftyRows();

	//Setup board of player 2
	while (run2)
	{
		ShowPlayerMenuMessage(2);
		std::cin >> option;
		InputValidator(option, 1, 2);
		int presetNum = 0;
		
		switch (option)
		{
			case 1:ManualPlace(boardPlayerTwo);
				run2 = false;
					break;

			default : InstructPresetNum(); // case 2
				std::cin >> presetNum;
				InputValidator(presetNum, 0, 10);
				PresetBoard(boardPlayerTwo, presetNum);
				run2 = false;
					break;
		}
	}

	ShowBoard(boardPlayerTwo);
	std::cout << std::endl;
	SkipFiftyRows();

	while (unhitSpotsPlayerOne > 0 && unhitSpotsPlayerTwo > 0)
	{
		int column;
		int row;

		std::cout << "Player One Attacks" << std::endl;
		std::cout << std::endl;

		std::cout << "Coordinates to attack" << std::endl;
		ShowBoard(boardToShowToOpponentPlayerTwo);
		std::cout << std::endl;
		
		std::cout << "Row (between [0 ; 9]): ";
		std::cin >> row;
		InputValidator(row, 0, 9);
		
		std::cout << "Column (between [0 ; 9]): ";
		std::cin >> column;
		InputValidator(column, 0, 9);

		ShowBoard(boardToShowToOpponentPlayerTwo); //Initial showup

		while (Attack(boardPlayerTwo, boardToShowToOpponentPlayerTwo, row, column, unhitSpotsPlayerTwo)) //If player 1 is on turn
		{
			int option = 0;

			unhitSpotsPlayerTwo--;
			ShowHitTargetMessage();
			std::cout << std::endl;

			ShowBoard(boardToShowToOpponentPlayerTwo);
			std::cout << std::endl;

			ShowAfterSuccessfulHitMessage();

			std::cin >> option;
			InputValidator(option, 1, 5);
			std::cout << std::endl;

			switch (option)
			{
				case 1: //Go up a square
					if (row == 0)
					{
						std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					row -= 1;
						break;
				case 2: //Go down a square
					if (row == 9)
					{
						std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					row += 1;
						break;
				case 3: //Go left a square
					if (column == 0)
					{
						std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					column -= 1;
						break;
				case  4: //Go right a square
					if (column == 9)
					{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
					}
					column += 1;
						break;
				default: //Enter new coordinates
					std::cout << "Row (between [0 ; 9]): ";
					std::cin >> row;
					InputValidator(row, 0, 9);

					std::cout << "Column (between [0 ; 9]): ";
					std::cin >> column;
					InputValidator(column, 0, 9);
			}
		}

		//Player two attack

		std::cout << "Player Two Attacks" << std::endl;
		std::cout << std::endl;

		std::cout << "Coordinates to attack:" << std::endl;
		ShowBoard(boardToShowToOpponentPlayerOne);
		std::cout << std::endl;
		std::cout << "Row (between [0 ; 9]): ";
		std::cin >> row;
		InputValidator(row, 0, 9);
		
		std::cout << "Column (between [0 ; 9]): ";
		std::cin >> column;
		InputValidator(column, 0, 9);
		
		ShowBoard(boardToShowToOpponentPlayerOne);
		
		while (Attack(boardPlayerOne, boardToShowToOpponentPlayerOne, row, column, unhitSpotsPlayerOne)) //If player 2 is on turn
		{
			int option = 0;
			unhitSpotsPlayerOne--;
			ShowHitTargetMessage();
			std::cout << std::endl;

			ShowBoard(boardToShowToOpponentPlayerOne);
			std::cout << std::endl;

			ShowAfterSuccessfulHitMessage();

			std::cin >> option;
			InputValidator(option, 1, 5);
			std::cout << std::endl;

			switch (option)
			{
				case 1: //Go up a square
					if (row == 0)
					{
						std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					row -= 1;
						break;
				case 2: //Go down a square
					if (row == 9)
					{
						std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					row += 1;
						break;
				case 3: //Go left a square
					if (column == 0)
					{
						std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					column -= 1;
						break;
				case 4: //Go right a square
					if (column == 9)
					{
						std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					column += 1;
						break;
				default:
					std::cout << "Row (between [0 ; 9]): ";
					std::cin >> row;
					InputValidator(row, 0, 9);

					std::cout << "Column (between [0 ; 9]): ";
					std::cin >> column;
					InputValidator(column, 0, 9);
			}
		}
	}
	if (unhitSpotsPlayerOne == 0)
	{
		std::cout << "Player Two wins" << std::endl;
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Player One wins" << std::endl;
		std::cout << std::endl;
	}
}

bool Attack(char boardOfPlayer[10][10], char boardToShowToOpponent[10][10], int rowCoordinate, int columnCoordinate, int &unHitSpotsPlayer) {
	if (boardOfPlayer[rowCoordinate][columnCoordinate] == 'C')
	{
		std::cout << "You have already made a guess for this spot, please make a new one : " << std::endl;
		unHitSpotsPlayer++;//To compensate for returning true, while we do not make any change to the board
		return true;
	}
	if (boardOfPlayer[rowCoordinate][columnCoordinate] == 'S') {
		boardToShowToOpponent[rowCoordinate][columnCoordinate] = 'H'; // H for hit
		boardOfPlayer[rowCoordinate][columnCoordinate] = 'C'; //C for checked
		return true; // You have hit the target
	}
	else {
		boardToShowToOpponent[rowCoordinate][columnCoordinate] = 'X'; // X for miss
		boardOfPlayer[rowCoordinate][columnCoordinate] = 'C';
		std::cout << "There was nothing!" << std::endl;
		std::cout << std::endl;
		return false;
	}
}
