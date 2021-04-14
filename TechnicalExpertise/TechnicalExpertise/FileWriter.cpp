#include "FileWriter.h"
#include "Request.h"
#include "Application.h"
#include "Profile.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include <fstream>
#include <ctime>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void FileWriter::writeRequestToFile(Request requestData)
{
	ofstream outFile("Database/Requests/" + requestData.getName() + ".txt");
	outFile << "My name: " << requestData.getName() << endl;
	outFile << "My email: " << requestData.getEmail() << endl;
	outFile << "Request Content: " << requestData.getContent() << endl;
	outFile.close();
}

void FileWriter::writeApplication(int ID, Application applicationData)
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	string tempDate = to_string(newtime.tm_mday) + '.' + to_string(newtime.tm_mon + 1) + '.' + to_string(newtime.tm_year + 1900);
	int tempAge = applicationData.getAge();
	string tempData = applicationData.getContent();
	string tempName = applicationData.getName();
	string tempLink = applicationData.getLink();
	ofstream outFile("Database/Applications/" + to_string(ID) + "/" + tempName + ".txt");
	outFile << "Name of application: " << tempName << endl;
	outFile << "My age: " << tempAge << endl;
	outFile << "Application's data: " << applicationData.getContent() << endl;
	outFile << "My link: " << tempLink << endl;
	outFile << "Date: " << tempDate << endl;
	outFile.close();
}

void FileWriter::writeAddedFileToApplication(int ID, Application applicationData)
{
	if (applicationData.getFilePath().length()>0) {
		ofstream outFile("Database/Applications/" + to_string(ID) + "/" + applicationData.getName() + ".txt", ios::app);
		ifstream inFile(applicationData.getFilePath());
		if (!inFile) {
			ViewMessages::cannotOpenFileToAddToApplication();
		}
		else {
			outFile << endl << "Added file content: " << endl;
			string s;
			while (!inFile.eof()) {
				getline(inFile, s);
				outFile << s << endl;
			}
		}
		inFile.close();
		outFile.close();
	}
}

void FileWriter::writeEmptyAccounts()
{
	ofstream accounts("Database/Accounts.txt");
	accounts.close();
}

void FileWriter::rewriteAccounts(int ID)
{
	ifstream oldAccounts("Database/Accounts.txt");
	ofstream newAccounts("Database/NewAccounts.txt");
	if((oldAccounts.is_open())&&(newAccounts.is_open()))
	{
		while(!oldAccounts.eof())
		{
			string password, login;
			int currentID;
			oldAccounts>>password>>login>>currentID;
			if(currentID!=ID)
			{
				newAccounts<<password<<" "<<login<<" "<<currentID<<endl;
			}
		}
		oldAccounts.close();
		newAccounts.close();
		fs::remove("Database/Accounts.txt");
		rename("Database/NewAccounts.txt", "Database/Accounts.txt");
		ViewMessages::successfulProfileDelete();
	}
}

void FileWriter::writeProfileData(Profile profileData)
{
	ofstream outProfile("Database/Profiles/"+std::to_string(profileData.getID())+".txt");
	outProfile << profileData.getName() << " " << profileData.getEmail() << " " << profileData.getType() << "\n";
	outProfile.close();
	
}

void FileWriter::writeProfileBalance(Profile profileData)
{
	ofstream outProfileBalance("Database/ProfilesBalance/" + to_string(profileData.getID()) + ".txt");
	outProfileBalance << profileData.getBalance() << "\n";
	outProfileBalance.close();
}

void FileWriter::writeLoginData(Profile profileData)
{
	ofstream Accounts("Database/Accounts.txt", ios::app);
	Accounts<<profileData.getPassword()<<" "<<profileData.getLogin()<<" "<<profileData.getID()<<"\n";
	Accounts.close();
}

void FileWriter::clearFileData(string path)
{
	ofstream outFile(path, ios::trunc);
	outFile.close();
}

