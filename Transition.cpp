#include <iostream>
#include "Transition.h"
bool IsPrepared(unsigned int playerSmallShipsCount, unsigned int playerMediumShipsCount, unsigned int playerLargeShipsCount, unsigned int playerCruiserShipsCount) {

	return playerSmallShipsCount == 0 && playerMediumShipsCount == 0 && playerLargeShipsCount == 0 && playerCruiserShipsCount == 0;
}
//To be taken by a variable
bool LockConfig(char response, unsigned int playerSmallShipsCount, unsigned int playerMediumShipsCount, unsigned int playerLargeShipsCount, unsigned int playerCruiserShipsCount) {
	if ((response == 'y') || (response == 'Y') && (IsPrepared(playerSmallShipsCount, playerMediumShipsCount, playerLargeShipsCount, playerCruiserShipsCount) == 1)) {
		return 1;
	}
	else return 0;
}