#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int z, b, n, a[1005];

int main(){
	scanf("%d", &z);
	for(int x=1; x<=z; x++){
		printf("Case #%d: ", x);
		scanf("%d %d", &b, &n);
		for(int i = 0; i < b; i++) scanf("%d", &a[i]);
		vector<int> cd;
		ll s = -1, e = 1LL<<60, m, d, ans, spos, md = 1LL<<60;
		while(s <= e){
			d = 0; m = (s+e)/2;
			for(int i = 0; i < b; i++){
			   	d += m/a[i] + 1;
			}
			if(d >= n) e = m-1;
			else{
				spos = m;
				ans = d;
			   	s = m+1;
			}
		}
		for(int i = 0; i < b; i++){
			ll v = a[i]-(spos%a[i]);
			if(v < md){
				md = v;
				cd.clear();
				cd.push_back(i);
			}
			else if(v == md) cd.push_back(i);
		}
		printf("%d\n", cd[n-ans-1]+1); 
	}
	return 0;
}

