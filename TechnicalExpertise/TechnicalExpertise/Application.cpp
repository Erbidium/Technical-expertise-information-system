#include "Application.h"

string Application::getName()const
{
	return ownerName;
}

int Application::getAge()const
{
	return ownerAge;
}

string Application::getContent()const
{
	return applicationContent;
}

string Application::getDate()const
{
	return applicationDate;
}

string Application::getReview() const
{
	return comissionReview;
}

bool Application::getGrantConfirm()const
{
	return grantIsConfirmed;
}
string Application::getFilePath()const
{
	return filePath;
}


void Application::setName(const string & ownerName)
{
	this->ownerName=ownerName;
}

void Application::setAge(const int& ownerAge)
{
	this->ownerAge=ownerAge;
}

void Application::setContent(const string& applicationContent)
{
	this->applicationContent=applicationContent;
}

void Application::setGrantConfirm(bool grantIsConfirmed)
{
	this->grantIsConfirmed=grantIsConfirmed;
}

void Application::setReview(const string& comissionReview)
{
	this->comissionReview=comissionReview;
}
void Application::setFilePath(const string& filePath)
{
	this-> filePath= filePath;
}
