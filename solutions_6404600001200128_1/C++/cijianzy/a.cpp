// File Name: a.cpp
// Author: darkdream
// Created Time: 2015年04月18日 星期六 09时52分04秒

#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#define LL long long

using namespace std;
LL a[10005];
int T;
int main(){
	freopen("A-large.in","r",stdin);
	freopen("output","w",stdout);
	scanf("%d",&T);
	for(int ca = 1; ca <= T; ca ++){
	   int n ; 	
	   LL ans1 = 0 ;
	   LL ans2 = 0 ;
	   LL mx = 0 ; 
	   scanf("%d",&n);
	   for(int i= 1;i <= n;i ++){
			scanf("%lld",&a[i]);
			if(i != 1 )
		    if(a[i] < a[i-1])
			{
				ans1 += a[i-1] - a[i];
				mx = max(a[i-1] - a[i],mx);
			}
	   }
	   //printf("%lld\n",mx);
	   for(int i = 1;i < n;i ++)
	   {
			if(a[i] < mx )
				ans2 += a[i];
			else ans2 += mx ;
	   }
	   printf("Case #%d: %lld %lld\n",ca,ans1,ans2);

	}
return 0;
}
