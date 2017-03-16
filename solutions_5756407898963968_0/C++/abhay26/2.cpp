/* ***************************
Author: Abhay Mangal (abhay26)
*************************** */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <numeric>
#include <utility>
#include <bitset>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
 #define tr(container, it) \
    for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define maX(a,b) (a) > (b) ? (a) : (b)
#define pii pair< int, int >
#define pip pair< int, pii >
#define FOR(i,n) for(int i=0; i<(int)n ;i++)
#define REP(i,a,n) for(int i=a;i<(int)n;i++)
#define pb push_back
#define mp make_pair
typedef long long ll;
//int dx[]= {-1,0,1,0};
//int dy[]= {0,1,0,-1};
int c[17];
int A[5][5];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    FOR(z,t)
    {
        for(int i=1;i<=16;i++)
            c[i] = 0;
        int r1,r2;
        scanf("%d",&r1);
        FOR(i,4)
            FOR(j,4)
                scanf("%d",&A[i][j]);
        for(int i=0;i<4;i++)
        {
            int x = A[r1-1][i];
            c[x]++;
        }
        scanf("%d",&r2);
        FOR(i,4)
            FOR(j,4)
                scanf("%d",&A[i][j]);
        for(int i=0;i<4;i++)
        {
            int x = A[r2-1][i];
            c[x]++;
        }
        int fl = 0; //
        int ans = -1;
        for(int i=1;i<=16;i++)
        {
            if(c[i] == 2 && ans == -1)
                ans = i;
            else if(c[i] == 2 && ans != -1)
                fl = 1;// Bad magician
        }
        printf("Case #%d: ",z+1);
        if(fl == 0 && ans == -1)
        {
            printf("Volunteer cheated!\n");
        }
        else if(fl == 1)
        {
            printf("Bad magician!\n");
        }
        else
        {
            printf("%d\n",ans);
        }
    }
return 0;
}
