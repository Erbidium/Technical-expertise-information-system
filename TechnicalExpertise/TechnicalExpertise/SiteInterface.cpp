#include "SiteInterface.h"
#include "AccountManagement.h"
#include "ApplyTheApplication.h"
#include "ApplyTheRequest.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;

int logIn(string login, string password);
void printFileData(string name);
void createReview(string path, string name);

void SiteInterface::showMenu()
{
	int choice;
	do
	{
		cout<<"Login(0) Register(1) Leave request for registration(2) Quit(3):\n";
		cin>>choice;
		switch(choice)
		{
		case 0: {
			string login, password;
			cout<<"Enter your login:\n";
			cin>>login;
			cout<<"Enter your password:\n";
			cin>>password;
			if((password=="admin")&&(login=="admin"))
			{
				int action;
				do
				{
					cout<<"Choose action!"<<endl;
					cout<<"View requests(0) Register profile(1) Log out(2) Quit(3):"<<endl;
					cin>>action;
					switch(action)
					{
					case 0:
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
								if(numberOfRequest!=1){
									printFileData("Database/Requests/"+files[numberOfRequest]);
								}
							}
						}while(numberOfRequest!=-1);
					}	
					break;
					case 1:
						cout<<"Which account do you want to register?\n";
						cout<<"Expert comission(0) Fund owner(1)\n";
						int accountType;
						cin>>accountType;
						AccountManagement::registerProfile(accountType+1);
					break;
					case 3:
						choice=3;
					}
				}while(action!=2);			
			}
			else
			{
				int ID = logIn(login, password);
				if (ID == -1) {
					cout << "Entered incorrect login or password\n";
					continue;
				}
				cout << "ID: " << ID << endl;
				//ApplyTheApplication tempApplication;
				//tempApplication.setApplication(ID);
				printFileData("Database/Applications/33707/gkgmnngg.txt");
				createReview("Database/Applications/33707/gkgmnngg.txt", "gkgmnngg.txt");
			}
		}
		break;
		case 1:
			AccountManagement::registerProfile(0);
		break;
		case 2:{
			ApplyTheRequest tempRequest;
			tempRequest.setRequest();
		}		
		break;
		}
	}while(choice!=3);
		/*switch(choice)
		{
		case 0:*/
			//int typeOfUser;
			//cout<<"\nGrant recipient(0) Expert comission(1) Fund owner(2) Admin(3) Quit(4): ";
			//cin>>typeOfUser;
			/*int ID;
			if(typeOfUser!=4)
			{
				cout<<"Enter account ID: ";
				cin>>ID;
				AccountManagement::enterToProfile(ID);
				cout<<"\nChoose action!"<<endl;
			}
			int action;
			switch(typeOfUser)
			{
			case 0:
				do
				{
					cout<<"Create an application(0)\nCheck the status of application(1)\nDelete the application(2)\nLog out(3): ";
					cin>>action;
				}while(action!=3);
				AccountManagement::exitFromProfile(ID);
			break;
			case 1:
				do
				{
					cout<<"View the application(0)\nEvaluate the application(1)\nLog out(2): ";
					cin>>action;
				}while(action!=2);
				AccountManagement::exitFromProfile(ID);
			break;
			case 2:
				do
				{
					cout<<"View the results of the examination of the application(0)\nEvaluate the application(1)\nLog out(2): ";
					cin>>action;
				}while(action!=2);
				AccountManagement::exitFromProfile(ID);
			break;
			case 4:
				choice=2;
			break;
			}
		break;
		case 1:
			typeOfUser=-1;
			cout<<"\nGrant recipient(0) Expert comission(1) Fund owner(2) Quit(3): ";
			cin>>typeOfUser;
			switch(typeOfUser)
			{
			case 0:

			break;
			case 1:
			case 2:
				int confirmation;
				do
				{
					cout<<"\nLeave request for registration(0) Log out(1): ";
					cin>>confirmation;
				}while(confirmation!=1);
				AccountManagement::exitFromProfile(ID);
			break;
			case 3:
				choice=2;
			}
		break;
		case 2:
			choice=2;
		}*/
	
}
int logIn(string login, string password) {
	int ID = -1;
	ifstream inFile("Database/Accounts.txt");
	if (!inFile) {
		cout << "Can't open a file :-(";
	}
	else {
		while (!inFile.eof()) {
			string tempPassword;
			string tempLogin;
			int tempID;
			inFile >> tempPassword;
			inFile >> tempLogin;
			inFile >> tempID;
			if (tempPassword == password && tempLogin == login) {
				ID = tempID;
			}
		}
	}
	inFile.close();
	return ID;
}
void printFileData(string name) {
	ifstream inFile(name);
	if (!inFile) {
		cout << "Can't open a file";
	}
	else {
		while (!inFile.eof()) {
			string temp;
			getline(inFile, temp);
			cout << temp << endl;
		}
	}
	inFile.close();
}
void createReview(string path, string name) {
	cout << "Input your rating for this application: " << endl;
	string rating;
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	getline(cin, rating);
	ofstream outFile(path, ios::app);
	if (!outFile) {
		cout << "Can not open a file with application to write a sum up";
	}
	else {
		outFile << "Sum up of application: " << rating;
		outFile.close();
	}
	string newName = "";
	newName = path;
	newName.insert(path.rfind('/')+1, "[checked]");
	cout << "newName: " << newName;
	rename(path.data(), newName.data());
	outFile.close();
}
