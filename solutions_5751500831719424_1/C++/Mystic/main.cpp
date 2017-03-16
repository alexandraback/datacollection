#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

string minimize(string s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i+1]) {
            s.erase(s.begin() + i);
            i--;
        }
    }
    return s;
}

int getmin(vector<int>& v) {
    int res = 1000000;
    int mx = *max_element(v.begin(), v.end());
    for (int i = 1; i <= mx; ++i) {
        int cur = 0;
        for (int j = 0; j < v.size(); ++j) {
            cur += abs(v[j] - i);
        }
        res = min(res, cur);
    }
    return res;
}

int main() {
    int T = 0;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        cout << "Case #" << test << ": ";
        int N = 0;
        cin >> N;
        vector<string> s(N);
        for (int i = 0; i < N; ++i)
            cin >> s[i];
        string templ = minimize(s[0]);
        bool fail = false;
        for (int i = 1; i < N; ++i) {
            string tmp = minimize(s[i]);
            if (tmp != templ) {
                fail = true;
                break;
            }
        }
        if (fail) {
            cout << "Fegla Won" << endl;
            continue;
        }

        vector<vector<int> > nums(templ.size(), vector<int>(N));
        for (int i = 0; i < N; ++i) {
            int num = 0;
            int count = 1;
            char last = s[i][0];
            for (int j = 1; j < s[i].size(); ++j) {
                if (last == s[i][j]) {
                    count++;
                    continue;
                }
                last = s[i][j];
                nums[num][i] = count;
                count = 1;
                num++;
            }
            nums[num][i] = count;
        }

        int result = 0;
        for (int i = 0; i < nums.size(); ++i) {
            result += getmin(nums[i]);
        }
        cout << result;

        cout << endl;
    }
}
