#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sortt (vector<int> &a, vector<int> &b) {
	int n = a.size();
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j]) {
				int t = a[i]; a[i] = a[j]; a[j] = t;
				int q = b[i]; b[i] = b[j]; b[j] = q;
			}
}

int main () {
	int T;
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");
	fin >> T;
	for (int t = 0; t < T; t++) {
		int n, s = 0;
		fin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			fin >> a[i];
			s += a[i];
			b[i] = i;
		}
		fout << "Case #" << t + 1 << ": ";
		while (s > 2) {
			sortt (a, b);
			if (s == 4 && a[0] == 2 && a[1] == 2) {
				fout << char('A' + b[0]) << char ('A' + b[1]) << " ";
				a[0]--;
				a[1]--;
				s -= 2;
				continue;
			}
			a[0]--;
			fout << char('A' + b[0]) << " ";
			s--;
		}
		sortt (a, b);

		fout << char('A' + b[0]) << char ('A' + b[1]);
		fout << endl;
	}
	fin.close();
	fout.close();
	return 0;
}