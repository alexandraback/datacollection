#include<cstdio>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

vector<int> tab;
int n;

int main() {
	int tests;
	scanf("%d",&tests);
	for(int test = 1; test <= tests; test++) {
		scanf("%d",&n);
		tab.clear();
		for (int i = 0; i < n; i++) {
			int t;
			scanf("%d",&t);
			tab.push_back(t);
		}
		int ret = 0; int mx = 0;
		for (int i = 1; i < n; i++) {
			if (mx < tab[i-1] - tab[i]) mx = tab[i-1] - tab[i];
		 	if (tab[i] < tab[i-1]) ret += tab[i-1] - tab[i];
		}

		int ret2 = 0;
		

		for (int i = 0; i < n-1; i++) ret2 += min(mx, tab[i]);

		printf("Case #%d: %d %d\n", test, ret, ret2);
	}
	return 0;
}