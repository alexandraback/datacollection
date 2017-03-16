#include "problem2.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
#include <array>
using namespace std;

void problem2(string filename) {
	ifstream infile(filename + ".in");
	ofstream outfile(filename + ".out");

	int t;
	infile >> t;

	for(int z = 1; z <= t; ++z) {
		long long b, n, x = 0;

		infile >> b >> n;
		vector<int> m;

		double rate = 0.0;
		for(int i = 0; i < b; ++i) {
			int temp;
			infile >> temp;
			m.push_back(temp);

			if(temp > x)
				x = temp;

			rate += 1.0 / temp;
		}

		int found = -1;
		long long guess = n / rate + 1;
		while(found < 0) {
			vector<int> each;
			for(int i = 0; i < b; ++i)
				each.push_back(guess / m[i] + 1);

			int total = 0;
			for(int i = 0; i < b; ++i) {
				total += each[i];
				if(guess % m[i] == 0) {
					int temp = total;
					for(int j = i + 1; j < b; ++j) {
						if(guess % m[j] == 0)
							temp += each[j] - 1;
						else
							temp += each[j];
					}

					if(temp == n)
						found = i + 1;
				}
			}

			--guess;
		}

		outfile << "Case #" << z << ": " << found << endl;
	}
}