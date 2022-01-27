#pragma once
void ShowWelcomeMenuMessage();
void ShowPlayerMenuMessage(int playerNumber);
void ShowInvalidRowMessage();
void ShowInvalidColumnMessage();
void ShowHitTargetMessage();
void ShowAfterSuccessfulHitMessage();
void ShowInvalidInputMessage();
void InputValidator(int& x, const int LOWERLIMIT, const int UPPERLIMIT);
void InstructPresetNum();