#include <iostream>
#include <fstream>

#include <string>
#include <sstream>
#include <cstdlib>
#include "math.h"
#include <vector>
#include <stack>
#include <map>
#include <set>


using namespace std;

// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(ifstream &infile, ofstream &outfile);


int main()
{
	char ALPHA[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	
	ifstream infile;
	ofstream outfile;
	openFiles(infile, outfile);

	cout << "Reading the input file..." << endl;

	size_t cases;
	infile >> cases;
	for (size_t q = 1; q <= cases; q++) {
		outfile << "Case #" << q << ": ";
		int N;
		infile >> N;
		int arr[50];
		int total = 0;
		int remaining = 0;
		for (int i = 0; i < N; i++) {
			infile >> arr[i];
			total += arr[i];
			if (arr[i] > 0) {
				remaining++;
			}
		}
		bool done = false;
		while (!done) {
			done = true;
			int max1 = 0;
			int ind1 = 0;
			int max2 = 0;
			int ind2 = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i] > max1) {
					max2 = max1;
					ind2 = ind1;
					max1 = arr[i];
					ind1 = i;
					done = false;
				}
				else {
					if (arr[i] > max2) {
						max2 = arr[i];
						ind2 = i;
						done = false;
					}
				}
			}
			if (!done) {
				if ((total == 3 && max1 == 1) || (total == 1)) {
					arr[ind1]--;
					outfile << ALPHA[ind1] << " ";
					total--;
				}
				else {
					if (max1 > (max2 + 1)) {
						arr[ind1] -= 2;
						outfile << ALPHA[ind1] << ALPHA[ind1] << " ";
						total -= 2;
					}
					else {
						arr[ind1]--;
						arr[ind2]--;
						outfile << ALPHA[ind1] << ALPHA[ind2] << " ";
						total -= 2;
					}
				}
			}
			
		}
		outfile << endl;

	}

	// close the files
	infile.close();
	outfile.close();
	cout << "Press enter to exit:" << endl;
	cin.get();
	cin.get();
}


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(ifstream &infile, ofstream &outfile)
{

	// open input data file
	string inFileName;
	cout << "Enter the name of the input file: ";
	cin >> inFileName;
	infile.open(inFileName.c_str());
	if (infile.fail()) {
		cout << "Error opening input data file" << endl;
		char junk;
		cout << "press enter to exit";
		junk = cin.get();
		junk = cin.get();
		exit(1);
	}

	// open output data file
	string outFileName;
	cout << "Enter the name of the output file: ";
	cin >> outFileName;
	outfile.open(outFileName.c_str());
	if (outfile.fail()) {
		cout << "Error opening output data file" << endl;
		char junk;
		cout << "press enter to exit";
		junk = cin.get();
		junk = cin.get();
		exit(1);
	}

}