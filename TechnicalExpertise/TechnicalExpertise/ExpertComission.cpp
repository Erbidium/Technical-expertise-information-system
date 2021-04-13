#include "ExpertComission.h"
#include "ViewInteraction.h"
#include <filesystem>
#include <iostream>
#include <vector>

#include "WorkWithInterface.h"

using namespace std;

ExpertComission::ExpertComission(Profile currentProfile)
{
	profileID=currentProfile.getID();
	name=currentProfile.getName();
	email=currentProfile.getEmail();
	password=currentProfile.getPassword();
	login=currentProfile.getLogin();
	typefUser=currentProfile.getType();
	Balance=currentProfile.getBalance();
}

void ExpertComission::viewApplicationAndEvaluate()
{
	int numberOfApplication=-1;
	do
	{
		vector <vector<string>> applicationNames(2);
		ViewInteraction::viewApplicationsAndPickComission(applicationNames, numberOfApplication);
		if(numberOfApplication!=-1)
		{
			printFileData(applicationNames[1][numberOfApplication]);
			createReview(applicationNames[1][numberOfApplication], applicationNames[0][numberOfApplication]);
		}
	}
	while(numberOfApplication!=-1);
}
