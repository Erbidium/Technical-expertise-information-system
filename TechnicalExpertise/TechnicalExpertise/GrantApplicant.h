#pragma once
#include "Profile.h"

class GrantApplicant:public Profile
{
public:
	GrantApplicant(Profile);
	void createApplication();
	void checkStatusOfApplication();
	void deleteApplication();
	void editApplication();
	void checkBalance();
};
