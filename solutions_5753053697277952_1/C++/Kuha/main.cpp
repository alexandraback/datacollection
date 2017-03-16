#include <bits/stdc++.h>

#define pii pair<int, int>
#define pdd pair<double, double>
#define ull unsigned long long
#define uint unsigned int
#define ll long long
#define ld long double
#define INF 999999999
#define LINF 999999999999999999
#define M 1000000007
#define E 0.0000001
#define N (1<<18)

#define cout out
#define cin in

using namespace std;

int main() {
    ofstream out("google.out");
    ifstream in("google.in");

    int t;
    cin>>t;

    for (int c = 1; c <= t; c++) {
        int n;
        cin>>n;
        pair<int, char> v[n];
        int s = 0;
        for (int i = 0; i < n; i++) cin>>v[i].first, v[i].second = 'A' + i;

        cout<<"Case #"<<c<<": ";
        sort(v, v + n);
        while (v[n - 1].first != v[n - 2].first) {
            v[n - 1].first--;
            cout<<v[n - 1].second<<" ";
            s--;
        }
        sort(v, v + n);
        for (int i = 0; i < n - 2; i++) {
            while (v[i].first) {
                v[i].first--;
                cout<<v[i].second<<" ";
            }
        }
        while (v[n - 1].first) {
            v[n - 1].first--;
            cout<<v[n - 1].second<<v[n - 2].second<<" ";
        }
        cout<<endl;
    }

    out.close();
}
