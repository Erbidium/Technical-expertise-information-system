#pragma once
#include "Application.h"
class ApplyTheApplication
{
public:
	void setApplication(int ID, std::string name = "");
	Application applicationData;
private:
	void applicationDataCheck(int ID);
	bool ApplicationConfirmation;
	void applicationsManager(int ID);
};

