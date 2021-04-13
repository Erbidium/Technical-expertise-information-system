#include "FileWriter.h"
#include "Request.h"
#include <fstream>
#include <iostream>

#include "Application.h"
#include "ViewMessages.h"

using namespace std;

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
	ofstream outFile("Database/Applications/" + to_string(ID) + "/" + tempName + ".txt");
	outFile << "Name of application: " << tempName << endl;
	outFile << "My age: " << tempAge << endl;
	outFile << "Application's data: " << applicationData.getContent() << endl;
	outFile << "Date: " << tempDate << endl;
	outFile.close();
}

void FileWriter::writeAddedFileToApplication(int ID, Application applicationData)
{
	if (applicationData.getFilePath().length()>0) {
		ofstream outFile("Database/Applications/" + to_string(ID) + "/" + applicationData.getName() + ".txt");
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
