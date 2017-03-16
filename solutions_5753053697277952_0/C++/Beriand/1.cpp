#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
using namespace std;

struct st
{
    char p;
    int ilu;

    friend bool operator < (st a, st b)
    {
        if (a.ilu==b.ilu)
            return a.p<b.p;

        return a.ilu>b.ilu;
    }
};

set<st> ss;

int main ()
{
    int a,b,c,d,e,f,g,z,n;
    st kaka,kaka2;
    set<st>::iterator it;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        scanf ("%d", &n);

        for (kaka.p=0; kaka.p<n; kaka.p++)
        {
            scanf ("%d", &kaka.ilu);
            ss.insert(kaka);
        }

        printf ("Case #%d:", a);

        while (!ss.empty())
        {
            if (ss.size()>=3)
            {
                it=ss.begin();
                it++;
                it++;

                if (it->ilu==ss.begin()->ilu)
                {
                    kaka=*ss.begin();
                    ss.erase(kaka);
                    kaka.ilu--;

                    if (kaka.ilu)
                        ss.insert(kaka);

                    printf (" %c", 'A'+kaka.p);
                    continue;
                }
            }

            kaka=*ss.begin();
            ss.erase(kaka);
            kaka2=*ss.begin();
            ss.erase(kaka2);

            printf (" %c%c", 'A'+kaka.p, 'A'+kaka2.p);

            kaka.ilu--;
            kaka2.ilu--;

            if (kaka.ilu)
                ss.insert(kaka);

            if (kaka2.ilu)
                ss.insert(kaka2);
        }

        printf ("\n");
    }

    return 0;
}
