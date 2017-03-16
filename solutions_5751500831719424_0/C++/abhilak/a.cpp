#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<string>
#include<cctype>
#include<list>
#include<set>
#include<deque>
#include<queue>
#include<bitset>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iomanip>
#include<ctime>
 
using namespace std;

int main()
{
	int t ,j,l,i,test=1,n,a[200][200],b[200],flag,ans,c;
	string s[200] , s1[200] ;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			cin >> s[i] ;
			l=s[i].length();
			s1[i]="";
			int count;
			c=0;
			for(j=0;j<l;j++)
			{
				s1[i]+=s[i][j];
				count=1;
				while((j<l-1)&&s[i][j]==s[i][j+1])
				{
					j++;
					count++;
				}
				a[i][c]=count;
				c++;
			}
		}
		flag=1;
		for(i=0;i<n-1;i++)
		{
			if(s1[i]!=s1[i+1])
			{
				flag=0;
				break;
			}
		}
		if(!flag)
		{
			printf("Case #%d: Fegla Won\n",test);
		}
		else
		{

			ans=0;
			for(i=0;i<c;i++)
			{
				for(j=0;j<n;j++)
				{
					b[j]=a[j][i];
					//printf("%d \n",b[j]);
				}
				//printf("\n");
				sort(b,b+n);
				l=b[(n/2)];
				for(j=0;j<n;j++)
				{
					ans+=abs(l-b[j]);
				}
			}
			printf("Case #%d: %d\n",test,ans);
		}
		test++;
	}
	return 0;
}