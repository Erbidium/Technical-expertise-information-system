#include "ViewMessages.h"
#include <iostream>

using namespace std;

void ViewMessages::successfulLogOut()
{
	cout<<"You are logged out!"<<endl;
}

void ViewMessages::unsuccessfulFileOpening()
{
	cout<<"Can't open a file :-("<<endl;
}

void ViewMessages::successfulProfileDelete()
{
	cout<<"Your profile is deleted!"<<endl;
}

void ViewMessages::cannotOpenFileToAddToApplication()
{
	cout<<"But can not open a file to add to application"<<endl;
}

void ViewMessages::cannotOpenFileToWriteConclusion()
{
	cout<<"Can not open a file with application to write a conclusion"<<endl;
}

void ViewMessages::cannotOpenFileToWriteSumUp()
{
	cout<<"Can not open a file with application to write a sum up";
}

void ViewMessages::applicationIsCorrect()
{
	cout<<"Your application is correct!"<<endl;
}

void ViewMessages::registrationIsCorrect()
{
	cout<<"Your registration is correct!"<<endl;
}

void ViewMessages::requestIsCorrect()
{
	cout<<"Yout request is correct!"<<endl;
}

void ViewMessages::successfulEdit()
{
	cout <<"Successfully edited!" << endl;
}

void ViewMessages::notconfirmed()
{
	cout << "verification not confirmed" << endl;
}
