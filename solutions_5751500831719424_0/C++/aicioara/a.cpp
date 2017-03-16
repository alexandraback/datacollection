#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

#define e '\n'
#define INF 1023456789
#define ll long long

//#define FILE "seif"

#ifdef FILE
ifstream f(string (string(FILE) + ".in").c_str());
ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
#define f cin
#define g cout
#endif

string s1, s2, s3;
int i, ii, j, n, m, t, k;
string str[1000];
char cc[1000][1000];
int vv[1000][1000];
bool wrong;
char aux;
int pos, rez;

vector<int> sorter;

int main() {

	f >> t;
	for (ii=1; ii<=t; ii++) {

		wrong = 0;

		f >> n;
		for (i=1; i<=n; i++) {
			f >> str[i];
			cc[i][0] = 0;
			vv[i][0] = 0;
			j = 1;
			pos = 0;
			while (j<=str[i].size()) {
				while (j<str[i].size() && (str[i][j] == str[i][j-1])) {
					j++;
				}
				cc[i][++cc[i][0]] = str[i][j-1];
				vv[i][++vv[i][0]] = j - pos;
				pos = j;
				j++;
			}

//			for (j=1; j<=vv[i][0]; j++) {
//				g << cc[i][j] << " ";
//			}
//			g << e;
		}

		for (i=2; i<=n; i++) {
			if (cc[i][0] != cc[i-1][0]) {
				wrong = 1;
			}
		}


		if (wrong) {
			g << "Case #" << ii << ": " << "Fegla Won" << e;
			continue;
		}

		for (i=2; i<=n; i++) {
			for (j = 1; j<=cc[i][0]; j++) {
				if (cc[i][j] != cc[i-1][j]) {
					wrong = 1;
				}
			}
		}

		if (wrong) {
			g << "Case #" << ii << ": " << "Fegla Won" << e;
			continue;
		}


		rez = 0;
		for (j=1; j<=vv[1][0]; j++) {
			sorter.clear();
			for (i=1; i<=n; i++) {
				sorter.push_back(vv[i][j]);
			}

//			g << "SORTED ";
//			for (i=0; i<n; i++) {
//				g << sorter[i] << " ";
//			}
//			g << e;

			sort (sorter.begin(),sorter.end());
			int median = sorter[sorter.size() / 2];
			for (i=1; i<=n; i++) {
				rez += (median - vv[i][j] > 0) ? (median - vv[i][j]) : (vv[i][j] - median);
			}
		}




		g << "Case #" << ii << ": " << rez << e;
	}


	return 0;

}
