#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
#include<cmath>
#include<iostream>
#include<vector>
#include<sstream>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define pb push_back
#define mp make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
#define NM 100005
#define inf 10000005
typedef long long int ll;
using namespace std;
ll a[1005];ll m;

ll f(ll k){ll sum=0;int i;//if(k==0){return m;}
rep(i,m){sum+=(k/a[i])*1LL;}
return sum+m;}

int main()
{
int t,kase=0;
cin>>t;
while(t--){kase++;
int i,j,b,mn=inf;ll n,ans;

cin>>m>>n;

rep(i,m){
cin>>a[i];if(a[i]<mn){mn=a[i];}}
printf("Case #%d: ",kase);
if(n<=m){pi(n);pn;continue;}
//n-=m;
ll high=1000000000000000LL,low=0LL,mid;

while(low<=high){
mid=((high-low)/2*1LL)+low;
if(f(mid)>=n){high=mid-1;}
else{low=mid+1;ans=mid;}
}


//pn;pi(ans);pn;

//cout<<f(ans+1)-f(ans);pn;

ans++;
n-=f(ans-1);
//cout<<n;pn;
rep(j,m){if(ans%a[j]==0){n--;}

if(n==0){pi(j+1);break;}}



pn;
}
return 0;}



