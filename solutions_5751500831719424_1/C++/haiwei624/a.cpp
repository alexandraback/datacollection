#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define MST(a,b) memset(a,b,sizeof(a))
#define MAXN 105
int n;
int an[MAXN],a[MAXN][MAXN],b[MAXN][MAXN];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int nn;
    scanf("%d",&nn);
    FOR(ii,1,nn)
    {
        printf("Case #%d: ",ii);
        MST(an,0);
        scanf("%d",&n);
        FOR(i,1,n)
        {
            char s[MAXN];
            scanf("%s",&s);
            if(!s[0])continue;
            an[i]=1;
            a[i][1]=s[0];
            b[i][1]=1;
            for(int j=1;s[j];j++)
            if(s[j]==a[i][an[i]])b[i][an[i]]++;
            else{
                an[i]++;
                a[i][an[i]]=s[j];
                b[i][an[i]]=1;
            }
        }
        int failed=0;
        FOR(i,2,n)if(an[i]!=an[1])failed=1;
        if(failed)
        {
            printf("Fegla Won\n");
            continue;
        }
        FOR(i,1,an[1])FOR(j,2,n)
            if(a[j][i]!=a[1][i])failed=1;
        if(failed)
        {
            printf("Fegla Won\n");
            continue;
        }
        int ans=0;
        FOR(i,1,an[1])
        {
            int c[MAXN];
            FOR(j,1,n)c[j]=b[j][i];
            sort(c+1,c+n+1);
            FOR(j,1,n)ans+=abs(c[j]-c[(n+1)/2]);
        }
        printf("%d\n",ans);
    }

    return 0;
}
