#include "Profile.h"

Profile::Profile(string name, string email, string login, string password, int ID, int type, float balance):
name(name), email(email), profileID(ID), typefUser(type),login(login), password(password), Balance(balance)
{}

string Profile::getName() const
{
	return name;
}

string Profile::getEmail() const
{
	return email;
}

string Profile::getLogin() const
{
	return login;
}

string Profile::getPassword() const
{
	return password;
}

int Profile::getType()
{
	return typefUser;
}

int Profile::getID()
{
	return profileID;
}

void Profile::setName(const string& name)
{
	this->name=name;
}

void Profile::setEmail(const string& email)
{
	this->email=email;
}

void Profile::setType(int type)
{
	this->typefUser=type;
}

void Profile::setBalance(float money)
{
	this->Balance += money;
}

float Profile::getBalance()
{
	return this->Balance;
}