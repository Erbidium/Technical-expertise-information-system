#pragma once
#include <string>
using namespace std;

class FileReader
{
public:
	static int readID(std::string login, std::string password);
	static float readMoney(int ID);
	static void readLoginAndPassword(int ID, string &login, string &password);
};

