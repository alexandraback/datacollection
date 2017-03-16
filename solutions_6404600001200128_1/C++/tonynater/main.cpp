//tonynater

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1010;

int N, A[MAXN];

int main() {
    freopen("/Users/tonynater/Downloads/A-large.in", "r", stdin);
    freopen("/Users/tonynater/Tony/Computer/Xcode_repos/Miscellaneous/GCJ_2015/R1A_A/r1a_a_large.out", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> A[i];
        }
        
        int res1 = 0, mxRate = 0;
        for(int i = 1; i < N; i++) {
            if(A[i-1] > A[i]) {
                res1 += A[i-1]-A[i];
                mxRate = max(A[i-1]-A[i], mxRate);
            }
        }
        
        int res2 = 0;
        for(int i = 0; i < N-1; i++) {
            res2 += min(A[i], mxRate);
        }
        
        cout << "Case #" << t+1 << ": " << res1 << ' ' << res2 << '\n';
    }
    
    return 0;
}