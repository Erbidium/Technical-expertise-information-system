#include "SiteInterface.h"
#include "AccountManagement.h"
#include "ApplyTheRequest.h"
#include "Profile.h"
#include "GrantApplicant.h"
#include "Admin.h"
#include "ExpertComission.h"
#include "FundOwner.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include "FileReader.h"
#include "FileWriter.h"
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
	if(!fs::is_regular_file("Database/Accounts.txt"))
	{
		FileWriter::writeEmptyAccounts();
	}
}

void SiteInterface::showMenu()
{
	int choice;
	do
	{
		ViewInteraction::startPick(choice);
		ViewInteraction::clearScreen();
		switch(choice)
		{
		case 0: {
			string login, password;
			ViewInteraction::logIn(login, password);
			ViewInteraction::clearScreen();
			if((password=="admin")&&(login=="admin"))
			{
				Admin admin;
				int action;
				do
				{
					ViewInteraction::adminPick(action);
					ViewInteraction::clearScreen();
					switch(action)
					{
					case 0:
						admin.viewRequests();
					break;
					case 1:
						admin.registerProfile();
					break;
					}
				}while(action!=2);
				ViewInteraction::clearScreen();
			}
			else
			{
				int ID=AccountManagement::enterToProfile(login, password);
				if (ID == -1) {
					ViewMessages::unsuccsessfulLogIn();
					continue;
				}
				ViewMessages::succsessfulLogIn();
				Profile current=FileReader::readProfile(ID);
				if(current.getType()==0)
				{
					int action;
					bool profileIsDeleted=false;
					GrantApplicant currentGrantApplicant(current);
					do
					{
						ViewInteraction::grantApplicantPick(action);
						ViewInteraction::clearScreen();
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
							string confirmation;
							ViewInteraction::confirmation(confirmation);
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
						ViewInteraction::clearScreen();
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
						ViewInteraction::comissionPick(action);
						ViewInteraction::clearScreen();
						if(action==0)
						{
							currentExpertComission.viewApplicationAndEvaluate();	
						}
						else if(action==1)
						{
							string confirmation;
							ViewInteraction::confirmation(confirmation);
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
						ViewInteraction::clearScreen();
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
						ViewInteraction::founderPick(action);
						ViewInteraction::clearScreen();
						if(action==0)
						{
							currentFundOwner.ViewExaminationResultsAndAcceptGrant();	
						}
						else if(action==1)
						{
							string confirmation;
							ViewInteraction::confirmation(confirmation);
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
						ViewInteraction::clearScreen();
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