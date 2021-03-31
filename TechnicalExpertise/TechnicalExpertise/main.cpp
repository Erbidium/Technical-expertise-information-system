#include <iostream>
#include <ctime>
#include <filesystem>
#include <string>
#include  "SiteInterface.h"

using namespace std;
namespace fs = filesystem;
int main()
{
	srand(time(NULL));
	fs::create_directory("Database");
	fs::create_directory("Database/Applications");
	fs::create_directory("Database/Profiles");
	fs::create_directory("Database/Requests");
	SiteInterface::showMenu();
}