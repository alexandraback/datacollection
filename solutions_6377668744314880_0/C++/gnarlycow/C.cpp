#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

long long x[22], y[22];
int ans[22];
bool u[22];

int cross(long long x1, long long y1, long long x2, long long y2) {
    long long c = x1*y2 - x2*y1;
    if(c<0) return -1;
    if(c>0) return 1;
    return 0;
}

int main() {
    int nc;
    cin >> nc;
    for(int cid=1; cid<=nc; ++cid) {
        int n;
        cin >> n;
        for(int i=0; i<n; ++i) {
            cin >> x[i] >> y[i];
        }
        memset(ans, 0, sizeof(ans));

        for(int p=1; p<(1<<n); ++p) {
            memset(u, 0, sizeof(u));
            int num = 0;
            for(int i=0; i<n; ++i)
                if((p>>i)&1) {
                    ++num;
                    u[i] = true;
                }
            if(num < 4) {
                for(int i=0; i<n; ++i)
                    if(u[i])
                        ans[i] = max(ans[i], num);
            } else {

                for(int i=0; i<n; ++i)
                    for(int j=i+1; j<n; ++j)
                        if(u[i] && u[j]) {
                            int mins = 2, maxs = -2;
                            for(int k=0; k<n; ++k)
                                if(k!=i && k!=j && u[k]) {
                                    int s = cross(x[j]-x[i], y[j]-y[i], x[k]-x[i], y[k]-y[i]);
                                    mins = min(mins, s);
                                    maxs = max(maxs, s);
                                }
                            assert(maxs >= mins);
                            if(maxs - mins <= 1) {
                                ans[i] = max(ans[i], num);
                                ans[j] = max(ans[j], num);
                            }
                        }
            }
        }

        printf("Case #%d:\n", cid);
        for(int i=0; i<n; ++i) printf("%d\n", n - ans[i]);
    }
    return 0;
}

