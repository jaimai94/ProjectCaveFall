/*
 * Idea, Concept & Development: Johannes Ewers
 *
 * About:
 * This little text adventure is a demo.
 *
 * Legal & Copyright:
 * Any form of publishing the game executables and files or this code needs my allowance
 * first.
 */

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<windows.h>
using namespace std;

// Functions of the game (listed):
void mainMenuInputHandler();
void gameInputHandler();
void play();
void exit();
void mainMenu();
void thanksForPlaying();


// Global variables:
bool exitGame = false;

// Game main function:
int main() {
	bool EULA = false;
	ifstream f("EULA.txt");
	char c;


	if(f.is_open()){
		cout << f.rdbuf();
	}
	cout << endl;
	cout << "Do you accepting this EULA (Y/N)? By declining you cannot use this Program." << endl;
	bool exitThisLoop = false;
	while(exitThisLoop == false){
		cin >> c;
//		if(c == ('y' || 'Y')){
		if(c == 'Y'){
			EULA = true;
			exitThisLoop = true;
		}
//		if(c == ('n' || 'N')){
		else if(c == 'N'){
			exitGame = true;
			exitThisLoop = true;
		}
//		if(c != ('y' || 'Y' || 'n' || 'N')){
		else{
			cout << "The input is invalid! Please enter a valid input." << endl;
		}
	}

	if(EULA == true){
		while (exitGame != true) {
			cout << "This demo was developed by Johannes Ewers" << endl;
			Sleep(7000);
			system("cls");
			mainMenu();
		}
	}
	else thanksForPlaying();

	return 0;
}

// Functions of the game (defined):
void play() {
	// Muss noch etwas machen!
	system("cls");
	//cout << "Game starting..." << endl;
	Sleep(3000);
	system("cls");
	cout << "The story began on a slightly foggy morning. " << endl;
	Sleep(8000);
	cout << endl;
	cout
			<< "You woke up and made you ready for leaving the sturdy house to chop new wood for your simple chimney. ";
	Sleep(16000);
	cout
			<< "For a moment you listened to the birds, which were at the same time awake like you. ";
	Sleep(17000);
	cout
			<< "You stood up, dressed yourself, took your old axe and left the house. "
			<< endl;
	cout << endl;
	Sleep(13000);
	cout << "You hiked thought the orange woods for a while. ";
	Sleep(9000);
	cout
			<< "You looked carefully to the sun, which were shining warm thought the white clouds on your worn clothes. ";
	cout << endl;
	cout << endl;
	Sleep(19000);
	cout << "Suddenly you stopped ";
	Sleep(3000);
	cout << "and looked around. ";
	Sleep(3000);
	cout << "As you found an old and dry looking tree. ";
	Sleep(9000);
	cout << "You hasty walked to it. "; //and took your trusty axe. ";
	Sleep(9000);
	//cout << "Willing to swing the axe into the old tree. ";
	//Sleep(9000);
	cout << "And swung your axe into the old tree with all your strength. "
			<< endl;
	cout << endl;
	Sleep(12000);
	cout
			<< "Suddenly in this moment, the earth breaks under your boots away and you both falling into unknown darknessess. ";
	Sleep(18000);
	system("cls");
	Sleep(10000);
	cout << "You woke up. ";
	Sleep(3000);
	cout << "Disoriented. ";
	Sleep(1000);
	cout << "Hurt. ";
	Sleep(1000);
	cout << "And even unable to see your own hands. ";
	Sleep(8000);
	cout << "But you still managed to stood up. " << endl;
	Sleep(13000);
	cout << "After that, you heard something rustling! " << endl;
	cout << endl;
	Sleep(6000);
	cout << "What do you want to do?" << endl;
	cout << "1. Scream" << endl;
	cout << "2. Move closer" << endl;
	cout << "3. Wait" << endl;
	cout << "4. Run" << endl;
	gameInputHandler();
	thanksForPlaying();
}

