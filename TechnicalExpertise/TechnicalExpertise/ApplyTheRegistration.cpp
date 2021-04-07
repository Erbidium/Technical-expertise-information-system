#include "ApplyTheRegistration.h"
#include "AccountManagement.h"
#include "View.h"
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
	if (password.length() < 6)
	{
		cout << endl << "Your password is too short! It must have at least 6 symbols." << endl;
		correct = false;
	}
	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] >= 48 && password[i] <= 57)
		{
			count++;
		}
		if ((password[i] >= 65 && password[i] <= 90) || (password[i] >= 97 && password[i] <= 122))
		{
			count2++;
		}
		if (!((password[i] >= 32 && password[i] <= 126)))
		{
			cout << endl << "Your password has been writen at different language." << endl;
			correct = false;
			i = password.length();
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
		system("cls");
		cout << "Your registration is correct!" << endl;
		profileManager();
	}
	else
	{
		bool leave = View::checkIfYouWannaRewrite("registration");
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
