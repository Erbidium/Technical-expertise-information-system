#include "GrantApplicant.h"
#include "ApplyTheApplication.h"
#include <vector>
#include <string>
#include <filesystem>
#include "FileWriter.h"
#include "FileReader.h"
#include "ViewInteraction.h"
#include <vector>
#include <filesystem>

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
	ViewInteraction::applicationStatusOut(counter, applicationNames, profileID);
	ViewInteraction::clearScreen();
}

void GrantApplicant::deleteApplication()
{
	int numberOfApplication=-1;
	do{
		vector <vector<string>> applicationNames(2);
		ViewInteraction::outApplicationAndDelete(numberOfApplication, applicationNames, profileID);
		if(numberOfApplication!=-1){
			remove(applicationNames[1][numberOfApplication].data());
		}
	}while(numberOfApplication!=-1);
	ViewInteraction::clearScreen();
}

void GrantApplicant::editApplication()
{
	int numberOfApplication = -1;
	do {
		vector <vector<string>> applicationNames(2);
		ViewInteraction::outApplicationAndDelete(numberOfApplication, applicationNames, profileID);
		if (numberOfApplication != -1) {
			ApplyTheApplication tempApplication;
			int position = applicationNames[0][numberOfApplication].find(".txt");
			string copy = applicationNames[0][numberOfApplication];
			copy.erase(position, 4);
			tempApplication.applicationData = FileReader::readApplication(profileID, copy);
			FileWriter::clearFileData(applicationNames[1][numberOfApplication]);
			filesystem::remove(applicationNames[1][numberOfApplication]);
			int tempAge = tempApplication.applicationData.getAge();
			string tempData = tempApplication.applicationData.getContent();
			string name = tempApplication.applicationData.getName();
			string filePath = tempApplication.applicationData.getFilePath();
			string link = tempApplication.applicationData.getLink();
			ViewInteraction::editApplication(tempAge, tempData, name, filePath, link);
			tempApplication.applicationData.setAge(tempAge);
			tempApplication.applicationData.setName(name);
			tempApplication.applicationData.setContent(tempData);
			tempApplication.applicationData.setFilePath(filePath);
			tempApplication.applicationData.setLink(link);
			FileWriter::writeApplication(profileID, tempApplication.applicationData);
			FileWriter::writeAddedFileToApplication(profileID, tempApplication.applicationData);
		}
	} while (numberOfApplication != -1);
	ViewInteraction::clearScreen();
}

void GrantApplicant::checkBalance()
{
	ViewInteraction::outBalance(profileID);
}
