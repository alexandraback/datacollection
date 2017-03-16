

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;


int main() {
    int TC;
    cin >> TC;
    for ( int tc=1 ; tc<=TC ; ++tc ) {
        int N;
        cin >> N;
        vector<int> mush(N);
        for ( int i=0 ; i<N ; ++i ) {
            cin >> mush[i];
        }

        int res1 = 0, res2 = 0;
        for ( int i=1 ; i<N ; ++i ) {
            res1 += max(0, mush[i-1] - mush[i]);
        }
        int rate = 0;
        for ( int i=1 ; i<N ; ++i ) {
            rate = max(rate, max(0, mush[i-1] - mush[i]));
        }
        for ( int i=1 ; i<N ; ++i ) {
            res2 += min(rate, mush[i-1]);
        }
        printf("Case #%d: %d %d\n", tc, res1, res2);
    }
}

