#include <bits/stdc++.h>
using namespace std;

#define All(a) a.begin(), a.end()
#define For(i,a,b) for (int i = (a); i < (b); ++i)
#define Fore(i,c) for (int i = 0; i < int((c).size()); ++i)
#define Mem(a,v) memset((a), (v), sizeof(a))
#define Sz(a) int(a.size())
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = (1 << 30);
const int MOD = 1000000007;

int N;
vector<pair<char,int>> v[110];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        cin >> N;
        string s;
        For(i,0,N) {
            v[i].clear();
            cin >> s;
            v[i].pb(mp(s[0],1));
            For(j,1,Sz(s)) {
                if (s[j] == v[i].back().ft) {
                    v[i].back().sd++;
                }
                else v[i].pb(mp(s[j],1));
            }
        }
        bool ok = true;
        int size = Sz(v[0]);
        For(i,0,N) {
            if (Sz(v[i]) != size) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "Fegla Won\n";
            continue;
        }
        set<char> chars;
        Fore(i,v[0]) {
            chars.insert(v[0][i].ft);
        }
        For(i,0,N) {
            Fore(j,v[i]) {
                if (chars.count(v[i][j].ft) == 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (!ok) {
            cout << "Fegla Won\n";
            continue;
        }
        int ans = 0;
        for (int p = 0; p < Sz(v[0]); ++p) {
            vector<int> counts;
            int maxc = 0;
            char c = v[0][p].ft;
            For(i,0,N) {
                if (v[i][p].ft != c) {
                    ok = false;
                    break;
                }
                maxc = max(maxc, v[i][p].sd);
                counts.pb(v[i][p].sd);
            }
            if (!ok) {
                break;
            }
            int minc = INF;
            For(i,1,maxc+1) {
                int ch = 0;
                Fore(j,counts)
                    ch += abs(counts[j]-i);
                minc = min(minc,ch);
            }
            ans += minc;
        }
        if (!ok) {
            cout << "Fegla Won\n";
            continue;
        }
        cout << ans << "\n";
    }
    return 0;
}