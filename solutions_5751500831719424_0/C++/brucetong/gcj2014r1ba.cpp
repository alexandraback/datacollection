//Problem: Google Code Jam 2014 Round 1B A
//Name: The Repeater
//Author: Bruce K. B. Tong
//Tag: Median, Greedy, Set

#include <cstdio>
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define SMALL
//#define LARGE

#define N_SIZE 100
#define STR_LENGTH 100

string s[N_SIZE];	//1 <= length(s[i]) <= 100

void read(int &N, string s[]) {
	cin >> N;
	cin.ignore();
	for (int i = 0; i < N; i++)
		getline(cin, s[i]);
}

string reduce(string s) {
	char ans[STR_LENGTH+1] = {s[0], 0};
	int k = 0;
	for (int i = 1; i < s.length(); i++)
		if (s[i] != s[i-1]) ans[++k] = s[i];
	string t = ans;
	return t;
}

int solve(int N, string s[]) {
	set<string> m;
	for (int i = 0; i < N; i++)
		m.insert(reduce(s[i]));
	if (m.size() > 1) return -1;

	int f[N_SIZE][STR_LENGTH] = {0};
	for (int i = 0; i < N; i++) {
		for (int k = 0, j = 0; j < s[i].length(); j++) {
			if (j > 0 && s[i][j] != s[i][j-1]) k++;
			f[i][k]++;
		}
	}
	int ans = 0;
	for (int k = 0; k < STR_LENGTH; k++) {
		int g[N_SIZE] = {0};
		for (int i = 0; i < N; i++)
			g[i] = f[i][k];
		sort(g, g+N);
		int median = N/2;
		for (int i = 0; i < N; i++)
			ans += abs(g[i]-g[median]);
	}
	return ans;
}

int main() {
	freopen("A-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("A-small-attempt0.in", "rt", stdin);
		freopen("A-small-attempt0.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("A-large.in", "rt", stdin);
		freopen("A-large.out", "wt", stdout);
	#endif

	int T;				//1 <= T <= 100
	int N;				//2 <= N <= 100

	cin >> T;
	cin.ignore();
	for (int i = 1; i <= T; i++) {
		read(N, s);
		cout << "Case #" << i << ": ";
		int ans = solve(N, s);
		if (ans >= 0)
			cout << ans;
		else
			cout << "Fegla Won";
		cout << endl;
	}
	return 0;
}