#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

vector<char>v,w;
int a[200][200];
char s[200];
vector<int>b;

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int i,j,k,m,n,T,ts=0,mi,ans,ok;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d: ",++ts);
		scanf("%d",&n);
		scanf("%s",&s);
		j=m=0;
		ans=0;
		v.clear();
		for(i=0;s[i];i++)
			if(s[i]!=s[j])
			{
				v.push_back(s[j]);
				a[0][m++]=i-j;
				j=i;
			}
		v.push_back(s[j]);
		a[0][m++]=i-j;
		ok=false;
		for(k=1;k<n;k++)
		{
			scanf("%s",&s);
			w.clear();
			j=m=0;
			for(i=0;s[i];i++)
				if(s[i]!=s[j])
				{
					w.push_back(s[j]);
					a[k][m++]=i-j;
					j=i;
				}
			w.push_back(s[j]);
			a[k][m++]=i-j;
			if(w!=v)
				ok=true;
		}
		if(ok)
		{

			puts("Fegla Won");
			continue;
		}
		for(i=0;i<m;i++)
		{
			b.clear();
			for(j=0;j<n;j++)
				b.push_back(a[j][i]);
			sort(b.begin(),b.end());
			k=0;
			for(j=0;j<n;j++)
				k+=b[j]-b[0];
			mi=k;
			for(j=1;j<n;j++)
			{
				k+=(2*j-n)*(b[j]-b[j-1]);
				if(mi>k)mi=k;
			}
			ans+=mi;
		}
		printf("%d\n",ans);				
	}
	return 0;
}