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
		case 0:
			cout<<"Exit!..."<<endl;
			return 0;
		case 1:
			int typeOfUser;
			cout<<"(0)Grant recipient (1)Expert comission (2)Fund owner (3)Admin (4)Exit: ";
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
				cout<<"(0)Create an application\n(1)Check the status of application\n(2)Delete the application: ";
				cin>>action;
				break;
			case 1:
				cout<<"Choose action!"<<endl;
				cout<<"(0)View the application\n(1)Evaluate the application(2): ";
			case 4:
				cout<<"Exit!..."<<endl;
				return 0;
			}
			break;
		case 2:
			typeOfUser=-1;
			cout<<"(0)Grant recipient (1)Expert comission (2)Fund owner (3)Exit: ";
			cin>>typeOfUser;
			break;
		}
	}
	while(choice!=0);
}