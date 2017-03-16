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

long long calc(int n, long long Time, int *A) {
	if (Time == -1) return 0;
	if (Time == 0) return n;
	long long ret = 0;
	For(i,1,n) ret += (Time) / A[i] + 1;
	return ret;
}

int n, A[MaxN], K;
int main() {
	//("input.txt","r",stdin); //freopen("output.txt","w",stdout);
	int T; cin >> T;
	For(TK,1,T) {
		printf("Case #%d: ", TK);
		cin >> n >> K;
		For(i,1,n) scanf("%d", &A[i]);
		long long l = 0, r = 1e15 + 5;
		while (l < r) {
			long long mid = (l + r) / 2;
			long long Count = calc(n, mid, A);
			if (Count >= K) r = mid; else l = mid + 1;
		}
		K -= calc(n, l - 1, A);
		int ans = 0;
		For(i,1,n) if (l % A[i] == 0) {
			if (--K == 0) ans = i;
		}
		cout << ans << endl;
	}
	return 0;
}

