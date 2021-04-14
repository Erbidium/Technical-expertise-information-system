#pragma once
#include <string>

using namespace std;

class Application
{
public:
	string getName()const;
	int getAge()const;
	string getContent()const;
	string getDate()const;
	string getReview()const;
	string getFilePath()const;
	bool getGrantConfirm()const;
	string getLink()const;
	void setName(const string&);
	void setAge(const int&);
	void setContent(const string&);
	void setDate(const string&);
	void setGrantConfirm(bool);
	void setReview(const string&);
	void setFilePath(const string&);
	void setLink(const string& link);
private:
	string ownerName;
	int ownerAge;
	string applicationContent;
	string applicationDate;
	bool grantIsConfirmed;
	string comissionReview;
	string filePath;
	string link;
	string date;
};

