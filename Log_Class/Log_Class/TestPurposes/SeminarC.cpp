#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;




map<char, string> parseArgsValues(int argc, char * argv[]){
	vector<string>strings;
	map<char, string> MapcharString;

	for (int i = 0; i < argc; i++)
	{
		strings.push_back(string(argv[i]));
	}

	for (int i = 0; i < argc; i++)
	{
		if (strings[i].size() > 2)
		{
			if (strings[i][0] == '-')
			{
				//cout << strings[i] << endl;
				char temC = strings[i][1];
			//	cout << temC << endl;
				string temS;
				for (int m = 3; m < strings[i].size(); m++)
				{
					temS += strings[i][m];
					//cout << temS << endl;
				}
				MapcharString[temC] = temS;
				cout << temC << " = " << MapcharString[temC] << endl;
			}
		}
	}
	cout << "" << endl;
	cout << "" << endl;
	return MapcharString;

}

set<char> parseArgsFlags(int argc, char * argv[])
{
	vector<string>strings;
	set<char> SetChar;

	for (int i = 0; i < argc ; i++)
	{
		strings.push_back(string(argv[i]));
	}

	for (int i = 0; i < argc; i++)
	{
		if (strings[i].size() == 2)
		{
			if (strings[i][0] == '-')
			{
				//cout << strings[i] << " ";

				SetChar.insert(strings[i][1]);
			}
		}
	}		
	for (set<char>::iterator i = SetChar.begin(); i != SetChar.end(); i++) {
		cout << *i <<endl;
	}
	cout << "" << endl;
	return SetChar;
}

vector<string> parseArgv(int argc, char * argv[])
{

	vector<string>strings;
	for (int i = 0; i < argc; i++)
	{
		strings.push_back(string(argv[i]));
	}

	for (int i = 0; i <argc; i++)
	{
		cout << strings[i] << " ";
	}
	cout << "" << endl;
	cout << "" << endl;
	return strings;
}

int main(int argc, char* argv[])
{
	cout << "" << endl;
	cout << "Parse argv" << endl;
	cout << "------------\n" << endl;
	parseArgv(argc, argv);

	cout << "Parse argv Flags" << endl;
	cout << "------------------\n" << endl;
	parseArgsFlags(argc, argv);

	cout << "Parse argv Values" << endl;
	cout << "-------------------\n" << endl;
	parseArgsValues(argc, argv);
	




}