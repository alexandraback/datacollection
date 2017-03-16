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
long long B, N, m[100005];

long long startedCutting (long long t) {
    long long rV = 0;
    FO (i,0,B) rV += t/m[i]+1;
    return rV;
}
    

int main() {
    freopen ("q2.in", "r", stdin);
    freopen ("q2.out", "w", stdout);
    scanf ("%d", &_T);
    FO (_z,0,_T) {
        printf ("Case #%d: ", _z+1);
        scanf ("%lld %lld", &B, &N);
        FO (i,0,B) scanf ("%lld", &m[i]);
        long long lo = 0;
        long long hi = 1e15 + 5;
        long long mid = 0;
        long long bSoFar = 0;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            long long nStart = startedCutting (mid);
            if (nStart >= N) {
                bSoFar = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        //bSoFar has the right time
        long long prevCut = 0;
        if (bSoFar == 0) prevCut = 0;
        else prevCut = startedCutting (bSoFar-1);
        long long curCut = startedCutting (bSoFar);
        long long numB = N-prevCut-1;
        vector <int> allBarbers;
        FO (i,0,B) if (bSoFar % m[i] == 0) allBarbers.push_back (i+1);
        printf ("%d\n", allBarbers[numB]);        
    }
    return 0;
}




