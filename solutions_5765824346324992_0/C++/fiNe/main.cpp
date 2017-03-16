#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

#define maxn 1010

typedef pair<int, int> barber;
int N, B, M[maxn];

priority_queue<barber, vector<barber>, greater<barber> > que;

int gcd(int a, int b)
{
    int c = a % b;
    while(c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out", "w",stdout);
    int T, time, product, cnt;
    barber tmp;
    scanf("%d", &T);
    for(int Case = 1; Case <= T; Case++)
    {
        product = 1;
        cnt = 0;
        while(!que.empty())
            que.pop();
        scanf("%d%d", &B, &N);

        for(int i = 0; i < B; i++)
        {
            que.push(barber(0, i + 1));
        }

        for(int i = 1; i <= B; i++)
        {
            scanf("%d", &M[i]);
            product = lcm(M[i], product);
        }
        for(int i = 1; i <= B; i++)
        {
            cnt += product / M[i];
        }

        int K = 1000;
        time = 0;
        N %= cnt;
        N += cnt;
        for(int i = 1; i < N; i++)
        {
            tmp = que.top();
            que.pop();
            time = tmp.first;
            que.push(barber(time + M[tmp.second], tmp.second));
        }
        printf("Case #%d: %d\n", Case, que.top().second);
    }
    return 0;
}
