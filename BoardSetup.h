#pragma once
void ShowBoard(const char boardOfPlayer[10][10]);
void PresetBoard(char boardOfPlayer[10][10], unsigned int numOfBoard);
void BoardCreator(char boardOfPlayer[10][10]);

const int LENGTHofSmallShip = 2;
const int LENGTHofMediumShip = 3;
const int LENGTHofLargeShip = 4;
const int LENGTHofCruiser = 6;
const int NUMBERofSmallShips = 4;
const int NUMBERofMediumShips = 3;
const int NUMBERofLargeShips = 2;
const int NUMBERofCruisers = 1;
const int MAXSHIPS = 10;