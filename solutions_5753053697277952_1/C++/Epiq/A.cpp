#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define pb push_back(x)
#define mp make_pair
#define debug(x) cerr << #x << " = " << (x) << endl;


#define PROBLEM_NAME "A"

int a[1000];
int b[1000];

int main(){
    ios_base::sync_with_stdio(false);

    freopen(PROBLEM_NAME".test.in", "r", stdin);
    freopen(PROBLEM_NAME".test.out", "w", stdout);

    ll T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        ll N;
        pair<int,int> f[26];

        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> f[i].first;
            f[i].second = i;
        }

        cout << "Case #" << test << ":";

        sort(f, f + N, greater<pair<int,int>>());

        while (f[0].first > 0) {
            if (f[0].first == f[1].first && f[2].first == 0) {
                cout << " " << (char)('A' + f[0].second) << (char)('A' + f[1].second);
                f[0].first--;
                f[1].first--;
            } else {
                cout << " " << (char)('A' + f[0].second);
                f[0].first--;
            }

            sort(f, f + N, greater<pair<int,int>>());
        }

        cout << endl;
    }

    return 0;
}
