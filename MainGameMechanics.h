#pragma once
void StartGame(char boardPlayerOne[10][10], char boardPlayerTwo[10][10]);
bool Attack(char functionBoardOfPlayer[10][10], char printedBoardOfPlayer[22][22], int rowCoordinate, int columnCoordinate, int& unHitSpotsPlayer);