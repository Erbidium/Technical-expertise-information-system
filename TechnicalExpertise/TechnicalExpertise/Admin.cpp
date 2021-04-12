#include "Admin.h"
#include <vector>
#include "AccountManagement.h"
#include "View.h"

using namespace std;

void Admin::viewRequests()
{
	View::showRequests();
}

void Admin::registerProfile()
{
	int accountType = View::inputAccTypeForRegistration();
	AccountManagement::registerProfile(accountType+1);
}

