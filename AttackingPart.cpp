#include <iostream>
#include "GuessingPart.h"

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

bool GuessingPhaseStart(bool playerOneResponse, bool playerTwoResponse) {
	return ((playerOneResponse == 1) && (playerOneResponse == playerTwoResponse));
}
