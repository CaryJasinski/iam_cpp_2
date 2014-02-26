#include "Menu.h"

Menu::Menu()
{
}
void Menu::DisplayTitle()
{
	system("cls");
	cout << "\n\n";
	cout << "  " << "------ " << "------ " << "|\\   /| " << "------ " << "|\\   |\n";
	cout << "  " << "|      " << "  ||   " << "| \\ / | " << "|    | " << "| \\  |\n";
	cout << "  " << "------ " << "  ||   " << "|  -  | " << "|    | " << "|  | |\n";
	cout << "  " << "     | " << "  ||   " << "|     | " << "|    | " << "|  \\ |\n";
	cout << "  " << "------ " << "------ " << "|     | " << "------ " << "|   \\|\n";
	cout << "\n\n";
	cout << "      " << "Press any key to continue"; 
	std::cin.ignore();
	std::cin.get();
}
void Menu::DisplayInstructions()
{
	system("cls");
	cout << "\n\n";
	cout << "  " << "HOW TO PLAY\n";
	cout << "  " << "-----------\n\n";
	cout << "  " << "- Memorize the ";
	//SetConsoleTextAttribute(hConsole, 2);
	cout << "GREEN";
	//SetConsoleTextAttribute(hConsole, 7);
	cout << " numbers in each slot when the round begins.\n\n";
	cout << "  " << "- Be Quick the pattern will disappear after a time.\n\n";
	cout << "  " << "- Repeat the pattern for each corrisponding slot.\n\n";
	cout << "  " << "- Enter the right number for all the slots to win the round.\n\n";
	cout << "  " << "- Get through as many rounds as you can!\n\n";
	cout << "\n\n";
	cout << "            " << "Press any key to begin"; 
	cin.ignore();
	cin.get(); 
}
void Menu::DisplayLoss() 
{
	system("cls");
	cout << "\n\n";
	cout << "  " << "\\    / " << "------ " << "|    | " << "  " << "|      " << "------ " << "------ " << "------\n";
	cout << "  " << " \\  /  " << "|    | " << "|    | " << "  " << "|      " << "|    | " << "|      " << "|     \n";
	cout << "  " << "  \\/   " << "|    | " << "|    | " << "  " << "|      " << "|    | " << "------ " << "|---  \n";
	cout << "  " << "  ||   " << "|    | " << "|    | " << "  " << "|      " << "|    | " << "     | " << "|     \n";
	cout << "  " << "  ||   " << "------ " << "------ " << "  " << "------ " << "------ " << "------ " << "------\n";
	cout << "\n\n";
	cout << "         " << "Press any key to return to Title Screen";
	cin.ignore();
	cin.get();
}
void Menu::DisplayWin() 
{
	system("cls");
	cout << "\n\n";
	cout << "  " << "\\    / " << "------ " << "|    | " << "  " << "|    | " << "------ " << "|\\   |\n";
	cout << "  " << " \\  /  " << "|    | " << "|    | " << "  " << "|    | " << "  ||   " << "| \\  |\n";
	cout << "  " << "  \\/   " << "|    | " << "|    | " << "  " << "|    | " << "  ||   " << "|  | |\n";
	cout << "  " << "  ||   " << "|    | " << "|    | " << "  " << "| /\\ | " << "  ||   " << "|  \\ |\n";
	cout << "  " << "  ||   " << "------ " << "------ " << "  " << "|/  \\| " << "------ " << "|   \\|\n";
	cout << "\n\n";
	cout << "     " << "Press any key to return to Title Screen";
	cin.ignore();
	cin.get();
}