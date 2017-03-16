#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int nmax = 100005;
const long double PI = acos(-1.0);
const ll mod = 1e9 + 7;
const long double eps = 1e-6;
set<pair<int, int> > s;
int main(){
    ios_base::sync_with_stdio(0);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    cin >> t;
    for(int q = 1; q <= t; ++q){
        int n;
        cin >> n;
        s.clear();
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            s.insert({x, i});
        }
        cout << "Case #" << q << ": ";
        while(!s.empty()){
            set<pair<int, int> >::iterator it = s.end();
            it--;
            pair<int, int> cur = *it;
            s.erase(it);
            it = s.end();
            it--;
            pair<int, int> prev = *it;
            s.erase(it);
            if (!cur.first) break;
            if (cur.first == 1){
                if (s.empty()){
                    cout << char('A' + cur.second);
                    cout << char('A' + prev.second) << ' ';
                }
                else {
                    cout << char('A' + cur.second) << ' ';
                    s.insert(prev);
                }
            }
            else{
                cout << char('A' + cur.second);
                cout << char('A' + prev.second) << ' ';
                cur.first--;
                prev.first--;
                s.insert(cur);
                if (prev.first)
                    s.insert(prev);
            }
        }
        cout << endl;
    }
    return 0;
}
