#include <fstream>
#include "ApplyTheRequest.h"
#include "View.h"
using namespace std;

void ApplyTheRequest::setRequest()
{
	requestData = View::createRequest();
	requestDataCheck();
}

void ApplyTheRequest::requestManager()
{
	ofstream outFile("Database/Requests/" + requestData.getName() + ".txt");
	outFile << "My name: " << requestData.getName() << endl;
	outFile << "My email: " << requestData.getEmail() << endl;
	outFile << "Request Content: " << requestData.getContent() << endl;
	outFile.close();
}

void ApplyTheRequest::requestDataCheck()
{
	bool correct = true;
	string name = requestData.getName();
	if (name.empty())
	{
		cout << endl << "Your name is epmty." << endl;
		correct = false;
	}
	for (int i = 0; i < name.length(); i++ )
	{
		if(!((name[i]>= 65 && name[i] <= 90)||(name[i]>=97 && name[i]<=122)))
		{
			cout << endl << "Your name has been writen wrong or at different language." << endl;
			correct = false;
			i = name.length();
		}
	}
	string email = requestData.getEmail();
	int count = 0;
	for (int i = 0; i < email.length(); i++ )
	{
		if(email[i] == '@')
		{
			count++;
		}
	}
	if(count != 1)
	{
		cout << endl << "Your email either have too many or no @ symbol at all." << endl;
		correct = false;
	}
	string Content = requestData.getContent();
	if (Content.empty())
	{
		cout << endl << "Your Request is epmty." << endl;
		correct = false;
	}
	if (correct)
	{
		system("cls");
		cout << "Yout request is correct!" << endl;
		requestManager();
	}
	else
	{
		bool leave = View::checkIfYouWannaRewrite("request");
		if(!leave)
		{
			setRequest();
		}
		else
		{
			system("cls");
		}
	}
}
