#include <iostream>
#include <ctime>
#include <filesystem>
#include <string>
#include <sys\stat.h>
#include  "SiteInterface.h"
using namespace std;
//namespace fs = filesystem;
int main()
{
	srand(time(NULL));
	struct stat buf;
	string filerep[5] = {"Database","Database/Applications","Database/Profiles","Database/Requests"};
	for (int i = 0; i < 5; i++)
	{
		if ((stat(filerep[i].data(), &buf))!= 0)
		{
			mkdir(filerep[i].data());
		}
	}
	//fs::create_directory("Database");
	//fs::create_directory("Database/Applications");
	//fs::create_directory("Database/Profiles");
	//fs::create_directory("Database/Requests");
	SiteInterface::showMenu();
}