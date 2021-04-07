#include "ExpertComission.h"
#include <filesystem>
#include <iostream>
#include <vector>

#include "WorkWithInterface.h"

using namespace std;

ExpertComission::ExpertComission(Profile currentProfile)
{
	profileID=currentProfile.getID();
	name=currentProfile.getName();
	email=currentProfile.getEmail();
	password=currentProfile.getPassword();
	login=currentProfile.getLogin();
	typefUser=currentProfile.getType();
	Balance=currentProfile.getBalance();
}

void ExpertComission::viewApplicationAndEvaluate()
{
	int numberOfApplication=-1;
	do{
		vector <vector<string>> applicationNames(2);
		int counter=0;
		for (const auto & entry : filesystem::recursive_directory_iterator("Database/Applications"))
		{
			if((entry.path().extension()==".txt")&&(entry.path().filename().string().find("[checked]")==string::npos)&&
				(entry.path().filename().string().find("[Paid]")==string::npos)&&(entry.path().filename().string().find("[NotPaid]")==string::npos))
			{
				applicationNames[0].push_back(entry.path().filename().string());
				applicationNames[1].push_back(entry.path().string());
				cout<<applicationNames[0].back()<<"("<<counter<<")"<<endl;
				counter++;
			}
		}
		cout<<"Choose application or enter -1 to quit"<<endl;
		cin>>numberOfApplication;
		if(numberOfApplication!=-1){
			printFileData(applicationNames[1][numberOfApplication]);
			createReview(applicationNames[1][numberOfApplication], applicationNames[0][numberOfApplication]);
		}
	}while(numberOfApplication!=-1);
}
