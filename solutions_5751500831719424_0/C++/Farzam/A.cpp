// In the name of God
#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <queue>
#include <utility>
#include <vector>


using namespace std;


typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> point;

#define siz(x) (int(x.size()))
#define err(x) cerr << #x << " = " << x << endl;
#define pb push_back
#define mp make_pair

#define X first
#define Y second
// #define X real()
// #define Y imag()

const double eps = 1e-8;

string s[200];
vector<pair<char, int> > v[200];

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> s[i];
            int cnt = 0;
            vector<pair<char, int> > tmp;
            for (int j = 0; j <= s[i].size(); j++) {
                if (j == 0 || (j < s[i].size() && s[i][j] == s[i][j - 1]))
                    cnt++;
                else {
                    tmp.push_back(make_pair(s[i][j - 1], cnt));
                    cnt = 0;
                }
            }
            v[i] = tmp;
        }
        bool flag = true;
        for (int i = 1; i < N; i++) {
            if (v[i].size() != v[0].size()) {
                flag = false;
                break;
            }
            for (int j = 0; j < v[0].size(); j++) {
                if (v[i][j].first != v[0][j].first) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        cout << "Case #" << t + 1 << ": ";
        if (!flag) {
            cout << "Fegla Won" << endl;
            continue;
        }
        int ans = 0;
        for (int i = 0; i < v[0].size(); i++) {
            int tmp = 0;
            for (int j = 0; j < N; j++) 
                tmp += v[j][i].second;
            tmp /= N;
            // cerr << tmp << endl;
            for (int j = 0; j < N; j++) 
                ans += abs(v[j][i].second - tmp);
        }
        cout << ans << endl;
    }


    return 0;
}
