/*
 * Problem : 
 * Author : Hwhitetooth
 * Date : 
 * Result :
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 1000 + 10;

int a[N];
int n;
int testCases;

int main() {
	scanf("%d", &testCases);
	for (int _ = 1; _ <= testCases; ++_) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int ansA = 0, speed = 0, ansB = 0;
		for (int i = 1; i < n; ++i) {
			if (a[i] < a[i - 1]) {
				ansA += a[i - 1] - a[i];
				speed = max(speed, a[i - 1] - a[i]);
			}
		}
		for (int i = 0; i < n - 1; ++i) {
			ansB += min(a[i], speed);
		}
		printf("Case #%d: %d %d\n", _, ansA, ansB);
	}
	return 0;
}