#include "Admin.h"
#include <iostream>
#include <vector>
#include <filesystem>
#include "AccountManagement.h"
#include "WorkWithInterface.h"
#include "View.h"

using namespace std;

void Admin::viewRequests()
{
	cout<<"All requests:"<<endl;
	vector <string> files;
	int counter=0;
	for (const auto & entry : filesystem::directory_iterator("Database/Requests"))
	{
		if(entry.path().extension()==".txt")
		{
			files.push_back(entry.path().filename().string());
			cout<<files.back()<<"("<<counter<<")"<<endl;
		}
		counter++;
	}
	int numberOfRequest=-1;
	do{
		cout<<"Choose request or enter -1 to quit"<<endl;
		cin>>numberOfRequest;
		if(numberOfRequest!=-1){
				printFileData("Database/Requests/"+files[numberOfRequest]);		
		}
	}while(numberOfRequest!=-1);
}

void Admin::registerProfile()
{
	int accountType = View::inputAccTypeForRegistration();
	AccountManagement::registerProfile(accountType+1);
}

