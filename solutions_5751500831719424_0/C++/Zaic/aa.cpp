#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x)
#   define E(x)
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}
template<class F> void operator<<(queue<F> &c, const F& v){v.push(v);}
template<class G> void operator>>(queue<G> &c, const G& v){const G r=v.front();v.pop();return r;}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pip;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

string getOnlyLetters(const string& t) {
    string res = "";
    char last = 0;
    for (char c : t) {
        if (c != last) {
            res += c;
            last = c;
        }
    }
    return res;
}

int main() {
	ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";

        int n; cin >> n;
        vector<string> s(n, "");
        for (int i = 0; i < n; ++i) cin >> s[i];
        string tmpl = getOnlyLetters(s[0]);
        bool ok = true;
        for (int j = 1; j < n; ++j) if (tmpl != getOnlyLetters(s[j])) {
            ok = false;
            break;
        }
        if (!ok) {
            cout << "Fegla won\n";
            continue;
        }

        vector<int> pos(n, 0);
        int res = 0;
        for (char c : tmpl) {
            vector<int> cnt(n, 0);
            for (int i = 0; i < n; ++i) {
                while(s[i][pos[i]] != c) ++pos[i];
                while(pos[i] + cnt[i] < Sz(s[i]) && s[i][pos[i] + cnt[i]] == c) ++cnt[i];
            }
            int best = inf;
            for (int curcnt = 1; curcnt < 102; ++curcnt) {
                int curres = 0;
                for (int i = 0; i < n; ++i) curres += abs(curcnt - cnt[i]);
                if (curres < best) best = curres;
            }
            res += best;
        }
        cout << res << '\n';
    }

	return 0;
}
