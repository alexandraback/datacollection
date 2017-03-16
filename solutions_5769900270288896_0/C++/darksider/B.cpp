#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define clear(a) memset((a),0,sizeof(a))
#define pb push_back
#define SIZE(v) v.size()
#define ull unsigned long long int
#define lli long long int
#define li long int
#define ii int
#define mod 1000000007
/* Created by : Rahul Johari
				Thapar University */

lli A[1<<21];
lli R,C,N;
 
inline lli func ( lli x )
{
	lli r,c,cnt=0;
	for ( r=0;r<R;r++ )
	{
		for ( c=0;c<C;c++ )
		{
			if ( c>0 && (x&(1<<(r*C+c))) && (x&(1<<(r*C+c-1))) )
				cnt += 1;
			if ( r>0 && (x&(1<<(r*C+c))) && (x&(1<<(r*C+c-C))) )
				cnt += 1;
		}
	}
	return cnt;
}
 
int main() 
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-s.txt","w",stdout);
	
	lli t,cse,ans,i;
	
	scanf("%lld",&t);
	
	for ( cse=1;cse<=t;cse++ )
	{
		scanf("%lld %lld %lld",&R,&C,&N);
		
		ans = R*C*N*100;
		
		for ( i=1;i<(1<<(R*C));i++ )
		{
			A[i] = A[i-(i&-i)] + 1;
			
			if ( A[i]==N ) 
				ans = (ans<func(i))?ans:func(i);
		}
		printf("Case #%lld: %lld\n",cse,ans);
	}
	return 0;
}
