#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;
const int N = 1010;
int TT;
long long b, n;
int a[N];
int q[N], f=0;
int main() {
	scanf("%d", &TT);
	for(int rr = 1 ; rr<=TT; ++rr){
		scanf("%lld%lld", &b, &n);
		n = n -1;
		for(int i=0; i<b; ++i){
			scanf("%d", a+i);
		}
		long long low = 0, high = (1ll * n) *(1ll * a[0]); 
		while(low < high){
			long long mid = (low + high) / 2;
			long long pre = 0;
			int ok = 0;
			for(int i=0; i<b; ++i){
				++pre;
				pre += mid / a[i];
			}
			if(pre > n) high = mid;
			else low = mid + 1;
		}
		{
			long long done = 0;
			f=0;
			for(int i=0; i<b; ++i){
				done += low / a[i];
				if(low % a[i] == 0) 
					q[f++] = i;
				else ++done;
			}
			if(n-done<0) cout<<"wawawa"<<endl;
			int ans = q[n-done] + 1;
			printf("Case #%d: %d\n", rr, ans);
		}
	}
	return 0;
}

