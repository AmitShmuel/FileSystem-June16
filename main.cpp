/***  
 *  Object Oriented Analysis and Design Course 
 *  HW 4 - File System Project
 *  Design Patterns used: Singleton, Prototype, Composite & Builder
 *
 *  author - Amit Shmuel 305213621
 */

#include <iostream>
#include <string>
#include "FileSystem.h"
using namespace std;

// some user interface tools
string input;
int choice, possibilities[]{ 1,2,3,4,5,6,7 };
void pause();
void userMenu();
void goodByeMsg();
bool isNumber(const string& s);
string getChoice(int* possibilities);


int main()
{
	FileSystem *fs = FileSystem::getInstance();

	do {
		userMenu();
		choice = atoi( getChoice( possibilities ).c_str() ); // return user choice as an int
		switch (choice) 
		{
		case 1: // exit
			goodByeMsg();
			break;
		case 2: // create a file
			fs->create(file);
			cout << endl << fs->print(); pause();
			break;
		case 3: // create a folder
			fs->create(folder);
			cout << endl << fs->print(); pause();
			break;
		case 4: // copy file/folder
			fs->copyOrRemove(&Folder::copy); 
			cout << endl << fs->print(); pause();
			break;
		case 5: // remove file/folder
			fs->copyOrRemove(&Folder::remove); 
			cout << endl << fs->print(); pause();
			break;
		case 6: // show content of the file system
			cout << endl << fs->print(); pause();
			break;
		case 7: // print file system content to txt/html file
			fs->toFile(); pause();
			break;
		}

		system("cls||clear");
	} while (choice != 1);

	getchar();
	return 0;
}


// user interface functions impl

void userMenu() {

	cout << "  ______ _ _         _____           _                 \n"
		 << " |  ____(_) |       / ____|         | |                \n"
		 << " | |__   _| | ___  | (___  _   _ ___| |_ ___ _ __ ___  \n"
		 << " |  __| | | |/ _ \\  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n"
		 << " | |    | | |  __/  ____) | |_| \\__ \\ ||  __/ | | | | |\n"
		 << " |_|    |_|_|\\___| |_____/ \\__, |___/\\__\\___|_| |_| |_|\n"
		 << "                            __/ |                      \n"
		 << "                           |___/                       \n"
		 << "\nWhat would you like to do?\n"
		 << "[1] Exit\n"
		 << "[2] Create a file\n"
		 << "[3] Create a folder\n"
		 << "[4] Copy file\n"
		 << "[5] Remove file\n"
		 << "[6] View content of the file system\n"
		 << "[7] export file system to an external file\n\n";
}

string getChoice(int* possibilities) { 

	while(1)
	{
		cin >> input; // getting input from user
		if (isNumber(input))
		{
			for (int* temp = possibilities; *temp != NULL; temp++) // looop until end of possibilities
				if (atoi(input.c_str()) == *temp) // match, input is valid
					return input;
		}
		cerr << "invalid option, please try again ";
	}
}

bool isNumber(const string& s) {

	for (string::const_iterator it = s.begin(); it != s.end(); ++it)
		if (!isdigit(*it))
			return false;
	return true;
}

void goodByeMsg() {

	cout << "Good Bye..\n";
	cin.ignore(10000, '\n');
	getchar();
}

void pause() {

	cout << "\npress ENTER to continue ";
	cin.ignore(10000, '\n');
	getchar();
}