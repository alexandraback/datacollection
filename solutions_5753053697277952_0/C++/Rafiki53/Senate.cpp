#include<bits/stdc++.h>
#define rep(i,k,n) for(int i= (int) k;i< (int) n;i++)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ft first
#define sd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
const long long INF = 4e18L + 1;
const int IINF = 2e9 + 1;
const int limit = 1048576;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
//     cin.tie(0);
    int T; cin >> T;
    rep(t, 1, T + 1) {
        int n; cin >> n;
        vector<pair<int, int> > senate(n);
        for(auto& s : senate)
            cin >> s.ft;
        rep(i, 0, n)
            senate[i].sd = i;
        sort(all(senate));
        cout << "Case #" << t << ": "; 
        while(senate[n - 1].ft > senate[n - 2].ft) {
            cout << char('A' + senate[n - 1].sd) << " ";
            senate[n - 1].ft--;
        }
        rep(i, 0, n - 2)
            rep(j, 0, senate[i].ft)
                cout << char('A' + senate[i].sd) << " ";
        
        rep(j, 0, senate[n - 1].ft)
            cout << char('A' + senate[n - 1].sd) << char('A' + senate[n - 2].sd) << " ";
        cout << "\n";
    }
    return 0;
}