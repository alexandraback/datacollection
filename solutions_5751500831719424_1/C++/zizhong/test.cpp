#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
int calc(vector<int>& tmp, int k) {
    int ret = 0;
    for(int i = 0; i < tmp.size(); i ++) {
        ret += abs(tmp[i] - tmp[k]);
    }
    return ret;
}
pair<string, vector<int>> gao(string& str) {
    string str1;
    str1.push_back(str[0]);
    vector<int> vec2(1, 1);
    int len = 1;
    for(int i = 1; i < str.size(); i ++) {
        if (str[i] == str1[len - 1]) {
            vec2[len - 1] ++;
        } else {
            len ++;
            str1.push_back(str[i]);
            vec2.push_back(1);
        }
    }
    //cout << str << " " << str1 << endl;
    return pair<string, vector<int>>(str1, vec2);
}
void solve(int ncase) {
    int n;
    cin >> n;
    vector<string> input(n);
    for(int i = 0; i < n; i ++) {
        cin >> input[i];
    }
    pair<string, vector<int>> str2cnt = gao(input[0]);
    vector<vector<int>> cnt;
    cnt.push_back(str2cnt.second);
    bool flag = true;
    for(int i = 1; i < n; i ++) {
        auto tmpstr2cnt = gao(input[i]);
        if (tmpstr2cnt.first != str2cnt.first) {
            flag = false;
            break;
        }
        cnt.push_back(tmpstr2cnt.second);
    }
    cout << "Case #" << ncase << ": ";
    if (flag == false) {
        cout << "Fegla Won\n";
    } else {
        int ans = 0;
        for(int i = 0; i < cnt[0].size(); i ++) {
            vector<int> tmp;
            for(int j = 0; j < cnt.size(); j ++) {
                tmp.push_back(cnt[j][i]);
            }
            int tmpans = 100 * 100;
            for(int k = 0; k < tmp.size(); k ++) {
                tmpans = min(tmpans, calc(tmp, k));
            }
            ans += tmpans;
        }
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    //cout << setprecision(16) << endl;
#ifdef _zzz_
   freopen("A--large.in", "r", stdin);
freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
