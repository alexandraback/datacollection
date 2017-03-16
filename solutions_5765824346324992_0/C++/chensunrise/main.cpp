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
LL M[maxn];
LL gcd(LL a,LL b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
LL gbd(LL a,LL b)
{
    return (a*b)/gcd(a,b);
}
struct node
{
    int v;
    LL T;
    node(){}
    node(int v,LL T):v(v),T(T){}
    bool operator <(const node &A)const
    {
        if (T==A.T) return v>A.v;
        return T>A.T;
    }
};
PQ<node>Q;
int main()
{
    IN; OUT;
    int t,cas=0,B;
    LL N;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%I64d",&B,&N);
        for (int i=1;i<=B;i++) scanf("%I64d",&M[i]);
        LL gg=M[1],num=0;
        for (int i=2;i<=B;i++) gg=gbd(gg,M[i]);
        for (int i=1;i<=B;i++) num+=gg/M[i];
        //if (num==N) {printf("Case #%d: %d\n",++cas,B); continue;}
        if (num<N) {LL tp=N/num; N-=(tp-1)*num; }
        //if (N==0) {printf("Case #%d: %d\n",++cas,B); continue;}
        while(!Q.empty()) Q.pop();
        for (int i=1;i<=B;i++) Q.push(node(i,0));
        while(!Q.empty())
        {
            node tp=Q.top(); Q.pop(); N--;
            if (N==0) {printf("Case #%d: %d\n",++cas,tp.v);break;}
            Q.push(node(tp.v,tp.T+M[tp.v]));
        }
    }
    return 0;
}
