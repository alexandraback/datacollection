#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <assert.h>
#include <time.h>

using namespace std;

int main(){
	int t;
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	scanf("%d", &t);
	for (int te = 0; te < t; te++){
		int n;
		scanf("%d", &n);
		int ans1 = 0;
		int a[1001];
		int mx = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if (i > 0){
				if (a[i - 1] > a[i]){
					ans1 += a[i - 1] - a[i];
					mx = max(a[i - 1] - a[i], mx);
				}
			}
		}
		int ans2 = 0;
		for (int i = 0; i < n - 1; i++){
			ans2 += min(a[i], mx);
		}
		printf("Case #%d: %d %d\n", te + 1, ans1, ans2);
	}
}