#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct Bee {
    char c;
    int x;
    Bee (char a, int b) : c(a), x(b) {}
};
vector<Bee> v[111];

char st[111][111];
int n;
void readthem() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) 
        scanf("%s", st[i]);
}
vector<int> f;
int working() {
    for (int i = 0; i < n; ++i)
        v[i].clear();
    for (int i = 0; i < n; ++i) {
        char last = 0;
        for (int j = 0; st[i][j]; ++j){ 
            if (st[i][j] == last)
                v[i].back().x += 1;
            else
                v[i].push_back(Bee(st[i][j], 1));
            last = st[i][j];
        }
    }
    int len = v[0].size();
    for (int i = 1; i < n; ++i)  
        if (len != v[i].size()) return -1;
    for (int i = 0; i < len; ++i)
        for (int j = 1; j < n; ++j)
            if (v[j][i].c != v[j - 1][i].c)
                return -1;
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        f.clear();
        for (int j = 0; j < n; ++j)
            f.push_back(v[j][i].x);
        sort(f.begin(), f.end());
        int m1 = f[n / 2];
        for (int j = 0; j < n; ++j)
            ret += abs(f[j] - m1);
            ///ret += min(abs(f[j] - m1), abs(f[j] - m2));
    }
    return ret;
} 

int main() {
    int task; scanf("%d", &task);
    for (int cas = 1; cas <= task; ++cas) {
        readthem();
        printf("Case #%d: ", cas);
        int ans = working();
        if (ans < 0) puts("Fegla Won");
            else printf("%d\n", ans);
    }
    return 0;
}
