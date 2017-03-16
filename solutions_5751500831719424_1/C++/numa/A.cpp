#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define repf(i, f, l) for(int i = f; i < (int)l; ++i)
#define repit(it, t) for(__typeof((t).begin()) it = (t).begin(); it != (t).end(); it++)

#define endl "\n"

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
#define DBG0(x) if(DEBUG){ cout << #x << ": " << x << "\t"; }
#define DBG(x) if(DEBUG){DBG0(x); cout << endl;}
#define DBG2(x, y) if(DEBUG){DBG0(x); DBG(y);}
#define DBG3(x, y, z) if(DEBUG){DBG0(x); DBG2(y, z);}
#define DBG4(w, x, y, z) if(DEBUG){DBG0(w); DBG3(x, y, z);}

typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ul> vul;
typedef vector<ull> vull;
typedef vector<bool> vbl;
typedef pair<int, int> pii;


string func(string str){
    string cs = "";
    rep(i, str.length()){
        if(cs.length() == 0) cs += str[i];
        else{
            if(cs[cs.length() - 1] != str[i])
                cs += str[i];
        }
    }
//  DBG2(str, cs);
    return cs;
}

void solve(int tc){
    int n;
    cin >> n;
    vector<string> vs(n);
    rep(i, n) cin >> vs[i];
    set<string> st;
    rep(i, n){
        st.insert(func(vs[i]));
    }
    if(st.size() > 1){
        printf("Case #%d: Fegla Won\n", tc);
        return;
    }
    string cs = *st.begin();
    vector<vector<int>> tbl(n, vector<int>(cs.length(), 0));
    rep(i, n){
        string str = vs[i];
        int id = 0;
        int j = 0;
        while(id < (int)cs.length()){
            while(cs[id] == str[j]){
                tbl[i][id]++;
                j++;
            }
            id++;
        }
    }
    int ret = 0;
    rep(j, cs.length()){
        int sum = 0;
        rep(i, n){
            sum += tbl[i][j];
        }
        int tg;
        if(n % 2 == 0){
            if(sum % n >= n / 2)
                tg = (sum + n - 1) / n;
            else
                tg = sum / n;
        }
        else{
            if(sum % n > n / 2)
                tg = (sum + n - 1) / n;
            else
                tg = sum / n;
        }
        rep(i, n){
            ret += abs(tbl[i][j] - tg);
        }
    }
    printf("Case #%d: %d\n", tc, ret);
}
int main(void){
    int t;
    cin >> t;
    rep(i, t){
        solve(i + 1);
    }
    return 0;
}
