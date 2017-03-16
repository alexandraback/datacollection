#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<pair<int,int> > VII;

const double eps = 1e-8;
const double pi = acos(-1.0);
#define N 107
char s[N][N];
string s0[N];
int num[N][N];
int a[N];
int main(){
    freopen("AA.in","r",stdin);
    freopen("A.out","w",stdout);
    int cas,k,n;
    scanf("%d",&cas);
    for (int run=1;run<=cas;run++)
    {
        memset(num,0,sizeof num);
        scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            s0[i]="";
            s0[i]+=s[i][0];
            k=1;
            num[i][0]=1;
            for (int j=1;s[i][j];j++)
                if (s[i][j]!=s0[i][k-1])
                {
                    s0[i]+=s[i][j];
                    num[i][k++]=1;
                }
                else
                    num[i][k-1]++;
        }
        bool ok=true;
        for (int i=1;i<n;i++)
            if (s0[i]!=s0[0])
            {
                ok=false;
                break;
            }
        printf("Case #%d: ",run);
        if (ok)
        {
            int ans=0;
            int l=s0[0].length();
            for (int i=0;i<l;i++)
            {
                for (int j=0;j<n;j++)
                    a[j]=num[j][i];
                sort(a,a+n);
                for (int j=0;j<n;j++)
                    ans+=abs(a[j]-a[n/2]);
            }
            printf("%d\n",ans);
        }
        else
            printf("Fegla Won\n");
    }
    return 0;
}
