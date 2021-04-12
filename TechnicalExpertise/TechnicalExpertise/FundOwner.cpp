#include "FundOwner.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>
#include "GrantManagement.h"
#include "WorkWithInterface.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"

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
		ViewInteraction::viewApplicationsAndPickOwner(applicationNames, numberOfApplication);
		if(numberOfApplication!=-1){
			printFileData(applicationNames[1][numberOfApplication]);
			createOwnersReview(applicationNames[1][numberOfApplication], applicationNames[0][numberOfApplication]);
		}
	}while(numberOfApplication!=-1);
}



void createOwnersReview(string path, string name) {
	bool conclusion = ViewInteraction::createConclusionOwner();
	string s;
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	ifstream outFile;
	if (!outFile) {
		ViewMessages::cannotOpenFileToWriteConclusion();
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