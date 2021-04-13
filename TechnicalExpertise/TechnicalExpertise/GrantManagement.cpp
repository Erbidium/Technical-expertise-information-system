#include "GrantManagement.h"
#include <iostream>
#include <fstream>
#include "View.h"
#include "Validation.h"
using namespace std;

float GrantManagement::getMoney(int ID)
{
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID) + ".txt";
	ifstream infile(pathToProfileBalance);
	float money;
	infile >> money;
	return money;
}

void GrantManagement::transferMoney(int ID)
{
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID) + ".txt";
	string money;
	float sum;
	do
	{
		View::inputAmountOfMoney(money);
	}
	while (Validation::MoneyCheck(money));
	ifstream inFile2(pathToProfileBalance);
	inFile2 >> sum;
	inFile2.close();
	ofstream outFile2(pathToProfileBalance);
	outFile2 << sum + stof(money);
	outFile2.close();
}

void GrantManagement::transferToBank(int ID)
{
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID) + ".txt";
	float dif;
	ifstream inFile2(pathToProfileBalance);
	inFile2 >> dif;
	inFile2.close();
	string money;
	string card;
	do
	{
		View::inputCardNumber(card);
	} 
	while (!Validation::CardCheck(card));
	do
	{
		View::inputAmountOfMoney(money);
	} 
	while (!Validation::AmountOfMoneyCheck(money, dif));
	ofstream outFile2(pathToProfileBalance);
	outFile2 << dif - stof(money);
	outFile2.close();
	cout << endl << "Successfully transfered!" << endl;
}