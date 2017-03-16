#include <stdlib.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#define FOR(x,z) for(int x=0;x<(z);++x)
#define DS(i) fprintf(stderr, "DEBUG: %s\n",i);
#define DI(i) fprintf(stderr, "DEBUG: %d\n",i);
#define DF(i) fprintf(stderr, "DEBUG: %f\n",i);
using namespace std;
int t1[4][4], t2[4][4];
int a1, a2;
void wczytaj()
{
    scanf("%d", &a1);
    FOR(i,4)
        FOR(j,4)
            scanf("%d",&t1[i][j]);
    scanf("%d", &a2);
    FOR(i,4)
        FOR(j,4)
            scanf("%d", &t2[i][j]);

}
void wykonaj()
{

    int w=0;
    int o=0;
    FOR(i,4)
        FOR(j,4)
        if(t2[a2-1][j]==t1[a1-1][i])
        {
            o=t1[a1-1][i];
            w++;
        }
    switch(w)
    {
    case 0:
        printf("%s\n", "Volunteer cheated!");
        break;
    case 1:
        printf("%d\n", o);
        break;
    default:
        printf("%s\n", "Bad magician!");
    }

}
int main()
{
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        wczytaj();
        DI(t)
        printf("Case #%d: ",t);
        wykonaj();
    }
    return 0;
}
