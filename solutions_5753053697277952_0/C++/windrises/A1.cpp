#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<complex>
#define ft first
#define sd second
#define pb push_back
#define mkp make_pair
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)<(b)?(b):(a))
using namespace std;
typedef long long LL;
typedef pair<int,int> Pair;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
const int maxn=1010;
int n;
struct Node
{
    char ch;
    int num;
    bool operator<(const Node &x)const{
        return num<x.num;
    }
};
priority_queue<Node> q;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    //freopen("A-large.in","r",stdin);
    //freopen("A-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        while(!q.empty()) q.pop();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            q.push(Node{char('A'+i-1),a});
        }
        printf("Case #%d: ",kase);
        if(q.size()==2)
        {
            Node t1=q.top();
            q.pop();
            Node t2=q.top();
            q.pop();
            printf("%c%c",t1.ch,t2.ch);
            t1.num--;
            t2.num--;
            if(t1.num>0) q.push(t1);
            if(t2.num>0) q.push(t2);
        }
        else
        {
            Node t=q.top();
            q.pop();
            printf("%c",t.ch);
            t.num--;
            if(t.num>0) q.push(t);
        }
        while(!q.empty())
        {
            if(q.size()==2)
            {
                Node t1=q.top();
                q.pop();
                Node t2=q.top();
                q.pop();
                printf(" %c%c",t1.ch,t2.ch);
                t1.num--;
                t2.num--;
                if(t1.num>0) q.push(t1);
                if(t2.num>0) q.push(t2);
            }
            else
            {
                Node t=q.top();
                q.pop();
                printf(" %c",t.ch);
                t.num--;
                if(t.num>0) q.push(t);
            }
        }
        puts("");
    }
}
