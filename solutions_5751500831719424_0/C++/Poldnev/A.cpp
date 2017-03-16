#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<long long, long long> plint;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<long long> vlint;
typedef vector<vector<long long>> vvlint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<long long, long long>> vplint;

ifstream in("A-small-attempt0.in");
ofstream out("output.txt");

void get_groups(const string &s, vector<char> &chars, vector<int> &cnts)
{
    chars.clear();
    cnts.clear();
    char prev = ' ';
    for (char c : s) {
        if (c != prev) {
            chars.pb(c);
            cnts.pb(0);
        }
        ++cnts.back();
        prev = c;
    }
}

int dists(const vector<int> &a, int med)
{
    int d = 0;
    for (int x : a) {
        d += abs(x - med);
    }
    return d;
}

int get_med(const vector<vector<int>> &cnts, int col)
{
    vector<int> a;
    for (const auto &cnt : cnts) {
        a.pb(cnt[col]);
    }
    int from = *min_element(a.begin(), a.end());
    int to = *max_element(a.begin(), a.end());
    int dist = 1000000000;
    for (int med = from; med <= to; ++med) {
        dist = min(dist, dists(a, med));
    }
    return dist;
}

void solve()
{
    int n;
    in >> n;
    vector<string> s(n);
    vector<char> chars, chars_cur;
    vector<vector<int>> cnts(n);
    in >> s[0];
    //cerr << __LINE__ << endl;
    get_groups(s[0], chars, cnts[0]);
    //cerr << __LINE__ << endl;
    for (int i = 1; i < n; ++i) {
        in >> s[i];
        get_groups(s[i], chars_cur, cnts[i]);
        if (chars_cur != chars) {
            out << "Fegla Won";
            return;
        }
    }
    int res = 0;
    int gn = chars.size();
    //cerr << __LINE__ << endl;
    for (int col = 0; col < gn; ++col) {
        res += get_med(cnts, col);
    }
    out << res;
}

int main()
{
    int cases;
    in >> cases;
    for (int z = 0; z < cases; ++z) {
        out << "Case #" << z + 1 << ": ";
        solve();
        out << endl;
    }

    return 0;
}
