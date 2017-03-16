#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<ctime>
#include<cctype>
#include<cmath>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<map>
#include<set>
#define sqr(x) ((x)*(x))
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.14159265358979
#define eps 1e-10
#define mm

using namespace std;

char s1[2222],s2[2222];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
		freopen("t2","w",stdout);
	#endif

	int tt;
	scanf("%d",&tt);

	for (int t=1;t<=tt;t++)
    {
        int n;
        scanf("%d",&n);
        printf("Case #%d: ",t);
        scanf("%s",s1);
        scanf("%s",s2);
        int l1=strlen(s1);
        int l2=strlen(s2);
        int i1=0,i2=0,c1=0,c2=0;
        int ans=0;

        while (s1[i1]==s2[i2])
        {
            c1=1;c2=1;
            while (i1+1<l1 && s1[i1]==s1[i1+1])
            {
                i1++;c1++;
            }
            while (i2+1<l2 && s2[i2]==s2[i2+1])
            {
                i2++;c2++;
            }
            ans+=abs(c1-c2);
            i1++;i2++;
            if (i1==l1 || i2==l2)  break;

        }
        if (i1==l1 && i2==l2)
        {
            printf("%d\n",ans);
        }
        else
        {
            puts("Fegla Won");
        }

    }




	return 0;
}
