#pragma once
#include "Application.h"
class ApplyTheApplication
{
public:
	void setApplication(int ID, std::string name = "");
private:
	Application applicationData;
	bool ApplicationConfirmation;
	void applicationsManager(int ID);
	void applicationDataCheck(int ID);
};

