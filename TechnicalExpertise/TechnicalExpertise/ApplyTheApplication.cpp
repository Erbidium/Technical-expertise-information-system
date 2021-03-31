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
	outFile << "My age: " << tempAge << endl;
	outFile << "Name of application: " << tempName << endl;
	outFile << "Application's data: " << applicationData.getContent() << endl;
	outFile << "Date: " << tempDate << endl;
	outFile.close();
}
void ApplyTheApplication::applicationDataCheck(int ID) {
	cout << "Your application has been registered\n";
	applicationsManager(ID);
}
void ApplyTheApplication::setApplication(int ID) {
	int tempAge;
	string tempData;
	string tempName;
	cout << endl << "Input your age:" << endl;
	cin >> tempAge;
	cout << endl << "Input your application's data:" << endl;
	cin.ignore();
	getline(cin, tempData);
	cout << endl << "Input your application's name:" << endl;
	getline(cin, tempName);
	applicationData.setAge(tempAge);
	applicationData.setContent(tempData);
	applicationData.setName(tempName);
	applicationDataCheck(ID);
}
