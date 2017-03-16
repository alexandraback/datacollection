#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;
#define nmax 105
int i, n, ls, j, poz, ne, mjc, rez, dist, t, ii;
bool ok;
int nr[nmax][nmax];
char s[nmax], v[nmax];

void citire()
{
    scanf("%ld",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%s",&s);
        ls=strlen(s);
        if (i==1)
           v[1]=s[0];
        else
            ok&=(s[0]==v[1]);
        nr[1][i]=1; poz=1;
        for (j=1;j<ls;j++)
        {
            if (s[j]==s[j-1])
                nr[poz][i]++;
            else
            {
                poz++;
                nr[poz][i]=1;
                if (i==1)
                    v[poz]=s[j];
                else
                    ok&=(s[j]==v[poz]);
            }
        }
        if (i>1)
            ok&=(poz==ne);
        else
            ne=poz;
    }

}

void rezolvare()
{
    mjc=(n+1)/2;    rez=0;
    for (i=1;i<=ne;i++)
    {
        sort(nr[i]+1,nr[i]+1+n);
        for (j=1;j<=n;j++)
        {
            dist=nr[i][j]-nr[i][mjc];
            if (dist<0)
                dist=-dist;
            rez+=dist;
        }
    }
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        ok=1;
        citire();
        printf("Case #%ld: ",ii);
        if (ok)
        {
            rezolvare();
            printf("%ld\n",rez);
        }
        else
            printf("Fegla Won\n");
    }
    return 0;
}
