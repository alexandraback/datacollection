#define _USE_32BIT_TIME_T 1
#include <vector> // headers {{{
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>

#define DEBUG(x) cout << #x << ": " << x << "\n"
using namespace std; // }}}

string norm(string s)
{
    s.erase(unique(s.begin(), s.end()), s.end());
    return s;
}

int adjust(const string& s, int idx, int cnt)
{
    char c = s[0];
    int change = 0, tot = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != c) {
            ++change;
            c = s[i];
        }
        if (change > idx)
            break;
        if (change == idx)
            ++tot;
    }
    return abs(tot - cnt);
}

string result(const vector<string>& v)
{
    const string& BAD = "Fegla Won";
    int N = v.size();
    string T = norm(v[0]);
    for (int i = 1; i < N; ++i) {
        if (norm(v[i]) != T)
            return BAD;
    }
    int res = 0;
    for (int i = 0; i < T.size(); ++i) {
        int cur = -1;
        for (int j = 1; j <= 100; ++j) {
            int tot = 0;
            for (int k = 0; k < N; ++k) {
                tot+= adjust(v[k], i, j);
            }
            if (cur == -1 || cur > tot)
                cur = tot;
        }
        res+= cur;
    }
    stringstream ss0;
    ss0 << res;
    return ss0.str();
}

int main()
{
    time_t start, end;
    time(&start);
    
    ifstream cin("test.in");
    ofstream cout("test.out");
    //cout.precision(6);
    //cout.setf(ios::fixed,ios::floatfield);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        int N;
        cin >> N;
        vector<string> v(N);
        for (int j = 0; j < N; ++j)
            cin >> v[j];
        cout << "Case #" << i << ": " << result(v) << endl;
        time(&end);
        ::cout << i << " " << difftime(end, start) << endl;
    }

    return 0;
}
