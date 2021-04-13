#include "ExpertComission.h"
#include "ViewInteraction.h"
#include <filesystem>
#include <vector>
#include "FileReader.h"
#include "FileWriter.h"

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
			FileReader::readAndPrintFileData(applicationNames[1][numberOfApplication]);
			FileWriter::createReview(applicationNames[1][numberOfApplication], applicationNames[0][numberOfApplication]);
		}
	}
	while(numberOfApplication!=-1);
}
