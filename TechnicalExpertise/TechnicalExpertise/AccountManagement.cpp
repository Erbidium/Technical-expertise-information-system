#include "AccountManagement.h"
#include "ApplyTheRegistration.h"
#include "Profile.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include "WorkWithInterface.h"
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int AccountManagement::enterToProfile(string login, string password)
{
	int ID = -1;
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

void AccountManagement::exitFromProfile(int ID)
{
	ViewMessages::successfulLogOut();
}

void AccountManagement::deleteProfile(int ID, int type)
{
	if(type==0)
	{
		fs::remove_all("Database/Applications/"+to_string(ID));
		fs::remove("Database/ProfilesBalance/"+to_string(ID)+".txt");
	}
	fs::remove("Database/Profiles/"+to_string(ID)+".txt");
	ifstream oldAccounts("Database/Accounts.txt");
	ofstream newAccounts("Database/NewAccounts.txt");
	if((oldAccounts.is_open())&&(newAccounts.is_open()))
	{
		while(!oldAccounts.eof())
		{
			string password, login;
			int currentID;
			oldAccounts>>password>>login>>currentID;
			if(currentID!=ID)
			{
				newAccounts<<password<<" "<<login<<" "<<currentID<<endl;
			}
		}
		oldAccounts.close();
		newAccounts.close();
		fs::remove("Database/Accounts.txt");
		rename("Database/NewAccounts.txt", "Database/Accounts.txt");
		ViewMessages::successfulProfileDelete();
	}
	
}

void AccountManagement::registerProfile(int type)
{
	int profileID=rand()%90000+10000;
	ApplyTheRegistration registrationController;
	Profile newProfile = ViewInteraction::createProfi(profileID, type);
	registrationController.setProfile(newProfile);
	registrationController.profileDataCheck();
}

void AccountManagement::editProfile(int ID) {
	Profile tempObject = readProfile(ID);
	printFileData("Database/Profiles/" + to_string(ID) + ".txt");
	fs::remove("Database/Profiles/" + to_string(ID) + ".txt");
	ofstream outFile("Database/Profiles/" + to_string(ID) + ".txt");
	string name, email;
	ViewInteraction::inputNameEmail(name,email);
	outFile << name << " " << email << " " << tempObject.getType() << "\n";
}