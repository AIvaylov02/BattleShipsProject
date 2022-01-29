#pragma once
void StartGame(char boardPlayerOne[10][10], char boardPlayerTwo[10][10]);
bool Attack(char boardOfPlayer[10][10], char boradToShowToOponent[10][10], int rowCoordinate, int columnCoordinate, int& unHitSpotsPlayer);