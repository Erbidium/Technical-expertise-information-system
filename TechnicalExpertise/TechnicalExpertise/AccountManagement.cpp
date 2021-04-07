#include "AccountManagement.h"
#include "ApplyTheRegistration.h"
#include "Profile.h"
#include "WorkWithInterface.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

int AccountManagement::enterToProfile(string login, string password)
{
	int ID = -1;
	ifstream inFile("Database/Accounts.txt");
	if (!inFile) {
		cout << "Can't open a file :-(";
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
	cout<<"You are logged out!"<<endl;
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
		cout<<"Your profile is deleted!"<<endl;
	}
	
}

void AccountManagement::registerProfile(int type)
{
	int profileID=rand()%90000+10000;
	ApplyTheRegistration registrationController;
	string login, password, name, email;
	cout<<"Enter your login:\n";
	cin>>login;
	cout<<"Enter your password:\n";
	cin>>password;
	cout<<"Enter your name:\n";
	cin>>name;
	cout<<"Enter your email:\n";
	cin>>email;
	Profile newProfile(name, email, login, password, profileID, type, 0);
	registrationController.setProfile(newProfile);
	registrationController.profileDataCheck();
}

void AccountManagement::editProfile(int ID) {
	Profile tempObject = readProfile(ID);
	printFileData("Database/Profiles/" + to_string(ID) + ".txt");
	fs::remove("Database/Profiles/" + to_string(ID) + ".txt");
	ofstream outFile("Database/Profiles/" + to_string(ID) + ".txt");
	string login, password, name, email;
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your email:\n";
	cin >> email;
	outFile << name << " " << email << " " << tempObject.getType() << "\n";
}