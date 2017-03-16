#include <iostream>
#include <cstdio>
#include <vector>
#include <set>

using namespace std;


#define ll long long

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    int T;
    cin>>T;
    for (int t=1;t<=T;++t) {
        int B,N;
        cin>>B>>N;
        vector<int> bar;
        ll lrm = 1;
        for (int i=0;i<B;++i) {
            int x;
            cin>>x;
            bar.push_back(x);
            lrm = lcm(lrm, x);
        }

        ll rm = 0;
        for (int i=0;i<B;++i) {
            rm += lrm / bar[i];
        }

        N = ((N - 1) % rm) + 1;

        std::set<pair<int, int>> Q;
        for (int i=0;i<B;++i) {
            Q.emplace(0, i);
        }

        int ans;
        for (int i=0;i<N;++i) {
            auto x = *Q.begin();
            Q.erase(Q.begin());
            ans = x.second + 1;
            Q.emplace(x.first + bar[x.second], x.second);
        }


        printf("Case #%d: %d\n", t, ans);
    }
}
