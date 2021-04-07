#include "ApplyTheApplication.h"
#include "View.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void ApplyTheApplication::applicationsManager(int ID) {
	int tempAge = applicationData.getAge();
	string tempData = applicationData.getContent();
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	string tempDate = to_string(newtime.tm_mday) + '.' + to_string(newtime.tm_mon + 1) + '.' + to_string(newtime.tm_year + 1900);
	string tempName = applicationData.getName();
	ofstream outFile("Database/Applications/" + to_string(ID) + "/" + tempName + ".txt");
	outFile << "Name of application: " << tempName << endl;
	outFile << "My age: " << tempAge << endl;
	outFile << "Application's data: " << applicationData.getContent() << endl;
	outFile << "Date: " << tempDate << endl;
	if (applicationData.getFilePath().length()>0) {
		ifstream inFile(applicationData.getFilePath());
		if (!inFile) {
			cout << "But can not open a file to add to application" << endl;
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
	}
	outFile.close();
}
void ApplyTheApplication::applicationDataCheck(int ID) {
	bool correct = true;
	string name = applicationData.getName();
	if (name.empty())
	{
		cout << endl << "Your application`s name is epmty." << endl;
		correct = false;
	}
	for (int i = 0; i < name.length(); i++)
	{
		if (!((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || name[i] == ' '))
		{
			cout << endl << "Your application`s name has been writen wrong or at different language." << endl;
			correct = false;
			i = name.length();
		}
	}
	string Content = applicationData.getContent();
	if (Content.empty())
	{
		cout << endl << "Your application is epmty." << endl;
		correct = false;
	}
	if (correct)
	{
		cout << endl << "Your application is correct!" << endl;
		applicationsManager(ID);
	}
	else
	{
		bool leave = View::checkIfYouWannaRewrite("application");
		if (!leave)
		{
			setApplication(ID);
		}
	}
}
void ApplyTheApplication::setApplication(int ID,string name) {
	int tempAge;
	string tempData;
	string filePath;
	View::createApplication(tempAge,tempData,name, filePath);
	applicationData.setAge(tempAge);
	applicationData.setContent(tempData);
	applicationData.setName(name);
	applicationData.setFilePath(filePath);
	applicationDataCheck(ID);
}
