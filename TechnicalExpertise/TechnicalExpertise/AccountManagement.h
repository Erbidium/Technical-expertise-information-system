#pragma once
#include <iostream>
class AccountManagement
{
public:
	static int enterToProfile(std::string login, std::string password);
	static void exitFromProfile(int ID);
	static void deleteProfile(int ID, int type);
	static void registerProfile(int);
};

