#pragma once
#include <string>

using namespace std;

class GrantManagement
{
public:
	static float getMoney(int ID);
	static void transferMoney(int ID);
	static void transferToBank(int ID);
};

