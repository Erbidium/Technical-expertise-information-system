﻿#include "GrantApplicant.h"
#include "ApplyTheApplication.h"
#include <vector>
#include <filesystem>
#include <fstream>

#include "FileWriter.h"
#include "ViewInteraction.h"

using namespace std;

GrantApplicant::GrantApplicant(Profile currentProfile)
{
	profileID=currentProfile.getID();
	name=currentProfile.getName();
	email=currentProfile.getEmail();
	password=currentProfile.getPassword();
	login=currentProfile.getLogin();
	typefUser=currentProfile.getType();
	Balance=currentProfile.getBalance();
}

void GrantApplicant::createApplication()
{
	ApplyTheApplication tempApplication;
	tempApplication.setApplication(profileID);
}

void GrantApplicant::checkStatusOfApplication()
{
	int counter=0;
	vector <vector<string>> applicationNames(2);
	ViewInteraction::applicationStatusOut(counter, applicationNames, profileID);
	ViewInteraction::clearScreen();
}

void GrantApplicant::deleteApplication()
{
	int numberOfApplication=-1;
	do{
		vector <vector<string>> applicationNames(2);
		ViewInteraction::outApplicationAndDelete(numberOfApplication, applicationNames, profileID);
		if(numberOfApplication!=-1){
			remove(applicationNames[1][numberOfApplication].data());
		}
	}while(numberOfApplication!=-1);
	ViewInteraction::clearScreen();
}

void GrantApplicant::editApplication()
{
	int numberOfApplication = -1;
	do {
		vector <vector<string>> applicationNames(2);
		ViewInteraction::outApplicationAndDelete(numberOfApplication, applicationNames, profileID);
		if (numberOfApplication != -1) {
			FileWriter::clearFileData(applicationNames[1][numberOfApplication]);
			ApplyTheApplication tempApplication;
			int position = applicationNames[0][numberOfApplication].find(".txt");
			string copy = applicationNames[0][numberOfApplication];
			copy.erase(position, 4);
			tempApplication.setApplication(profileID, copy);
		}
	} while (numberOfApplication != -1);
	ViewInteraction::clearScreen();
}

void GrantApplicant::checkBalance()
{
	ViewInteraction::outBalance(profileID);
}
