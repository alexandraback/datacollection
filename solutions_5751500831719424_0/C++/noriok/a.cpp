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

void calc(const vector<string>& v) {
    if (v.size() != 2) {
        puts("ERROR!!!");
        assert(false);
        return;
    }

    vector<G> a = group(v[0]);
    vector<G> b = group(v[1]);


    if (a.size() != b.size()) {
        puts("Fegla Won");
        return;
    }

    int ans = 0;
    For(i, a.size()) {
        G x = a[i];
        G y = b[i];

        if (x.c != y.c) {
            puts("Fegla Won");
            return;
        }

        ans += abs(x.cnt - y.cnt);
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


