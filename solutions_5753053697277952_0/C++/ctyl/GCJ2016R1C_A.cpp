#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define repd(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    
    int Q;
    cin >> Q;
    rep(q, Q){
        int N;
        cin >> N;
        vector<pair<int, char>> P(N);
        int remain = 0;
        rep(i, N) {
            cin >> P[i].first;
            remain += P[i].first;
            P[i].second = 'A' + i;
        }
        
        vector<string> ret;
        while(remain){
            sort(all(P)), reverse(all(P));
            string s = "";
            P[0].first--;
            s += P[0].second;
            remain--;
            if(P[1].first > 0 && P[1].first * 2 > remain) {
                s += P[1].second;
                remain--;
            }
            ret.pb(s);
        }
        
        
        cout << "Case #" << q + 1 << ": ";
        rep(i, ret.size()){
            if(i) cout << " ";
            cout << ret[i];
        }
        cout << endl;
        
    }
    
    return 0;
}