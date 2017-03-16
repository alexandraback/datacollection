#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#define MAXN 1005
using namespace std;
int gcd(int a, int b)
{
    if(a % b == 0) return b;
    else
        return gcd(b, a % b);
}
struct Node
{
    int mm, id;
    bool operator < (const Node &a) const
    {
        if(mm != a.mm) return mm > a.mm;
        else
            return id > a.id;
    }
};
int star[MAXN];
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out.out", "w", stdout);
    int t;
    scanf("%d", &t);
    int m, n;
    int numCase = 1;
    while(t--)
    {
        int sum = 1;
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &star[i]);
            sum *= star[i];
        }
       int G = star[0];
       for(int i = 1; i < m; i++)
       {
           G = gcd(star[i], G);
       }
       int lcm = sum / G;
       printf("Case #%d: ",numCase++);
       if(m == 1)
       {
           printf("1\n");
           continue;
       }
       else
       {
           int s = 0;
           for(int i = 0; i < m; i++) s += (lcm / star[i]);
           int num = n % s;
           if(num == 0) num = s;
           priority_queue<Node> Q;
           while(!Q.empty()) Q.pop();
           int ans = -1;
           for(int i = 0; i < m; i++)
           {
               Node now;
               now.id = i;
               now.mm = 0;
               Q.push(now);
           }
           for(int i = 0; i < num; i++)
           {
               Node now = Q.top();
               Q.pop();
               ans = now.id + 1;
               now.mm += (star[now.id]);
               Q.push(now);
           }
           printf("%d\n", ans);
       }
    }
    return 0;
}
