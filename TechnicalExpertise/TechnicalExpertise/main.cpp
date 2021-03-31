#include <iostream>
#include "AccountManagement.h"

using namespace std;

int main()
{
	int choice;
	do
	{
		cout<<"\nLogin(0) Register(1) Quit(2): ";
		cin>>choice;
		switch(choice)
		{
		case 0:
			int typeOfUser;
			cout<<"\nGrant recipient(0) Expert comission(1) Fund owner(2) Admin(3) Quit(4): ";
			cin>>typeOfUser;
			int ID;
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
		}
	}while(choice!=2);
}