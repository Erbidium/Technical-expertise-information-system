#pragma once
#include <string>

class Profile
{
public:
	Profile(){}
	Profile(std::string, std::string, std::string, std::string, int, int, float);
	std::string getName()const;
	std::string getEmail()const;
	std::string getPassword()const;
	std::string getLogin()const;
	int getType();
	int getID();
	void setName(const std::string&);
	void setEmail(const std::string&);
	void setType(int);
	void setID(int);
	void setBalance(float);
	float getBalance();
protected:
	int profileID;
	std::string name;
	std::string email;
	std::string password;
	std::string login;
	int typefUser;
	float Balance;
};
