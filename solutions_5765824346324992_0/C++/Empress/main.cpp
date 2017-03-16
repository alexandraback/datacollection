#include <bits/stdc++.h>
using namespace std;

//int a[1005];
//int main()
//{
//    freopen("B-small-attempt0.in", "r", stdin);
//    freopen("out.txt", "w", stdout);
//    int t, ca=1;
//    scanf("%d", &t);
//    while(t--)
//    {
//        int n, b;
//        scanf("%d%d", &b, &n);
//        for(int i=1;i<=b;i++)
//            scanf("%d", &a[i]);
//        int cur=0, ans=-1;
//        for(int i=0;;i++)
//        {
//            for(int j=1;j<=b;j++)
//                if(i==0 || i%a[j]==0)
//                {
//                    cur++;
//                    if(cur==n)
//                    {
//                        ans=j;
//                        break;
//                    }
//                }
//            if(ans!=-1)
//                break;
//        }
//        printf("Case #%d: %d\n", ca++, ans);
//    }
//    return 0;
//}
int M[100];
struct node
{
    int id,time;
    node() {}
    node(int id,int time):id(id),time(time) {}
    bool operator < (const node &a)const
    {
        if(time!=a.time)
            return time>a.time;
        return id>a.id;
    }
};
priority_queue<node> Q;
int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t, ca=1;
    scanf("%d", &t);
    while(t--)
    {
        while(!Q.empty())
            Q.pop();
        int n,l;
        scanf("%d%d", &n, &l);
        for(int i=1; i<=n ; i++)
            scanf("%d", &M[i]);
        int LCM=1;
        for(int i=1; i<=n; i++)
            LCM=LCM*M[i]/__gcd(LCM, M[i]);
        int cnt=0;
        for(int i=1; i<=n ; i++)
            cnt+=LCM/M[i];
        l%=cnt;
        if(!l)
            l+=cnt;
        int ans;
        for(int i=1 ; i<=n ; i++)
            Q.push(node(i, 0));
        while(l--)
        {
            node u=Q.top();
            Q.pop();
            ans=u.id;
            u.time+=M[u.id];
            Q.push(u);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
