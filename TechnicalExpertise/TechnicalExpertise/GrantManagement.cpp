#include "GrantManagement.h"
#include "FileReader.h"
#include "ViewInteraction.h"
#include "FileWriter.h"
#include "ViewMessages.h"
#include "Validation.h"
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
	string money;
	float sum;
	do
	{
		ViewInteraction::inputValue("How much money are you transfering?",money);
	}
	while (!Validation::MoneyCheck(money));
	ifstream inFile2(pathToProfileBalance);
	inFile2 >> sum;
	inFile2.close();
	FileWriter::writeMoney(pathToProfileBalance, money, sum);
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
		ViewInteraction::inputValue("Input your card number:",card);
	} 
	while (!Validation::CardCheck(card));
	do
	{
		ViewInteraction::inputValue("How much money are you transfering?", money);
	} 
	while (!Validation::AmountOfMoneyCheck(money, dif));
	FileWriter::writeDifMoney(pathToProfileBalance, money, dif);
	ViewMessages::successfulTransfer();
}