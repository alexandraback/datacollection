#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<time.h>
#include<vector>
using namespace std;

int a[110];

int get(int n)
{
    sort(a,a+n);
    int i,ret=0;

    for(i=0;i<n;i++)
	ret+=abs(a[i]-a[n/2]);
    return ret;
}

char s[110];
vector<int>val[110];
vector<int>num[110];

int main()
{
    int t,n,i,j,k;
    int ii=0;

    freopen("a.in","r",stdin);
    freopen("a.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    val[i].clear();
	    num[i].clear();
	    scanf("%s",s);

	    for(j=0;s[j];j++)if(j==0||s[j]-s[j-1])
	    {
		val[i].push_back(s[j]);
		num[i].push_back(1);
	    }
	    else
		num[i][num[i].size()-1]++;
	}
	int lose=0;
	for(i=1;i<n;i++)if(val[i].size()-val[i-1].size())
	    lose=1;
	if(!lose)
	{
	    for(i=1;i<n;i++)
		for(j=0;j<val[0].size();j++)if(val[i][j]-val[i-1][j])
		{
		    lose=1;
		}
	}
	printf("Case #%d: ",++ii);
	if(lose)
	    puts("Fegla Won");
	else
	{
	    int ans=0;
	    for(i=0;i<val[0].size();i++)
	    {
		for(j=0;j<n;j++)
		    a[j]=num[j][i];
		ans+=get(n);
	    }
	    printf("%d\n",ans);
	}
    }
}
