//compiler: MSVC 2010 (C++ obviously)
//one template to rule them all

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <queue>

typedef unsigned long long ull;
typedef long long ll;

#define FN "gcj_b"

using namespace std;

int m[1000];
int main() {
	//freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);

	ifstream in(FN ".in");
	ofstream out(FN ".out");

	int t;
	in >> t;

	for(int tt = 0; tt < t; tt++) {
		int b, n;
		in >> b >> n;
		int mincut = 1000000000;
		for(int i = 0; i < b; i++) {
			in >> m[i];
			mincut = min(mincut, m[i]);
		}

		ull l = 0;
		ull r = mincut * (ull) n;
		while(r - l > 1) {
			ull mp = r - (r - l) / 2;
			ull count_cut = 0;
			for(int i = 0; i < b; i++) {
				count_cut += (mp + m[i] - 1) / m[i];
			}
			if(count_cut < n) {
				l = mp;
			} else {
				r = mp;
			}
		}

		int cutz = 0;
		int freez = 0;
		for(int j = 0; j < b; j++) {
			cutz += (l + m[j] - 1) / m[j];
			freez += (((l) % m[j]) == 0);
		}
		if(cutz < n && cutz + freez >= n) {
			for(int j = 0; j < b; j++) {
				if((l) % m[j] == 0) {
					if(cutz == n - 1) {
						out << "Case #" << tt + 1 << ": " << j + 1 << "\n";
						break;
					}
					else 
						cutz++;
				}
			}
		}
	}


	return 0;
}