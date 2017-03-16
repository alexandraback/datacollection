#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
using namespace std;

#define x first
#define y second
int quad(const pair<long, long> &p)
{
    int x=p.x, y=p.y;
    if (x > 0 && y >= 0) return 1;
    if (x <= 0 && y > 0) return 2;
    if (x < 0 && y <= 0) return 3;
    if (x >= 0 && y < 0) return 4;
    assert(false);
}

long long ar(const pair<long, long> &p1, const pair<long, long> &p2)
{
    return p2.x*p2.y - p1.x*p1.y + (p1.x-p2.x)*(p1.y+p2.y);
}

bool cmp(const pair<long, long> &p1, const pair<long, long> &p2)
{
    if (quad(p1) < quad(p2)) return true;
    if (quad(p2) < quad(p1)) return false;
    return ar(p1, p2) > 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        int N, X[3001], Y[3001];
        scanf("%d", &N);
        for(int i=0; i<N; i++)
        {
            scanf("%d %d", X+i, Y+i);
        }
        printf("Case #%d:\n", t);
        for(int k=0; k<N; k++)
        {
            pair<long, long> pt[3001];
            int p=0;
            for(int j=0; j<N; j++)
                if(j!=k)
                {
                    pt[p++] = make_pair(X[j]-X[k], Y[j]-Y[k]);
                }
            sort(pt, pt+p, cmp);
            int ans = N;
            int pos2=0;
            for (int pos1 = 0; pos1 < p; pos1++)
            {
                while (true)
                {
                    int next = (pos2+1)%p;
                    long long a = ar(pt[pos1], pt[next]);
                    if (a > 0)
                    {
                        pos2 = next;
                    }
                    else break;
                }
                ans = min(ans, (pos2+p-pos1)%p);
                if (pos2 == pos1) pos2 = (pos1+1)%p;
            }
            if (N==1) ans=0;
            printf("%d\n", ans);
        }
    }
}
