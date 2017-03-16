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
vector <P> vs[105];

vector <P> cnt(string a);
int get_best(vector <int> v);

int main() {
    scanf("%d", &t);
    for(int f = 1; f <= t; ++f) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s", word);
            lines[i] = string(word);
            vs[i] = cnt(lines[i]);
        }
        bool ok = true;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(vs[i].size() != vs[j].size()) {
                    ok = false;
                    break;
                }
                for(int k = 0; k < vs[i].size(); ++k) {
                    if(vs[i][k].first != vs[j][k].first) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(!ok) {
            printf("Case #%d: Fegla Won\n", f);
            continue;
        }
        int res = 0;
        for(int i = 0; i < vs[0].size(); ++i) {
            vector <int> nums;
            for(int j = 0; j < n; ++j) {
                nums.push_back(vs[j][i].second);
            }
            res += get_best(nums);
        }
        printf("Case #%d: %d\n", f, res);
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

int get_best(vector <int> v) {
    int act, best = 100000;
    for(int i = 1; i <= 100; ++i) {
        act = 0;
        for(int j = 0; j < v.size(); ++j) {
            act += abs(v[j] - i);
        }
        best = min(best, act);
    }
    return best;
}
