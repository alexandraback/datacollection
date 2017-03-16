#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>
#include <cassert>
using namespace std;

string rem(string s) {
    string t = "";
    for (int j=0; j<s.size(); j++) {
        if (j==0 || s[j]!=s[j-1]) {
            t += s[j];
        }
    }
    return t;
}

vector<int> get_count(string tpl, string s) {
    int i = 0, j = 0;
    vector<int> count(tpl.size());
    for (int j=0; j<s.size(); j++) {
        if (j>0 && s[j]!=s[j-1]) i++;
        count[i]++;
    }
    return count;
}

int main() {
    int T = 0;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {

        int N = 0;
        scanf(" %d", &N);

        char buf[128];
        vector<string> s;
        s.clear();
        //if (t==12 || t==37 || t==43) { printf("CASE %d:\n", t); }
        for (int i=0; i<N; i++) {
            scanf(" %s", buf);
            //if (t==12 || t==37 || t==43) { printf("%s\n", buf); }
            s.push_back(buf);
        }

        bool fail = false;
        string tpl = rem(s[0]);
        for (int i=1; i<N; i++) {
            if (tpl != rem(s[i])) {
                fail = true;
                break;
            }
        }

        //for (int i=0; i<N; i++) { printf("%s\n", s[i].c_str()); }

        if (fail == true) {
            printf("Case #%d: Fegla Won\n", t);
            continue;
        }

        vector<vector<int> > count(N);
        for (int i=0; i<N; i++) {
            count[i] = get_count(tpl, s[i]);
        }

        int cost = 0;
        for (int k = 0; k<tpl.size(); k++) {

            //for (int i=0; i<N; i++) { printf("%d ", count[i][k]); } printf("- ");

            int best = 1<<30, X=-1;
            for (int x=1; x<128; x++) {
                int cur = 0;
                for (int i = 0; i<N; i++) {
                    cur += abs(x-count[i][k]);
                }
                if (cur < best) {
                    best = cur;
                    X = x;
                }
            }
            //printf("Changing all %c to %d: %d\n", tpl[k], X, best);
            cost += best;
        }

        //if (N==2 && s[0]==s[1]) { assert(cost==0); }
        printf("Case #%d: %d\n", t, cost);
    }
}

// vim: set ff=unix ai tw=80 ts=4 sts=4 sw=4 et:
