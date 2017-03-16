#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <fstream>

#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
//#include <random>
#include <time.h>

using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ size

int main() {
	int i, pocet, ii, n, ok, iii, pom, vys;
	vector<string> st, st2;
	vector<int> pom2;
	vector<vector<int> > pocty;
	string s;
	double pom3;
	char last;
	cin >> pocet;
	for (i = 0; i < pocet; i++) {
		cin >> n;
		for (ii = 0; ii < n; ii++) {
			cin >> s;
			st.PB(s);
		}
		for (ii = 0; ii < n; ii++) {
			s = "" + st[ii][0];
			last = st[ii][0];
			pom = 1;
			for (iii = 1; iii < st[ii].SZ(); iii++) {
				if (last == st[ii][iii]) {
					//cout << "meh" << endl;
					pom++;
				} else {
					//cout << pom << last << st[ii][iii] << endl;
					last = st[ii][iii];
					s = s + st[ii][iii];
					
					pom2.PB(pom);
					pom = 1;
				}
			}
			s = s + st[ii][iii];
			pom2.PB(pom);
			st2.PB(s);
			pocty.PB(pom2);
			pom2.clear();
		}
		ok = 1;
		s = st2[0];
		for (ii = 1; ii < n; ii++) {
			if (st2[ii] != s)
				ok = 0;
		}
		if (ok == 1) {
			vys = 0;
			for (ii = 0; ii < pocty[0].SZ(); ii++) {
				pom = 0;
				for (iii = 0; iii < n; iii++) {
					pom = pocty[iii][ii] + pom;
					//cout << pocty[iii][ii] << " AA" << endl;
				}
				pom3 = round(pom / (double)n);
				//cout << pom3 << " AA" << endl;
				for (iii = 0; iii < n; iii++) {
					vys = vys + abs(pocty[iii][ii] - pom3);
				}
			}
			cout << "Case #" << i + 1 << ": " << vys << endl;
		} else {
			cout << "Case #" << i + 1 << ": Fegla Won" << endl;
		}
		st.clear();
		st2.clear();
		pocty.clear();
	}
  	return 0;
}