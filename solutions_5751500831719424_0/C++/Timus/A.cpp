#include <iostream>
#include <vector>
#include <string>
#include <memory.h>

using namespace std;

string un(string s) {
    string ns;
    for (int i = 0; i < s.size() - 1; ++i)
        if (s[i] != s[i + 1])
            ns.push_back(s[i]);
    ns.push_back(s[s.size() - 1]);
    return ns;
}

int calc(string s, int p) {
    int ans = 0;
    char c = s[p];
    while (s[p] == c && p < s.size())
        ++p, ++ans;
    return ans;
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int N;
        cin >> N;
        vector<string> s(N);
        vector<string> ns(N);
        for (int i = 0; i < N; ++i)
            cin >> s[i];
        int ans = 0;
        double m = 0;
        for (int i = 0; i < N; ++i) {
            ns[i] = un(s[i]);
            ans += s[i].size() - ns[i].size();
            m += s[i].size();
        }
        m = m / N;
        bool flag = true;
        for (int i = 1; i < N; ++i) {
            if (ns[i] != ns[0])
                flag = false;
        }
        if (!flag) {
            printf("Case #%d: Fegla won\n", test);
            continue;
        }/*
        for (int l = ns[0].size(); l < 1000; ++l) {
            int tmp = 0;
            for (int i = 0; i < N; ++i) {
                tmp += abs((int)s[i].size() - l);
            }
            ans = min(ans, tmp);
        }*/
        int p[N];
        ans = 0;
        memset(p, 0, sizeof(p));
        for (int i = 0; i < ns[0].size(); ++i) {
            int tmp = 1e9;
            for (int len = 0; len < 105; ++len) {
                int cur = 0;
                for (int j = 0; j < N; ++j) {
                    int block_length = calc(s[j], p[j]);
                    cur += abs(block_length - len);
                }
                tmp = min(tmp, cur);
            }
            ans += tmp;
            for (int j = 0; j < N; ++j)
                p[j] += calc(s[j], p[j]);
        }

        printf("Case #%d: %d\n", test, ans);
    }
}
