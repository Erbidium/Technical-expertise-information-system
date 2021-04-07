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

using namespace std;

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
				Admin admin;
				int action;
				do
				{
					cout<<"Choose action!"<<endl;
					cout<<"View requests(0) Register profile(1) Log out(2):"<<endl;
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
						cout<<"Create an application(0)\nCheck the status of application(1)\nDelete the application(2)\nEditApplication(3)\nDelete profile(4)\nCheck your Balance(5)\nEdit profile(6)\nLog out(7):"<<endl;
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
							cout<<"Are you sure?\nConfirm(0) No(any key)\n";
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
						AccountManagement::exitFromProfile(ID);
				}
				else if(current.getType()==1)
				{
					int action;
					ExpertComission currentExpertComission(current);
					do
					{
						cout<<"View the application and evaluate it(0) \nLog out(1):"<<endl;
						cin>>action;
						if(action==0)
						{
							currentExpertComission.viewApplicationAndEvaluate();	
						}
					}while(action!=1);
					AccountManagement::exitFromProfile(ID);
				}
				else if(current.getType()==2)
				{
					int action;
					FundOwner currentFundOwner(current);
					do
					{
						cout<<"View the results of the examination of the application and accept grant(0)\nLog out(1): ";
						cin>>action;
						if(action==0)
						{
							currentFundOwner.ViewExaminationResultsAndAcceptGrant();	
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