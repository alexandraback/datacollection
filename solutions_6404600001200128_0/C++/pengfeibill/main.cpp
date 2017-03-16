#include <iostream>
#include <fstream>

using namespace std;

int t, n;
int m[1000];

ifstream fin("A-small-attempt0.in");
ofstream fout("test.out");

int main() {
	fin >> t;
	for (int case_num = 1; case_num <= t; case_num++) {
		fin >> n;
		for (int i = 0; i < n; i++)
			fin >> m[i];
		int res1 = 0;
		int speed = 0;
		for (int i = 0; i < n - 1; i++)
			if (m[i] > m[i + 1]) {
				res1 += m[i] - m[i + 1];
				if (m[i] - m[i + 1] > speed)
					speed = m[i] - m[i + 1];
			}
		int res2 = 0;
		for (int i = 0; i < n - 1; i++)
			if (m[i] >= speed)
				res2 += speed;
			else
				res2 += m[i];
		fout << "Case #" << case_num << ": " << res1 << " " << res2 << endl;
	}
	return 0;
}