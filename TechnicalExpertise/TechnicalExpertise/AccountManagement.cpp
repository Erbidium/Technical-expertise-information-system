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
		FileWriter::editFileLogin(ID, oldPassword, newLogin);
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
		FileWriter::editFilePassword(ID, oldLogin, newPassword);
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
		FileWriter::editFileName(OldPath, NewPath, newName);
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
		FileWriter::editFileEmail(OldPath, NewPath, newEmail);
	}
	else
	{
		ViewMessages::notConfirmed();
	}
}