#include "AccountManagement.h"
#include "ApplyTheRegistration.h"
#include "Profile.h"
#include <iostream>

using namespace std;

enum typesOfUsers{};

void AccountManagement::enterToProfile(int ID)
{
	cout<<"Succesfully logined!"<<endl;
}

void AccountManagement::exitFromProfile(int ID)
{
	cout<<"You are logged out!"<<endl;
}

void AccountManagement::deleteProfile(int ID)
{
	cout<<"Your profile is deleted!"<<endl;
}

void AccountManagement::registerProfile(int type)
{
	int profileID=rand()%90000+10000;//додати перевірку, чи існує акаунт з такм id
	ApplyTheRegistration registrationController;
	string login, password, name, email;
	cin.ignore();
	cout<<"Enter your login: ";
	getline(cin, login);
	cout<<"Enter your password: ";
	getline(cin, password);
	cout<<"Enter your name: ";
	getline(cin, name);
	cout<<"Enter your email: ";
	getline(cin, email);
	Profile newProfile(name, email, login, password, profileID, type);
	registrationController.setProfile(newProfile);
	registrationController.profileDataCheck();
}
