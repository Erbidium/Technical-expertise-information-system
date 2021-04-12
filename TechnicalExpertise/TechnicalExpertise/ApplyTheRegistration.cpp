#include "ApplyTheRegistration.h"
#include "AccountManagement.h"
#include "Validation.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs=std::filesystem;

void ApplyTheRegistration::profileManager()
{
	ofstream Accounts("Database/Accounts.txt", ios::app);
	ofstream outProfile("Database/Profiles/"+std::to_string(profileData.getID())+".txt");
	ofstream outProfileBalance("Database/ProfilesBalance/" + to_string(profileData.getID()) + ".txt");
	Accounts<<profileData.getPassword()<<" "<<profileData.getLogin()<<" "<<profileData.getID()<<"\n";
	outProfile << profileData.getName() << " " << profileData.getEmail() << " " << profileData.getType() << "\n";
	outProfileBalance << profileData.getBalance() << "\n";
	if(profileData.getType()==0)
	{
		string path = "Database/Applications/"+to_string(profileData.getID());
		if (fs::exists(path)==false)
		{
			fs::create_directory(path);
		}
	}
	outProfile.close();
	Accounts.close();
	outProfileBalance.close();
}

void ApplyTheRegistration::profileDataCheck()
{
	bool correct = true;
	if (!Validation::NameCheck(profileData.getName(), "name"))
	{
		correct = false;
	}
	if (!Validation::EmailCheck(profileData.getEmail()))
	{
		correct = false;
	}
	if (!Validation::PasswordCheck(profileData.getPassword()))
	{
		correct = false;
	}
	if (!Validation::LoginCheck(profileData.getLogin()))
	{
		correct = false;
	}
	if (correct)
	{
		system("cls");
		ViewMessages::registrationIsCorrect();
		profileManager();
	}
	else
	{
		bool leave = ViewInteraction::checkIfYouWannaRewrite("registration");
		if (!leave)
		{
			AccountManagement::registerProfile(0);
		}
		else
		{
			system("cls");
		}
	}
}

void ApplyTheRegistration::setProfile(Profile currentProfile)
{
	this->profileData=currentProfile;
}
