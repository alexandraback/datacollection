#include<bits/stdc++.h>
#define ALL(X)        X.begin(),X.end()
#define FOR(I,A,B)    for(int (I) = (A); (I) <= (B); (I)++)
#define FORW(I,A,B)   for(int (I) = (A); (I) < (B);  (I)++)
#define FORD(I,A,B)   for(int (I) = (A); (I) >= (B); (I)--)
#define CLEAR(X)      memset(X,0,sizeof(X))
#define SIZE(X)       int(X.size())
#define CONTAINS(A,X) (A.find(X) != A.end())
#define PB            push_back
#define MP            make_pair
#define X             first
#define Y             second
using namespace std;
template<typename T, typename U> ostream& operator << (ostream& os, const pair<T, U> &_p) { return os << "(" << _p.X << "," << _p.Y << ")"; }
template<typename T> ostream& operator << (ostream &os, const vector<T>& _V) { bool f = true; os << "["; for(auto v: _V) { os << (f ? "" : ",") << v; f = false; } return os << "]"; }
template<typename T> ostream& operator << (ostream &os, const set<T>& _S) { bool f = true; os << "("; for(auto s: _S) { os << (f ? "" : ",") << s; f = false; } return os << ")"; }
template<typename T, typename U> ostream& operator << (ostream &os, const map<T, U>& _M) { return os << set<pair<T, U>>(ALL(_M)); }
typedef signed long long slong;
typedef long double ldouble;
const slong INF = 1000000100;
const ldouble EPS = 1e-9;

const int MAXN = 101010;
int N;
int A[MAXN];

void read_data() {
    scanf("%d", &N);
    FOR(i,1,N) scanf("%d", A+i);
}

bool ok() {
    int sum = 0;
    int maxx = -1;
    FOR(i,1,N) {
        sum += A[i];
        maxx = max(maxx, A[i]);
    }
    return 2*maxx <= sum;
}

bool try2() {
    FOR(i,1,N) FOR(j,i,N) {
        --A[i];
        --A[j];
        if(A[i] >= 0 and A[j] >= 0 and ok()) {
            printf("%c%c ", i+'A'-1, j+'A'-1);
            return true;
        } else {
            ++A[i];
            ++A[j];
        }
    }
    return false;
}

bool try1() {
    FOR(i,1,N) {
        --A[i];
        if(A[i] >= 0 and ok()) {
            printf("%c ", i+'A'-1);
            return true;
        } else {
            ++A[i];
        }
    }
    return false;
}

void solve() {
    int sum = INF;
    while(sum > 0) {
        if(try2()) continue;
        if(try1()) continue;
        
        sum = 0;
        FOR(i,1,N) sum += A[i];
    }
}

int main() {
    int z;
    scanf("%d", &z);
    FOR(test_id,1,z) {
        printf("Case #%d: ", test_id);
        read_data();
        solve();
        printf("\n");
    }
}
