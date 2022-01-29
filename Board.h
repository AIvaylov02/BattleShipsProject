#pragma once
void ShowBoard(const char boardOfPlayer[10][10]);
void PresetBoard(char boardOfPlayer[10][10], unsigned int numOfBoard);
void BoardCreator(char boardOfPlayer[10][10]);
//void AttackedBoardCreator(char boardToBeSeen[22][22]);; Seem to be bugged for now
//void ShowAttackedBoard(const char boardToBeSeen[22][22]);
void ManualPlace(char boardOfPlayer[10][10]);