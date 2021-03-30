#pragma once
#include <string>

using namespace std;

class GrantManagement
{
public:
	void setBill(string);
	void transferMoney(int ID);
private:
	string bill;
};

