#include <stdio.h>
#include <string>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

#include <direct.h>
#include <Windows.h>
#include "DynArray.h"

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
		else if (strings[i].size() > 1)
		{
			if (strings[i][0] == '-')
			{
				char tempC = strings[i][1];
				MapcharString[tempC] = "_log";
			}
		}
	}
	return MapcharString;

}

set<char> parseArgsFlags(int argc, char * argv[])
{
	vector<string>strings;
	set<char> SetChar;

	for (int i = 0; i < argc; i++)
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
		cout << *i << endl;
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
/*	cout << "" << endl;
	cout << "Parse argv" << endl;
	cout << "------------\n" << endl;
	parseArgv(argc, argv);

	cout << "Parse argv Flags" << endl;
	cout << "------------------\n" << endl;
	parseArgsFlags(argc, argv);*/

	cout << "Parse argv Values" << endl;
	cout << "-------------------\n" << endl;
	map <char, string> flags = parseArgsValues(argc, argv);

	char flag = flags.begin()->first;
	string file = flags.begin()->second;

	DynArray<int> potato(flag, file);
	potato.push_back(5);
	potato.push_back(5);
	potato.push_back(5);
	potato.push_back(5);
	cout << potato.size() << endl;

	potato.get(4);

	//string path = "\\\\nasstudusers\\6$\\N0562762\\Year Two\\Software Design  & Implementation\\Coursework 1\\Log_Class\\Log_Class\\potath";

	//wstring stemp = wstring(path.begin(), path.end());
	//LPCWSTR sw = stemp.c_str();

	//CreateDirectory(sw, NULL);
	

		


	





























	/*char choice;
	cout << "Would you like to see an example of the PRO FUNCTIONALITY? -";
	cin >> choice;

	if (choice = 'y'){
		///////////////////////////////////////////////////
		////////////[PRO FUNCTIONALITY]////////////////////
		///////////////////////////////////////////////////

		cout << "\n//////////CREATE ARRAY PUT////////" << endl;
		DynArray<int>Put;
		cout << "Capacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();

		cout << "\n\n//////////PUSH BACK 10////////" << endl;
		for (int i = 0; i <= 10; i++){
			Put.push_back(i);
			cout << Put.back() << " ";
		}
		cout << "\n";
		Put.ShowAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;

		cout << "\n\n//////////POP BACK ONE////////" << endl;
		Put.pop_back();
		Put.ShowAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;

		cout << "\n\n//////////POP BACK ONE////////" << endl;
		Put.pop_back();
		Put.ShowAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;

		cout << "\n\n//////////GET INDEX 5////////" << endl;
		cout << Put.get(5);

		cout << "\n\n//////////SET////////" << endl;
		cout << "Set Index 5 to 97" << endl;
		Put.set(97, 5);
		Put.ShowAll();

		cout << "\n\n//////////GET INDEX 5////////" << endl;

		cout << Put.get(5);

		cout << "\n\n//////////ZAP////////" << endl;
		Put.zap();
		Put.ShowAll();
		cout << "\nCapacity - " << Put.capacity();
		cout << "\nSize - " << Put.size();
		cout << "\nFront - " << Put.front();
		cout << "\nBack - " << Put.back();
		cout << "\nEmpty? " << (Put.empty() ? "Yes" : "No") << endl;

		//delete[] Put;
		cout << "Would you like to see an example of the PREMIUM FUNCTIONALITY? -";
		cin >> choice;
		if (choice = 'y'){
			///////////////////////////////////////////////////////
			//////////////[PREMIUM FUNCTIONALITY]//////////////////
			///////////////////////////////////////////////////////

			cout << "\n//////////CREATE ARRAY HOME////////" << endl;
			DynArray<int>home;
			cout << "\n\n//////////PUSH BACK 10////////" << endl;
			for (int i = 0; i <= 10; i++){
				home.push_back(i);
				cout << home.back() << " ";
			}
			cout << "\n";
			home.ShowAll();
			cout << "\nCapacity - " << home.capacity();
			cout << "\nSize - " << home.size();

			cout << "\n\n//////////REMOVE ITEM NUMBER 7////////" << endl;
			home.Remove(7);
			home.ShowAll();
			cout << "Capacity - " << home.capacity();
			cout << "\nSize - " << home.size();

			cout << "\n\n//////////INSERT ITEM 78 into index 3////////" << endl;
			home.Insert(78, 3);
			home.ShowAll();
			cout << "Capacity - " << home.capacity();
			cout << "\nSize - " << home.size();


			cout << "\n//////////CREATE ARRAY HOPE(HOME)////////" << endl;
			DynArray<int>hope(home);
			cout << "\n";
			hope.ShowAll();
			cout << "\nCapacity - " << hope.capacity();
			cout << "\nSize - " << hope.size();

			cout << "\n//////////SHRINK////////" << endl;
			hope.pop_back();
			hope.pop_back();
			hope.Shrink();
			hope.ShowAll();
			cout << "\nCapacity - " << hope.capacity();
			cout << "\nSize - " << hope.size();

			cout << "\n//////////CREATE ARRAY////////" << endl;
			DynArray<int>hope2;
			cout << "\n//////////OPERATOR = HOPE////////" << endl;
			hope2 = hope;
			cout << "\n";
			hope2.ShowAll();
			cout << "\nCapacity - " << hope2.capacity();
			cout << "\nSize - " << hope2.size();

			cout << "\n////////////////OPERATOR == HOPE/////////////////" << endl;
			cout << "//////No Shrink////" << endl;
			cout << (hope2 == hope ? "Same" : "Different") << endl;
			hope2.push_back(5);
			cout << "//////With PUSH_BACK 5////" << endl;
			cout << (hope2 == hope ? "Same" : "Different") << endl;

			cout << "Would you like to see an example of the ULTIMATE FUNCTIONALITY? -";
			cin >> choice;
			if (choice = 'y'){
				/////////////////////////////////////////////////////////////////
				//////////////////[ULTIMATE FUNCTIONALITIES]/////////////////////
				/////////////////////////////////////////////////////////////////

				cout << "\n\n\n//////////CREATE ARRAY ULTIMATE////////" << endl;
				DynArray<int>ultimate;
				cout << "\n//////////PUSH BACK 10////////" << endl;
				for (int i = 0; i <= 10; i++){
					ultimate.push_back(i);
					cout << ultimate.back() << " ";
				}
				cout << "\n";
				ultimate.ShowAll();

				cout << "\n//////////INSERT FRONT 57////////" << endl;
				ultimate.InsertFront(57);
				ultimate.ShowAll();

				cout << "\n//////////REMOVE FRONT////////" << endl;
				ultimate.RemoveFront();
				ultimate.ShowAll();

				cout << "\n\n\n//////////CREATE ARRAY ULTIMATE2////////" << endl;
				DynArray<int>ultimate2;
				cout << "\n//////////PUSH BACK 3////////" << endl;
				for (int i = 0; i <= 3; i++){
					ultimate2.push_back(i + 10);
				}
				cout << "\n";
				ultimate2.ShowAll();
				cout << "\nCapacity - " << ultimate2.capacity();
				cout << "\nSize - " << ultimate2.size();

				cout << "\n//////////operator+= ULTIMATE////////" << endl;
				ultimate2 += ultimate;
				ultimate2.ShowAll();
				cout << "\nCapacity - " << ultimate2.capacity();
				cout << "\nSize - " << ultimate2.size();

				cout << "\n\n//////////operator[9]////////" << endl;
				cout << ultimate2[9] << endl;
				ultimate2.ShowAll();

				cout << "\n\n//////////operator[9] = 44////////" << endl;
				ultimate2[9] = 44;
				ultimate2.ShowAll();
			}
		}
	}*/
}