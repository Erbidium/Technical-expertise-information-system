#include "ApplyTheApplication.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include "Validation.h"
#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void ApplyTheApplication::applicationsManager(int ID) {
	int tempAge = applicationData.getAge();
	string tempData = applicationData.getContent();
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	string tempDate = to_string(newtime.tm_mday) + '.' + to_string(newtime.tm_mon + 1) + '.' + to_string(newtime.tm_year + 1900);
	string tempName = applicationData.getName();
	ofstream outFile("Database/Applications/" + to_string(ID) + "/" + tempName + ".txt");
	outFile << "Name of application: " << tempName << endl;
	outFile << "My age: " << tempAge << endl;
	outFile << "Application's data: " << applicationData.getContent() << endl;
	outFile << "Date: " << tempDate << endl;
	if (applicationData.getFilePath().length()>0) {
		ifstream inFile(applicationData.getFilePath());
		if (!inFile) {
			ViewMessages::cannotOpenFileToAddToApplication();
		}
		else {
			outFile << endl << "Added file content: " << endl;
			string s;
			while (!inFile.eof()) {
				getline(inFile, s);
				outFile << s << endl;
			}
		}
		inFile.close();
	}
	outFile.close();
}
void ApplyTheApplication::applicationDataCheck(int ID) {
	bool correct = true;
	if (!Validation::NameCheck(applicationData.getName(), "application`s name"))
	{
		correct = false;
	}
	if (!Validation::DataEmptyCheck(applicationData.getContent(), "application"))
	{
		correct = false;
	}
	if (correct)
	{
		ViewMessages::applicationIsCorrect();
		applicationsManager(ID);
	}
	else
	{
		bool leave = ViewInteraction::checkIfYouWannaRewrite("application");
		if (!leave)
		{
			setApplication(ID);
		}
	}
}
void ApplyTheApplication::setApplication(int ID,string name) {
	int tempAge;
	string tempData;
	string filePath;
	ViewInteraction::createApplication(tempAge,tempData,name, filePath);
	applicationData.setAge(tempAge);
	applicationData.setContent(tempData);
	applicationData.setName(name);
	applicationData.setFilePath(filePath);
	applicationDataCheck(ID);
}
