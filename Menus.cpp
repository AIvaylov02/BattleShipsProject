#include <iostream>
#include  "Menus.h"

void ShowWelcomeMenuMessage()
{
	std::cout << "Hello and Welcome to Battleships!" << std::endl;
	std::cout << "1) Start" << std::endl;
	std::cout << "2) Exit" << std::endl;
	std::cout << "Your choice: ";

}

void ShowPlayerMenuMessage(int playerNumber)
{
	if (playerNumber == 1)
	{
		std::cout << "Player 1, How do you want to place your ships ? " << std::endl;
	}
	else
	{
		std::cout << "Player 2, How do you want to place your ships ? " << std::endl;
	}
	std::cout << "1) Manually " << std::endl;
	std::cout << "2) From a preset " << std::endl;
	std::cout << "Your choice: ";
}

void ShowInvalidRowMessage()
{
	std::cout << "Invalid input! " << std::endl;
	std::cout << "Please enter row again: ";
}
void ShowInvalidColumnMessage()
{
	std::cout << "Invalid input " << std::endl;
	std::cout << "Please enter column again: ";
}

void ShowHitTargetMessage()
{
	std::cout << "You have hit a target!" << std::endl;
	std::cout << "Attack again!" << std::endl;
}

void ShowAfterSuccessfulHitMessage()
{
	std::cout << "Do you want to attack:" << std::endl;
	std::cout << "1) One square up" << std::endl;
	std::cout << "2) One square down" << std::endl;
	std::cout << "3) One square left" << std::endl;
	std::cout << "4) One square right" << std::endl;
	std::cout << "5) Enter new coordinates" << std::endl;
	std::cout << "Your choice: ";
}

void ShowInvalidInputMessage()
{
	std::cout << "Invalid input!\n" << std::endl;
}

void InstructPresetNum() 
{
	std::cout << "Please enter a valid preset [ 0 - 10 ] : ";
}

void InputValidator(int& x, const int LOWERLIMIT, const int UPPERLIMIT) { //Checks if the input is an integer
	if (x < LOWERLIMIT || x > UPPERLIMIT)
		ShowInvalidInputMessage();
	while (std::cin.fail()) {
		ShowInvalidInputMessage();
		std::cin.clear(); //Clears the error
		std::cin.ignore(256, '\n'); //Ignores next 256 characters until it meets a sentinel, in this case a newline
		std::cin >> x;
		std::cout << std::endl;
	}
}