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
	static void clearFileData(std::string path);
	static void writeMoney(std::string pathToProfileBalance, std::string money, float sum);
	static void writeDifMoney(std::string pathToProfileBalance, std::string money, float dif);
	static void createReview(std::string path, std::string name);
};

