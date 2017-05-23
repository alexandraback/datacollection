#include <bits/stdc++.h>
using namespace std;
#define read            freopen("C:\\Users\\Dell\\Desktop\\in.txt", "r", stdin)
#define write           freopen("C:\\Users\\Dell\\Desktop\\out.txt", "w", stdout)
#define pii             pair<int , int >
#define inf             INT_MAX/3
#define linf            LLONG_MAX/3
#define in(a)           scanf("%d", &a)
#define ins(a)          scanf("%s", a)
#define in2(a, b)       scanf("%d%d", &a, &b)
#define in3(a, b, c)    scanf("%d%d%d", &a, &b, &c)
#define pn              printf("\n");
#define pr(a)           printf("%d\n", a)
#define prs(a)          printf("%d ", a)
#define pr2(a, b)       printf("%d %d\n", a, b)
#define pr3(a, b, c)    printf("%d %d %d\n", a, b, c)
#define pcs(a)          printf("Case %d: ", a)
#define MP              make_pair
#define vi              vector<int >
#define cl              clear()
#define sz              size()
#define pb              push_back
#define MEM(a, b)       memset((a), (b), sizeof(a))
#define all(X)          (X).begin(), (X).end ()
#define iter(it, X)     for (__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define oka(x, y)       ((x)>=0&&(x)<row&&(y)>=0&&(y)<col)

typedef long long LL;
inline int getnum()
{
    char c = getchar();
    int num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}
string haircut(string a)
{
    int l=0, r=a.size()-1, i;
    string b;
    while (l<a.size()&&a[l]==')'&&a[i]!=']') l++;
    while (r>=0&&a[r]=='('&&a[i]!='[') r--;
    for (i=l; i<=r; i++) b+=a[i];
    return b;
}
//int  dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int  dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int  dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//bool check(int n, int pos) {return (n & (1<<pos))>>pos;} //typecast 1 in case of int
//int  on(int n, int pos) {return n | (1<<pos);} //typecast 1 in case of int
//int  off(int n, int pos) {return n & ~(1<<pos);} //typecast 1 in case of int
//bool operator < (const data &d) const{return cost<d.cost;} //reverse in priority queue

const int M=500100;
struct data {
    int k, cnt;
    data (int a=0, int b=0) {k=a; cnt=b;}
    bool operator < (const data &d) const{return cnt<d.cnt;}
};
priority_queue<data>q;
vector<pii>ans;
int main()
{
#ifndef ONLINE_JUDGE
    read;
    write;
#endif
    int t, cs=0, i, j, k, n;

    in(t);
    while (t--)
    {
        while (!q.empty()) q.pop();

        in(n);
        for (i=0; i<n; i++)
        {
            in(k);
            q.push(data(i, k));
        }

        data a, b;
        while (!q.empty())
        {
            a=q.top();
            q.pop();

            if (q.empty())
            {
                ans.pb(MP(a.k, -1));
                break;
            }

            b=q.top();
            q.pop();


            ans.pb(MP(a.k, b.k));


            a.cnt--;
            b.cnt--;

            if (a.cnt>0) q.push(a);
            if (b.cnt>0) q.push(b);
        }

        printf("Case #%d:", ++cs);
        reverse(all(ans));
        for (i=0; i<ans.size(); i++)
        {
            if (ans[i].second==-1) printf(" %c", ans[i].first+'A');
            else printf(" %c%c", ans[i].first+'A', ans[i].second+'A');
        }
        pn

        ans.cl;
    }

return 0;
}
