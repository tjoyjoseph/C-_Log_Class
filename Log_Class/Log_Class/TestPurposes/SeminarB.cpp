#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

#include "DynArray.h"

using namespace std;


int main(int argc, char* argv[])
{
	char choice;
	cout << "Would you like to see an example of the PRO FUNCTIONALITY? -";
	cin >> choice;

	std::vector<int> myVector;
	//myVector.push_back(10);
	//std::cout << myVector[100];
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
			cout << "\/////No Shrink////" << endl;
			cout << (hope2 == hope ? "Same" : "Different") << endl;
			hope2.push_back(5);
			cout << "\/////With PUSH_BACK 5////" << endl;
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
	}

}


