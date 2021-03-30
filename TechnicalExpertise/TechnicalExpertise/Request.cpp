#include "Request.h"

string Request::getName() const
{
	return name;
}

string Request::getEmail() const
{
	return email;
}

string Request::getContent() const
{
	return requestContent;
}

void Request::setEmail(const string& email)
{
	this->email=email;
}

void Request::setName(const string& name)
{
	this->name=name;
}

void Request::setContent(const string& requestContent)
{
	this->requestContent=requestContent;
}
