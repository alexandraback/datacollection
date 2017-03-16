#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<vector>
#include<sstream>
#include <map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#define PB push_back
#define MP make_pair
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
#define pll(n) printf("%llu",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%llu",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
using namespace std;
int mini(int a,int b){return a<b?a:b;}

int main(){int t;
si(t);
for(int kase=1;kase<=t;kase++){
int i,j,k,l,x,sum=0,n,cnt,ind[105];
string s[105];char r[105][105];vector <int> v[105];
si(n);
rep(i,n){cin>>s[i];}

//rep(i,104){rep(j,104){fck[i][j]=0;}}

rep(i,n){r[i][0]=s[i][0];cnt=1;
int l=1;
for(j=1;j<=s[i].length();j++){
if(s[i][j]!=s[i][j-1]){r[i][l++]=s[i][j];
//cout<<r[i][l-1];pw;
v[i].push_back(cnt);cnt=1;}else{cnt++;}}ind[i]=l;
//if(flag==0){v[i].push_back(cnt);}
}

//printf("%s",r[0]);
//rep(i,n){rep(j,ind[i]){cout<<r[i][j];}pn;}
int flag=0;
//rep(i,n){rep(j,v[i].size()){cout<<v[i][j];pw;}pn;}
for(i=1;i<n;i++){if(ind[i-1]!=ind[i]||v[i].size()!=v[0].size()
){flag=1;break;}else{rep(j,ind[i]){if(r[i][j]!=r[i-1][j]){flag=1;break;}}}}
printf("Case #%d: ",kase);
if(flag==1){puts("Fegla Won");}
else{//pn;pi(v[0][0]);pn;
for(i=0;i<v[0].size();i++){int ans2=1000000,ans=0;
for(int mid=1;mid<=100;mid++){ans=0;
rep(j,n){ans+=abs(v[j][i]-mid);}
ans2=mini(ans,ans2);
}//pi(ans2);pw;
sum+=ans2;}
pi(sum);pn;}

}

return 0;}
