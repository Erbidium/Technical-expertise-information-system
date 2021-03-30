#pragma once
#include "Profile.h"

class ApplyTheRegistration
{
public:
	void profileManager();
	void profileDataCheck();
	void setProfile(Profile);
private:
	Profile profileData;
	bool profileConfirmation;
};

