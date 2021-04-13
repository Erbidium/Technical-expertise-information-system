#include "ViewInteraction.h"
#include <iostream>
#include "GrantManagement.h"
#include "WorkWithInterface.h"

using namespace std;

Profile ViewInteraction::createProfi(int profileID, int type)
{
	string login, password, name, email;
	cout << "Enter your login:\n";
	cin >> login;
	cout << "Enter your password:\n";
	cin >> password;
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your email:\n";
	cin >> email;
	Profile newProfile(name, email, login, password, profileID, type, 0);
	return newProfile;
}
void ViewInteraction::inputNameEmail(string& name, string& email) {
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your email:\n";
	cin >> email;
}
int ViewInteraction::inputAccTypeForRegistration() {
	cout << "Which account do you want to register?\n";
	cout << "(0)Expert comission\n(1)Fund owner\n";
	int accountType;
	cin >> accountType;
	return accountType;
}
string ViewInteraction::inputApplicationRating()
{
	string rating;
	cout << "Input your rating for this application: " << endl;
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	getline(cin, rating);
	return rating;
}
bool ViewInteraction::checkIfYouWannaRewrite(string word) {
	cout << endl << "Would you like to rewrite your " << word << "(0) or leave(1)?" << endl;
	bool leave;
	cin >> leave;
	return leave;
}
void ViewInteraction::createApplication(int& tempAge, string& tempData, string& name,string& filePath) {
	cout << endl << "Input your age:" << endl;
	cin >> tempAge;
	cout << endl << "Input your application's data:" << endl;
	cin.ignore();
	getline(cin, tempData);
	if (name == "") {
		cout << endl << "Input your application's name:" << endl;
		getline(cin, name);
	}
	bool wannaAdd;
	cout << "Do you want to add some files to your application? Yes(1) No(0)" << endl;
	cin >> wannaAdd;
	if (wannaAdd) {
		cout << "Input the path to your file on your PC. Example: Database / Applications / " << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin, filePath);
	}
}
Request ViewInteraction::createRequest() {
	Request requestData;
	string tempContent;
	string tempName;
	string tempEmail;
	cout << endl << "Input your name: " << endl;
	cin >> tempName;
	cout << endl << "Input your email: " << endl;
	cin >> tempEmail;
	cout << endl << "Input your request: " << endl;
	cin.ignore();
	getline(cin, tempContent);
	requestData.setName(tempName);
	requestData.setEmail(tempEmail);
	requestData.setContent(tempContent);
	return requestData;
}
int ViewInteraction::viewApplicationsAndPickComission(vector <vector<string>>& applicationNames, int& numberOfApplication) {
	int counter = 0;
	for (const auto& entry : filesystem::recursive_directory_iterator("Database/Applications"))
	{
		if ((entry.path().extension() == ".txt") && (entry.path().filename().string().find("[checked]") == string::npos) &&
			(entry.path().filename().string().find("[Paid]") == string::npos) && (entry.path().filename().string().find("[NotPaid]") == string::npos))
		{
			applicationNames[0].push_back(entry.path().filename().string());
			applicationNames[1].push_back(entry.path().string());
			cout << applicationNames[0].back() << "(" << counter << ")" << endl;
			counter++;
		}
	}
	cout << "Choose application or enter -1 to quit" << endl;
	cin >> numberOfApplication;
	return numberOfApplication;
}
int ViewInteraction::viewApplicationsAndPickOwner(vector <vector<string>>& applicationNames, int& numberOfApplication) {
	int counter = 0;
	for (const auto& entry : filesystem::recursive_directory_iterator("Database/Applications"))
	{
		if ((entry.path().extension() == ".txt") && (entry.path().filename().string().find("[checked]") != string::npos) &&
			(entry.path().filename().string().find("[Paid]") == string::npos) && (entry.path().filename().string().find("[NotPaid]") == string::npos))
		{
			applicationNames[0].push_back(entry.path().filename().string());
			applicationNames[1].push_back(entry.path().string());
			cout << applicationNames[0].back() << "(" << counter << ")" << endl;
			counter++;
		}

	}
	cout << "Choose application or enter -1 to quit" << endl;
	cin >> numberOfApplication;
	return numberOfApplication;
}
void ViewInteraction::showRequests()
{
	cout<<"All requests:"<<endl;
	vector <string> files;
	int counter=0;
	for (const auto & entry : filesystem::directory_iterator("Database/Requests"))
	{
		if(entry.path().extension()==".txt")
		{
			files.push_back(entry.path().filename().string());
			cout<<files.back()<<"("<<counter<<")"<<endl;
		}
		counter++;
	}
	int numberOfRequest=-1;
	do{
		cout<<"Choose request or enter -1 to quit"<<endl;
		cin>>numberOfRequest;
		if(numberOfRequest!=-1){
				printFileData("Database/Requests/"+files[numberOfRequest]);		
		}
	}while(numberOfRequest!=-1);
}
bool ViewInteraction::createConclusionOwner() {
	cout << "Input your conclusion (1 - yes, 0 - no): " << endl;
	bool conclusion;
	cin >> conclusion;
	return conclusion;
}
void ViewInteraction::applicationStatusOut(int counter, vector <vector<string>>& applicationNames, int profileID){
	for (const auto& entry : filesystem::directory_iterator("Database/Applications/" + to_string(profileID)))
	{
		if (entry.path().extension() == ".txt")
		{
			applicationNames[0].push_back(entry.path().filename().string());
			applicationNames[1].push_back(entry.path().string());
			cout << applicationNames[0].back() << "(" << counter << ")" << endl;
			counter++;
		}
	}
	cout << "Press any key to quit" << endl;
	string key;
	cin >> key;
}
void ViewInteraction::outApplicationAndDelete(int& numberOfApplication, vector <vector<string>>& applicationNames, int profileID) {
	int counter = 0;
	for (const auto& entry : filesystem::directory_iterator("Database/Applications/" + to_string(profileID)))
	{
		if (entry.path().extension() == ".txt")
		{
			applicationNames[0].push_back(entry.path().filename().string());
			applicationNames[1].push_back(entry.path().string());
			cout << applicationNames[0].back() << "(" << counter << ")" << endl;
			counter++;
		}
	}
	cout << "Choose application or enter -1 to quit" << endl;
	cin >> numberOfApplication;
}
void ViewInteraction::outBalance(int profileID) {
	cout << endl << "Your current balance is: " << fixed << setprecision(2) << GrantManagement::getMoney(profileID) << endl;
	bool bank;
	cout << endl << "Would you like to withdraw money to your bank account? (1 - yes, 0 - no): " << endl;
	cin >> bank;
	if (bank)
	{
		GrantManagement::transferToBank(profileID);
	}
}
void ViewInteraction::inputAmountOfMoney(string& money) {
	cout << endl << "How much money are you transfering?" << endl;
	cin >> money;
}
void ViewInteraction::inputCardNumber(string& card) {
	cout << endl << "Input your card number:" << endl;
	cin >> card;
}

void ViewInteraction::clearScreen()
{
	system("cls");
}
