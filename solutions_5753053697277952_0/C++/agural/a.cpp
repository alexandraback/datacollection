#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

FILE *fin  = fopen("a.in",  "r");
FILE *fout = fopen("a.out", "w");
static bool DBG = 0;

int p[30];
int main() {
    int T;
    fscanf(fin, "%d", &T);
    for(int t = 1; t <= T; t++) {
        if(!DBG) fprintf(fout, "Case #%d:", t);
        if(DBG) cout << "Case #" << t << ":";
        int n; fscanf(fin, "%d", &n);
        for(int i = 0; i < n; i++) {
            fscanf(fin, "%d", &p[i]);
        }
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < n; i++) {
            pq.push(make_pair(p[i], 'A' + i));
        }
        while(!pq.empty()) {
            if(pq.size() > 2) {
                auto x = pq.top();
                pq.pop();
                if(!DBG) fprintf(fout, " %c", x.second);
                if(DBG) cout << " " << x.second;
                if(x.first > 1) pq.push(make_pair(x.first-1,x.second));
            } else {
                auto xm = pq.top(); pq.pop();
                auto ym = pq.top(); pq.pop();
                while(xm.first > ym.first) {
                    if(!DBG) fprintf(fout, " %c", xm.second);
                    if(DBG) cout << " " << xm.second;
                    xm.first--;
                }
                while(xm.first) {
                    if(!DBG) fprintf(fout, " %c%c", xm.second, ym.second);
                    if(DBG) cout << " " << xm.second << ym.second;
                    xm.first--;
                }
            }
        }
        if(!DBG) fprintf(fout, "\n");
        if(DBG) cout << endl;
    }

    return 0;
}
