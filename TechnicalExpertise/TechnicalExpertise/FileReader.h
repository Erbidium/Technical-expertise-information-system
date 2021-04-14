#pragma once
#include <string>
#include "Profile.h"

class FileReader
{
public:
	static int readID(std::string login, std::string password);
	static float readMoney(int ID);
	static void readLoginAndPassword(int ID, std::string &login, std::string &password);
	static void readAndPrintFileData(std::string name);
	static Profile readProfile(int ID);
	static bool readCheckID(int ID);
	static bool readCheckLogin(std::string login);
};

