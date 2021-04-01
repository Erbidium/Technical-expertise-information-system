#include "GrantManagement.h"
#include <iostream>
#include <fstream>
using namespace std;

float GrantManagement::getMoney(int ID)
{
	string pathToProfileBalance = "Database/ProfilesBalance/";
	ifstream infile(pathToProfileBalance);
	float money;
	infile >> money;
	return money;
}

void GrantManagement::transferMoney(int ID)
{
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID);
	ofstream outFile2(pathToProfileBalance);
	float money;
	cout << endl << "How much money are you transfering?" << endl;
	cin >> money;
	outFile2 << money;
	outFile2.close();
}
