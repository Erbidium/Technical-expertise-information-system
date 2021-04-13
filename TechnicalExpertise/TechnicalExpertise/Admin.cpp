#include "Admin.h"
#include "AccountManagement.h"
#include "ViewInteraction.h"

using namespace std;

void Admin::viewRequests()
{
	ViewInteraction::showRequests();
}

void Admin::registerProfile()
{
	int accountType = ViewInteraction::inputAccTypeForRegistration();
	AccountManagement::registerProfile(accountType+1);
}

