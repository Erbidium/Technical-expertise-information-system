#include "Application.h"

using namespace std;

string Application::getName()const
{
	return ownerName;
}

string Application::getAge()const
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
	return this->grantIsConfirmed;
}

string Application::getFilePath()const
{
	return filePath;
}
string Application::getLink()const
{
	return link;
}

void Application::setName(const string & ownerName)
{
	this->ownerName=ownerName;
}

void Application::setAge(const string& ownerAge)
{
	this->ownerAge=ownerAge;
}
void Application::setDate(const string& data)
{
	this->date = data;
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
void Application::setLink(const string& link)
{
	this->link = link;
}