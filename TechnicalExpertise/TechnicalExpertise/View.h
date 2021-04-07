#pragma once
#include <string>


class View {
public:
	static Profile createProfile(int profileID, int type);
	static void inputNameEmail(std::string& name, std::string& email);
};