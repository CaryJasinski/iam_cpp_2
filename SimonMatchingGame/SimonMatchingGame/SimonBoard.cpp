#include "SimonBoard.h"
#include "Menu.h"

SimonBoard::SimonBoard()
{
	console = GetConsoleWindow();
	GetWindowRect(console, &consoleRect);
	MoveWindow(console, consoleRect.left, consoleRect.top, 800, 600, true);

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	intRoundsToWin = 2;
	fltAdvanceRoundDelay = 2;
	fltRoundTimerModifier = 1;
	if (fltRoundTimerModifier > 1) fltRoundTimerModifier = 1; 
	if (fltRoundTimerModifier < 0) fltRoundTimerModifier = 0;
}
void SimonBoard::StartGame()
{
	Menu menu;
	intBoardSize = 3;
	int intInitialBoardSize = intBoardSize;
	intCurrentRound = 1;
	blnPlayerCorrect = true;

	menu.DisplayTitle();
	menu.DisplayInstructions();
	CreatePattern();
	while (blnPlayerCorrect && intBoardSize <= intRoundsToWin + intInitialBoardSize)
	{
		DisplayPattern();
		CompareAnswers();
		if(blnPlayerCorrect)
			AdvanceRound();
		else
		{
			ClearBoard();
			menu.DisplayLoss();
		}
	}
	if (blnPlayerCorrect && intBoardSize >= intRoundsToWin + intInitialBoardSize)
	{
		ClearBoard();
		menu.DisplayWin();
	}
}
void SimonBoard::CreatePattern()
{
	srand ((int)time(NULL));
	int intRandomSlot;

	vector<int> vecRoundPattern;

	while (vecRoundPattern.size() < intBoardSize - vecFullPattern.size())
	{
		intRandomSlot = (rand() % 4 + 1);
		vecRoundPattern.insert(vecRoundPattern.end(), intRandomSlot);
	}
	vecFullPattern += vecRoundPattern;
}
void SimonBoard::DisplayPattern()
{
	//+---+---+
	//| 1 | 2 |
	//+---+---+
	//| 3 | 4 |
	//+---+---+
	int index = 0;

	system("cls");
	cout << "\n\n";
	cout << "Current Round: " << intCurrentRound << "\n";
	cout << "\n";
	for (Fulliter = vecFullPattern.begin(); Fulliter != vecFullPattern.end(); ++Fulliter)
	{
		cout << "  " << "- Slot " << ++index << " -\n";
		switch(*Fulliter)
		{
		case 1: cout << "  " << "+---+---+\n";
				cout << "  " << "| ";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "1";
				SetConsoleTextAttribute(hConsole, 7);
				cout << " |   |\n";
				cout << "  " << "+---+---+\n";
				cout << "  " << "|   |   |\n";
				cout << "  " << "+---+---+\n";
			break;
		case 2: cout << "  " << "+---+---+\n";
				cout << "  " << "|   | ";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "2";
				SetConsoleTextAttribute(hConsole, 7);
				cout <<" |\n";
				cout << "  " << "+---+---+\n";
				cout << "  " << "|   |   |\n";
				cout << "  " << "+---+---+\n";
			break;
		case 3: cout << "  " << "+---+---+\n";
				cout << "  " << "|   |   |\n";
				cout << "  " << "+---+---+\n";
				cout << "  " << "| ";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "3";
				SetConsoleTextAttribute(hConsole, 7);
				cout <<" |   |\n";
				cout << "  " << "+---+---+\n";
			break;
		case 4: cout << "  " << "+---+---+\n";
				cout << "  " << "|   |   |\n";
				cout << "  " << "+---+---+\n";
				cout << "  " << "|   | ";
				SetConsoleTextAttribute(hConsole, 2);
				cout << "4";
				SetConsoleTextAttribute(hConsole, 7);
				cout <<" |\n";
				cout << "  " << "+---+---+\n";
			break;
		default: ;
			break;
		}
		cout << "\n";
	}
	Sleep(fltRoundTimerModifier * 1000 * intBoardSize);
	system("cls");
}
void SimonBoard::CompareAnswers()
{
	int index = 0;
	cout << "\n\n";
	cout << "Current Round: " << intCurrentRound << "\n";
	cout << "Enter the pattern you just saw in the proper order.\n\n";
	while (index < intBoardSize)
	{
		cout << "Current slot = " << index + 1;
		cout << " \n";
		cout << "Enter your choice: ";
		cin >> intPlayerSlotChoice;
		if(vecFullPattern.at(index) == intPlayerSlotChoice)
		{
			cout << "\n";
			index++;
			continue;
		}
		else
		{
			cout << "\n";
			cout << "That was not a match.";
			cout << "\n\n";
			cout << "You input " << intPlayerSlotChoice << ". The correct choice was " << vecFullPattern.at(index) << ".\n\n";
			blnPlayerCorrect = false;
			Sleep(2000);
			break;
		}
		cout << "\n";
		index++;
	}
	if (blnPlayerCorrect)
	{
		cout << "\n";
		cout << "You beat the round!! You da besssss \n";
		cout << "\n";
		cout << "Next Round in " << fltAdvanceRoundDelay << " seconds.";
	}
}
void SimonBoard::AdvanceRound()
{
	intCurrentRound += 1;
	if (intBoardSize % 2 == 1 && intBoardSize > 4)
		intBoardSize += 2;
	else
		intBoardSize += 1;
	Sleep(fltAdvanceRoundDelay * 1000);
	CreatePattern();
}
void SimonBoard::ClearBoard()
{
	vecFullPattern.clear();
}