void FileWriter::writeMoney(string pathToProfileBalance, string money, float sum)
{
	ofstream outFile2(pathToProfileBalance);
	outFile2 << sum + stof(money);
	outFile2.close();
}

void FileWriter::writeDifMoney(string pathToProfileBalance, string money, float dif)
{
	ofstream outFile2(pathToProfileBalance);
	outFile2 << dif - stof(money);
	outFile2.close();
}

void FileWriter::createReview(string path, string name) {
	string rating=ViewInteraction::inputApplicationRating();
	ofstream outFile(path, ios::app);
	if (!outFile) {
		ViewMessages::cannotOpenFileToWriteSumUp();
	}
	else {
		outFile << "Sum up of application: " << rating << endl;
		outFile.close();
	}
	string newName = "";
	for (int i = 0; i < path.length(); i++) {
		if (static_cast<int>(path[i]) == 92) {
			path[i] = '/';
		}
	}
	newName = path;
	newName.insert(path.rfind('/') + 1, "[checked]");
	rename(path.data(), newName.data());
	outFile.close();
}

void FileWriter::editFileLogin(int ID, string oldPassword, string newLogin)
{
	ifstream oldAccounts("Database/Accounts.txt");
	ofstream newAccounts("Database/NewAccounts.txt");
	if ((oldAccounts.is_open()) && (newAccounts.is_open()))
	{
		while (!oldAccounts.eof())
		{
			string password, login;
			int currentID;
			oldAccounts >> password >> login >> currentID;
			if (currentID != ID)
			{
				newAccounts << password << " " << login << " " << currentID << endl;
			}
		}
		newAccounts << oldPassword << " " << newLogin << " " << ID << endl;
		oldAccounts.close();
		newAccounts.close();
		fs::remove("Database/Accounts.txt");
		rename("Database/NewAccounts.txt", "Database/Accounts.txt");
		ViewMessages::successfulEdit();
	}
}

void FileWriter::editFilePassword(int ID, string oldLogin, string newPassword)
{
	ifstream oldAccounts("Database/Accounts.txt");
	ofstream newAccounts("Database/NewAccounts.txt");
	if ((oldAccounts.is_open()) && (newAccounts.is_open()))
	{
		while (!oldAccounts.eof())
		{
			string password, login;
			int currentID;
			oldAccounts >> password >> login >> currentID;
			if (currentID != ID)
			{
				newAccounts << password << " " << login << " " << currentID << endl;
			}
		}
		newAccounts << newPassword << " " << oldLogin << " " << ID << endl;
		oldAccounts.close();
		newAccounts.close();
		fs::remove("Database/Accounts.txt");
		rename("Database/NewAccounts.txt", "Database/Accounts.txt");
		ViewMessages::successfulEdit();
	}
}

void FileWriter::editFileName(string OldPath, string NewPath, string newName)
{
	ifstream oldProfile(OldPath);
	ofstream newProfile(NewPath);
	if ((oldProfile.is_open()) && (newProfile.is_open()))
	{
		string name, email;
		int type;
		oldProfile >> name >> email >> type;
		newProfile << newName << " " << email << " " << type << endl;
		oldProfile.close();
		newProfile.close();
		fs::remove(OldPath);
		rename(NewPath.data(), OldPath.data());
		ViewMessages::successfulEdit();
	}
}

void FileWriter::editFileEmail(string OldPath, string NewPath, string newEmail)
{
	ifstream oldProfile(OldPath);
	ofstream newProfile(NewPath);
	if ((oldProfile.is_open()) && (newProfile.is_open()))
	{
		string name, email;
		int type;
		oldProfile >> name >> email >> type;
		newProfile << name << " " << newEmail << " " << type << endl;
		oldProfile.close();
		newProfile.close();
		fs::remove(OldPath);
		rename(NewPath.data(), OldPath.data());
		ViewMessages::successfulEdit();
	}
}
