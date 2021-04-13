#pragma once
#include "Application.h"
#include "Request.h"

class FileWriter
{
public:
	static void writeRequestToFile(Request requestData);
	static void writeApplication(int ID, Application applicationData);
	static void writeAddedFileToApplication(int ID, Application applicationData);
};

