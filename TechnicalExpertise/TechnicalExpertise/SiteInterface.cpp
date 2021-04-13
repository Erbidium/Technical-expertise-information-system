#include "SiteInterface.h"
#include "AccountManagement.h"
#include "ApplyTheRequest.h"
#include "WorkWithInterface.h"
#include "Profile.h"
#include "GrantApplicant.h"
#include "Admin.h"
#include "ExpertComission.h"
#include "FundOwner.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <ctime>

using namespace std;
namespace fs = filesystem;

void SiteInterface::createDefaultFiles()
{
	srand(time(NULL));
	string fileNames[5] = { "Database","Database/Applications","Database/Profiles","Database/Requests","Database/ProfilesBalance"};
	for (int i = 0; i < 5; i++)
	{
		if (fs::is_directory(fileNames[i])==false)
		{
			fs::create_directory(fileNames[i]);
		}
	}
	ofstream accounts("Database/Accounts.txt");
	accounts.close();
}

void SiteInterface::showMenu()
{
	int choice;
	do
	{
		cout<<"(0)Login\n(1)Register\n(2)Leave request for registration\n(3)Quit:\n";
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
				Admin admin;
				int action;
				do
				{
					cout<<"Choose action!"<<endl;
					cout<<"(0)View requests\n(1)Register profile\n(2)Log out:\n";
					cin>>action;
					switch(action)
					{
					case 0:
						admin.viewRequests();
					break;
					case 1:
						admin.registerProfile();
					break;
					case 3:
						choice=3;
					}
				}while(action!=2);
				system("cls");
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
					GrantApplicant currentGrantApplicant(current);
					do
					{
						cout<<"(0)Create an application\n(1)Check the status of application\n(2)Delete the application\n(3)EditApplication\n(4)Delete profile\n(5)Check your Balance\n(6)Edit profile\n(7)Log out:"<<endl;
						cin>>action;
						if(action==0)
							currentGrantApplicant.createApplication();
						else if(action==1)
							currentGrantApplicant.checkStatusOfApplication();
						else if(action==2)
							currentGrantApplicant.deleteApplication();
						else if(action==3)
							currentGrantApplicant.editApplication();
						else if(action==4)
						{
							cout<<"Are you sure?\n(0)Confirm\n(Any key)No\n";
							string confirmation;
							cin>>confirmation;
							if(confirmation=="0")
							{
								AccountManagement::deleteProfile(ID, currentGrantApplicant.getType());
								action=7;
								profileIsDeleted=true;
							}
						}
						else if(action==5)
							currentGrantApplicant.checkBalance();
						else if(action==6)
							AccountManagement::editProfile(ID);
					}while(action!=7);
					if(!profileIsDeleted)
					{
						system("cls");
						AccountManagement::exitFromProfile(ID);
					}
					
				}
				else if(current.getType()==1)
				{
					int action;
					bool profileIsDeleted=false;
					ExpertComission currentExpertComission(current);
					do
					{
						cout<<"(0)View the application and evaluate it\n(1)Delete profile\n(2)Log out:"<<endl;
						cin>>action;
						if(action==0)
						{
							currentExpertComission.viewApplicationAndEvaluate();	
						}
						else if(action==1)
						{
							cout<<"Are you sure?\n(0)Confirm\n(Any key)No\n";
							string confirmation;
							cin>>confirmation;
							if(confirmation=="0")
							{
								AccountManagement::deleteProfile(ID, currentExpertComission.getType());
								action=2;
								profileIsDeleted=true;
							}
						}
					}while(action!=2);
					if(!profileIsDeleted)
					{
						system("cls");
						AccountManagement::exitFromProfile(ID);
					}
				}
				else if(current.getType()==2)
				{
					int action;
					bool profileIsDeleted=false;
					FundOwner currentFundOwner(current);
					do
					{
						cout<<"(0)View the results of the examination of the application and accept grant\n(1)Delete profile\n(2)Log out: ";
						cin>>action;
						if(action==0)
						{
							currentFundOwner.ViewExaminationResultsAndAcceptGrant();	
						}
						else if(action==1)
						{
							cout<<"Are you sure?\n(0)Confirm\n(Any key)No\n";
							string confirmation;
							cin>>confirmation;
							if(confirmation=="0")
							{
								AccountManagement::deleteProfile(ID, currentFundOwner.getType());
								action=2;
								profileIsDeleted=true;
							}
						}
					}while(action!=2);
					if(!profileIsDeleted)
					{
						system("cls");
						AccountManagement::exitFromProfile(ID);
					}
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