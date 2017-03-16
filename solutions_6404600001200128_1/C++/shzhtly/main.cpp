#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 1005;
const int mod = 100007;

int n;
int a[maxn];

int main(){
//	freopen("A-large.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T;
	int x, y;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; ++TT){
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", a + i);
		x = 0;
		for (int i = 0; i < n-1; ++i){
			if (a[i] > a[i + 1]) x += a[i] - a[i + 1];
		}
		y = 0;
		for (int i = 0; i < n - 1; ++i){
			y = max(y, a[i] - a[i + 1]);
		}
		int z = 0;
		for (int i = 0; i < n - 1; ++i){
			if (a[i] >= y) z += y;
			else z += a[i];
		}
		printf("Case #%d: %d %d\n", TT, x, z);
	}
	return 0;
}