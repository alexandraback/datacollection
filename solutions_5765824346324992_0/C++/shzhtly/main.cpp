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
const LL inf = 1ll << 60;

int n,b;
int a[maxn];
LL res[maxn];

int main(){
//	freopen("B-small-attempt0.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; ++TT){
		scanf("%d%d", &b, &n);
		for (int i = 0; i < b; ++i) scanf("%d", a + i);
		for (int i = 0; i < b; ++i){
			int low = 0, high = n;
			int ans;
			while (low <= high){
				int mid = (low + high) >> 1;
				LL t = 1ll*a[i] * (mid - 1);
				LL cnt = mid - 1;
				for (int j = 0; j < b; ++j){
					if (j < i) cnt += t / a[j] + 1;
					else if (j > i) cnt += (t - 1) / a[j] + 1;
				}
				if (cnt >= n - 1){
					ans = mid;
					high = mid - 1;
				}
				else low = mid + 1;
			}
			res[i] = 1ll * (ans - 1)*a[i];
		}
		LL tt = inf;
		int ans;
		for (int i = 0; i < b; ++i){
			if (tt > res[i]){
				tt = res[i];
				ans = i + 1;
			}
		}
		printf("Case #%d: %d\n", TT, ans);
	}
	return 0;
}