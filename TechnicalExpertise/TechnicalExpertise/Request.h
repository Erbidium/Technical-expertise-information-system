#pragma once
#include <string>

class Request
{
public:
	std::string getName()const;
	std::string getEmail()const;
	std::string getContent()const;
	void setName(const std::string&);
	void setEmail(const std::string&);
	void setContent(const std::string&);
private:
	std::string name;
	std::string email;
	std::string requestContent;
};

