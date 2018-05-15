#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>


#include <string>
#include <fstream>


using namespace std;

vector<string> readTextFile()
{
#ifdef _DEBUG
	clog << "In function readfTextFile();" << endl;
#endif // _DEBUG
	vector <string> convstr;

	string setOf;

	ifstream InFile;
	InFile.open("\\\\nasstudusers\\6$\\N0562762\\Year Two\\Software Design  & Implementation\\SeminarA\\SeminarA\\SeminarA.txt");
	if (InFile.fail())
	{
		cerr << "File Not Found!" << endl;
	}
	else{
		while (!InFile.eof())
		{
			//InFile >> setOf;
			getline(InFile, setOf);
			if (!(setOf == "")){
				convstr.push_back(setOf);
			}
		}
	}

	InFile.close();


	return convstr;

}

int main(int argc, char* argv[])
{
	vector<string> textFile;

	ofstream OutFile;
	OutFile.open("\\\\nasstudusers\\6$\\N0562762\\Year Two\\Software Design  & Implementation\\SeminarA\\SeminarA\\SeminarA.txt");
	OutFile.close();


	textFile = readTextFile();

	if (textFile.size() == 0)
	{
		cout << "No items in file" << endl;

	}

	OutFile.open("\\\\nasstudusers\\6$\\N0562762\\Year Two\\Software Design  & Implementation\\SeminarA\\SeminarA\\SeminarA.txt");

	OutFile << "Potataoes are carrots too" <<  endl;
	OutFile << "But, Carrots are not potataoes" << endl;
	OutFile.close();

	textFile = readTextFile();

	if (textFile.size() == 0)
	{
		cout << "No items in file" << endl;
		
	}
	else
	{
		cout << textFile.size() << endl;
		string pot;
	//	cin >> pot;
	}


	return 0;
}
