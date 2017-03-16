#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<list>
#include<map>
#include<queue>
#include<stack>

#define inp(n) scanf("%d",&n);
#define inp2(x,y) scanf("%d%d",&x,&y);
#define inpl(n) scanf("%lld",&n);
#define inpl2(x,y) scanf("%lld%lld",&x,&y);
#define out(n) printf("%d\n",n);
#define outl(n) printf("%lld\n",n);
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,b,a) for(int i=b-1;i>=a;i--)
#define PB(a) push_back(a)
#define C(x) printf("%d\n",x);
#define MAX 1000010

using namespace std;

typedef vector< int > vi;
typedef pair< int,int > pii;
typedef vector< pii > vpii;
typedef list< int > li;
typedef long long ll;
typedef unsigned long long ull;

/*int gcd(int a,int b)
{
	while(b)
		b^=a^=b^=a%=b;
	return a;
}*/

/*int mypower(int base,int index)
{
	if(index == 0)
		return 1;
	else if(index == 1)
		return base;
	int temp=mypower(base,index/2);
	temp=(temp*temp);
	if(index&1)
		return temp*base;
	else
		return temp;
}*/

main()
{
	int t,n,num=0;
	inp(t)
	while(t--)
	{
		char s[200][200],c[200][200];
		num++;
		int b[200][200]={};
		inp(n)
		FOR(i,0,n)
			scanf("%s",s[i]);
		FOR(i,0,n)
		{
			int j;
			for(j=0;s[i][j];j++)
				c[i][j]=s[i][j];
			c[i][j]='\0';
		}
		FOR(i,0,n)
		{
			int j,k;
			c[i][0]=s[i][0];
			k=0;
			for(j=0;s[i][j];j++)
				if(s[i][j] != c[i][k])
				{
					k++;
					c[i][k]=s[i][j];
				}
			k++;
			c[i][k]='\0';
		}
		int flag=0;
		/*FOR(i,0,n)
			printf("%s\n",c[i]);*/
		FOR(i,0,n)
		{
			FOR(j,i+1,n)
			{
				if(strcmp(c[i],c[j]))
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)	
		{
			printf("Case #%d: Fegla Won\n",num);
			continue;
		}
		else
		{
			int k=0,i;
			FOR(j,0,n)
			{
				i=0;
				for(int l=0;s[j][l];l++)
				{
					if(s[j][l] != c[0][i])
						i++;
					b[j][i]++;
				}
			}
			/*FOR(j,0,n)
			{
				for(int i=0;c[j][i];i++)
					printf("%d ",b[j][i]);
				cout<<endl;
			}*/
			int ans=0;
			for(int l=0;c[0][l];l++)
			{
				int m=0;
				FOR(j,0,n)	
					m=max(m,b[j][l]);
				int y=0,z;
				FOR(j,1,m+1)
				{
					y=0;
					FOR(p,0,n)
						y+= abs(b[p][l]-j);
					if(j==1)
						z=y;
					else
						z=min(z,y);
				}
				ans+=z;
			}
			printf("Case #%d: %d\n",num,ans);
		}
				
		
	}
	
	return 0;
}
