#include "FileReader.h"
#include "ViewMessages.h"
#include <fstream>

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
