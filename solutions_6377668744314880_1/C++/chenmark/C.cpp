#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#define FF first
#define SS second
#define MP make_pair
#define PB push_back

#define MOD 1000000007
#define INF 2000000000

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

int T, N;

const int MAXN = 3030;
int x[MAXN], y[MAXN], res[MAXN];

vector<double> rslopes, lslopes;

int main() {
    scanf("%d", &T);

    for (int test = 0; test < T; test++) {
        // remember to reset structures
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> x[i] >> y[i];
            res[i] = N;
        }

        for (int i = 0; i < N; i++) { // central point
            int pinfs = 0, ninfs = 0;

            rslopes.clear();
            lslopes.clear();

            for (int j = 0; j < N; j++) {
                if (j == i) continue;

                if (x[i] == x[j]) {
                    if (y[j] > y[i]) pinfs++;
                    else ninfs++;
                }
                else {
                    if (x[j] - x[i] > 0) {
                        rslopes.PB(1.0 * (y[j] - y[i]) / (x[j] - x[i]));
                    }
                    else {
                        lslopes.PB(1.0 * (y[j] - y[i]) / (x[j] - x[i]));
                    }
                }
            }

            res[i] = min(lslopes.size(), rslopes.size());

            sort(rslopes.begin(), rslopes.end()); int rsz = rslopes.size();
            sort(lslopes.begin(), lslopes.end()); int lsz = lslopes.size();

            int ridx = 0; int lidx = 0;

            while (ridx < rsz) {
                double val = rslopes[ridx]; int req = 1;
                while (ridx+1 < rsz && rslopes[ridx+1] - val < 1e-12) { ridx++; req++; }
                int rgt = rsz - 1 - ridx;

                while (lidx < lsz && lslopes[lidx] <= val - 1e-12) { lidx++; }
                int llt = lidx;

                while (lidx < lsz && lslopes[lidx] <= val + 1e-12) { lidx++; }
                int leq = lidx - llt;

                int up = rgt + llt + pinfs;

                res[i] = min(res[i], up);
                res[i] = min(res[i], N-1-up-leq-req);

                ridx++;
            }
        }

        cout << "Case #" << (test+1) << ": " << "\n";
        for (int i = 0; i < N; i++) {
            cout << res[i] << "\n";
        }
    }
    
    return 0; 
}
