#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
	string FILENAME = "A-small-attempt0.in";
	string OUT_FILENAME = "output.out";

	ifstream inputfile;
	inputfile.open(FILENAME);
	int testCases;
	ofstream outfile;
	outfile.open(OUT_FILENAME);
	outfile.precision(10);

	int numbers[17];
	for (int i = 1; i < 17; ++i) {
		numbers[i] = 0;
	}

	inputfile >> testCases;
	int firstRow;
	int secondRow;
	int temp;
	for (int i = 1; i <= testCases; ++i) {
		inputfile >> firstRow;
		for (int j = 0; j < 16; ++j) {
			inputfile >> temp;
			if (j / 4 + 1 == firstRow) {
				++numbers[temp];
			}
		}
		inputfile >> secondRow;
		for (int j = 0; j < 16; ++j) {
			inputfile >> temp;
			if (j / 4 + 1 == secondRow) {
				++numbers[temp];
			}
		}
		int magiciansGuess = 0;
		bool magicianMistake = false;
		for (int k = 1; k < 17; ++k) {
			if (numbers[k] == 2) {
				if (magiciansGuess != 0) { //already found a viable candidate
					magicianMistake = true;
//					outfile << "Case #" << i << ": " << "Bad magician!" << endl;
//					break;
				}
				magiciansGuess = k;
			}
			numbers[k] = 0;
		}

		outfile << "Case #" << i << ": ";
		if (magicianMistake) {
			outfile << "Bad magician!" << endl;
		}
		else if (magiciansGuess == 0) {
			outfile << "Volunteer cheated!" << endl;
		}
		else {
			outfile << magiciansGuess << endl;
		}
	}

	return 0;

}