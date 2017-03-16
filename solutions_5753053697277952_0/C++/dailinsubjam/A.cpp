#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 30;

int a[N], n;

int main()
{
    int T;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; ++Case)
    {
        printf("Case #%d:", Case);
        scanf("%d", &n);
        int sum = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]), sum += a[i];
        priority_queue< pair<int, int> > que;
        while(!que.empty()) que.pop();
        for(int i = 1; i <= n; ++i) que.push(make_pair(a[i], i));
        while(!que.empty())
        {
            pair<int, int> now = que.top(); que.pop();
            
            bool ok = 1;
            if(now.first < 2) ok = 0;
            if(!que.empty() && que.top().first * 2 <= sum - 1)
            {
                printf(" %c", 'A' + now.second - 1);
                a[now.second] -= 1;
                sum -= 1;
            }
            else if(!que.empty() && que.top().first * 2 > (sum - 2))
            {
                pair<int, int> now2 = que.top(); que.pop();
                printf(" %c%c", 'A' + now.second - 1, 'A' + now2.second - 1);
                a[now.second] -= 1;
                a[now2.second] -= 1;
                sum -= 2;
                if(a[now2.second] > 0) que.push(make_pair(a[now2.second], now2.second));
            }
            else if(ok)
            {
                printf(" %c%c", 'A' + now.second - 1, 'A' + now.second - 1);
                a[now.second] -= 2;
                sum -= 2;
            }
            else
            {
                printf(" %c", 'A' + now.second - 1);
                a[now.second] -= 1;
                sum -= 1;
            }
            
            if(a[now.second] > 0) que.push(make_pair(a[now.second], now.second));
        }
        printf("\n");
    }
    return 0;
}