#include <filesystem>
#include <vector>
#include "FundOwner.h"
#include "FileReader.h"
#include "GrantManagement.h"
#include "ViewInteraction.h"

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
			FileReader::readAndPrintFileData(applicationNames[1][numberOfApplication]);
			string path=applicationNames[1][numberOfApplication];
			string name=applicationNames[0][numberOfApplication];
			bool conclusion = ViewInteraction::createConclusionOwner();
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
		}
	}while(numberOfApplication!=-1);
}