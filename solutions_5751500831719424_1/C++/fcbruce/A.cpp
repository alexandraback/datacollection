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

char s[111][111];
int l[111];
int si[111];
int c[111];

int n,ans;

bool check1()
{
    for (int i=1;i<n;i++)
    {
        if (s[i][si[i]]!=s[0][si[0]])
        {
            return false;
        }
    }
    return true;
}

bool check2()
{
    for (int i=0;i<n;i++)
    {
        if (si[i]==l[i])
            return true;
    }
    return false;
}

bool check3()
{
    for (int i=0;i<n;i++)
    {
        if (si[i]!=l[i])
            return false;
    }
    return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("t","r",stdin);
		freopen("tA_big","w",stdout);
	#endif

	int tt;
	scanf("%d",&tt);

	for (int t=1;t<=tt;t++)
    {

        scanf("%d",&n);
        printf("Case #%d: ",t);
        for (int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            l[i]=strlen(s[i]);
        }
        memset(si,0,sizeof(si));
        ans=0;

        while (check1())
        {
            for (int i=0;i<n;i++)
            {
                c[i]=1;
                while (si[i]+1<l[i] && s[i][si[i]]==s[i][si[i]+1])
                {
                    si[i]++;c[i]++;
                }
                si[i]++;
            }
            sort(c,c+n);
            for (int i=0;i<n;i++)
            {
                ans+=abs(c[n>>1]-c[i]);
            }

            if (check2())  break;

        }
        if (check3())
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
