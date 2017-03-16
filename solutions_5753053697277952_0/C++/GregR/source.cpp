#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <iomanip>

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)

using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int t, T, i, j, k, N, x, y;
	int p[26];
	int in, maxval, maxind, active;
	char c, c1, c2;

	fin >> T;
	for1(t, T) {

		cout << "Case #" << t << ": ";
		fout << "Case #" << t << ": ";

		fin >> N;
		memset(p, 0, sizeof(p[0]) * 26);
		forn(i, N) fin >> p[i];

		in = 0;
		forn(i, N) in += p[i];
		
		active = N;

		while (in > 0) {

			if (active > 2) {
				maxval = -1;
				forn(i, N) if (p[i] > 0 && p[i] > maxval) { maxval = p[i]; maxind = i; }

				c = (char)maxind + 'A';
				cout << c << " ";
				fout << c << " ";

				p[maxind]--;
				in--;
				if (p[maxind] == 0) active--;
			}

			if (active == 2) {
				x = -1;
				y = -1;
				forn(i, N) {
					if (p[i] > 0 && x == -1) {
						x = i;
					} else
						if (p[i] > 0) {
							y = i;
					}
				}

				c1 = (char)x + 'A';
				c2 = (char)y + 'A';
				forn(i, p[x]) {
					cout << c1 << c2 << " ";
					fout << c1 << c2 << " ";
				}
				in = 0;
			}

		}

		cout << endl;
		fout << endl;



	}

	return 0;
}