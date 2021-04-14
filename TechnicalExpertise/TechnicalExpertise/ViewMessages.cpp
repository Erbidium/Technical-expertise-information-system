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
void ViewMessages::successfulTransfer()
{
	cout << endl << "Successfully transfered!" << endl;
}
void ViewMessages::unsuccsessfulLogIn() {
	cout << "Entered incorrect login or password\n";
}
void ViewMessages::succsessfulLogIn() {
	cout << "Succesfully logined!" << endl;
}

void ViewMessages::successfulEdit()
{
	cout <<"Successfully edited!" << endl;
}

void ViewMessages::notConfirmed()
{
	cout << "verification not confirmed." << endl;
}

void ViewMessages::LoginTaken()
{
	cout << "This login is already taken." << endl;
}

void ViewMessages::verificationConfirmed()
{
	cout << "verification confirmed!" << endl;
}