#pragma once
#include "Request.h"

class ApplyTheRequest
{
public:
	void setRequest();
private:
	Request requestData;
	void requestManager();
	void requestDataCheck();
};

