#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int a[30];
struct node{
    int id;
    int num;
    bool operator<(const node& w) const
    {
        return num < w.num;
    }
};

int main()
{
    freopen("/Users/os/Desktop/A-large.in.txt", "r", stdin);
    freopen("/Users/os/Desktop/A-large.out.txt", "w", stdout);
    int t, Case = 0;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        priority_queue<node> q;
        int sum;
        for (int i = 0; i < n; i++)
        {
            node now;
            now.id = i;
            scanf("%d", &now.num);
            sum += now.num;
            q.push(now);
        }
        printf("Case #%d:", ++Case);
        while (!q.empty())
        {
            printf(" ");
            node x = q.top();
            q.pop();
            if (x.num > 0)
            {
                printf("%c", x.id + 'A');
                x.num--;
                sum--;
            }
            if (x.num > 0)
            {
                q.push(x);
            }
            if (q.empty())
                break;
            if (q.top().num <= sum / 2)
                continue;
            x = q.top();
            q.pop();
            if (x.num > 0)
            {
                printf("%c", x.id + 'A');
                x.num--;
                sum--;
            }
            if (x.num > 0)
            {
                q.push(x);
            }
        }
        printf("\n");
    }
    
    
}