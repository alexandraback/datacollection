// 2015q3.cpp : Defines the entry point for the console application.;
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <functional>
//#include <boost/math/special_functions/sign.hpp>


using namespace std;

string problem(std::ifstream& fin, std::ofstream& ferr) {

	long long N;
	long long P[26];
	stringstream res;

	fin >> N;
	
	for (int i = 0; i < N; ++i) {
		fin >> P[i];
	}

	for (;;) {
		long m1 = 0, m2 = 0,c = 0;

		for (int i = 0; i < N; ++i) {
			if (P[i]) c++;

			if (P[i] > P[m1]) {
				m1 = i;
			}
		}

		if (c == 0) break;
		for (int i = 0; i < N; ++i) {
			if (P[i] >= P[m2] && i!=m1) {
				m2 = i;
			}
		}

		res << ((char)('A' + m1));
		
		if (c == 2 && P[m1] == P[m2]) {
			res << ((char) ('A' + m2));
			P[m2]--;
		}

		res << (' ');
		
		P[m1]--;
		
	}

	return res.str();
}

int main()
{
	int T;
	string filename;

	string result;

	cout << "Enter the file prefix" << endl;
	cin >> filename;

	std::ifstream f_in(filename + ".in");
	std::ofstream f_out(filename + ".out");
	std::ofstream f_err(filename + ".err");


	if (!f_in) { cerr << "Failed to open input file." << endl; }
	if (!f_out) { cerr << "Failed to open output file." << endl; }
	if (!f_out) { cerr << "Failed to open debug file." << endl; }

	if (f_in && f_out) {

		f_in >> T;

		for (int i = 1; i <= T; i++) {
			result = problem(f_in, f_err);
			cerr << "Case #" << i << ": " << result << endl;
			f_out << "Case #" << i << ": " << result << endl;
		}

		f_in.close();
		f_out.close();
	}
}
