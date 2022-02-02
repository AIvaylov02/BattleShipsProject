#pragma once
void PresetBoard(char boardOfPlayer[10][10], unsigned int numOfBoard);
void FunctionalBoardCreator(char boardOfPlayer[10][10]);
void VisualBoardCreator(char boardToBeSeen[22][22]);
void BoardAtStart(char boardToBeSeen[22][22], const char boardOfPlayer[10][10]);
void ClearBoard(char boardToBeSeen[22][22]);
void ShowVisualBoard(const char boardToBeSeen[22][22]);
void ManualPlace(char boardOfPlayer[10][10], char boardToBeSeen[22][22]);