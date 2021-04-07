#include "FundOwner.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>
#include "GrantManagement.h"
#include "WorkWithInterface.h"

void createOwnersReview(string path, string name);

FundOwner::FundOwner(Profile currentProfile)
{
	profileID=currentProfile.getID();
	name=currentProfile.getName();
	email=currentProfile.getEmail();
	password=currentProfile.getPassword();
	login=currentProfile.getLogin();
	typefUser=currentProfile.getType();
	Balance=currentProfile.getBalance();
}

void FundOwner::ViewExaminationResultsAndAcceptGrant()
{
	int numberOfApplication=-1;
	do{
		vector <vector<string>> applicationNames(2);
		int counter=0;
		for (const auto & entry : filesystem::recursive_directory_iterator("Database/Applications"))
		{
			if((entry.path().extension()==".txt")&&(entry.path().filename().string().find("[checked]")!=string::npos)&&
				(entry.path().filename().string().find("[Paid]")==string::npos)&&(entry.path().filename().string().find("[NotPaid]")==string::npos))
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
			printFileData(applicationNames[1][numberOfApplication]);
			createOwnersReview(applicationNames[1][numberOfApplication], applicationNames[0][numberOfApplication]);
		}
	}while(numberOfApplication!=-1);
}



void createOwnersReview(string path, string name) {
	cout << "Input your conclusion (1 - yes, 0 - no): " << endl;
	bool conclusion;
	cin >> conclusion;
	string s;
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	ifstream outFile;
	if (!outFile) {
		cout << endl << "Can not open a file with application to write a conclution" << endl;
	}
	else {
		while (getline(outFile, s))
		{
			cout << s << endl;
		}
	}
	string newName = "";
	for (int i = 0; i < path.length(); i++) {
		if (static_cast<int>(path[i]) == 92) {
			path[i] = '/';
		}
	}
	newName = path;
	int ID = stoi(path.substr(22, 5));
	if (conclusion)
	{
		newName.replace(newName.rfind('['), 9, "[Paid]");
		GrantManagement::transferMoney(ID);
	}
	else
	{
		newName.replace(newName.rfind('['), 9, "[NotPaid]");
	}
	rename(path.data(), newName.data());
	outFile.close();
}