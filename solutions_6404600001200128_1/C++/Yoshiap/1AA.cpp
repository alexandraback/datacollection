#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1AA.out");
ifstream fin ("1AA.in");

int N;
int maxe;
int tote;
int prev;
int cnt[10000];

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		maxe = 0;
		tote = 0;
		fin >> N;
		fin >> prev;
		cnt[0] = prev;
		for (int i = 1; i < N; i++) {
			int a;
			fin >> a;
			if (prev > a) {
				tote += prev-a;
				maxe = max(maxe,prev-a);
			}
			prev = a;
			cnt[i] = a;
		}
		int ans2 = 0;
		for (int i = 0; i < N-1; i++) {
			ans2 += min(maxe,cnt[i]);
		}
		fout << "Case #" << t << ": " << tote << " " << ans2 << "\n";
	}
    return 0;
}