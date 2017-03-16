//============================================================================
// Name        : B.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 10010
using namespace std;
int arr[MAXN];
int n, b;
typedef long long LL;
LL f(int mid) {
	LL cnt = 0;
	for (int i = 0; i < b; i++) {
		cnt += mid / arr[i] + 1;
	}
	return cnt;
}
int lft[MAXN];
int main() {
	int T;
	int ca = 1;
	freopen("B.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int ans = 0;
		scanf("%d%d", &b, &n);
		for (int i = 0; i < b; i++) {
			scanf("%d", &arr[i]);
		}
		LL low = 0;
		LL high = 1e16;
		while (low < high) {
			int mid = (low + high) / 2;
			LL cnt = f(mid);
			if (cnt >= n) {
				high = mid;
			} else {
				low = mid + 1;
			}
		}
		int cnt = 0;
		for (int i = 0; i < b; i++) {
			lft[i] = low % arr[i];
			cnt += low / arr[i];
		}
		cnt = n - cnt;
		while (cnt > 0) {
			for (int i = 0; i < b; i++) {
				if (lft[i] == 0) {
					cnt--;
					if (cnt == 0) {
						ans = i;
						break;
					}
				}
			}
			int tmp = 10000000;
			for (int i = 0; i < b; i++) {
				tmp = min(tmp, arr[i] - lft[i]);
			}
			for (int i = 0; i < b; i++) {
				lft[i] += tmp;
				lft[i] %= arr[i];
			}
		}
		printf("Case #%d: %d\n", ca++, ans + 1);
	}
	return 0;
}
