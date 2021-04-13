#pragma once
#include <iostream>
class AccountManagement
{
	static void editLogin(int ID);
	static void editPassword(int ID);
	static void editName(int ID);
	static void editEmail(int ID);
	static bool confirmation(int ID, std::string& login, std::string& password);
public:
	static int enterToProfile(std::string login, std::string password);
	static void exitFromProfile(int ID);
	static void deleteProfile(int ID, int type);
	static void registerProfile(int);
	static void editProfile(int ID);
};

