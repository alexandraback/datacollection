#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <set>
#include <string>

using namespace std;

int n;
string strs[1000];
int ptrs[1000];
int strns[1000][1000];
int nd = 0;
bool possible;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int tcase = 1; tcase <= t; tcase++)
	{
		printf("Case #%d: ", tcase);
		possible = true;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> strs[i];
		}
		char curc = '1';
		nd = 0;
		for (int i = 0; i < 1000; i++)
		{
			ptrs[i] = 0;
			for (int j = 0; j < 1000; j++)
				strns[i][j] = 0;
		}
		while (possible && curc) {
			curc = ptrs[0] < strs[0].size() ? strs[0][ptrs[0]] : 0;
			for (int i = 0; i < n; i++) {
				int sz = strs[i].size();
				char cc = ptrs[i] < sz ? strs[i][ptrs[i]] : 0;
				if (curc != cc) {
					possible = false;
					break;
				}
				while (ptrs[i] < sz && strs[i][ptrs[i]] == curc) {
					ptrs[i]++;
					strns[i][nd]++;
				}
			}
			nd++;
		}
		nd--;
		int minsum = 0;
		if (possible) {
			for (int j = 0; j < nd; j++) {
				int minv = 2000000000, cs = 0;
				for (int k = 1; k <= 100; k++) {
					cs = 0;
					for (int i = 0; i < n; i++) {
						cs += abs(k - strns[i][j]);
					}
					if (minv > cs) {
						minv = cs;
					}
				}
				minsum += minv;
			}
			printf("%d", minsum);
		} else {
			printf("Fegla Won");
		}

		printf("\n");				
	}
}