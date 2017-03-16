#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define MP make_pair
#define PB push_back
#define TR(it,c) for( typeof(c.begin()) it = c.begin(); it != c.end(); ++it )
#define TRR(it,c) for( typeof(c.rbegin()) it = c.rbegin(); it != c.rend(); ++it
#define REP(i,a) for (int i = 0; i < (a); i++)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)

#define DRI(a) int a; scanf("%d", &a);
#define DRII(a, b) int a, b; scanf("%d %d", &a, &b);
#define RI(a) scanf("%d", &a);
#define RII(a, b) scanf("%d %d", &a, &b);

#define MM(arr, num) memset((arr), (num), sizeof((arr)))

inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;
typedef unsigned long long ull;

/*************************************************************/

int arr[18];

int main(){


    DRI(cs);
    FOR(c,1,cs){
        MM(arr,0);
        REP(q,2){DRI(r1);
        FOR(i,1,4)FOR(j,1,4){
            DRI(x);
            if( r1 == i)arr[x]++;
        }}
        int out = 0,val;
        FOR(i,1,16){
            if(arr[i]>1){out++; val = i;}
        }
        printf("Case #%d: ",c);
        switch(out){
            case 0: printf("Volunteer cheated!\n"); break;
            case 1: printf("%d\n",val); break;
            default: printf("Bad magician!\n"); break;
        }
    }


    return 0;
}

