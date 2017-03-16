#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 200;
const int MAXL = 200;

int N;
char s[MAXN][MAXL];
int ind[MAXN];

int lens[MAXN];

int go() {
	for(int i = 0; i < N; i++) {
		ind[i] = 0;
	}
	int res = 0;
	while(s[0][ind[0]]) {
		char c = s[0][ind[0]];
		for(int i = 0; i < N; i++) {
			lens[i] = 0;
			while(s[i][ind[i]] == c) {
				ind[i] ++, lens[i]++;
			}
			if(lens[i] == 0) return -1;
		}
		sort(lens, lens + N);
		int mid = lens[N / 2];
		for(int i = 0; i < N; i++) {
			res += abs(lens[i] - mid);
		}
	}
	for(int i = 0; i < N; i++) {
		if(s[i][ind[i]]) return -1;
	}
	return res;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> N;
		for(int i = 0; i < N; i++) cin >> s[i];
		int v = go();
		cout << "Case #" << t << ": ";
		if(v == -1) cout << "Fegla Won";
		else cout << v;
		cout << '\n';
	}
	return 0;
}
