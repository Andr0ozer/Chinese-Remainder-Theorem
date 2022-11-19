#include <iostream>
#include "mod.h"
#include <vector>
using namespace std;

//Function to see if the gcd of two numbers is 1
bool gcdIsOne(int a, int b);

//Main Function
int main()
{
	while (true)
	{
		//initalize variables
		bool accurate, gcdnot1 = false;
		int conditions, y_input, n_input, n_subI, nproduct = 1, inverse = 0, finalx = 0;
		string input_to_check;
		Mod crtTest;
		vector<Mod> mods;
		vector<int> finalprods;
		crtTest.sety(1);
		
		//Input number of conditions or quit
		cout << "This program is meant to utilize the Chinese Remainder Theorem." << endl << 
			"How many conditions are there? " << "(Enter Q or q to quit)" << endl;
		cin >> conditions;
		while (cin.fail())
		{
			cin.clear();
			
			cin >> input_to_check;
			
			if (input_to_check == "Q" || input_to_check == "q")
			{
				break;
			}
			else
			{
				cout << "Expecting a number as the option!" << endl << "How many conditions are there? " << "(Enter Q or q to quit)" << endl;
				cin >> conditions;
			}
		}
		if (input_to_check == "Q" || input_to_check == "q") 
		{
			break;
		}
		
		//input y and n values for each condition.
		for (int i = 0; i < conditions; i++)
		{
			Mod tempMod;
			cout << "Using the form X = Y(mod N) what is the value of Y? ";
			cin >> y_input;
			tempMod.sety(y_input);
			cout << "Using the form X = Y(mod N) what is the value of N? ";
			cin >> n_input;
			for (int i = 0; i < mods.size(); i++)
			{
				if (!gcdIsOne(n_input, mods[i].getn()))
				{
					gcdnot1 = true;
				}
			}
			while (n_input <= y_input || gcdnot1)
			{
				cout << "**While using the form X = Y(mod N) N must be greater" << endl 
					<< "**Than Y and all values of N must be pairwise coprime." << endl 
					<< "Please input a different value for N: ";
				cin >> n_input;
				for (int i = 0; i < mods.size(); i++)
				{
					if (gcdIsOne(n_input, mods[i].getn()))
					{
						gcdnot1 = false;
					}
				}
			}
			tempMod.setn(n_input);
			mods.push_back(tempMod);			
		}

		//output original conditions
		cout << "Your conditions are:" << endl;
		for(int j = 0; j < mods.size(); j++)
		{
			mods[j].print();
			nproduct = nproduct * mods[j].getn();
		}
		cout << endl << "****************************" << endl << endl;

		//calculating x using the CRT
		for (int j = 0; j < mods.size(); j++)
		{
			n_subI = nproduct / mods[j].getn();
			crtTest.setn(mods[j].getn());

			//finfing inverse for each input
			for(int i = 1; i < mods[j].getn(); i++)
			{
				crtTest.setx(i* n_subI);
				if (crtTest.testmod())
				{
					inverse = i;
				}
			}

			finalprods.push_back(inverse * n_subI * mods[j].gety());
		}

		//reducing final answer
		for (int i = 0; i < finalprods.size(); i++)
		{
			finalx = finalx + finalprods[i];
		}
		finalx = finalx % nproduct;

		//testing for accuracy and outputting
		accurate = true;
		for (int i = 0; i < mods.size(); i++)
		{
			mods[i].setx(finalx);
			if (!mods[i].testmod())
			{
				accurate = false;
			}
		}
		if (accurate)
		{			
			for (int i = 0; i < mods.size(); i++)
			{
				mods[i].print();
			}
			cout << endl << "Your X value is: " << finalx << endl << endl;
		}
	}
	cout << "Thank you for using my Chinese Remainder Theorem program!" << endl;
}

//Definition for gcdIsNotOne
bool gcdIsOne(int a, int b)
{
	vector<int> multiples_Of_A;
	for (int i = 1; i < b; i++)
	{
		multiples_Of_A.push_back(a * i);
	}
	for (int i = 0; i < multiples_Of_A.size(); i++)
	{
		if (multiples_Of_A[i] % b == 0)
		{
			return false;
		}
	}
	return true;
}