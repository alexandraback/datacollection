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

template<typename T>
struct number_iterator : std::iterator<random_access_iterator_tag, T>{
    T v;
    number_iterator(T _v = 0) : v(_v) {}
    operator T&(){return v;}
    T operator *() const {return v;}
};

int main() {
    //ios_base::sync_with_stdio(false);
    int T;
    scanf("%d", &T);
    int caso = 1;
    while (T--) {
        int B, N;
        scanf("%d %d", &B, &N);
        vector<ll> M(B);
        rep(i,B) scanf("%lld", &M[i]);
        
        
        
        rep(id,B) {
            
            auto f = [&] (ll value) {
                ll tempo = M[id] * (value - 1);
                // printf("%lld %lld\n", tempo, value);
                ll cnt = value;
                rep(i,B) if (i != id) {
                    // printf("%lld %lld %lld\n", tempo, M[i], (tempo + M[i] - 1) / M[i]);
                    cnt += (tempo + M[i] - 1) / M[i];
                    // printf("%lld\n", cnt);
                    if (i < id && tempo % M[i] == 0) ++cnt;
                }
                return cnt;
            };
            
            auto g = [&] (ll value) {
                return f(value) <= N;
            };
            
            ll lb = partition_point(number_iterator<ll>(1), number_iterator<ll>(N+1), g) - 1;
            
            if (f(lb) == N) {
                printf("Case #%d: %d\n", caso++, id + 1);
                break;
            }
        }
        cerr << "finished test case " << caso-1 << endl;
    }
    return 0;
}
