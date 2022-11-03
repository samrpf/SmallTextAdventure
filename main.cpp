#include <iostream>

#if defined(_WIN32)
	// Note: Windows is weird
	#define SLEEP_COMMAND "timeout /t 1 /nobreak > NUL"
#else
	#define SLEEP_COMMAND "sleep 1"
#endif

using std::cout;
using std::cin;

int main() {
	char opt;
	int passcode;
	bool keyFoundChest = false;
	bool keyFoundDoor = false;
	bool chestFound = false;
	bool doorFound = false;
  	cout << "SmallTextAdventure\n";
	cout << "a small text adventure\n";
	cout << "You are stuck in a room. You need to escape.\n";
	while(true) {
		system(SLEEP_COMMAND);
		cout << "Which way will you look? North, east, south, west (n, e, s, w)\n";
		cin >> opt;
		if (opt == 'n') {
			// north
			if (keyFoundDoor) {
				// Key found, door can be opened
				cout << "You slide in the door key... \n";
				cout << "And it works!\n";
				cout << "You step out the door, leaving behind the room that you were stuck in.\n";
				return 0;
			} else {
				// Key not found yet, door can not be unlocked
				cout << "You see a door. It is locked.\n";
				cout << "However, it looks like it can be unlocked with a key.\n";
				doorFound = true; // Door found, chest key can now be found	
			}
		} else if (opt == 'e') {
			// east
			if (doorFound) {
				// Door found, chest key enabled
				cout << "You find a key.\n";
				cout << "It looks like a chest key... \n";
				keyFoundChest = true;
			} else {
				// Door not found, chest key not enabled
				cout << "You find a key.\n";
				cout << "You have no idea what it is for.\n";
				cout << "So you leave it there.\n";
			}
		} else if (opt == 's') {
			// south
			cout << "You find a small note.\n";
			cout << "It says the numbers 3762 on it.\n";
		} else if (opt == 'w') {
			// west
			if (keyFoundChest) {
				// Chest key found, chest (almost) unlocked
				cout << "You find a chest.\n";
				cout << "You slide in the chest key... \n";
				cout << "It works!\n";
				cout << "It seems to require a passcode.\n"; // For half a year of this being up, it was spelt "passode." I didn't notice until I started making the Java edition
				cout << "Type the passcode: \n";
				cin >> passcode;
				if (passcode == 3762) {
					// Correct passcode
					cout << "You did it!\n";
					cout << "You got a door key.\n";
					keyFoundDoor = true;
				} else {
					// Wrong passcode
					cout << "Wrong passcode!\n";
					cout << "Maybe you need to find it somewhere.\n";
				}
			} else {
				// Chest key not found, chest can't be unlocked
				cout << "You find a chest.\n";
				cout << "It seems to require a key.\n";
				chestFound = true;
			}
		} else {
			// error
			cout << "Uh oh! '" << opt << "' is not a valid option.\n";
			cout << "Try again.\n";
		}
	}
}
