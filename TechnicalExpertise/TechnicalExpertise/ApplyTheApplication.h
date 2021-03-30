#pragma once
#include "Application.h"
class ApplyTheApplication
{
public:
	Application applicationData;
	bool ApplicationConfirmation;
private:
	void applicationsManager();
	void applicationDtaCheck();
	void setApplication(Application);
};