void exit() {
	system("cls");
	cout << "Game closing..." << endl;
	Sleep(3000);
	exitGame = true;
}

void mainMenu() {
	// Start screen:
	cout << "Main Menu" << endl;
	cout << endl;
	cout << "1. Play" << endl;
	cout << "2. Exit" << endl;
	cout << endl;
	mainMenuInputHandler();
}

void mainMenuInputHandler() {
//	short counter = 0;
	bool continueLoop = true;

	cout << "Please enter a number:" << endl;
	while (continueLoop != false) {
		string input = "";
		startCheckups: cin >> input;
//		// Checkup for unnecessary loops:
//		if (counter >= 1) {
//			continueLoop = false;
//			exitGame = true;
//			goto escapeThis;
//		}
		// Checkup for empty strings:
		if (input.empty() == true) {
			cout << "Empty! Enter something." << endl;
//			counter++;
			goto startCheckups;
		}
		// Checkup for words:
		/*
		 *	Bug: Detects negative numbers as words!
		 */
		if (input.size() > 1) {
//			cout << "No words allowed!" << endl;
			cout << "No words and negative numbers allowed!" << endl;
			goto startCheckups;
		}
		// Checkup for big letters:
		for (char letter = 'A'; letter >= 'A' && letter <= 'Z'; letter++) {
			if (input.find_first_of(letter) != string::npos) {
				cout << "No letters allowed!" << endl;
				goto startCheckups;
			}
		}
		// Checkup for little letters:
		for (char letter = 'a'; letter >= 'a' && letter <= 'z'; letter++) {
			if (input.find_first_of(letter) != string::npos) {
				cout << "No letters allowed!" << endl;
				goto startCheckups;
			}
		}
		// String handling:
		/*
		 * Checkups above should already sort everything else, which is not a number, out.
		 */
		if (input.find('1') == 0) {
			continueLoop = false;
			play();
		} else if (input.find('2') == 0) {
			continueLoop = false;
			exit();
		} else {
			cout << "Invalid number!" << endl;
			goto startCheckups;
		}
//		//Checkup for negative numbers:
//		if (convertedInput < 1) {
//			cout << "No negative number allowed!" << endl;
////			while (convertedInput < 1) {
////				cin >> input;
////			}
//			goto startCheckups;
//		}
//		switch (convertedInput) {
//		case 1:
//			if (convertedInput == 1) {
//				continueLoop = false;
//				play();
//			}
//			break;
//		case 2:
//			if (convertedInput == 2) {
//				continueLoop = false;
//				exit();
//			}
//			break;
//		default:
//			break;
//		}

	}
}

void thanksForPlaying() {
	system("cls");
	cout << "T";
	Sleep(250);
	cout << "h";
	Sleep(250);
	cout << "a";
	Sleep(250);
	cout << "n";
	Sleep(250);
	cout << "k ";
	Sleep(250);
	cout << "Y";
	Sleep(250);
	cout << "o";
	Sleep(250);
	cout << "u ";
	Sleep(250);
	cout << "f";
	Sleep(250);
	cout << "o";
	Sleep(250);
	cout << "r ";
	Sleep(250);
	cout << "P";
	Sleep(250);
	cout << "l";
	Sleep(250);
	cout << "a";
	Sleep(250);
	cout << "y";
	Sleep(250);
	cout << "i";
	Sleep(250);
	cout << "n";
	Sleep(250);
	cout << "g";
	Sleep(250);
	cout << "!" << endl;
	Sleep(3000);
	system("cls");
	exit();
}

