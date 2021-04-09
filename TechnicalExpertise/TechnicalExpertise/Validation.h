#include <iostream>
#include <string>
#include <fstream>
#pragma once
using namespace std;

class Validation
{
public:
	static bool EmailCheck(string email);
	static bool NameCheck(string name, string str);
	static bool LoginCheck(string login);
	static bool PasswordCheck(string password);
	static bool DataEmptyCheck(string data,string str);
};