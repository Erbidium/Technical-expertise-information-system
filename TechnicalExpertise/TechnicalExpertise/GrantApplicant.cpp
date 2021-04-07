#include "GrantApplicant.h"
#include "ApplyTheApplication.h"
#include <vector>
#include <filesystem>
#include <fstream>
#include <iostream>

#include "GrantManagement.h"

using namespace std;

GrantApplicant::GrantApplicant(Profile currentProfile)
{
	profileID=currentProfile.getID();
	name=currentProfile.getName();
	email=currentProfile.getEmail();
	password=currentProfile.getPassword();
	login=currentProfile.getLogin();
	typefUser=currentProfile.getType();
	Balance=currentProfile.getBalance();
}

void GrantApplicant::createApplication()
{
	ApplyTheApplication tempApplication;
	tempApplication.setApplication(profileID);
}

void GrantApplicant::checkStatusOfApplication()
{
	int counter=0;
	vector <vector<string>> applicationNames(2);
	for (const auto & entry : filesystem::directory_iterator("Database/Applications/"+to_string(profileID)))
	{
		if(entry.path().extension()==".txt")
		{
			applicationNames[0].push_back(entry.path().filename().string());
			applicationNames[1].push_back(entry.path().string());
			cout<<applicationNames[0].back()<<"("<<counter<<")"<<endl;
			counter++;
		}
	}
	cout<<"Press any key to quit"<<endl;
	string key;
	cin>>key;
}

void GrantApplicant::deleteApplication()
{
	int numberOfApplication=-1;
	do{
		int counter=0;
		vector <vector<string>> applicationNames(2);
		for (const auto & entry : filesystem::directory_iterator("Database/Applications/"+to_string(profileID)))
		{
			if(entry.path().extension()==".txt")
			{
				applicationNames[0].push_back(entry.path().filename().string());
				applicationNames[1].push_back(entry.path().string());
				cout<<applicationNames[0].back()<<"("<<counter<<")"<<endl;
				counter++;
			}
		}
		cout<<"Choose application or enter -1 to quit"<<endl;
		cin>>numberOfApplication;
		if(numberOfApplication!=-1){
			remove(applicationNames[1][numberOfApplication].data());
		}
	}while(numberOfApplication!=-1);
}

void GrantApplicant::editApplication()
{
	int numberOfApplication = -1;
	do {
		int counter = 0;
		vector <vector<string>> applicationNames(2);
		for (const auto& entry : filesystem::directory_iterator("Database/Applications/" + to_string(profileID)))
		{
			if (entry.path().extension() == ".txt")
			{
				applicationNames[0].push_back(entry.path().filename().string());
				applicationNames[1].push_back(entry.path().string());
				cout << applicationNames[0].back() << "(" << counter << ")" << endl;
				counter++;
			}
		}
		cout << "Choose application or enter -1 to quit" << endl;
		cin >> numberOfApplication;
		if (numberOfApplication != -1) {
			ofstream outFile(applicationNames[1][numberOfApplication], ios::trunc);
			ApplyTheApplication tempApplication;
			int position = applicationNames[0][numberOfApplication].find(".txt");
			string copy = applicationNames[0][numberOfApplication];
			copy.erase(position, 4);
			tempApplication.setApplication(profileID, copy);
		}
	} while (numberOfApplication != -1);
}

void GrantApplicant::checkBalance()
{
	cout << endl <<  "Your current balance is: " << fixed << setprecision(2) << GrantManagement::getMoney(profileID) << endl;
	bool bank;
	cout << endl << "Would you like to withdraw money to your bank account? (1 - yes, 0 - no): " << endl;
	cin >> bank;
	if (bank)
	{
		GrantManagement::transferToBank(profileID);
	}
}
