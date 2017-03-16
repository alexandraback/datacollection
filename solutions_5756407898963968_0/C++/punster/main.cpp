#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdio>
#include "stdlib.h"
using namespace std;

template <typename T>
  string NumToStr ( T Num )
  {
     ostringstream ss;
     ss << Num;
     return ss.str();
  }

string do_something() {
	int row;
	vector<int> matches;
	int trash;
	int a[4];
	int b[4];
	
	cin >> row;
	for (int i=1; i<=4; ++i) {
		if (i==row) { cin >> a[0] >> a[1] >> a[2] >> a[3]; }
		else { cin >> trash >> trash >> trash >> trash; }
	}
	cin >> row;
	for (int i=1; i<=4; ++i) {
		if (i==row) { cin >> b[0] >> b[1] >> b[2] >> b[3]; }
		else { cin >> trash >> trash >> trash >> trash; }
	}
	for (int i=0; i<4; ++i) {
		for (int j=0; j<4; ++j) {
			if (a[i] == b[j]) matches.push_back(a[i]);
		}
	}
	if (matches.size() == 0) { return "Volunteer cheated!"; }
	if (matches.size() == 1) { return NumToStr(matches[0]); }
	return "Bad magician!"; 
}

int main(int argc, char **argv)
{
	int tests;
	cin >> tests;

	for (int i=1; i <= tests; ++i) {
	  cout << "Case #" << i << ": " << do_something() << "\n"; 
	}
	return 0;
}

