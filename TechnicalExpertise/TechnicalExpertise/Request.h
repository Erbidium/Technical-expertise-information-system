#pragma once
#include <string>

using namespace std;

class Request
{
public:
	string getName()const;
	string getEmail()const;
	string getContent()const;
	void setName(const string&);
	void setEmail(const string&);
	void setContent(const string&);
private:
	string name;
	string email;
	string requestContent;
};
