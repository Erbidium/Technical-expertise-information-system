#include <fstream>
#include "Validation.h";
#include "ApplyTheRequest.h"
#include "View.h"
using namespace std;

void ApplyTheRequest::setRequest()
{
	requestData = View::createRequest();
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
		cout << "Yout request is correct!" << endl;
		requestManager();
	}
	else
	{
		bool leave = View::checkIfYouWannaRewrite("request");
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
