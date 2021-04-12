#include "GrantManagement.h"
#include "FileReader.h"
#include "ViewInteraction.h"
#include <iostream>
#include <fstream>

using namespace std;

float GrantManagement::getMoney(int ID)
{
	float money=FileReader::readMoney(ID);
	return money;
}

void GrantManagement::transferMoney(int ID)
{
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID) + ".txt";
	string money = "-1";
	float sum;
	while (stof(money) < 0)
	{
		ViewInteraction::inputAmountOfMoney(money);
		for (int i = 0; i < money.length(); i++)
		{
			if (!((money[i] >= 48 && money[i] <= 57) || money[i] == '.'))
			{
				money = "-1";
			}
		}
		if (stof(money) < 0)
		{
			cout << endl << "You entered wrong amount of money! Please, try again." << endl;
		}
	}
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
	ifstream inFile2(pathToProfileBalance);
	string money = "-1";
	float dif;
	inFile2 >> dif;
	inFile2.close();
	string card = "-1";
	while (stof(card) <= 0)
	{
		ViewInteraction::inputCardNumber(card);
		if (card.length() != 16)
		{
			cout << endl << "Card number is too short or too long!" << endl;
			card = "0";
		}
		for (int i = 0; i < card.length(); i++)
		{
			if (card[i] < 48 || card[i] > 57)
			{
				cout << endl << "You entered wrong card number! Please try again!" << endl;
				card = "-1";
			}
		}

	}
	while (stof(money) < 0)
	{
		ViewInteraction::inputAmountOfMoney(money);
		for (int i = 0; i < money.length(); i++)
		{
			if (!((money[i] >= 48 && money[i] <= 57) || money[i] == '.'))
			{
				money = "-1";
			}
		}
		if (stof(money) < 0)
		{
			cout << endl << "You entered wrong amount of money! Please, try again." << endl;
			money = "-1";
		}
		if (stof(money) > dif)
		{
			cout << endl << "You don't have that much money on your account! Please try again!" << endl;
			money = "-1";
		}
		else {
			cout << endl << "Successfully transfered!" << endl;
		}
	}
	ofstream outFile2(pathToProfileBalance);
	outFile2 << dif - stof(money);
	outFile2.close();
}