#include <iostream>
#include <ctime>
#include  "SiteInterface.h"

using namespace std;

int main()
{
	srand(time(NULL));
	SiteInterface::showMenu();
}