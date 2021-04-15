#include "ViewInteraction.h"
#include "FileReader.h"
#include "GrantManagement.h"
#include <iostream>
#include "Validation.h"

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
	int accountType;
	string accountType1;
	do
	{
		cout << "(0)Expert comission\n(1)Fund owner\n";
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,accountType1);
	} while (!Validation::PickCheck(accountType1, 1));
	accountType = stoi(accountType1);
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
	bool leave;
	string leave1;
	do
	{
		cout << "Would you like to rewrite your " << word << "(0) or leave(1)?" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,leave1);
	} while (!Validation::PickCheck(leave1, 1));
	leave = stoi(leave1);
	return leave;
}

void ViewInteraction::createApplication(string& tempAge, string& tempData, string& name,string& filePath,string& link) {
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
	string wannaAdd1;
	do
	{
		cout << "Do you want to add some files to your application? Yes(1) No(0)" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,wannaAdd1);
	} while (!Validation::PickCheck(wannaAdd1, 1));
	wannaAdd = stoi(wannaAdd1);
	if (wannaAdd) {
		cout << "Input the path to your file on your PC. Example: Database / Applications / " << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin, filePath);
	}
	bool wannaAddLink;
	string wannaAddLink1;
	do
	{
		cout << "Do you want to add sine links to your application? Yes(1) No(0)" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,wannaAddLink1);
	} while (!Validation::PickCheck(wannaAddLink1, 1));
	wannaAddLink = stoi(wannaAddLink1);
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
	checkAndGetNumberOfApplication(numberOfApplication, applicationNames[0]);
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
	checkAndGetNumberOfApplication(numberOfApplication, applicationNames[0]);
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
		checkAndGetNumberOfApplication(numberOfRequest, files);
		if(numberOfRequest!=-1){
			FileReader::readAndPrintFileData("Database/Requests/"+files[numberOfRequest]);	
		}
	}while(numberOfRequest!=-1);
}

bool ViewInteraction::createConclusionOwner() {
	bool conclusion;
	string conclusion1;
	do
	{
		cout << "Input your conclusion (1 - yes, 0 - no): " << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,conclusion1);
	} while (!Validation::PickCheck(conclusion1, 1));
	conclusion = stoi(conclusion1);
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
	checkAndGetNumberOfApplication(numberOfApplication, applicationNames[0]);
}

void ViewInteraction::outBalance(int profileID) {
	cout << endl << "Your current balance is: " << fixed << setprecision(2) << GrantManagement::getMoney(profileID) << endl;
	bool bank;
	string bank1;
	do
	{
		cout << endl << "Would you like to withdraw money to your bank account? (1 - yes, 0 - no): " << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,bank1);
	} while (!Validation::PickCheck(bank1, 1));
	bank = stoi(bank1);
	if (bank)
	{
		GrantManagement::transferToBank(profileID);
	}
	else
	{
		clearScreen();
	}
}

void ViewInteraction::clearScreen()
{
	system("cls");
}

int ViewInteraction::inputEditing()
{
	clearScreen();
	cout << "What do you want to edit?\n";
	string typeOfEditing1;
	int typeOfEditing;
	do
	{
		cout << "(0)Login\n(1)Password\n(2)Name\n(3)Email" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,typeOfEditing1);
	} while (!Validation::PickCheck(typeOfEditing1, 3));
	typeOfEditing = stoi(typeOfEditing1);
	return typeOfEditing;
}

bool ViewInteraction::checkIfYouWannaEdit()
{
	string leave1;
	bool leave;
	do
	{
		clearScreen();
		cout << endl << "Would you like to edit something else(0) or leave(1)?" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,leave1);
	} while (!Validation::PickCheck(leave1, 1));
	leave = stoi(leave1);
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
	string choice1;
	do
	{
		cout << "(0)Login\n(1)Register\n(2)Leave request for registration\n(3)Quit:\n";
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,choice1);
	} while (!Validation::PickCheck(choice1, 3));
	choice = stoi(choice1);
}

void ViewInteraction::adminPick(int& action) {
	cout << "Choose action!" << endl;
	string action1;
	do
	{
		cout << "(0)View requests\n(1)Register profile\n(2)Log out:\n";
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,action1);
	} while (!Validation::PickCheck(action1, 2));
	action = stoi(action1);
}

