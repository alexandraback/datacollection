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

int n,a[1010];

int func(int speed){
	int i,j,ret=0,x;
	for(i=0;i<n;i++){
		if(speed*10>=a[i])x=a[i];
		else x=speed*10;
		if(i<n-1 && a[i]-x>a[i+1])return -1;
		if(i<n-1)ret+=x;
	}
	return ret;
}

int main(){
	int cs,t=1,i,j,ra,rb,diff;
	cin>>cs;
	while(cs--){
		cin>>n;
		for(i=0;i<n;i++)cin>>a[i];
		ra=rb=0;
		for(i=1;i<n;i++){
			if(a[i-1]>a[i])ra+=(a[i-1]-a[i]);
		}
		diff=0;
		for(i=1;i<n;i++){
			j=a[i-1]-a[i];
			diff=max(diff,j);
		}
		for(i=1;i<n;i++){
			if(a[i-1]<diff)rb+=a[i-1];
			else rb+=diff;
		}
		printf("Case #%d: %d %d\n",t++,ra,rb);
	}
	return 0;
}


