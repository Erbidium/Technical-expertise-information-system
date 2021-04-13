#include "WorkWithInterface.h"
#include "ViewMessages.h"
#include "ViewInteraction.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Profile.h"

using namespace std;

void printFileData(string name) {
	ifstream inFile(name);
	if (!inFile) {
		cout << "Can't open a file";
	}
	else {
		while (!inFile.eof()) {
			string temp;
			getline(inFile, temp);
			cout << temp << endl;
		}
	}
	inFile.close();
}

void createReview(string path, string name) {
	string rating=ViewInteraction::inputApplicationRating();
	ofstream outFile(path, ios::app);
	if (!outFile) {
		ViewMessages::cannotOpenFileToWriteSumUp();
	}
	else {
		outFile << "Sum up of application: " << rating << endl;
		outFile.close();
	}
	string newName = "";
	for (int i = 0; i < path.length(); i++) {
		if (static_cast<int>(path[i]) == 92) {
			path[i] = '/';
		}
	}
	newName = path;
	newName.insert(path.rfind('/') + 1, "[checked]");
	rename(path.data(), newName.data());
	outFile.close();
}

Profile readProfile(int ID)
{
	ifstream fileProfile("Database/Profiles/" + to_string(ID) + ".txt");
	string name, email;
	int type;
	fileProfile >> name >> email >> type;
	Profile currentProfile;
	currentProfile.setEmail(email);
	currentProfile.setName(name);
	currentProfile.setType(type);
	currentProfile.setID(ID);
	return currentProfile;
}