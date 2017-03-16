#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define ll long long
const ll inf = 1e15 + 10;
int T,N,B;
int ans;
int mk[1010];

ll func(ll x){
	ll ret(0);
	for(int i=1;i<=B;++i)
		ret += (x-1) / mk[i] + 1;
	return ret;
}

int rm[1010];

int main(){
//	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(int re=1;re<=T;++re){
		scanf("%d",&B);
		scanf("%d",&N);
		for(int i=1;i<=B;++i) scanf("%d",mk+i);
		ll L(0) , R(inf);
		while(L + 1 < R){
			ll M = (L+R) / 2;
//			cout << func(M) << endl;
			if(func(M) <=  0ll+N-1) L = M;
			else R = M;
		}
		int c = func(L);
		for(int i=1;i<=B;++i)
			rm[i] = ((L-1)/mk[i] + 1)* mk[i] - L;
		while(c < N){
			int MIN = 0x37373737 , id = 0;
			for(int i=1;i<=B;++i)
				if(rm[i] < MIN)
					MIN = rm[i] , id = i;
			for(int i=1;i<=B;++i)
				rm[i] -= MIN;
			rm[id] = mk[id];
			ans = id;
			c++;
		}

		printf("Case #%d: %d\n",re,ans);
	}
	return 0;
}
