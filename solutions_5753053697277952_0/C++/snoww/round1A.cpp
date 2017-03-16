// ConsoleApplication5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <array>

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
using namespace std;

//typedef long long LL;

int main() {
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("A.in");
	outputFile.open("A.out");

	int N =0;
	string deBuggerString;
	int nbrOfCases;
	int diff;
	int parties;
	
	inputFile >> nbrOfCases;

	int partySize[26]; 

	for (int i42 = 1; i42 <= nbrOfCases; i42++)
	{
		//cout << "Case #" << i << ": ";
		//outputFile << "\n";
		inputFile >> parties;
		int partySize[26] = { 0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0,0,0,0,0 ,0,0,0,0,0,0 };
		int sum = 0;
		char evac1;
		char evac2;
		for (size_t i2 = 0; i2 < parties; i2++)
		{
			inputFile >> partySize[i2];
			sum += partySize[i2];
		}



		outputFile << "Case #" << i42 << ": ";

		if (sum % 2 == 1)
		{


			evac1 = distance(partySize, max_element(partySize, partySize + 26));
			partySize[evac1] = partySize[evac1] - 1;
			evac1 = 'A' + evac1;
			outputFile << evac1 << " ";
			sum = sum - 1;
		}






		while (sum > 0)
		{
			evac1 = distance(partySize, max_element(partySize, partySize + 26));
			partySize[evac1] = partySize[evac1] - 1;
			evac1 = 'A' + evac1;
			outputFile << evac1;
			evac2 = distance(partySize, max_element(partySize, partySize + 26));
			partySize[evac2] = partySize[evac2] - 1;
			evac2 = 'A' + evac2;
			outputFile << evac2 << " ";
			sum = sum - 2;
		}




		outputFile << "\n";

		
	}
	cin >> N;
	//outputFile << "\n";
	inputFile.close();
	outputFile.close();
	return 0;
}