#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include "Profile.h"
#include "Request.h"


class ViewInteraction {
public:
	static Profile createProfi(int profileID, int type);
	static void inputNameEmail(std::string& name, std::string& email);
	static int inputAccTypeForRegistration();
	static string inputApplicationRating();
	static bool checkIfYouWannaRewrite(string word);
	static void createApplication(int& tempAge, string& tempData, string& name, string& filePath, string& link);
	static Request createRequest();
	static int viewApplicationsAndPickComission(vector <vector<string>>& applicationNames, int& numberOfApplication);
	static int viewApplicationsAndPickOwner(vector <vector<string>>& applicationNames, int& numberOfApplication);
	static void showRequests();
	static bool createConclusionOwner();
	static void applicationStatusOut(int counter, vector <vector<string>>& applicationNames, int profileID);
	static void outApplicationAndDelete(int& numberOfApplication, vector <vector<string>>& applicationNames, int profileID);
	static void outBalance(int profileID);
	static void inputAmountOfMoney(string& money);
	static void inputCardNumber(string& card);
	static void clearScreen();
	static void logIn(string& login, string& password);
	static void startPick(int& choice);
	static void adminPick(int& action);
	static void grantApplicantPick(int& action);
	static void confirmation(string& confirmation);
	static void comissionPick(int& action);
	static void founderPick(int& action);
};