void gameInputHandler() {
	bool continueLoop = true;

	cout << "Please enter a number:" << endl;
	while (continueLoop != false) {
		string input = "";
		startCheckups2: cin >> input;

		// Checkup for empty strings:
		if (input.empty() == true) {
			cout << "Empty! Enter something." << endl;
//			counter++;
			goto startCheckups2;
		}
		// Checkup for words:
		/*
		 *	Bug: Detects negative numbers as words!
		 */
		if (input.size() > 1) {
//			cout << "No words allowed!" << endl;
			cout << "No words and negative numbers allowed!" << endl;
			goto startCheckups2;
		}
		// Checkup for big letters:
		for (char letter = 'A'; letter >= 'A' && letter <= 'Z'; letter++) {
			if (input.find_first_of(letter) != string::npos) {
				cout << "No letters allowed!" << endl;
				goto startCheckups2;
			}
		}
		// Checkup for little letters:
		for (char letter = 'a'; letter >= 'a' && letter <= 'z'; letter++) {
			if (input.find_first_of(letter) != string::npos) {
				cout << "No letters allowed!" << endl;
				goto startCheckups2;
			}
		}
		// String handling:
		/*
		 * Checkups above should already sort everything else, which is not a number, out.
		 */
		if (input.find('1') == 0) {
			continueLoop = false;
			cout << endl;
			cout
					<< "You are screaming for help and attracting everything in the cave towards your position."
					<< endl;
			Sleep(14000);
			system("cls");
			cout << "You died of being eaten alive..." << endl;
			Sleep(5000);
			system("cls");
			cout << "Game Over" << endl;
			Sleep(5000);
		} else if (input.find('2') == 0) {
			continueLoop = false;
			cout << endl;
			cout
					<< "You are going to the source of the noice you heared earlier."
					<< endl;
			Sleep(12000);
			cout
					<< "As you reaching the position, you being grabbed and immidietly bitten in your throat."
					<< endl;
			Sleep(14000);
			system("cls");
			cout << "You died of bloodloss..." << endl;
			Sleep(5000);
			system("cls");
			cout << "Game Over" << endl;
			Sleep(5000);
		} else if (input.find('3') == 0) {
			continueLoop = false;
			cout << endl;
			cout << "You are waiting..." << endl;
			Sleep(3000);
			cout << "And waiting..." << endl;
			Sleep(3000);
			cout << "And waiting..." << endl;
			Sleep(3000);
			cout << "And waiting..." << endl;
			Sleep(3000);
			cout << "..." << endl;
			cout << endl;
			Sleep(5000);
			system("cls");
			cout << "You died of hunger and thirst..." << endl;
			Sleep(5000);
			system("cls");
			cout << "Game Over" << endl;
			Sleep(5000);
		} else if (input.find('4') == 0) {
			continueLoop = false;
			cout << endl;
			cout << "You are running in fear though the darkness. ";
			Sleep(10000);
			cout << "Enduring your pain. " << endl;
			Sleep(3000);
			cout << "You hearing something chasing and growling behind you. ";
			Sleep(10000);
			cout
					<< "You keep running and groping through the invisible labyrinth of stone and dirt. ";
			Sleep(15000);
			cout << "Knowing, that you will die, if you cannot find an exit. ";
			Sleep(15000);
			cout
					<< "Luckily, you found a light, which got bigger and bigger as you moved closer to it. "
					<< endl;
			Sleep(16000);
			cout << endl;
			cout
					<< "Gasping for fresh air, you were lying and coughing in the soft grass. "
					<< endl;
			Sleep(16000);
			cout
					<< "You looked around, but cannot saw the creature, which were chasing you in the cave before. ";
			Sleep(17000);
			cout
					<< "After a few minutes you stood up and grabbed a bit of dry wood, you could find around your position. "
					<< endl;
			Sleep(20000);
			system("cls");
			cout
					<< "You escaped the cave and made succesfull a fire in your cimney."
					<< endl;
			Sleep(5000);
		} else if (input.find('5') == 0) {
			cout << endl;
			cout
					<< "You are looking around, but can only feel the dead old tree with your hands."
					<< endl;
			cout << endl;
			Sleep(15000);
			cout << "Please enter a number:" << endl;
		} else {
			cout << "Invalid number!" << endl;
			goto startCheckups2;
		}
	}
}
