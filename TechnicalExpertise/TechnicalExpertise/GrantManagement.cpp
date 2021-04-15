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
	string money;
	do
	{
		ViewInteraction::inputValue("How much money are you transfering?",money);
	}
	while (!Validation::MoneyCheck(money));
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID) + ".txt";
	float sum=FileReader::readMoney(ID);
	FileWriter::writeMoney(pathToProfileBalance, money, sum);
}

void GrantManagement::transferToBank(int ID)
{
	float currentMoney=FileReader::readMoney(ID);
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
	while (!Validation::AmountOfMoneyCheck(money, currentMoney));
	string pathToProfileBalance = "Database/ProfilesBalance/" + to_string(ID) + ".txt";
	FileWriter::writeDifMoney(pathToProfileBalance, money, currentMoney);
	ViewInteraction::clearScreen();
	ViewMessages::successfulTransfer();
}