#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int main()
{
	int t;
	getint(t);
	int r,c,n,ind,i,j,k;
	rep(ind,1,t)
	{
		getint(r);
		getint(c);
		getint(n);
		printf("Case #%d: ", ind);
		if((r*c)==1)
		{
			putintln(0);
			continue;
		}
		int tot=1<<(r*c);
		int mini=10000000,val=0,mat[r][c];
		rep(i,1,tot)
		{
			val=0;
			j=0;
			int temp=i;
			int cr=0;
			while(j!=(r*c))
			{
				if(temp%2==1)
				{
					mat[j/c][j%c]=1;
					cr++;
				}
				else
					mat[j/c][j%c]=0;
				temp/=2;
				j++;
			}
			if(cr!=n)
				continue;
			rep(j,0,r-1)
			rep(k,0,c-1)
			{
				if(k!=(c-1))
					if(mat[j][k]==1&&mat[j][k+1]==1)
						val++;
				if(j!=(r-1))
					if(mat[j][k]==1&&mat[j+1][k]==1)
						val++;
			}
			if(val<mini)
				mini=val;
		}
		putintln(mini);
	}
}