#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
using namespace std;

#define N 1000

int a[N+10];
int n;

void solve(int &cnt1, int &cnt2){

	cnt1 = 0;
	for (int i=1; i<n; ++i)
		cnt1 += max(0, a[i-1]-a[i]);

	int maxSub = 0;
	for (int i=1; i<n; ++i)
		maxSub = max(maxSub, a[i-1]-a[i]);	
	cnt2 = 0;
	for (int i=0; i<n-1; ++i)
		cnt2 += min(maxSub, a[i]);
}

int main(){
	int tests;
	scanf("%d", &tests);
	for (int test = 1; test <= tests; ++test){
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) 
			scanf("%d", &a[i]);

		int cnt1, cnt2;
		solve(cnt1, cnt2);
		printf("Case #%d: %d %d\n", test, cnt1, cnt2);
	}
	return 0;
}
