#include "FileReader.h"
#include "ViewMessages.h"
#include <fstream>
#include <iostream>

#include "Profile.h"

using namespace std;

int FileReader::readID(string login, string password)
{
	int ID=-1;
	ifstream inFile("Database/Accounts.txt");
	if (!inFile) {
		ViewMessages::unsuccessfulFileOpening();
	}
	else {
		while (!inFile.eof()) {
			string tempPassword;
			string tempLogin;
			int tempID;
			inFile >> tempPassword;
			inFile >> tempLogin;
			inFile >> tempID;
			if (tempPassword == password && tempLogin == login) {
				ID = tempID;
			}
		}
	}
	inFile.close();
	return ID;
}

float FileReader::readMoney(int ID)
{
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID) + ".txt";
	ifstream infile(pathToProfileBalance);
	float money;
	infile >> money;
	return money;
}

void FileReader::readLoginAndPassword(int ID, string& login, string& password)
{
	ifstream inFile("Database/Accounts.txt");
	if (!inFile) {
		ViewMessages::unsuccessfulFileOpening();
	}
	else {
		while (!inFile.eof()) {
			string tempPassword;
			string tempLogin;
			int tempID = 0;
			inFile >> tempPassword;
			inFile >> tempLogin;
			inFile >> tempID;
			if (ID == tempID) {
				login = tempLogin;
				password = tempPassword;
			}
		}
	}
	inFile.close();
}

void FileReader::readAndPrintFileData(string name)
{
	//void printFileData(string name)
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

Profile FileReader::readProfile(int ID)
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
