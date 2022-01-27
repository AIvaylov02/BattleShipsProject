#include <iostream>
#include  "MainGameMechanics.h"
#include "Menus.h"
#include  "Board.h"
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

	BoardCreator(boardToShowToOpponentPlayerOne);
	BoardCreator(boardToShowToOpponentPlayerTwo);


	// Setup board of player 1
	while (run1)
	{
		ShowPlayerMenuMessage(1);
		std::cin >> option;
		int presetNum = 0;
		

		switch (option)
		{
		case 1: ManualPlace(boardPlayerOne);
			run1 = false;
			break;

		case 2: InstructPresetNum();
			std::cin >> presetNum;
			InputValidator(presetNum, 0, 10);
			PresetBoard(boardPlayerOne, presetNum);
			run1 = false;
			break;
		default:
			InputValidator(option, 1, 2);
		}
	}

	ShowBoard(boardPlayerOne);
	std::cout << std::endl;


	//Setup board of player 2
	while (run2)
	{
		ShowPlayerMenuMessage(2);
		std::cin >> option;
		int presetNum = 0;
		
		switch (option)
		{
		case 1:ManualPlace(boardPlayerTwo);
			run2 = false;
			break;

		case 2: InstructPresetNum();
			std::cin >> presetNum;
			InputValidator(presetNum, 0, 10);
			PresetBoard(boardPlayerTwo, presetNum);
			run2 = false;
			break;
		default:
			InputValidator(option, 1, 2);
		}
	}

	ShowBoard(boardPlayerTwo);
	std::cout << std::endl;


	while (unhitSpotsPlayerOne > 0 && unhitSpotsPlayerTwo > 0)
	{
		int column;
		int row;

		std::cout << "Player One Attacks" << std::endl;
		std::cout << std::endl;

		std::cout << "Coordinates to attack" << std::endl;
		
		std::cout << "Row: (between [0 ; 9])";
		std::cin >> row;
		InputValidator(row, 0, 9);
		
		while (std::cin.fail() || (row < 0) || (row > 9)) //Check if input is valid for the rows
		{

			if (std::cin.fail()) //What triggers the false flag - if its still true, to clear it, a.k.a not read from console
			{
				std::cin.clear();
				std::cin.ignore();
			}
			ShowInvalidRowMessage();
			std::cout << "Pick a number between [0 ; 9]: ";
			std::cin >> row;
		}
		
		std::cout << "Column: (between [0 ; 9])";
		std::cin >> column;
		InputValidator(column, 0, 9);

		while (std::cin.fail() || (column < 0) || (column > 9)) //Check if input is valid for the columns
		{
			
			if (std::cin.fail()) //What triggers the false flag - if its still true, to clear it, a.k.a not read from console
			{
				std::cin.clear();
				std::cin.ignore();
			}
			ShowInvalidColumnMessage();
			std::cout << "Pick a number between [0 ; 9]: ";
			std::cin >> column;
		}
		

		while (Attack(boardPlayerTwo, boardToShowToOpponentPlayerTwo, row, column, unhitSpotsPlayerTwo))
		{
			int option = 0;

			unhitSpotsPlayerTwo--;

			ShowHitTargetMessage();
			std::cout << std::endl;

			ShowBoard(boardToShowToOpponentPlayerTwo);
			std::cout << std::endl;

			ShowAfterSuccessfulHitMessage();

			std::cin >> option;
			std::cout << std::endl;


			switch (option)
			{
			case 1:
				if (row == 0)
				{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
				}
				row -= 1;
				break;
			case 2:
				if (row == 9)
				{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
				}
				row += 1;
				break;
			case 3:
				if (column == 0)
				{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
				}
				column -= 1;
				break;
			case  4:
				if (column == 9)
				{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
				}
				column += 1;
				break;
			default:;

			}

		}
		
		ShowBoard(boardToShowToOpponentPlayerTwo);
		std::cout << std::endl;


		//Player two attack

		std::cout << "Player Two Attacks" << std::endl;
		std::cout << std::endl;

		std::cout << "Coordinates to attack" << std::endl;

		std::cout << "Row: (between [0 ; 9])";
		std::cin >> row;
		InputValidator(row, 0, 9);

		while (std::cin.fail() || (row < 0) || (row > 9)) //Check if input is valid for the rows
		{

			if (std::cin.fail()) //What triggers the false flag - if its still true, to clear it, a.k.a not read from console
			{
				std::cin.clear();
				std::cin.ignore();
			}
			ShowInvalidRowMessage();
			std::cout << "Pick a number between [0 ; 9]: ";
			std::cin >> row;
		}
		
		std::cout << "Column: (between [0 ; 9]) ";
		std::cin >> column;
		InputValidator(column, 0, 9);

		while (std::cin.fail() || (column < 0) || (column > 9)) //Check if input is valid for the columns
		{

			if (std::cin.fail()) //What triggers the false flag - if its still true, to clear it, a.k.a not read from console
			{
				std::cin.clear();
				std::cin.ignore();
			}
			ShowInvalidColumnMessage();
			std::cout << "Pick a number between [0 ; 9]: ";
			std::cin >> column;
		}

		while (Attack(boardPlayerOne, boardToShowToOpponentPlayerOne, row, column, unhitSpotsPlayerOne))
		{
			int option = 0;
			unhitSpotsPlayerOne--;

			ShowHitTargetMessage();
			std::cout << std::endl;

			ShowBoard(boardToShowToOpponentPlayerTwo);
			std::cout << std::endl;

			ShowAfterSuccessfulHitMessage();

			std::cin >> option;
			std::cout << std::endl;


			switch (option)
			{
			case 1: 
					if (row == 0)
					{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
						continue;
					}
					row -= 1;
						break;
			case 2: 
					if (row == 9)
					{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
					}
					row += 1;
						break;
			case 3:
					if (column == 0)
					{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
					}
					column -= 1;
						break;
			case  4: 
					if (column == 9)
					{
					std::cout << "Oops, it seems like you are at the end of the board, please try another input!" << std::endl;
					continue;
					}
					column += 1;
						break;
			default:;

			}

		}

		ShowBoard(boardToShowToOpponentPlayerOne);
		std::cout << std::endl;

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
				std::cout << "Try again " << std::endl;
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
		case 4:
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
		default:
			InputValidator(shipOption, 1, 4);
			continue;

		}

		std::cout << "Coordinates of the starting point: " << std::endl;

		std::cout << "*Row: ";
		std::cin >> row;

		if (row > 10 || row < 0)
		{
			ShowInvalidRowMessage();
			std::cin >> row;
			std::cout << std::endl;

		}

		std::cout << "*Column: ";
		std::cin >> column;
		std::cout << std::endl;


		if (column > 10 || column < 0)
		{
			ShowInvalidColumnMessage();
			std::cin >> column;
			std::cout << std::endl;
		}

		std::cout << "Direction of placement ? " << std::endl;
		std::cout << "1) Up" << std::endl;
		std::cout << "2) Down " << std::endl;
		std::cout << "3) Left" << std::endl;
		std::cout << "4) Right " << std::endl;
		std::cout << "Your choise: ";
		std::cin >> directionOption;
		std::cout << std::endl;


		switch (directionOption) {

		case 1: direction = 'U';
			break;
		case 2: direction = 'D';
			break;
		case 3: direction = 'L';
			break;
		case 4: direction = 'R';
			break;
		default:
			std::cout << std::endl;
			std::cout << "Invalid input " << std::endl;
			std::cout << std::endl;
			std::cin.clear();
			std::cin.ignore((256), '\n');
			continue;

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
		std::cout << std::endl;



		switch (changeOption)
		{
		case 1:RemoveShip(boardOfPlayer, row, column, currentShipLength, direction);
			std::cout << "Enter your new ship position: " << std::endl;
			std::cout << std::endl;
			placedShips--;
			break;
		case 2:
			std::cin.clear();
			std::cin.ignore((256), '\n');
			continue;
			break;
		}
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
