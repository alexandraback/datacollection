#include <iostream>
#include <vector>
#include <utility>
using namespace std;

pair<int,int> solve(vector<int> a) {
    int m1 = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        m1 += max(a[i-1] - a[i], 0);
    }
    
    int rate = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        rate = max(rate, a[i-1] - a[i]);
    }

    int m2 = 0;
    for (int i = 1; i < (int)a.size(); ++i) {
        m2 += min(rate, max(a[i-1], 0));
    }

    return make_pair(m1, m2);
}

int main() {
    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        int N; cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        
        auto res = solve(a);
        cout << "Case #" << tc << ": " << res.first << " " << res.second << endl;
    } 
}
