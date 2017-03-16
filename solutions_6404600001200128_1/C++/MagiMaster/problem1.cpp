#include "problem1.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <array>
using namespace std;

void problem1(string filename) {
	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int z = 1; z <= t; ++z) {
		int n;
		vector<int> m;

		infile >> n;
		for(int i = 0; i < n; ++i) {
			int temp;
			infile >> temp;
			m.push_back(temp);
		}

		int first = 0;
		int x = 0;
		for(int i = 1; i < n; ++i) {
			if(m[i - 1] > m[i]) {
				first += m[i - 1] - m[i];
				if(m[i - 1] - m[i] > x)
					x = m[i - 1] - m[i];
			}
		}

		int second = 0;
		for(int i = 0; i < n - 1; ++i) {
			if(m[i] < x)
				second += m[i];
			else
				second += x;
		}

		outfile << "Case #" << z << ": " << first << " " << second << endl;
	}
}