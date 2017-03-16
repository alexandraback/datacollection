#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)

#ifdef ONLINE_JUDGE
#define DEBUG false
#else
#define DEBUG true
#endif

#define pb emplace_back
#define lb lower_bound
#define ul unsigned long
#define ull unsigned long long
#define ll long long
#define INF 1000000007
#define MOD 1000000007
#define fs first
#define sd second

#define ALL(c) (c).begin(),(c).end()

#define DBG0(x)    {if(DEBUG){ cout << #x << ": " << x << "\t"; }}
#define DBG(x)     {if(DEBUG){DBG0(x); cout << endl;}}
#define DBG2(x, y) {if(DEBUG){DBG0(x); DBG(y);}}
#define DBG3(x, y, z) {if(DEBUG){DBG0(x); DBG2(y, z);}}
#define DBG4(w, x, y, z) {if(DEBUG){DBG0(w); DBG3(x, y, z);}}

template <class T>
ostream& operator<<(ostream& os, vector<T> xs){ for(T x: xs) os << x << ' '; return os; }
template <class S, class T>
ostream& operator<<(ostream& os, pair<S,T> st){ os << "(" << st.first << "," << st.second <<")"; return os; }

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;

int dx[] = { 0, 1};
int dy[] = { 1, 0};
int r, c, n;

bool valid(int i, int j){
    return (0 <= i && i < r && 0 <= j && j < c);
}

int main(void){
    int T;
    cin >> T;
    repf(xx, 1, T + 1){
        cin >> r >> c >> n;
        DBG3(r, c, n);
        if(n <= (r * c + 1) / 2){
            cout << "Case #" << xx << ": " << 0 << endl;
            continue;
        }

        int ans = 1000000009;
        {
            vector<vector<int>> room(r, vector<int>(c, 0));
            int nn = n;
            rep(i, r) rep(j, c){
                if(0 < nn && ((i + j) & 1) == 0){
                    room[i][j]++;
                    nn--;
                }
            }

            if(nn && room[0][0] == 0){
                room[0][0] = 1;
                nn--;
            }
            if(nn && room[r - 1][0] == 0){
                room[r - 1][0] = 1;
                nn--;
            }
            if(nn && room[r - 1][c - 1] == 0){
                room[r - 1][c - 1] = 1;
                nn--;
            }
            if(nn && room[0][c - 1] == 0){
                room[0][c - 1] = 1;
                nn--;
            }

            rep(i, r) {
                int j = 0;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
                j = c - 1;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
            }

            rep(j, c) {
                int i = 0;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
                i = r - 1;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
            }
            rep(i, r) rep(j, c) if(nn && room[i][j] == 0) {
                room[i][j] = 1;
                nn--;
            }

            DBG(room);
            int aa = 0;
            rep(i, r) rep(j, c) rep(k, 2){
                if(room[i][j] == 0) continue;
                int bx = i + dx[k];
                int by = j + dy[k];
                if(valid(bx, by)){
                    if(room[bx][by]) aa++;
                }
            }
            ans = min(ans, aa);
        }
        {
            vector<vector<int>> room(r, vector<int>(c, 0));
            int nn = n;
            rep(i, r) rep(j, c){
                if(0 < nn && ((i + j) & 1) == 1){
                    room[i][j]++;
                    nn--;
                }
            }

            if(nn && room[0][0] == 0){
                room[0][0] = 1;
                nn--;
            }
            if(nn && room[r - 1][0] == 0){
                room[r - 1][0] = 1;
                nn--;
            }
            if(nn && room[r - 1][c - 1] == 0){
                room[r - 1][c - 1] = 1;
                nn--;
            }
            if(nn && room[0][c - 1] == 0){
                room[0][c - 1] = 1;
                nn--;
            }

            rep(i, r) {
                int j = 0;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
                j = c - 1;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
            }

            rep(j, c) {
                int i = 0;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
                i = r - 1;
                if(0 < nn && room[i][j] == 0){
                    room[i][j] = 1;
                    nn--;
                }
            }
            rep(i, r) rep(j, c) if(nn && room[i][j] == 0) {
                room[i][j] = 1;
                nn--;
            }

            DBG(room);
            int aa = 0;
            rep(i, r) rep(j, c) rep(k, 2){
                if(room[i][j] == 0) continue;
                int bx = i + dx[k];
                int by = j + dy[k];
                if(valid(bx, by)){
                    if(room[bx][by]) aa++;
                }
            }
            ans = min(ans, aa);
        }
        cout << "Case #" << xx << ": " << ans << endl;
    }
    return 0;
}
