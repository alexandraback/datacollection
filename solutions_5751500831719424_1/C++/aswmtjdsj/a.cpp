#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;
const double eps = 1e-8;

int sgn(double x) {
    return fabs(x) < eps ? 0:x < -eps ? -1:1;
}

int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c++) {
        printf("Case #%d: ", c);
        string s[105];
        vector < pair<char, int> > vs[105];
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int p = 0, q = 0;
            int l = s[i].size();
            while(p < l && q < l) {
                if(s[i][p] == s[i][q]) {
                    q++;
                }
                else {
                    vs[i].PB(MP(s[i][p], q - p));
                    p = q;
                }
            }
            if(p < l) {
                vs[i].PB(MP(s[i][p], q - p));
            }
        }
        bool mark = true;
        int base = vs[0].size();
        for(int i = 1; i < n; i++) {
            if(vs[i].size() != base) {
                mark = false;
                break;
            }
            for(int j = 0; j < vs[i].size(); j++) {
                if(vs[i][j].first != vs[0][j].first) {
                    mark = false;
                    break;
                }
            }
            if(!mark) {
                break;
            }
        }
        if(mark) {
            for(int i = 0; i < vs[0].size(); i++) {
                int temp_ans = 100000;
                for(int j = 0; j < n; j++) {
                    int temp = 0;
                    for(int k = 0; k < n; k++) {
                        temp += abs(vs[j][i].second - vs[k][i].second);
                    }
                    temp_ans = min(temp_ans, temp);
                }
                ans += temp_ans;
            }
            printf("%d\n", ans);
        }
        else {
            puts("Fegla Won");
        }
    }
}
