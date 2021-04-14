#pragma once
#include <string>

class Application
{
public:
	std::string getName()const;
	std::string getAge()const;
	std::string getContent()const;
	std::string getDate()const;
	std::string getReview()const;
	std::string getFilePath()const;
	bool getGrantConfirm()const;
	std::string getLink()const;
	void setName(const std::string&);
	void setAge(const std::string&);
	void setContent(const std::string&);
	void setDate(const std::string&);
	void setGrantConfirm(bool);
	void setReview(const std::string&);
	void setFilePath(const std::string&);
	void setLink(const std::string& link);
private:
	std::string ownerName;
	std::string ownerAge;
	std::string applicationContent;
	std::string applicationDate;
	bool grantIsConfirmed;
	std::string date;
	std::string comissionReview;
	std::string filePath;
	std::string link;
};

