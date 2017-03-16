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

int lcm(int a, int b) {
    return a * b / __gcd(a,b);
}

int main() {
    //ios_base::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    int caso = 1;
    while (T--) {
        int B, N;
        scanf("%d %d", &B, &N);
        vector<int> M(B);
        rep(i,B) scanf("%d", &M[i]);
        int lcm_ = M[0];
        fr(i,1,B) lcm_ = lcm(lcm_, M[i]);
        int repeat = 0;
        rep(i,B) repeat += lcm_ / M[i];
        N = (N - 1) % repeat;
        if (N < B) printf("Case #%d: %d\n", caso++, N + 1);
        else {
            set<pii> S;
            rep(i,B) S.insert({M[i], i});
            N -= B;
            rep(i,N+1) {
                auto top = *S.begin();
                S.erase(S.begin());
                S.insert({top.fst + M[top.snd], top.snd});
                if (i == N) {
                    printf("Case #%d: %d\n", caso++, top.snd + 1);
                }
            }
        }
    }
    return 0;
}
