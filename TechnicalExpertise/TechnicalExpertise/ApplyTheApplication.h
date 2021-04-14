#pragma once
#include "Application.h"
class ApplyTheApplication
{
public:
	void setApplication(int ID, string name = "");
	Application applicationData;
	void applicationDataCheck(int ID);
private:
	bool ApplicationConfirmation;
	void applicationsManager(int ID);
};

