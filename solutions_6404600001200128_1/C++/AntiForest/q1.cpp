#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

int _T;
int N;
int m[100005];

int main() {
    freopen ("q1.in", "r", stdin);
    freopen ("q1.out", "w", stdout);
    scanf ("%d", &_T);
    FO (_z,0,_T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%d", &N);
        FO (i,0,N) scanf ("%d", &m[i]);
        int fAns = 0;
        FO (i,1,N) {
            if (m[i] < m[i-1]) fAns += m[i-1]-m[i];
        }
        int sRate = 0;
        int sAns = 0;
        FO (i,0,N-1) {
            sRate = max (sRate, m[i]-m[i+1]);
        }
        FO (i,0,N-1) {
            sAns += min (sRate, m[i]);
        }
        printf ("%d %d\n", fAns, sAns);
        
    }
    return 0;
}
