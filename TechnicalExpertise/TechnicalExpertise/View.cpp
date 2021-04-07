#include "View.h"
#include <iostream>
#include "Profile.h"
using namespace std;
Profile View::createProfile(int profileID, int type)
{
	string login, password, name, email;
	cout << "Enter your login:\n";
	cin >> login;
	cout << "Enter your password:\n";
	cin >> password;
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your email:\n";
	cin >> email;
	Profile newProfile(name, email, login, password, profileID, type, 0);
	return newProfile;
}
void View::inputNameEmail(string& name, string& email) {
	cout << "Enter your name:\n";
	cin >> name;
	cout << "Enter your email:\n";
	cin >> email;
}