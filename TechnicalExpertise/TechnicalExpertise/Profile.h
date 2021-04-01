#pragma once
#include <string>

using namespace std;

class Profile
{
public:
	Profile(){}
	Profile(string, string, string, string, int, int, float);
	string getName()const;
	string getEmail()const;
	string getPassword()const;
	string getLogin()const;
	int getType();
	int getID();
	void setName(const string&);
	void setEmail(const string&);
	void setType(int);
	void setBalance(float);
	float getBalance();
private:
	int profileID;
	string name;
	string email;
	string password;
	string login;
	int typefUser;
	float Balance;
};
