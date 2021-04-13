#include "FileWriter.h"
#include "Request.h"
#include <fstream>
#include <iostream>

using namespace std;

void FileWriter::writeRequestToFile(Request requestData)
{
	ofstream outFile("Database/Requests/" + requestData.getName() + ".txt");
	outFile << "My name: " << requestData.getName() << endl;
	outFile << "My email: " << requestData.getEmail() << endl;
	outFile << "Request Content: " << requestData.getContent() << endl;
	outFile.close();
}
