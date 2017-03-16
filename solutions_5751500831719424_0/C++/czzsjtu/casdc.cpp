#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <string.h>
using namespace std;

int T, n;
char st[101][110];
int len[101], pos[101], queue[101];

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

int getMid() {
	qsort(queue+1, n, sizeof(int), cmp);
	int j = 0;
	for (int i=1; i<=n; i++)
		j += labs(queue[i]-queue[(n+1)/2]);
	return j;
}

int allended() {
	int j = 0;
	for (int i=1; i<=n; i++)
		if (pos[i] >= len[i]) j++;
	return j;
}

int checkfail() {
	for (int i=1; i<n; i++)
		if (st[i][pos[i]] != st[i+1][pos[i+1]]) return 1;
	return 0;
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	fin >> T;
	for (int test=1; test<=T; test++) {
		fin >> n;
		for (int i=1; i<=n; i++) {
			fin >> st[i];
			len[i] = strlen(st[i]);
			pos[i] = 0;
		}
		
		int ans = 0;
		while (true) {
			if (checkfail()) {
				ans = -1;
				break;
			}
			int flag = allended();
			if (flag == n) break;
			else if (flag>0 && flag<n) {
				ans = -1; break;
			}
			for (int i=1; i<=n; i++) {
				int j = pos[i];
				while (st[i][j] == st[i][pos[i]]) j++;
				queue[i] = j-pos[i];
				pos[i] = j;
			}
			ans += getMid();
		}
		fout << "Case #" << test << ": ";
		if (ans >= 0) fout << ans << endl; else fout << "Fegla Won" << endl;
	}
	fin.close();
	fout.close();
}
