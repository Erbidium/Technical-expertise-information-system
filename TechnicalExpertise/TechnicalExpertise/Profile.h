#pragma once
#include <string>

using namespace std;

class Profile
{
public:
	string getName()const;
	string getEmail()const;
	int getType();
	int getID();
	void setName(const string&);
	void setEmail(const string&);
	void setType(int);
private:
	string name;
	string email;
	int typefUser;
	int profileID;
};
