#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair<PI, PI > PII;
const double eps=1e-5;
const int inf=1e5;
const double pi=acos(-1.0);
const int N=5e5+5;

int a[30];
int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d", &a[i]);
            sum+=a[i];
        }
        printf("Case #%d: ", ca++);
        bool flag=0;
        while(sum)
        {
            int maxni, maxn=0;
            for(int i=0;i<n;i++)
                if(a[i]>maxn)
                    maxn=a[i], maxni=i;
            putchar(maxni+'A'), flag^=1, sum-=1, a[maxni]--;
            if(sum==2) flag=0;
            if(flag==0 && sum!=0) putchar(' ');
        }
        puts("");
    }
    return 0;
}
