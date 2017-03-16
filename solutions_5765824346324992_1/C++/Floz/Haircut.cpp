#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
#define maxn 1010
int a[maxn];
typedef pair<int,int> ii;
vector<ii> t;
#define fi first
#define se second
int main(){
	int T;
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int _=1;_<=T;_++) {
		int b,n;
		scanf("%d%d",&b,&n);
		for (int i=1;i<=b;i++) scanf("%d",a+i);
		#define inf 1000000000000000ll
		ll l=0,r=inf;
		n--;
		while (l+1<r) {
			ll mid=(l+r)>>1,sum=0;
			for (int i=1;i<=b;i++) {
				sum+=mid/a[i];
				if (mid%a[i]!=0) sum++;
			}
			if (sum>n) r=mid;
			else l=mid;
		}
		ll sum=0;
		t.clear();
		for (int i=1;i<=b;i++) {
			sum+=l/a[i];
			if (l%a[i]!=0) sum++;
			t.push_back(ii(l%a[i],i));
		}
		sort(t.begin(),t.end());
		printf("Case #%d: %lld\n",_,t[n-sum].se);
	}
	return 0;
}
