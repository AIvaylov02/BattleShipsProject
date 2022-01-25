#pragma once
bool IsNearbyShipUp(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);
bool IsNearbyShipDown(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);
bool IsNearbyShipLeft(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);
bool IsNearbyShipRight(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);

bool IsShip(char boardOfPlayer[10][10], int row, int col);
bool IsShipUp(char boardOfPlayer[10][10], int row, int col);
bool IsShipDown(char boardOfPlayer[10][10], int row, int col);
bool IsShipLeft(char boardOfPlayer[10][10], int row, int col);
bool IsShipRight(char boardOfPlayer[10][10], int row, int col);
bool IsShipUpLeftDiagonal(char boardOfPlayer[10][10], int row, int col);
bool IsShipUpRightDiagonal(char boardOfPlayer[10][10], int row, int col);
bool IsShipDownLeftDiagonal(char boardOfPlayer[10][10], int row, int col);
bool IsShipDownRightDiagonal(char boardOfPlayer[10][10], int row, int col);

bool ShipPlacer(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType, const char direction);

void RemoveShipUp(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);
void RemoveShipDown(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);
void RemoveShipLeft(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);
void RemoveShipRight(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType);
void RemoveShip(char boardOfPlayer[10][10], int row, int column, const int LengthOfShipType, const char direction);
