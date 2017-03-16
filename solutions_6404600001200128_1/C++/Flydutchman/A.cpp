#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
#include<map>
#include<string>
#include<vector>
#include<set>

using namespace std;
#define For(i,l,r) for (int i = l; i <= r; ++i)
#define Cor(i,l,r) for (int i = l; i >= r; --i)
#define Fill(a,b) memset(a,b,sizeof(a))
#define FI first
#define SE second
#define MP make_pair
#define PII pair<int,int>
#define flt double
#define INF (0x3f3f3f3f)
#define MaxN 1020304
#define MaxNode 1020304
#define MD 1000000007

long long getLL() {
	long long ret = 0;
	char c;
	while (1) {
		c = getchar();
		if (c >= '0' && c <= '9') break ;
	}
	while (1) {
		ret = ret * 10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') break ;
	}
	return ret;
}

int getInt() {
	int ret = 0;
	char c;
	while (1) {
		c = getchar();
		if (c >= '0' && c <= '9') break ;
	}
	while (1) {
		ret = ret * 10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') break ;
	}
	return ret;
}

int First(int n, int *A) {
	int ret = 0;
	int cur = A[1];
	For(i,2,n) {
		if (A[i] < cur) ret += cur - A[i];
		cur = A[i];
	}
	return ret;
}

int Second(int n, int *A) {
	int ret = INF;
	For(speed,0,20000) {
		int cur = A[1];
		int tans = 0;
		For(i,2,n) {
			if (cur - speed > A[i]) {
				tans = INF;
				break ;
			}
			tans += min(cur, speed);
			cur = A[i];
		}
		ret = min(ret, tans);
	}
	return ret;
}

int n, A[MaxN];
int main() {
	//freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TTT,1,T) {
		printf("Case #%d: ", TTT);
		int n; cin >> n;
		For(i,1,n) scanf("%d", &A[i]);
		printf("%d %d\n", First(n, A), Second(n, A));
	}
	return 0;
}

