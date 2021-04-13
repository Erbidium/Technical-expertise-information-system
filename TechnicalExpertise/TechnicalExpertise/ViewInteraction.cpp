#include "ViewInteraction.h"
#include "FileReader.h"
#include "GrantManagement.h"
#include <iostream>

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
	cout << "Would you like to rewrite your " << word << "(0) or leave(1)?" << endl;
	bool leave;
	cin >> leave;
	return leave;
}
void ViewInteraction::createApplication(int& tempAge, string& tempData, string& name,string& filePath,string& link) {
	cout << "Input your age:" << endl;
	cin >> tempAge;
	cout << "Input your application's data:" << endl;
	cin.ignore();
	getline(cin, tempData);
	if (name == "") {
		cout << "Input your application's name:" << endl;
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
	bool wannaAddLink;
	cout << "Do you want to add sine links to your application? Yes(1) No(0)" << endl;
	cin >> wannaAddLink;
	if (wannaAddLink) {
		cout << "Input the full link. It can be your gitHub repositoy, etc. Example: https://github.com/ErnestoFolting/ArithmeticCalculations";
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin, link);
	}
	else {
		link = "-";
	}
}
Request ViewInteraction::createRequest() {
	Request requestData;
	string tempContent;
	string tempName;
	string tempEmail;
	cout << "Input your name: " << endl;
	cin >> tempName;
	cout << "Input your email: " << endl;
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
			FileReader::readAndPrintFileData("Database/Requests/"+files[numberOfRequest]);	
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
void ViewInteraction::clearScreen()
{
	system("cls");
}
int ViewInteraction::inputEditing()
{
	cout << "What do you want to edit?\n";
	cout << "(0)Login\n(1)Password\n(2)Name\n(3)Email" << endl;
	int typeOfEditing;
	cin >> typeOfEditing;
	return typeOfEditing;
}
bool ViewInteraction::checkIfYouWannaEdit()
{
	cout << endl << "Would you like to edit something else(0) or leave(1)?" << endl;
	bool leave;
	cin >> leave;
	return leave;
}
void ViewInteraction::inputValue(string str, string& value)
{
	cout << endl << str << endl;
	cin >> value;
}
void ViewInteraction::logIn(string& login, string& password) {
	cout << "Enter your login:\n";
	cin >> login;
	cout << "Enter your password:\n";
	cin >> password;
}
void ViewInteraction::startPick(int& choice) {
	cout << "(0)Login\n(1)Register\n(2)Leave request for registration\n(3)Quit:\n";
	cin >> choice;
}

void ViewInteraction::adminPick(int& action) {
	cout << "Choose action!" << endl;
	cout << "(0)View requests\n(1)Register profile\n(2)Log out:\n";
	cin >> action;
}
void ViewInteraction::grantApplicantPick(int& action) {
	cout << "(0)Create an application\n(1)Check the status of application\n(2)Delete the application\n(3)EditApplication\n(4)Delete profile\n(5)Check your Balance\n(6)Edit profile\n(7)Log out:" << endl;
	cin >> action;
}
void ViewInteraction::confirmation(string& confirmation) {
	cout << "Are you sure?\n(0)Confirm\n(Any key)No\n";
	cin >> confirmation;
}
void ViewInteraction::comissionPick(int& action) {
	cout << "(0)View the application and evaluate it\n(1)Delete profile\n(2)Log out:" << endl;
	cin >> action;
}
void ViewInteraction::founderPick(int& action) {
	cout << "(0)View the results of the examination of the application and accept grant\n(1)Delete profile\n(2)Log out: ";
	cin >> action;
}

