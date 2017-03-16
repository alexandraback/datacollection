#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define inf (1<<29)
#define i64 long long
#define MX 1000002

typedef pair<int,int> pii;
i64 n,a[1010],b;

i64 func(i64 tm){
	i64 i,j,ret=0;
	for(i=0;i<b;i++){
		ret+=((tm+a[i]-1)/a[i]);
	}
	return ret;
}

int main(){
	int cs,t=1,res;
	i64 x,low,high,mid,i,v;
	cin>>cs;
	while(cs--){
		cin>>b>>n;
		for(i=0;i<b;i++)cin>>a[i];
		low=0;
		high=(1e14)+9;
		while(low<=high){
			mid=(low+high)/2;
			x=func(mid);
			if(x>=n) high=mid-1;
			else {
				low=mid+1;
				v=mid;
			}
		}
		x=func(v);
		x=n-x;
		for(i=0;i<b;i++){
			if(v%a[i]==0){
				if(x==1){
					res=i+1;
					break;
				}
				x--;
			}
		}
		printf("Case #%d: %d\n",t++,res);
	}
	return 0;
}


