#include <iostream>
#include <string>
#include <vector>
#include "windows.h"
#include "time.h"

#define _WIN32_WINNT 0x0500

using namespace std;

class SimonBoard
{
private:
	int intBoardSize;
	int intCurrentRound;
	int intPlayerSlotChoice;
	int intRoundsToWin;
	float fltAdvanceRoundDelay;
	float fltRoundTimerModifier;
	bool blnPlayerCorrect;
	vector<int> vecFullPattern;
	vector<int>::iterator Fulliter;

public:
	HWND console;
	HANDLE hConsole;
	RECT consoleRect;
	SimonBoard();
	void StartGame();
	void CreatePattern();
	void CompareAnswers();
	void AdvanceRound();
	void DisplayPattern();
	void ClearBoard();
};

template <typename T>
inline vector<T> & operator+=(vector<T> & left, const vector<T> & right ) {
	for( const auto & value : right )
		left.push_back( value );

	return left;
}