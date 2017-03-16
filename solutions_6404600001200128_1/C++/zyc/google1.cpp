/*************************************************************************
    > File Name: google1.cpp
    > Author: cy
    > Mail: 1002@qq.com 
    > Created Time: 15/4/18 9:34:47
 ************************************************************************/

#include<iostream>
#include<cstring>
#include <algorithm>
#include<cstdlib>
#include<vector>
#include<cmath>
#include<stdlib.h>
#include<iomanip>
#include<list>
#include<deque>
#include<map>
#include <stdio.h>
#include <queue>

const int maxn=1000+5;

#define inf 0x3f3f3f3f
  #define INF 0x3FFFFFFFFFFFFFFFLL
#define rep(i,n) for(i=0;i<n;i++)
 #define reP(i,n) for(i=1;i<=n;i++)

#define ull unsigned long long
 #define ll long long

#define cle(a) memset(a,0,sizeof(a))

using namespace std;
int val[maxn];
int main()
{
#ifndef ONLINE_JUDGE
    // freopen("A-large.in","r",stdin);
    // freopen("out.txt","w",stdout);
#endif
	int T;
	cin>>T;
	int CASE=1;
	while(T--){
		int n;
		cin>>n;
		int i,ans=0;
		rep(i,n){
			scanf("%d",&val[i]);
			if(i!=0){
				if(val[i]<val[i-1])ans+=(val[i-1]-val[i]);
			}
		}
		int maxnum=0;
		rep(i,n){
			if(i!=0){
				if(val[i]<val[i-1]){
					maxnum=max(maxnum,val[i-1]-val[i]);
				}
			}
		}
		int cnt=0;
		rep(i,n){
			if(i==n-1)break;
			if(val[i]<maxnum)cnt+=val[i];
			else cnt+=maxnum;
		}
		printf("Case #%d: %d %d\n",CASE++,ans,cnt);
	}
    return 0;
}
