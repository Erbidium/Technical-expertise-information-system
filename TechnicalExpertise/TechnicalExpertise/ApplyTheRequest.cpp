#include <fstream>
#include "ApplyTheRequest.h"
using namespace std;

void ApplyTheRequest::setRequest()
{
	string tempContent;
	string tempName;
	string tempEmail;
	cout << endl << "Input your name: " << endl;
	cin >> tempName;
	cout << endl << "Input your email: " << endl;
	cin >> tempEmail;
	cout << "Input your request: " << endl;
	cin.ignore();
	getline(cin, tempContent);
	requestData.setName(tempName);
    requestData.setEmail(tempEmail);
	requestData.setContent(tempContent);
	requestDataCheck();
}

void ApplyTheRequest::requestManager()
{
	ofstream outFile("Database/Requests/" + requestData.getName() + ".txt");
	outFile << "My name: " << requestData.getName() << endl;
	outFile << "My email: " << requestData.getEmail() << endl;
	outFile << "Request Content: " << requestData.getContent() << endl;
	outFile.close();
}

void ApplyTheRequest::requestDataCheck()
{
	cout << "Your request is correct!";
	requestManager();
}
