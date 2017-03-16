#include <iostream>
#include <cstdio>
using namespace std;

bool p[20],q[20];
int n;


int main()
{
    FILE *out = fopen("ki.txt", "w");
    scanf("%d", &n);

    for (int ii = 1; ii<=n; ii++)
    {
        for (int i = 1; i<=16; i++) { p[i] = false; q[i] = false; }
        int row1,row2;
        scanf("%d", &row1);
        for (int i = 1; i<=4; i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (row1 == i)
            {
                p[a] = true;
                p[b] = true;
                p[c] = true;
                p[d] = true;
            }
        }

        scanf("%d", &row2);
        for (int i = 1; i<=4; i++)
        {
            int a,b,c,d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (row2 == i)
            {
                q[a] = true;
                q[b] = true;
                q[c] = true;
                q[d] = true;
            }
        }

        int h = -1;
        bool more = false;
        for (int i = 1; i<=16; i++)
        {
            if (p[i] && q[i])
            {
                if (h>-1) more = true;
                h = i;
            }
        }
        if (more) fprintf(out, "Case #%d: Bad magician!\n", ii);
        else
        {
            if (h == -1) fprintf(out, "Case #%d: Volunteer cheated!\n", ii);
            else fprintf(out, "Case #%d: %d\n", ii, h);
        }
    }

    return 0;
}
