#include <bits/stdc++.h>

using namespace std;

#define fr(a,b,c) for(int (a) = (b); (a) < (c); ++(a))
#define rep(a,b) fr(a,0,b)
#define fst first
#define snd second
#define db(x) cerr << #x << " == " << x << endl
#define _ << ", " <<

const int oo = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int,int> pii;

int main() {
    //ios_base::sync_with_stdio(false);
    
    int T;
    scanf("%d", &T);
    int caso = 1;
    while (T--) {
        int N;
        scanf("%d", &N);
        vector<int> v(N);
        rep(i,N) scanf("%d", &v[i]);
        int rsp1 = 0, rate = 0;
        fr(i,1,N) {
            if (v[i] < v[i-1]) {
                rsp1 += v[i-1] - v[i];
                rate = max(rate, v[i-1] - v[i]);
            }
        }
        int rsp2 = 0;
        fr(i,1,N) {
            if (v[i] < v[i-1]) {
                rsp2 += min(rate, v[i-1]);
            } else {
                rsp2 += min(rate, v[i-1]);   
            }
        }
        printf("Case #%d: %d %d\n", caso++, rsp1, rsp2);
    }
    
    return 0;
}
