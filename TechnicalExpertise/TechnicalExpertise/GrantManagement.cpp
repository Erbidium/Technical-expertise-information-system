#include "GrantManagement.h"
#include "FileReader.h"
#include "ViewInteraction.h"
#include <iostream>
#include <fstream>

#include "FileWriter.h"
#include "ViewInteraction.h"
#include "ViewMessages.h"
#include "Validation.h"
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
		ViewInteraction::inputAmountOfMoney(money);
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
		ViewInteraction::inputCardNumber(card);
	} 
	while (!Validation::CardCheck(card));
	do
	{
		ViewInteraction::inputAmountOfMoney(money);
	} 
	while (!Validation::AmountOfMoneyCheck(money, dif));
	FileWriter::writeDifMoney(pathToProfileBalance, money, dif);
	ViewMessages::successfulTransfer();
}