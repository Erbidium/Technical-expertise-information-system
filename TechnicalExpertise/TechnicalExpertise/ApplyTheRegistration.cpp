#include "ApplyTheRegistration.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void ApplyTheRegistration::profileManager()
{
	ofstream Accounts("Database/Accounts.txt", ios::app);
	ofstream outProfile("Database/Profiles/"+std::to_string(profileData.getID())+".txt");
	Accounts<<profileData.getPassword()<<" "<<profileData.getLogin()<<" "<<profileData.getID()<<"\n";
	outProfile<<profileData.getName()<<" "<<profileData.getEmail()<<" "<<profileData.getType()<<"\n";
	fs::create_directory("Database/Applications/"+to_string(profileData.getID()));
	outProfile.close();
	Accounts.close();
}

void ApplyTheRegistration::profileDataCheck()
{
	cout<<"Your data is correct!"<<endl;
	profileManager();
}

void ApplyTheRegistration::setProfile(Profile currentProfile)
{
	this->profileData=currentProfile;
}
