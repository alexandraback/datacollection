#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

// #define DEBUG

#ifdef DEBUG
#define DEBUG_PRINT(...) fprintf (stderr, __VA_ARGS__)
#else
#define DEBUG_PRINT(...)
#endif


int readTestCase(ifstream& InputFile, int* pCardRow) {
	
	int Answer;
	
	InputFile >> Answer;
	Answer--;
	
	for (int CurGridRow = 0; CurGridRow < 4; CurGridRow++) {
		
		for (int CurGridCol = 0; CurGridCol < 4; CurGridCol++) {
			
			int Card = 0;
			
			InputFile >> Card;
			
			if (CurGridRow == Answer) {
				pCardRow[CurGridCol] = Card;
				DEBUG_PRINT(">%d< ", Card);
			} else {
				DEBUG_PRINT(" %d  ", Card);
			}
			
		}
		
		DEBUG_PRINT("\n");
	}
	
	return 0;
}


int main(int argc, char **argv)
{
	ifstream InputFile ("small.txt");
	
	int NbTestCases = 0;
	
	if (!InputFile.is_open()) {
		cerr << "Could not open input.txt" << endl;
		return 1;
	}
	
	InputFile >> NbTestCases;
	
	DEBUG_PRINT("NbTestCases = %d\n", NbTestCases);
	
	int CardRow1[4];
	int CardRow2[4];

	for (int CurTestCase = 0; CurTestCase < NbTestCases; CurTestCase++) {
		
		DEBUG_PRINT("\n\nTest Case %d\n", CurTestCase+1);
		
		DEBUG_PRINT("Deck 1:\n");
		readTestCase(InputFile, (int*) CardRow1);
		DEBUG_PRINT("Deck 2\n");
		readTestCase(InputFile, (int*) CardRow2);
		
		int ResultCard = -1;
		bool BadMagician = false;
		
		for (int i = 0; i < 4 && !BadMagician; i++) {
			for (int j = 0; j < 4 && !BadMagician; j++) {
				if (CardRow1[i] == CardRow2[j]) {
					
					if (ResultCard != -1) {
						cout << "Case #" << (CurTestCase+1) << ": Bad magician!" << endl;
						BadMagician = true;
						break;
					}
					
					ResultCard = CardRow1[i];				
				}
			}
		}
		
		if (BadMagician) {
			continue;
		}
		
		if (ResultCard == -1) {
			cout << "Case #" << (CurTestCase+1) << ": Volunteer cheated!" << endl;
		} else {
			cout << "Case #" << (CurTestCase+1) << ": " << ResultCard << endl;
		}
		
		
	}
	
	
	return 0;
}
