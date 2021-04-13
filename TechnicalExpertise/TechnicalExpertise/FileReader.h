#pragma once
#include <string>
#include "Profile.h"

class FileReader
{
public:
	static int readID(std::string login, std::string password);
	static float readMoney(int ID);
	static void readAndPrintFileData(std::string name);
	static Profile readProfile(int ID);
};

