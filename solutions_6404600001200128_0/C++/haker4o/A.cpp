#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

int main() {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    int T, NT;
    cin>>NT;
    int i, j, n, m;
    for(T=1; T<=NT; ++T) {
        cin>>n;
        vector<int> v(n);
        for(i=0; i<n; ++i) {
            cin>>v[i];
        }
        int y, z;
        y=0; z=0;
        int minEat = 0;
        for(i=1; i<n; ++i) {
            if (v[i-1] > v[i]) {
                y += v[i-1]-v[i];
                int diff = v[i-1]-v[i];
                minEat = max(diff, minEat);
            }
        }
        for(i=1; i<n; ++i) {
            z += min(v[i-1], minEat);
        }
        printf("Case #%d: %d %d\n", T, y, z);
    }
    return 0;
}
