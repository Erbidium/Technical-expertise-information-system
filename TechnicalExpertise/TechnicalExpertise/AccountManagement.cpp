#include "AccountManagement.h"
#include "ApplyTheRegistration.h"
#include "Profile.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include "WorkWithInterface.h"
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
	Profile tempObject = readProfile(ID);
	printFileData("Database/Profiles/" + to_string(ID) + ".txt");
	fs::remove("Database/Profiles/" + to_string(ID) + ".txt");
	ofstream outFile("Database/Profiles/" + to_string(ID) + ".txt");
	string name, email;
	ViewInteraction::inputNameEmail(name,email);
	outFile << name << " " << email << " " << tempObject.getType() << "\n";
}