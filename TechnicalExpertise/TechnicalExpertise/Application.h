#pragma once
#include <string>

using namespace std;
class Application
{
public:
	string getName();
	int getAge();
	string getContent();
	string getDate();
	bool getGrantConfirm();
	void setName(string);
	void setAge(int);
	void setContent(string);
	void setDate(string);
	void setGrantConfirm(bool);
	void setReview(string);
private:
	string ownerName;
	int ownerAge;
	string applicationContent;
	string applicationDate;
	bool grantIsConfirmed;
	string comissionReview;
};

