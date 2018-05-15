#include <vector>
#include <map>

//#include <stdio.h>
//#include <string>
//#include <iostream>

#include "DynArray.h"

//using namespace std;


map<char, string> parseArgsValues(int argc, char * argv[])
{
	vector<string>tmpStr;
	map<char, string> _FlagnValues;
	char flag;

	///places command line into a vector of words 
	for (int i = 0; i < argc; i++)
	{
		tmpStr.push_back(string(argv[i]));
	}

	///picks out the flags and the text
	if (tmpStr[1][0] == '-')
	{
		flag = tmpStr[1][1];
#ifdef _DEBUG
		clog << "Flag: " << flag << endl;
#endif 
		if (tmpStr[1].size() > 2)
		{
			string values;
			for (size_t m = 3; m < tmpStr[1].size(); m++)
			{
				values += tmpStr[1][m];
			}
			_FlagnValues[flag] = values;
		}
		else if (tmpStr[1].size() > 1)
		{
#ifdef _DEBUG
			clog << "No output file name has been defineD. Default name applied" << endl;
#endif 
			_FlagnValues[flag] = "_log";
		}
#ifdef _DEBUG
		clog << "Flag\tOutput File name" << endl;
		clog << flag << "\t" << _FlagnValues[flag] << endl;
#endif
	}
	return _FlagnValues;
}

int main(int argc, char* argv[])
{
	map <char, string> flag_Val = parseArgsValues(argc, argv);
	
	char flag = flag_Val.begin()->first;
	string fileName = flag_Val.begin()->second;

	cout << "Creating Dynamic Array bunchOfNums" << endl;
	DynArray<int> bunchOfNums(flag, fileName);

	cout << "\nPush Back 4 items" << endl;
	bunchOfNums.push_back(5);
	bunchOfNums.push_back(5);
	bunchOfNums.push_back(5);
	bunchOfNums.push_back(5);

	cout << "\nSize" << endl;
	cout << bunchOfNums.size() << endl;

	cout << "\nGet 4 : out of index" << endl;
	bunchOfNums.get(4);
	cout << "\nGet 3 : in index" << endl;
	bunchOfNums.get(3);

	cout << "\nset index 4 as 9 :  out of index" << endl;
	bunchOfNums.set(9, 4);
	cout << "\nset index 3 as 9 :  in of index" << endl;
	bunchOfNums.set(9, 3);

	cout << "\nremove 5 : out of index" << endl;
	bunchOfNums.remove(5);
	cout << "\nremove 3 : in of index" << endl;
	bunchOfNums.remove(3);

	cout << "\nPop Back" << endl;
	bunchOfNums.pop_back();

	cout << "\nPush Back 3 items" << endl;
	bunchOfNums.push_back(3);
	bunchOfNums.push_back(3);
	bunchOfNums.push_back(3);

	cout << "\nzap" << endl;
	bunchOfNums.zap();

}