#pragma once
#include "Application.h"
#include "Profile.h"
#include "Request.h"

class FileWriter
{
public:
	static void writeRequestToFile(Request requestData);
	static void writeApplication(int ID, Application applicationData);
	static void writeAddedFileToApplication(int ID, Application applicationData);
	static void writeEmptyAccounts();
	static void rewriteAccounts(int ID);
	static void writeProfileData(Profile profileData);
	static void writeProfileBalance(Profile profileData);
	static void writeLoginData(Profile profileData);
	static void clearFileData(string path);
	static void writeMoney(string pathToProfileBalance, string money, float sum);
	static void writeDifMoney(string pathToProfileBalance, string money, float dif);
};

