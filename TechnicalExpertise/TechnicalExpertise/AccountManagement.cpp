#include "AccountManagement.h"
#include "ApplyTheRegistration.h"
#include "Profile.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include <fstream>
#include <filesystem>
#include "FileReader.h"
#include "FileWriter.h"
#include "Validation.h"

using namespace std;
namespace fs = filesystem;

int AccountManagement::enterToProfile(string login, string password)
{
	int ID=FileReader::readID(login, password);
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
	FileWriter::rewriteAccounts(ID);
}

void AccountManagement::registerProfile(int type)
{
	int profileID=rand()%90000+10000;
	while(!Validation::IDCheck(profileID))
	{
		profileID=rand()%90000+10000;
	}
	ApplyTheRegistration registrationController;
	Profile newProfile = ViewInteraction::createProfi(profileID, type);
	registrationController.setProfile(newProfile);
	registrationController.profileDataCheck();
}

void AccountManagement::editProfile(int ID) {
	do
	{
		switch (ViewInteraction::inputEditing())
		{
		case 0:
			editLogin(ID);
			break;
		case 1:
			editPassword(ID);
			break;
		case 2:
			editName(ID);
			break;
		case 3:
			editEmail(ID);
			break;
		}
	} 	while (!ViewInteraction::checkIfYouWannaEdit());
}

bool AccountManagement::confirmation(int ID, string& login, string& password)
{
	bool correct = false;
	string checkLogin;
	string checkPassword;
	ViewInteraction::inputValue("Before editing profile confirm your old login and password\nOld login:", checkLogin);
	ViewInteraction::inputValue("Old password:", checkPassword);
	if (checkLogin == login && checkPassword == password)
	{
		correct = true;
	}
	return correct;
}

void AccountManagement::editLogin(int ID)
{
	string newLogin;
	string oldLogin;
	string oldPassword;
	FileReader::readLoginAndPassword(ID, oldLogin, oldPassword);
	if (confirmation(ID, oldLogin, oldPassword))
	{
		ViewInteraction::inputValue("Verification confirmed!\nEnter your new login:", newLogin);
		ifstream oldAccounts("Database/Accounts.txt");
		ofstream newAccounts("Database/NewAccounts.txt");
		if ((oldAccounts.is_open()) && (newAccounts.is_open()))
		{
			while (!oldAccounts.eof())
			{
				string password, login;
				int currentID;
				oldAccounts >> password >> login >> currentID;
				if (currentID != ID)
				{
					newAccounts << password << " " << login << " " << currentID << endl;
				}
			}
			newAccounts << oldPassword << " " << newLogin << " " << ID << endl;
			oldAccounts.close();
			newAccounts.close();
			fs::remove("Database/Accounts.txt");
			rename("Database/NewAccounts.txt", "Database/Accounts.txt");
			ViewMessages::successfulEdit();
		}
	}
	else
	{
		ViewMessages::notConfirmed();
	}
}

void AccountManagement::editPassword(int ID)
{
	string newPassword;
	string oldLogin;
	string oldPassword;
	FileReader::readLoginAndPassword(ID, oldLogin, oldPassword);
	if (confirmation(ID, oldLogin, oldPassword))
	{
		ViewInteraction::inputValue("Verification confirmed!\nEnter your new password:", newPassword);
		ifstream oldAccounts("Database/Accounts.txt");
		ofstream newAccounts("Database/NewAccounts.txt");
		if ((oldAccounts.is_open()) && (newAccounts.is_open()))
		{
			while (!oldAccounts.eof())
			{
				string password, login;
				int currentID;
				oldAccounts >> password >> login >> currentID;
				if (currentID != ID)
				{
					newAccounts << password << " " << login << " " << currentID << endl;
				}
			}
			newAccounts << newPassword << " " << oldLogin << " " << ID << endl;
			oldAccounts.close();
			newAccounts.close();
			fs::remove("Database/Accounts.txt");
			rename("Database/NewAccounts.txt", "Database/Accounts.txt");
			ViewMessages::successfulEdit();
		}
	}
	else
	{
		ViewMessages::notConfirmed();
	}
}

void AccountManagement::editName(int ID)
{
	string newName;
	string oldLogin;
	string oldPassword;
	string OldPath = "Database/Profiles/" + to_string(ID) + ".txt";
	string NewPath = "Database/Profiles/New" + to_string(ID) + ".txt";
	FileReader::readLoginAndPassword(ID, oldLogin, oldPassword);
	if (confirmation(ID, oldLogin, oldPassword))
	{
		ViewInteraction::inputValue("Verification confirmed!\nEnter your new name:", newName);
		ifstream oldProfile(OldPath);
		ofstream newProfile(NewPath);
		if ((oldProfile.is_open()) && (newProfile.is_open()))
		{
				string name, email;
				int type;
				oldProfile >> name >> email >> type;
				newProfile << newName << " " << email << " " << type << endl;
			oldProfile.close();
			newProfile.close();
			fs::remove(OldPath);
			rename(NewPath.data(), OldPath.data());
			ViewMessages::successfulEdit();
		}
	}
	else
	{
		ViewMessages::notConfirmed();
	}
}

void AccountManagement::editEmail(int ID)
{
	string newEmail;
	string oldLogin;
	string oldPassword;
	string OldPath = "Database/Profiles/" + to_string(ID) + ".txt";
	string NewPath = "Database/Profiles/New" + to_string(ID) + ".txt";
	FileReader::readLoginAndPassword(ID, oldLogin, oldPassword);
	if (confirmation(ID, oldLogin, oldPassword))
	{
		ViewInteraction::inputValue("Verification confirmed!\nEnter your new email:", newEmail);
		ifstream oldProfile(OldPath);
		ofstream newProfile(NewPath);
		if ((oldProfile.is_open()) && (newProfile.is_open()))
		{
			string name, email;
			int type;
			oldProfile >> name >> email >> type;
			newProfile << name << " " << newEmail << " " << type << endl;
			oldProfile.close();
			newProfile.close();
			fs::remove("Database/Profiles/" + to_string(ID) + ".txt");
			rename(NewPath.data(), OldPath.data());
			ViewMessages::successfulEdit();
		}
	}
	else
	{
		ViewMessages::notConfirmed();
	}
}