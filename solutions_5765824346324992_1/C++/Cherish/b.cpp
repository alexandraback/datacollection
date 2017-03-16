#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<utility>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

int a[1010];

struct data{
	int num, id;
	data(int num, int id):num(num), id(id){}
	data(){}
	bool operator < (const data& b)const {
		return num < b.num || num == b.num && id < b.id;
	}
}xxx[1010];

int main()
{
	int t,cas=0;
	cin>>t;
	while(cas++ < t){
		int n;
		LL m;
		cin>>n>>m;
		int mi = INF;
		Rep(i,n) {
			scanf("%d",a+i);
			if(a[i]<mi)mi=a[i];
		}
		int l=0, r=m;
		while(l<r){
			LL mid=l+r+1>>1, tot=mid*mi, temp=0;
			Rep(i,n) {
				temp += (tot+a[i]-1)/a[i];
			}
			if(temp>=m)r=mid-1;
			else l=mid;
		}
		LL cur=(LL)l*mi, num=m;
		Rep(i,n) num-=(cur+a[i]-1)/a[i];
		Rep(i,n) {
			xxx[i]=data((cur-1)/a[i]*a[i]+a[i]-cur,i);
		}
		sort(xxx+1,xxx+1+n);
		int ans = xxx[num].id;
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

