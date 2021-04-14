#pragma once
#include <string>
#include <vector>
#include <filesystem>
#include <vector>
#include "Profile.h"
#include "Request.h"

class ViewInteraction {
public:
	static Profile createProfi(int profileID, int type);
	static void inputNameEmail(std::string& name, std::string& email);
	static int inputAccTypeForRegistration();
	static std::string inputApplicationRating();
	static bool checkIfYouWannaRewrite(std::string word);
	static void createApplication(std::string& tempAge, std::string& tempData, std::string& name, std::string& filePath, std::string& link);
	static Request createRequest();
	static int viewApplicationsAndPickComission(std::vector <std::vector<std::string>>& applicationNames, int& numberOfApplication);
	static int viewApplicationsAndPickOwner(std::vector <std::vector<std::string>>& applicationNames, int& numberOfApplication);
	static void showRequests();
	static bool createConclusionOwner();
	static void applicationStatusOut(int counter, std::vector <std::vector<std::string>>& applicationNames, int profileID);
	static void outApplicationAndDelete(int& numberOfApplication, std::vector <std::vector<std::string>>& applicationNames, int profileID);
	static void outBalance(int profileID);
	static void clearScreen();
	static int inputEditing();
	static bool checkIfYouWannaEdit();
	static void inputValue(std::string  str, std::string &value);
	static void logIn(std::string& login, std::string& password);
	static void startPick(int& choice);
	static void adminPick(int& action);
	static void grantApplicantPick(int& action);
	static void confirmation(std::string& confirmation);
	static void comissionPick(int& action);
	static void founderPick(int& action);
	static void editApplication(std::string& tempAge, std::string& tempData, std::string& name, std::string& filePath, std::string& link);
};