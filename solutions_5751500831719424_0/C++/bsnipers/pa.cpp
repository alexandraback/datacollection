#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[105][105];
int m[105][105];

int main()
{
	int i1,i2,i3,j,j2;
	int t,n;
	int l;
	char pat[105];
	int ans;
	
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	
	scanf("%d",&t);
	for(i1=1; i1<=t; i1++)
	{
		ans=0;
		memset(m,0,sizeof(m));
		scanf("%d",&n);
		for(i2=0; i2<n; i2++)
		{
			scanf("%s",str[i2]);
		}
		l=strlen(str[0]);
		j=0;
		pat[0]=str[0][0];
		m[0][0]=1;
		for(i2=1; i2<l; i2++)
		{
			if(pat[j]!=str[0][i2])
			{
				j++;
				pat[j]=str[0][i2];
				m[j][0]++;
			}else{
				m[j][0]++;
			}
		}
		pat[j+1]=' ';
		for(i2=1; i2<n; i2++)
		{
			if(pat[0]!=str[i2][0])
			{
				break;
			}
			m[0][i2]=1;
			l=strlen(str[i2]);
			j2=0;
			for(i3=1; i3<l; i3++)
			{
				if(pat[j2]!=str[i2][i3])
				{
					if(pat[j2+1]==str[i2][i3])
					{
						j2++;
						m[j2][i2]++;
					}else{
						break;
					}
				}else{
					m[j2][i2]++;
				}
			}
			if(i3!=l)
			{
				break;
			}
			if(j2!=j)
			{
				break;
			}
		}
		if(i2!=n)
		{
			printf("Case #%d: Fegla Won\n",i1);
			continue;
		}
		for(i2=0; i2<=j; i2++)
		{
			sort(m[i2],m[i2]+n);
			for(i3=0; i3<n/2; i3++)
			{
				ans+=m[i2][n/2]-m[i2][i3];
			}
			for(i3++; i3<n; i3++)
			{
				ans+=m[i2][i3]-m[i2][n/2];
			}
		}
		printf("Case #%d: %d\n",i1,ans);
	}
	
	return 0;
}

