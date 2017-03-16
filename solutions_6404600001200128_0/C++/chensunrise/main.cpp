#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define PI acos(-1.0)
#define eps 1e-8
#define LL long long
#define MEM(a,b) memset(a,b,sizeof(a))
#define PB push_back
#define MP make_pair
#define PQ priority_queue
#define MII map<int,int>::iterator
#define MLL map<LL,LL>::iterator
#define PII pair<int,int>
#define SI set<int>::iterator
#define SL set<LL>::iterator
#define MSI map<string,int>::iterator
#define M_SI multiset<int>::iterator
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
#define BUG printf("bug************bug************bug\n");
using namespace std;
const int maxn=2000+10;
int M[maxn];
int main()
{
    IN; OUT;
    int t,cas=0,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&M[i]);
        int ans1=0,ans2=0,tp=0;
        for (int i=2;i<=n;i++)
        if (M[i]<M[i-1]) ans1+=M[i-1]-M[i];
        for (int i=2;i<=n;i++) if (M[i-1]>M[i])tp=max(tp,M[i-1]-M[i]);
        for (int i=1;i<n;i++) if (M[i]>=tp) ans2+=tp; else ans2+=M[i];
        printf("Case #%d: %d %d\n",++cas,ans1,ans2);
    }
    return 0;
}
