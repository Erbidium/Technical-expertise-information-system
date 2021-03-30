#include "Profile.h"

string Profile::getName() const
{
	return name;
}

string Profile::getEmail() const
{
	return email;
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

void Profile::setType(int profileID)
{
	this->profileID=profileID;
}
