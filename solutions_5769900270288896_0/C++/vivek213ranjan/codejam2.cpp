#include <bits/stdc++.h>
#define INPUT ( { int a ; read(a) ; a; } )
using namespace std; 
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
int r,c,n;
int function(int posn)
{
	int result = 0;
	for (int i=0;i<r;i++)
	{
		for (int j=0; j<c;j++)
		{
			if (j>0 && (posn & (1<<(i*c+j))) && (posn & (1<<(i*c+j-1))))
				result++;
			if (i>0 && (posn & (1<<(i*c+j))) && (posn & (1<<(i*c+j-c))))
				result++;
		}
	}
	return result;
}
int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	int dp[1<<18];
	cin>>t;
	for (int cases=1; cases<=t;cases++)
	{
cin>>r>>c>>n;
		//r = INPUT ;
		//c = INPUT ;
		//n = INPUT ;
		int full = r*c*n*100;
		for(int i=1;i<(1<<(r*c));i++)
		{
			dp[i] =dp[i-(i & -i)]+1;
			if (dp[i]==n) 
			full=min(full,function(i));
		}
		printf("Case #%d: %d\n",cases,full);
	}
}
