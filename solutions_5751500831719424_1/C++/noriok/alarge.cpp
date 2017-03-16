#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define For(i,x) for (int i=0; i<(int)(x); i++)

struct G {
    char c;
    int cnt;
};

vector<G> group(const string& s) {
    const int n = s.length();

    vector<G> v;
    char c = s[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (c != s[i]) {
            v.push_back((G){ c, cnt });
            c = s[i];
            cnt = 1;
        }
        else {
            cnt++;
        }
    }

    v.push_back((G){ c, cnt });
    return v;
}

void won() {
    puts("Fegla Won");
}

void calc(const vector<string>& v) {
    vector< vector<G> > gs;
    For(i, v.size()) {
        gs.push_back(group(v[i]));
    }

    for (int i = 1; i < gs.size(); i++) {
        if (gs[i-1].size() != gs[i].size()) {
            won();
            return;
        }
    }

    int ans = 0;
    int n = gs[0].size();
    for (int i = 0; i < n; i++) {

        int vmin = gs[0][i].cnt;
        int vmax = gs[0][i].cnt;
        for (int j = 1; j < gs.size(); j++) {
            if (gs[j-1][i].c != gs[j][i].c) {
                won();
                return;
            }

            vmin = min(vmin, gs[j][i].cnt);
            vmax = max(vmax, gs[j][i].cnt);
        }

        ans += vmax - vmin;
    }
    printf("%d\n", ans);
}

int main() {
    int ncases;
    scanf("%d", &ncases);

    For(cc, ncases) {
        int n;
        scanf("%d", &n);

        vector<string> v;
        char s[1000];
        For(i, n) {
            scanf("%s", s);
            v.push_back(s);
        }

        printf("Case #%d: ", cc+1);
        calc(v);
    }
}


