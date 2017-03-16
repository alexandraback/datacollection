#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("A-large.in");
ofstream fout("out.txt");

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	int tests;
	fin >> tests;
	for (int test = 0; test < tests; ++test) {
		int n, total = 0;
		fin >> n;
		vector<pair<int, int>> a;
		for (int i = 0; i < n; ++i) {
			int x;
			fin >> x;
			total += x;
			a.push_back(make_pair(x, i));
		}

		sort(a.begin(), a.end(), comp);
		
		fout << "Case #" << test + 1 << ": ";
		while (total != 2) {
			int i = 0;
			int cur = a[i].first;
			int chars = 0;
			char ch1, ch2;
			while (i < n && total > 2 && a[i].first == cur) {
				if (chars == 0) {
				    ch1 = a[i].second + 'A';
					++chars;
				} else if (chars == 1) {
					ch2 = a[i].second + 'A';
					fout << ch1 << ch2 << " ";
					chars = 0;
				}
				--a[i].first;
				--total;
				++i;
			}
			if (chars) {
				fout << ch1 << " ";
			}
		}
		char ch1, ch2;
		for (int i = 0; i < n; ++i) {
			if (a[i].first == 1 && total == 2) {
				ch1 = a[i].second + 'A';
				--total;
			} else
			if (a[i].first == 1 && total == 1) {
				ch2 = a[i].second + 'A';
				--total;
			}
		}
		fout << ch1 << ch2 << endl;
	}

	return 0;
}
