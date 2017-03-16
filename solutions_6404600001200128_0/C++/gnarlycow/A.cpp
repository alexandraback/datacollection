#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int d[1001];

int main() {
    int nc;
    cin >> nc;
    for(int cid=1; cid<=nc; ++cid) {
        int n;
        cin >> n;
        for(int i=0; i<n; ++i) cin >> d[i];
        int A = 0;
        int maxdiff = 0, countdiff = 0;
        for(int i=1; i<n; ++i)
            if(d[i] < d[i-1]) {
                A += d[i-1] - d[i];
                maxdiff = max(maxdiff, d[i-1] - d[i]);
                ++countdiff;
            }

        int B = 0;
        for(int i=1; i<n; ++i) B += min(d[i-1], maxdiff);

        printf("Case #%d: %d %d\n", cid, A, B);
    }
    return 0;
}

