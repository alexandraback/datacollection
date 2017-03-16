#include <bits/stdc++.h>
using namespace std;

struct data
{
	char a;
	int num;
}senate[30];


bool comp(const data &a,const data &b)
{
	return a.num<b.num;
}

int main()
{
    freopen("aL.in","r",stdin);
    freopen("outL.txt","w",stdout);
	int t;
	scanf("%d",&t);
	int tc = 1;
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&senate[i].num);
			senate[i].a = 'A'+i;
		}
		sort(senate,senate+n,comp);
		string ans = "";
		for(int i=0;i<n-1;i++)
		{
			while(senate[i].num!=0)
			{
				ans = ans + senate[i].a + senate[i+1].a;
				ans = ans + " ";
				senate[i].num--;
				senate[i+1].num--;
			}
		}
		while(senate[n-1].num!=0)
		{
		    if(senate[n-1].num>=2)
            {
                ans = ans + senate[n-1].a + senate[n-1].a;
                senate[n-1].num-=2;
            }
            else
            {
                ans = ans + senate[n-1].a;
                senate[n-1].num--;
            }
            if(senate[n-1].num!=0)
            {
                ans = ans + " ";
            }
		}

		int len = ans.length();
		printf("Case #%d: ",tc);
		tc++;
		int k = len-1;
		if(ans[k]==' ')
        {
            k--;
        }
		for(;k>=0;k--)
		{
			printf("%c",ans[k]);
		}
		printf("\n");
	}
}