void ViewInteraction::grantApplicantPick(int& action) {
	string action1;
	do
	{
		cout << "(0)Create an application\n(1)Check the status of application\n(2)Delete the application\n(3)EditApplication\n(4)Delete profile\n(5)Check your Balance\n(6)Edit profile\n(7)Log out:" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,action1);
	} while (!Validation::PickCheck(action1, 7));
	action = stoi(action1);
}

void ViewInteraction::confirmation(string& confirmation) {
	cout << "Are you sure?\n(0)Confirm\n(Any key)No\n";
	cin >> confirmation;
}

void ViewInteraction::comissionPick(int& action) {
	string action1;
	do
	{
		cout << "(0)View the application and evaluate it\n(1)Delete profile\n(2)Log out:" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,action1);
	} while (!Validation::PickCheck(action1, 2));
	action = stoi(action1);
}

void ViewInteraction::founderPick(int& action) {
	string action1;
	do
	{
		cout << "(0)View the results of the examination of the application and accept grant\n(1)Delete profile\n(2)Log out:\n";
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin,action1);
	} while (!Validation::PickCheck(action1, 2));
	action = stoi(action1);
}
void ViewInteraction::editApplication(string& tempAge, string& tempData, string& name, string& filePath, string& link) {
	bool correct;
	do
	{
		correct = true;
		cout << "If you do not want to change the field, input '-' on it" << endl;
		cout << "Input your age:" << endl;
		string age;
		cin >> age;
		cout << "Input your application's data:" << endl;
		string data;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin, data);
		string tempName;
		cout << "Input your application's name:" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin, tempName);
		bool wannaAdd;
		string wannaAdd1;
		do
		{
			cout << "Do you want to change the file that you added to application? Yes(1) No(0)" << endl;
			if (cin.peek() == '\n') {
				cin.ignore();
			}
			getline(cin,wannaAdd1);
		} while (Validation::PickCheck(wannaAdd1, 1));
		wannaAdd = stoi(wannaAdd1);
		if (wannaAdd) {
			cout << "Input the path to your file on your PC. Example: Database / Applications / " << endl;
			if (cin.peek() == '\n') {
				cin.ignore();
			}
			getline(cin, filePath);
		}
		bool wannaAddLink;
		string wannaAddLink1;
		do
		{
			cout << "Do you want to change the link, you added to your application? Yes(1) No(0)" << endl;
			if (cin.peek() == '\n') {
				cin.ignore();
			}
			getline(cin,wannaAddLink1);
		} while (!Validation::PickCheck(wannaAddLink1, 1));
		wannaAddLink = stoi(wannaAddLink1);
		if (wannaAddLink) {
			cout << "Input the full link. It can be your gitHub repositoy, etc. Example: https://github.com/ErnestoFolting/ArithmeticCalculations";
			if (cin.peek() == '\n') {
				cin.ignore();
			}
			getline(cin, link);
		}
		if (age != "-") {
			tempAge = age;
			if (!Validation::AgeCheck(age))
			{
				correct = false;
			}
		}
		if (data != "-") {
			tempData = data;
			if (!Validation::DataEmptyCheck(data, "Application`s data"))
			{
				correct = false;
			}
		}
		if (tempName != "-") {
			name = tempName;
			if (!Validation::NameCheck(name, "Application`s name"))
			{
				correct = false;
			}
		}
		if (!correct)
		{
			cout << "Please try again!" << endl;
		}
		else
		{
			cout << "Everything is correct! Would you like to edit something else?" << endl;
		}
	} while (!correct);
}

void ViewInteraction::checkAndGetNumberOfApplication(int& numberOfApplication, vector <string> applicationNames)
{
	while(true)
	{
		string strNumberApplication;
		cout << "Choose application or enter -1 to quit" << endl;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		getline(cin, strNumberApplication);
		bool isNumber=true;
		if(strNumberApplication!="-1")
		{
			for(int i=0;i<strNumberApplication.size();i++)
			{
				if((strNumberApplication[i]<48)||(strNumberApplication[i]>57))
					isNumber=false;
			}
		}
		if(isNumber==true)
		{
			numberOfApplication=stoi(strNumberApplication);
			if(((numberOfApplication>=0)&&(numberOfApplication<applicationNames.size()))||(numberOfApplication==-1))
				break;
		}
	}
}
