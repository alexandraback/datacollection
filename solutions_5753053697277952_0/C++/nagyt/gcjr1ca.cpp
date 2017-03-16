// gcjr1a.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
bool IsNotZero(int i) { return i != 0; }

int main()
{
	ifstream a("D:\\gcj\\example.txt");
	ofstream o("D:\\gcj\\output.txt");
	int nr; a >> nr;
	std::string line;
	std::getline(a, line);
	for (int ii = 0; ii<nr; ii++) {
		o << "Case #" << (ii + 1) << ":";
		cout << "Case #" << (ii + 1) << ":";
		int n;
		a >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int t;
			a >> t;
			v.push_back(t);
		}

		while (true) {

			auto it1 = std::max_element(v.begin(), v.end());
			*it1 -= 1;
			char i1 = std::distance(v.begin(), it1) + 'A';
			auto it2 = std::max_element(v.begin(), v.end());
			*it2 -= 1;
			char i2 = std::distance(v.begin(), it2) + 'A';
			int mycount = count_if(v.begin(), v.end(), IsNotZero);

			if (mycount == 1)
			{
				*it2 += 1;
				o << " " << i1;
				cout << " " << i1;
			}
			else
			{
				o << " " << i1;
				cout << " " << i1;
				o << i2;
				cout << i2;

			}
			if (mycount == 0)
			{
				break;
			}
		}
		o << endl;
		cout << endl;		
	}
	a.close();
	o.close();
	char c; cin >> c;
	return 0;
}

