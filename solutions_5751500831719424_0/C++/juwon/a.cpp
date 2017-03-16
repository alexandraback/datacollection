#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n;
vector<vector<pair<char, int> > > p;

vector<pair<char, int> > parse(char* buf) {
    int len = strlen(buf);
    vector<pair<char, int> > ret;
    int i = 0;
    int count = 0;
    while (i < len) {
        char t = buf[i];
        count = 0;
        while (i < len && buf[i] == t) {
            count++;
            i++;
        }
        ret.push_back(make_pair(t, count));
    }
    return ret;
}

int isValid() {
    for (int i = 0; i < n; ++i) {
        if (p[i].size() != p[0].size()) {
            return 0;
        }
        for (int j = 0; j < (int)p[i].size(); ++j) {
            if (p[0][j].first != p[i][j].first) {
                return 0;
            }
        }
    }
    return 1;
}

int getCol(int col, int v) {
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += abs(v - p[i][col].second);
    }
    return ret;
}

int getAns() {
    int m = (int)p[0].size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int minv = 0x7fffffff;
        for (int j = 1; j <= 100; ++j) {
            minv = min(minv, getCol(i, j));
        }
        ans += minv;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ", cs);
        scanf("%d", &n);
        p.clear();
        for (int i = 0; i < n; ++i) {
            char buf[256] = {0};
            scanf("%s", buf);
            p.push_back(parse(buf));
        }
        if (!isValid()) {
            printf("Fegla Won\n");
        } else {
            printf("%d\n", getAns());
        }
    }
    return 0;
}


