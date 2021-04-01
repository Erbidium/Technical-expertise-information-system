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
	int profileID=rand()%90000+10000;//������ ��������, �� ���� ������ � ���� id
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
