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
			cout<<"Succesfully logined!"<<endl;
			break;
		case 2:
			cout<<"Choose type of user: ";
		default:
			cout<<"Exit!..."<<endl;
			return 0;
		}
	}
	while(choice!=0);
}