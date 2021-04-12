#pragma once
#include <string>

class FileReader
{
public:
	static int readID(std::string login, std::string password);
	static float readMoney(int ID);
};

