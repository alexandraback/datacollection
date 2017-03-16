#include <bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000
using namespace std;
typedef long long ll;
typedef int char_32;
#define INF16 1000000


int a = 0, b = 1000000;
pair <int, int> p[50];
int main() {
    freopen("A-large (2).in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
    int t; cin >> t;

    for(int z = 0; z < t; ++z) {


        //vector <pair<int,int>> ans;
        int n, x, sum = 0; cin >> n;
        for(int i = 0; i < n; ++i) {

            cin >> x;
            p[i].first = x;
            p[i].second = i;
            sum += x;
        }
        p[n].first = -10000;
        p[n].second = 0;

        sort(p, p + n, ::greater<pair<int,int>>());
        cout << "Case #" << z + 1 << ": ";
        while(true) {

            if(sum == 0) break;
            if(sum == 3) {

                cout << (char)('A' + p[0].second) << " ";
                sum -= 1;
                p[0].first -= 1;
                int ind = 0;
                for(int i = 1; i < n; ++i ) {
                    if(p[ind].first < p[i].first) {
                        swap(p[ind], p[i]);
                        ind += 1;
                    }
                    else break;
                }
            }
            cout << (char)('A' + p[0].second) << (char)('A' + p[1].second);
            sum -= 2;
            if(sum != 0) cout << " ";
            p[0].first -= 1;
            p[1].first -= 1;
            int ind = 1;
            for(int i = 2; i < n; ++i ) {
                if(p[ind].first < p[i].first) {
                    swap(p[ind], p[i]);
                    ind += 1;
                }
                else break;
            }
            ind = 0;

            for(int i = 1; i < n; ++i ) {
                if(p[ind].first < p[i].first) {
                    swap(p[ind], p[i]);
                    ind += 1;
                }
                else break;
            }

        }
        cout << endl;
    }
}
