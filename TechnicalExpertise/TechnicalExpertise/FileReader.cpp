#include "FileReader.h"
#include "ViewMessages.h"
#include "Profile.h"
#include <fstream>
#include <iostream>

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
	ifstream inFile(pathToProfileBalance);
	float money;
	inFile >> money;
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

bool FileReader::readCheckID(int ID)
{
	bool correct = true;
	ifstream inFile("Database/Accounts.txt");
	if (!inFile) {
		cout << endl << "Error! Can't open a file with accounts. Please try again." << endl;
		correct = false;
	}
	else {
		while (!inFile.eof())
		{
			int tempID;
			string buffer;
			inFile >> buffer;
			inFile >> buffer;
			inFile >> tempID;
			if (tempID == ID)
			{
				correct = false;
			}
		}
	}
	inFile.close();
	return correct;
}

bool FileReader::readCheckLogin(string login)
{
	bool correct = true;
	if (login.length() < 3)
	{
		cout << endl << "Your login is too short! It must have at least 4 symbols." << endl;
		correct = false;
	}
	ifstream inFile("Database/Accounts.txt");
	if (!inFile) {
		cout << endl << "Error! Can't open a file with accounts. Please try again." << endl;
		correct = false;
	}
	else {
		while (!inFile.eof())
		{
			string tempLogin;
			string buffer;
			inFile >> buffer;
			inFile >> tempLogin;
			inFile >> buffer;
			if (tempLogin == login) 
			{
				cout << endl << "Your login is already taken" << endl;
				correct = false;
			}
		}
	}
	inFile.close();
	return correct;
}
