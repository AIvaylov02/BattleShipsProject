#pragma once
void ShowWelcomeMenuMessage();
void ShowPlayerMenuMessage(int playerNumber);
void ShowHitTargetMessage();
void ShowAfterSuccessfulHitMessage();
void ShowInvalidInputMessage(const int LOWERLIMIT, const int UPPERLIMIT);
void InputValidator(int& x, const int LOWERLIMIT, const int UPPERLIMIT);
void InstructPresetNum();
void SkipFiftyRows();