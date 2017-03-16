#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;
vector<int> v[101];

int main()
{
    freopen("Input.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;

    cin >> t;
    int cs;
    cs = 0;
    while(t--) {
        int n;
        cs ++;
        cout << "Case #" << cs << ": ";
        cin >> n;
        string s[n];
        for(int i = 0; i < n; i++) {
            cin >> s[i];
            int cc = 1;
            v[i].clear();
            for(int j = 1; j < s[i].size(); j++) {
                if(s[i][j] == s[i][j-1]) cc++;
                else {
                    v[i].push_back(cc);
                    cc = 1;
                }
            }
            v[i].push_back(cc);
        }
        map<string, int> m;
        for(int i = 0; i < n; i++) {
            string ss = "";
            ss = s[i][0];
            for(int j = 1; j < s[i].size(); j++) {
                if(s[i][j] == s[i][j-1]) continue;
                else ss += s[i][j];
            }
          //  cout << ss << endl;
            m[ss]++;
        }
        if(m.size() != 1) {

            cout << "Fegla Won" << endl;
            continue;
        }
        else {
            int sol = 0;
            for(int i = 0; i < v[0].size(); i++) {
                int ans = 10000;
                for(int j = 1; j <= 100; j++) {
                   int res = 0;
                   for(int k = 0; k < n; k++) {
                        res += abs(v[k][i]-j);
                   }
                   ans = min(ans, res);
                }
                sol += ans;
            }
            cout << sol << endl;
        }
    }
}
