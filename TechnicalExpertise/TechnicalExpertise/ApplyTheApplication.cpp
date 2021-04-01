#include "ApplyTheApplication.h"
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
		cout << endl << "Yout application is correct!" << endl;
		applicationsManager(ID);
	}
	else
	{
		cout << endl << "Would you like to rewrite your application(0) or leave(1)?" << endl;
		bool leave;
		cin >> leave;
		if (!leave)
		{
			setApplication(ID);
		}
	}
}
void ApplyTheApplication::setApplication(int ID,string name) {
	int tempAge;
	string tempData;
	cout << endl << "Input your age:" << endl;
	cin >> tempAge;
	cout << endl << "Input your application's data:" << endl;
	cin.ignore();
	getline(cin, tempData);
	if (name == "") {
		cout << endl << "Input your application's name:" << endl;
		getline(cin, name);
	}
	applicationData.setAge(tempAge);
	applicationData.setContent(tempData);
	applicationData.setName(name);
	applicationDataCheck(ID);
}
