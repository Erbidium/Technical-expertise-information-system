#include <iostream>

using namespace std;

int main()
{
	int choice;
	do
	{
		cout<<"Login(1) Register(2) Quit(0): ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			int typeOfUser;
			cout<<"Grant recipient(0) Expert comission(1) Fund owner(2) Admin(3) Exit(4): ";
			cin>>typeOfUser;
			int ID;
			cout<<"Enter account ID: ";
			cin>>ID;
			cout<<"Succesfully logined!"<<endl;
			int action;
			switch(typeOfUser)
			{
			case 0:
				cout<<"Choose action!"<<endl;
				cout<<"Create an application(0)\nCheck the status of application(1)\nDelete the application(2): ";
				cin>>action;
				break;
			case 1:
				cout<<"Choose action!"<<endl;
				cout<<"View the application(0)\nEvaluate the application(1): ";
				cin>>action;
			case 2:
				cout<<"Choose action!"<<endl;
				cout<<"View the results of the examination of the application(0)\nEvaluate the application(1): ";
				cin>>action;
			case 4:
				choice=0;
			}
			break;
		case 2:
			typeOfUser=-1;
			cout<<"Grant recipient(0) Expert comission(1) Fund owner(2) Exit(3): ";
			cin>>typeOfUser;
			switch(typeOfUser)
			{
			case 0:

			break;
			case 1:
			case 2:
				int confirmation;
				cout<<"Leave request for registration(0): ";
				cin>>confirmation;
				
				break;
			case 3:
				choice=0;
			}
			break;
		}
	}
	while(choice!=0);
}