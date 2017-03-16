#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
struct LIST
{
    int x, y;
    LIST(int x_, int y_) : x(x_), y(y_)
    {}
    bool operator < (const LIST& rhs) const
    {
        if(y != rhs.y) return y < rhs.y;
        return x < rhs.x;
    }
};
int T, N;
void Print(LIST a)
{
    printf("%c", 'A' + a.x - 1);
}
int main()
{
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        int N;
        scanf("%d", &N);
        int K = 0;
        priority_queue<LIST> pq;
        for(int i = 1; i <= N; i++)
        {
            int x;
            scanf("%d", &x);
            pq.push(LIST(i, x));
            K += x;
        }
        printf("Case #%d: ", t);
        int cnt = 0;
        while(K > 2)
        {
            LIST a = pq.top();
            pq.pop();
            if(a.y > 1)
            {
                pq.push(LIST(a.x, a.y - 1));
            }
            LIST b = pq.top();
            if(cnt == 2 || (cnt != 0 && 2 * (b.y) > (K - 1)))
            {
                printf(" ");
                cnt = 0;
            }
            Print(a); K--;
            cnt++;
        }
        if(cnt != 0) printf(" ");
        while(K > 0)
        {
            LIST a = pq.top();
            Print(a); pq.pop(); K--;
        }
        printf("\n");
    }
}
