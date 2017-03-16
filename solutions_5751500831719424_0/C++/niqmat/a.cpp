#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;
typedef pair <char, int> P;
const int MAXN = 100;

int t, n;
char word[200];
string lines[105];

vector <P> cnt(string a);

int main() {
    scanf("%d", &t);
    for(int f = 1; f <= t; ++f) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s", word);
            lines[i] = string(word);
        }
        vector <P> v1 = cnt(lines[0]);
        vector <P> v2 = cnt(lines[1]);
        if(v1.size() != v2.size()) {
            printf("Case #%d: Fegla Won\n", f);
            continue;
        }
        int res = 0;
        for(int i = 0; i < v1.size(); ++i) {
            if(v1[i].first != v2[i].first) {
                res = -1;
                break;
            } else {
                res += abs(v1[i].second - v2[i].second);
            }
        }
        if(res == -1) {
            printf("Case #%d: Fegla Won\n", f);
        } else {
            printf("Case #%d: %d\n", f, res);
        }
    }     
    return 0;
}

vector <P> cnt(string a) {
    vector <P> v;
    char c = a[0];
    int act = 1;
    for(int i = 1; i < a.size(); ++i) {
        if(a[i] == c) ++act;
        else {
            v.push_back(make_pair(c, act));
            act = 1;
            c = a[i];
        }
    }
    v.push_back(make_pair(c, act));
    return v;
}
