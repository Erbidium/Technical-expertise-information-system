#include "ApplyTheApplication.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include "Validation.h"
#include "FileWriter.h"

using namespace std;

void ApplyTheApplication::applicationsManager(int ID) {
	FileWriter::writeApplication(ID, applicationData);
	FileWriter::writeAddedFileToApplication(ID, applicationData);
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
		ViewInteraction::clearScreen();
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
