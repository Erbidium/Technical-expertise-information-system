#include "ApplyTheRegistration.h"
#include "AccountManagement.h"
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
	if(profileData.getType()==0)
	{
		string filerep = "Database/Applications/"+to_string(profileData.getID());
		if ((stat(filerep.data(), &buf))!= 0)
		{
			_mkdir(filerep.data());
		}
	}
	outProfile.close();
	Accounts.close();
}

void ApplyTheRegistration::profileDataCheck()
{
	bool correct = true;
	string name = profileData.getName();
	if (name.empty())
	{
		cout << endl << "Your name is epmty." << endl;
		correct = false;
	}
	for (int i = 0; i < name.length(); i++)
	{
		if (!((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122)))
		{
			cout << endl << "Your name has been writen wrong or at different language." << endl;
			correct = false;
			i = name.length();
		}
	}
	string email = profileData.getEmail();
	int count = 0;
	for (int i = 0; i < email.length(); i++)
	{
		if (email[i] == '@')
		{
			count++;
		}
	}
	if (count != 1)
	{
		cout << endl << "Your email either have too many or no @ symbol at all." << endl;
		correct = false;
	}
	int count2 = 0;
	count = 0;
	string password = profileData.getPassword();
	cout <<endl <<"length" << password.length();
	if (password.length() < 6)
	{
		cout << endl << "Your password is too short! It must have at least 6 symbols." << endl;
		correct = false;
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (!((password[i] >= 32 && password[i] <= 126)))
		{
			cout << endl << "Your password has been writen at different language." << endl;
			correct = false;
			i = name.length();
		}
		if (password[i] >= 48 && password[i] <= 57)
		{
			count++;
		}
		if ((name[i] >= 65 && password[i] <= 90) || (password[i] >= 97 && password[i] <= 122))
		{
			count2++;
		}
	}
	if (count < 1)
	{
		cout << endl << "Your password need to have at least one numeral." << endl;
		correct = false;
	}
	if (count2 < 1)
	{
		cout << endl << "Your password need to have at least one letter." << endl;
		correct = false;
	}
	if (correct)
	{
		cout << endl << "Yout registration is correct!" << endl;
		profileManager();
	}
	else
	{
		cout << endl << "Would you like to rewrite your registration(0) or leave(1)?" << endl;
		bool leave;
		cin >> leave;
		if (!leave)
		{
			AccountManagement::registerProfile(0);
		}
	}
}

void ApplyTheRegistration::setProfile(Profile currentProfile)
{
	this->profileData=currentProfile;
}
