#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m, T, i, x, j, mn, qq, q, k, t, TT, o, v[105], a[105][105][105], b[105][105][105];
char s[105];
int mod(int x)
{
    if(x>0) return x;
    return -x;
}
int main()
{
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    scanf("%d", &T);
    TT=T;
    while(T--)
    {
        scanf("%d", &n);
        printf("Case #%d: ", TT-T);
        gets(s);
        o=1;
        for(i=1;i<=n;i++)
        {
            gets(s);
            m=strlen(s);
            qq=q;
            q=1;
            a[T][i][q]=s[0]-'a';
            b[T][i][q]=1;
            for(j=1;j<m;j++)
            {
                if(a[T][i][q]==s[j]-'a')
                    b[T][i][q]++;
                else
                {
                    a[T][i][++q]=s[j]-'a';
                    b[T][i][q]=1;
                }
            }
            if(qq!=q&&i>1) o=-1;
            if(i>1)
            {
                for(j=1;j<=q;j++)
                    if(a[T][i][j]!=a[T][i-1][j])
                    {
                        o=-1;
                        break;
                    }
            }
        }
        if(o==-1)
        {
            printf("Fegla Won\n");
            continue;
        }
        t=0;
        for(i=1;i<=q;i++)
        {
            for(j=1;j<=n;j++)
                v[j]=b[T][j][i];
            sort(v+1,v+n+1);
            mn=9999999;
            for(j=1;j<=n;j++)
            {
                x=0;
                for(k=1;k<j;k++)
                    x=x+v[j]-v[k];
                for(k=j+1;k<=n;k++)
                    x=x+v[k]-v[j];
                if(x<mn) mn=x;
            }
            t+=mn;
        }
        printf("%d\n", t);
    }
    return 0;
}
