#include <ctime>
#include <filesystem>
#include <string>
#include  "SiteInterface.h"

using namespace std;
namespace fs = filesystem;

int main()
{
	srand(time(NULL));
	string fileNames[4] = {"Database","Database/Applications","Database/Profiles","Database/Requests"};
	for (int i = 0; i < 4; i++)
	{
		if (fs::is_directory(fileNames[i])==false)
		{
			fs::create_directory(fileNames[i]);
		}
	}
	SiteInterface::showMenu();
}