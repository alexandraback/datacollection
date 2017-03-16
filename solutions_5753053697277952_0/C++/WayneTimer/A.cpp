#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct typer
{
    int k,v;
};

// can be equal: v*2==s
int n,s;
priority_queue<typer> q;

bool operator < (typer x,typer y)
{
    if (x.v<y.v) return true;
    if (x.v>y.v) return false;
    return (x.k>y.k);
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        while (!q.empty()) q.pop();
        scanf("%d",&n);
        s = 0;
        for (int i=0;i<n;i++)
        {
            typer t;
            scanf("%d",&t.v);
            t.k = i;
            s+=t.v;
            q.push(t);
        }
        printf("Case #%d: ",o);
        while (s)
        {
            typer t;
            int v;
            t = q.top();
            printf("%c",t.k+'A');
            q.pop();
            s--;
            t.v--;
            q.push(t);

            t = q.top();
            if (t.v<<1 > s)
            {
                printf("%c",t.k+'A');
                q.pop();
                s--;
                t.v--;
                q.push(t);
            }
            if (s) printf(" ");
        }
        puts("");
    }
    return 0;
}
