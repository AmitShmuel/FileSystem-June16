#include "FileSystem.h"


FileSystem* FileSystem::fs = 0;

FileSystem::FileSystem() {

	root = new Folder("ROOT");
}

FileSystem* FileSystem::getInstance() {

	if (fs == NULL)
		fs = new FileSystem();

	return fs;
}

FileSystem::~FileSystem() {

	if (root)
		delete root;
}


void FileSystem::create(kind k) {

	string fileName, dst = "0", choice;
	cout << "Enter file name : "; cin >> fileName;
	cout << "would you like to save it under a specific folder?\n[1] Yes\n[2] No    ";
	while (1)
	{
		cin >> choice;
		if (choice == "1" || choice == "2")
		{
			if (choice == "1")
			{
				cout << root->toString();
				cout << "Enter folder id : "; 
				cin >> dst;
			}
			break;
		}
		cerr << "invalid option, please try again ";
	}

	if(k == folder)
		root->addFile(new Folder(fileName), atoi(dst.c_str()));
	else {
		root->addFile(new File(fileName), atoi(dst.c_str()));
	}
}


void FileSystem::copyOrRemove(pfunc func) { // func is either copy or remove, decided in main

	cout << root->toString();
	string fileId;
	cout << "Enter file id : "; cin >> fileId;
	(root->*func) (atoi(fileId.c_str()));
}

void FileSystem::toFile() {

	cout << "Export file system to :\n[1] TXT file\n[2] HTML file    ";
	string choice;
	while (1)
	{
		cin >> choice;
		if (choice == "1" || choice == "2")
		{
			if (choice == "1")
			{
				selector.process(FileSelector::TEXT, print());
				break;
			}
			else {
				selector.process(FileSelector::HTML, print());
				break;
			}		
		}
		cerr << "invalid option, please try again ";
	}
}