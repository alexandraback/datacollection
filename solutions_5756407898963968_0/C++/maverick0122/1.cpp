#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<set>
using namespace std;

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		int n;
		scanf("%d",&n);
		int da[4];
		for(int i=1; i<=4; i++)
        {
            for(int j=0; j<4; j++)
            {
                int tmp;
                scanf("%d",&tmp);
                if(i==n) da[j]=tmp;
            }
        }
        scanf("%d",&n);
        int ans = 0, ret = -1;
        for(int i=1; i<=4; i++)
        {
            for(int j=0; j<4; j++)
            {
                int tmp;
                scanf("%d",&tmp);
                if(i==n)
                {
                    for(int k=0; k<4; k++)
                        if(tmp==da[k])
                        {
                            ans++;
                            ret = tmp;
                        }
                }
            }
        }
        if(ans==0) printf("Case #%d: Volunteer cheated!\n",cnt);
        else if(ans==1) printf("Case #%d: %d\n",cnt,ret);
        else printf("Case #%d: Bad magician!\n",cnt);
	} 
} 
