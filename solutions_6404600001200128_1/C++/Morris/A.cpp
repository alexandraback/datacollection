#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	ifstream infile(argv[1]);
	ofstream outfile("AOut");
	
	int numTrials;
	infile >> numTrials;

	for (int trial = 1; trial <= numTrials; trial++){
		outfile << "Case #" << trial << ": ";
		int N;
		infile >> N;
		int a[N];
		for (int i = 0; i < N; i++) infile >> a[i];

		// Version 1
		int total = 0;
		for (int i = 0; i < N-1; i++)
			if (a[i] > a[i+1]) total += (a[i] - a[i+1]);
		outfile << total << ' ';

		// Version 2: find tha largest decrease.
		int dec = 0;
		for (int i = 0; i < N-1; i++){
			int newDec = a[i] - a[i+1];
			if (newDec > dec) dec = newDec;
		}
		total = 0;
		for (int i = 0; i < N-1; i++){
			if (a[i] <= dec) total += a[i];
			else total += dec;
		}
		outfile << total << endl;


	}
}
