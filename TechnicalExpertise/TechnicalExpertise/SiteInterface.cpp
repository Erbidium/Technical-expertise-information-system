#include "SiteInterface.h"
#include "AccountManagement.h"
#include "ApplyTheApplication.h"
#include "ApplyTheRequest.h"
#include "Profile.h"
#include "GrantManagement.h"
#include <fstream>
#include <iostream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

void printFileData(string name);
void createReview(string path, string name);
Profile readProfile(int ID);

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
									printFileData("Database/Requests/"+files[numberOfRequest]);		
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
				int ID=AccountManagement::enterToProfile(login, password);
				if (ID == -1) {
					cout << "Entered incorrect login or password\n";
					continue;
				}
				cout<<"Succesfully logined!"<<endl;
				Profile current=readProfile(ID);
				if(current.getType()==0)
				{
					int action;
					bool profileIsDeleted=false;
					do
					{
						cout<<"Create an application(0)\nCheck the status of application(1)\nDelete the application(2)\nEditApplication(3)\nDelete profile(4)\nCheck your Balance(5)\nLog out(6):"<<endl;
						cin>>action;
						if(action==0)
						{
							ApplyTheApplication tempApplication;
							tempApplication.setApplication(ID);
						}
						else if(action==1)
						{
							int counter=0;
							vector <vector<string>> applicationNames(2);
							for (const auto & entry : filesystem::directory_iterator("Database/Applications/"+to_string(ID)))
							{
								if(entry.path().extension()==".txt")
								{
									applicationNames[0].push_back(entry.path().filename().string());
									applicationNames[1].push_back(entry.path().string());
									cout<<applicationNames[0].back()<<"("<<counter<<")"<<endl;
									counter++;
								}
							}
							cout<<"Press any key to quit"<<endl;
							string key;
							cin>>key;
						}
						else if(action==2)
						{
							
							int numberOfApplication=-1;
							do{
								int counter=0;
								vector <vector<string>> applicationNames(2);
								for (const auto & entry : filesystem::directory_iterator("Database/Applications/"+to_string(ID)))
								{
									if(entry.path().extension()==".txt")
									{
										applicationNames[0].push_back(entry.path().filename().string());
										applicationNames[1].push_back(entry.path().string());
										cout<<applicationNames[0].back()<<"("<<counter<<")"<<endl;
										counter++;
									}
								}
								cout<<"Choose application or enter -1 to quit"<<endl;
								cin>>numberOfApplication;
								if(numberOfApplication!=-1){
									remove(applicationNames[1][numberOfApplication].data());
								}
							}while(numberOfApplication!=-1);
						}
						else if (action == 3)
						{
							int numberOfApplication = -1;
							do {
								int counter = 0;
								vector <vector<string>> applicationNames(2);
								for (const auto& entry : filesystem::directory_iterator("Database/Applications/" + to_string(ID)))
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
								if (numberOfApplication != -1) {
									ofstream outFile(applicationNames[1][numberOfApplication], ios::trunc);
									ApplyTheApplication tempApplication;
									int position = applicationNames[0][numberOfApplication].find(".txt");
									string copy = applicationNames[0][numberOfApplication];
									copy.erase(position, 4);
									tempApplication.setApplication(ID, copy);
								}
							} while (numberOfApplication != -1);
						}
						else if (action == 4)
						{
							cout<<"Are you sure?\nConfirm(0) No(any key)\n";
							string confirmation;
							cin>>confirmation;
							if(confirmation=="0")
							{
								AccountManagement::deleteProfile(ID);
								action=5;
								profileIsDeleted=true;
							}
						}
					}while(action!=6);
					if(!profileIsDeleted)
					{
						AccountManagement::exitFromProfile(ID);
					}
				}
				else if(current.getType()==1)
				{
					int action;
					do
					{
						cout<<"View the application and evaluate it(0) \nLog out(1):"<<endl;
						cin>>action;
						if(action==0)
						{
							int numberOfApplication=-1;
							do{
								vector <vector<string>> applicationNames(2);
								int counter=0;
								for (const auto & entry : filesystem::recursive_directory_iterator("Database/Applications"))
								{
									if((entry.path().extension()==".txt")&&(entry.path().filename().string().find("[checked]")==string::npos)&&
										(entry.path().filename().string().find("[paid]")==string::npos))
									{
										applicationNames[0].push_back(entry.path().filename().string());
										applicationNames[1].push_back(entry.path().string());
										cout<<applicationNames[0].back()<<"("<<counter<<")"<<endl;
										counter++;
									}
								}
								cout<<"Choose application or enter -1 to quit"<<endl;
								cin>>numberOfApplication;
								if(numberOfApplication!=-1){
									printFileData(applicationNames[1][numberOfApplication]);
									createReview(applicationNames[1][numberOfApplication], applicationNames[0][numberOfApplication]);
								}
							}while(numberOfApplication!=-1);
							
						}
					}while(action!=1);
					AccountManagement::exitFromProfile(ID);
				}
				else if(current.getType()==2)
				{
					int action;
					do
					{
						cout<<"View the results of the examination of the application and accept grant(0)\nLog out(1): ";
						cin>>action;
						if(action==0)
						{
							vector <vector<string>> applicationNames(2);
							int counter=0;
							for (const auto & entry : filesystem::recursive_directory_iterator("Database/Applications"))
							{
								if((entry.path().extension()==".txt")&&(entry.path().filename().string().find("[checked]")!=string::npos)&&
									(entry.path().filename().string().find("[paid]")==string::npos))
								{
									applicationNames[0].push_back(entry.path().filename().string());
									applicationNames[1].push_back(entry.path().string());
									cout<<applicationNames[0].back()<<"("<<counter<<")"<<endl;
									counter++;
								}
								
							}
							int numberOfApplication=-1;
							do{
								cout<<"Choose application or enter -1 to quit"<<endl;
								cin>>numberOfApplication;
								if(numberOfApplication!=-1){
									printFileData(applicationNames[1][numberOfApplication]);
									
								}
							}while(numberOfApplication!=-1);
						}
					}while(action!=1);
					AccountManagement::exitFromProfile(ID);
				}
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
	newName.insert(path.rfind('/')+1, "[checked]");
	rename(path.data(), newName.data());
	outFile.close();
}

void createOwnersReview(string path, string name, int ID) {
	cout << "Input your conclusion: " << endl;
	bool conclusion;
	string s;
	int ID;
	if (cin.peek() == '\n') {
		cin.ignore();
	}
	ifstream outFile;
	if (!outFile) {
		cout << endl <<"Can not open a file with application to write a conclution" << endl;
	}
	else {
		while (getline(outFile,s))
		{
			cout << s << endl;
		}
	}
	string newName = "";
	for (int i = 0; i < path.length(); i++) {
		if (static_cast<int>(path[i]) == 92) {
			path[i] = '/';
		}
	}
	newName = path;
	ID = stoi(path.substr(23, 5));
	if (conclusion)
	{
		newName.replace(newName.rfind('['), 9, "[Payed]");
		GrantManagement::transferMoney(ID);
	}
	else
	{
		newName.replace(newName.rfind('['), 9, "[NotPayed]");
	}
	rename(path.data(), newName.data());
	outFile.close();
}

Profile readProfile(int ID)
{
	ifstream fileProfile("Database/Profiles/"+to_string(ID)+".txt");
	string name, email;
	int type;
	fileProfile>>name>>email>>type;
	Profile currentProfile;
	currentProfile.setEmail(email);
	currentProfile.setName(name);
	currentProfile.setType(type);
	return currentProfile;
}