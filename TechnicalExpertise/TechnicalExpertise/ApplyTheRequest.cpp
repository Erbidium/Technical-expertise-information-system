#include <fstream>
#include "Validation.h"
#include "ApplyTheRequest.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"

using namespace std;

void ApplyTheRequest::setRequest()
{
	requestData = ViewInteraction::createRequest();
	requestDataCheck();
}

void ApplyTheRequest::requestManager()
{
	ofstream outFile("Database/Requests/" + requestData.getName() + ".txt");
	outFile << "My name: " << requestData.getName() << endl;
	outFile << "My email: " << requestData.getEmail() << endl;
	outFile << "Request Content: " << requestData.getContent() << endl;
	outFile.close();
}

void ApplyTheRequest::requestDataCheck()
{
	bool correct = true;
	if (!Validation::NameCheck(requestData.getName(), "name"))
	{
		correct = false;
	}
	if (!Validation::EmailCheck(requestData.getEmail()))
	{
		correct = false;
	}
	if (!Validation::DataEmptyCheck(requestData.getContent(), "request"))
	{
		correct = false;
	}
	if (correct)
	{
		system("cls");
		ViewMessages::requestIsCorrect();
		requestManager();
	}
	else
	{
		bool leave = ViewInteraction::checkIfYouWannaRewrite("request");
		if(!leave)
		{
			setRequest();
		}
		else
		{
			system("cls");
		}
	}
}
