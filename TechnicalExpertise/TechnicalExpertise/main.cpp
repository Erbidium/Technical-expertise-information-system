#include <iostream>

using namespace std;

int main()
{
	int choice;
	do
	{
		cout<<"\nLogin(1) Register(2) Quit(0): ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			int typeOfUser;
			cout<<"\nGrant recipient(0) Expert comission(1) Fund owner(2) Admin(3) Exit(4): ";
			cin>>typeOfUser;
			int ID;
			cout<<"Enter account ID: ";
			cin>>ID;
			cout<<"Succesfully logined!"<<endl;
			int action;
			switch(typeOfUser)
			{
			case 0:
				do
				{
					cout<<"\nChoose action!"<<endl;
					cout<<"Create an application(0)\nCheck the status of application(1)\nDelete the application(2)\nLog out(3): ";
					cin>>action;
				}while(action!=3);
			break;
			case 1:
				do
				{
					cout<<"\nChoose action!"<<endl;
					cout<<"View the application(0)\nEvaluate the application(1)\n\nLog out(2): ";
					cin>>action;
				}while(action!=2);
			break;
			case 2:
				do
				{
					cout<<"\nChoose action!"<<endl;
					cout<<"View the results of the examination of the application(0)\nEvaluate the application(1)\nLog out(2): ";
					cin>>action;
				}while(action!=2);
			break;
			case 4:
				choice=0;
			}
		break;
		case 2:
			typeOfUser=-1;
			cout<<"\nGrant recipient(0) Expert comission(1) Fund owner(2) Exit(3): ";
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
			break;
			case 3:
				choice=0;
			}
		break;
		}
	}while(choice!=0);
}