#include "Validation.h"
#include "ApplyTheRequest.h"
#include "FileWriter.h"
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
	FileWriter::writeRequestToFile(requestData);
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
		ViewInteraction::clearScreen();
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
			ViewInteraction::clearScreen();
		}
	}
}
