#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 1000 + 10;
typedef long long LL; 
int n,b;
int c[maxn];
LL check(LL tot){
	LL ret = 0;
	for (int i = 1;i <= b;i++)
		ret += LL(tot / c[i]) + 1;
	return ret;
}
int main()
{
	int T; cin>>T;
	for (int ii = 1;ii <= T;ii++){
		scanf("%d%d",&b,&n);
		for (int i = 1;i <= b;i++) scanf("%d",&c[i]);
		LL L = 0,R = 1000000000000000 * 1LL;
		while(L <= R){
			LL mid = (L + R) >> 1;
			if (check(mid) >= 1LL * n) R = mid - 1;
			else L = mid + 1;
		}
		while (check(L) < n * 1LL) L++;
		while (check(L - 1) >= n * 1LL) L--;
		int left = n - check(L - 1);
		for (int i = 1;i <= b;i++){
			if (L % c[i] == 0) left--;
			if (!left){
				printf("Case #%d: %d\n",ii,i);
				break;
			}
		}
	}

	return 0;
}
