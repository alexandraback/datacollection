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
int main() {
	int T;
	int ca = 1;
	freopen("A.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		int n;
		int a, b;
		a = b = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		int tmp = 0;
		for (int i = 1; i < n; i++) {
			if (arr[i] < arr[i - 1]) {
				a += arr[i - 1] - arr[i];
				tmp = max(tmp, arr[i - 1] - arr[i]);
			}
		}
		for (int i = 0; i < n - 1; i++) {
			b += min(tmp, arr[i]);
		}
		printf("Case #%d: %d %d\n", ca++, a, b);
	}
	return 0;
}
