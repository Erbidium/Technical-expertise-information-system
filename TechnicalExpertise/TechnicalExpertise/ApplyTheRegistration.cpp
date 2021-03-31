#include "ApplyTheRegistration.h"
#include <iostream>
#include <fstream>
#include <sys\stat.h>
#include <direct.h>
using namespace std;

void ApplyTheRegistration::profileManager()
{
	ofstream Accounts("Database/Accounts.txt", ios::app);
	ofstream outProfile("Database/Profiles/"+std::to_string(profileData.getID())+".txt");
	Accounts<<profileData.getPassword()<<" "<<profileData.getLogin()<<" "<<profileData.getID()<<"\n";
	outProfile<<profileData.getName()<<" "<<profileData.getEmail()<<" "<<profileData.getType()<<"\n";
	struct stat buf;
	string filerep = "Database/Applications/"+to_string(profileData.getID());
	if ((stat(filerep.data(), &buf))!= 0)
	{
		_mkdir(filerep.data());
		
	}
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
