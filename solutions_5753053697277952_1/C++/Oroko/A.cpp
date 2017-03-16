#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define ff first
#define ss second
using namespace std;

int n;

int main() {
    int t;
    cin >> t;
    int t2 = t;
    vector <pair <int, int> > v;
    while( t--) {
        cout << "Case #"<< t2-t<<": ";
        cin >> n;
        int x;
        for(int i = 0; i < n; i++) {
            cin >> x;
            v.PB(MP(x, i));
        }
        while(!v.empty()) {
            sort(v.begin(), v.end());
            if(v.size()>=2 && v[v.size()-2].ff == v.back().ff && !(v.size() == 3 && v.back().ff == 1)) {
                v[v.size()-2].ff--;
                v.back().ff--;
                cout << (char)('A'+v[v.size()-2].ss);
                cout << (char)('A' + v.back().ss);
                if(v[v.size()-2].ff == 0) {
                    v.pop_back();
                    v.pop_back();
                }
            }
            else {
                v.back().ff--;
                cout << (char)('A' + v.back().ss);
                if(v.back().ff == 0) {
                    v.pop_back();
                }
            }
            cout<< " ";
        }
        cout<<endl;
    }
    return 0;
}


