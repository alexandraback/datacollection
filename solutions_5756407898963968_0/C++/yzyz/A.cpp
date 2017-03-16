#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <utility>

using namespace std;

ofstream fout ("Asmall.out");
ifstream fin ("Asmall.in");

int T;
int a,b,aa[17],bb[17],x;

int main() {
	fin >> T;
	for (int tc = 1; tc <= T; tc++) {
		fin >> a;
		a--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fin >> x;
				aa[x] = i;
			}
		}
		fin >> b;
		b--;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				fin >> x;
				bb[x] = i;
			}
		}
		int ans = -1;
		bool bad = false;
		for (int i = 1; i <= 16; i++) {
			if (aa[i] == a && bb[i] == b) {
				if (ans < 0) ans = i;
				else bad = true;
			}
		}
		fout << "Case #" << tc << ": ";
		if (ans < 0) fout << "Volunteer cheated!\n";
		else if (bad) fout << "Bad magician!\n";
		else fout << ans << '\n';
	}
    return 0;
}