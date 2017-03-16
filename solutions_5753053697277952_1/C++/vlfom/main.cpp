#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <memory.h>
#include <cmath>

using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define FOR0(i,n) for( i = 0 ; i < n ; ++i )
#define FOR1(i,n) for( i = 1 ; i <= n ; ++i )
#define sys_p system( "pause" )
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define sz(a) (int)a.size()

typedef long long LL;

int T, T_;
int n, p;
int i, j;
int cnt = 0;

set<pair<int, int>> s;
pair <int, int> a, b;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;
    FOR1(T_, T) {
        cin >> n;
        s.clear();
        FOR1(i, n) {
            cin >> p;
            s.insert(mp(-p, i));
            cnt += p;
        }
        cout << "Case #" << T_ << ": ";
        while (!s.empty()) {
            a = (*s.begin());
            s.erase(s.begin());
                a.FI += 1;
                cout << char('A' + (a.SE - 1));
                if (a.FI < 0)
                    s.insert(a);
                cnt -= 1;

            if (s.empty())
                break;


                a = (*s.begin());

                if (a.FI == -1 && s.size() == 2) {
                    cout << " ";
                    continue;
                }

                s.erase(s.begin());


                a.FI += 1;
                cout << char('A' + (a.SE - 1)) << " ";
                if (a.FI < 0)
                    s.insert(a);
                cnt -= 1;

            if (s.empty())
                break;
        }
        cout << endl;
    }
}