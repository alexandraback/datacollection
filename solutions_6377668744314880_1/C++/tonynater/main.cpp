//tonynater

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const double pi = acos(-1);
const double eps = 1e-9;

const int MAXN = 3010;

int N, X[MAXN], Y[MAXN];

double cur[MAXN];

int main() {
    freopen("/Users/tonynater/Downloads/C-large.in", "r", stdin);
    freopen("/Users/tonynater/Tony/Computer/Xcode_repos/Miscellaneous/GCJ_2015/R1A_C/r1a_c_large.out", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N;
        for(int i = 0; i < N; i++) {
            cin >> X[i] >> Y[i];
        }
        
        cout << "Case #" << t+1 << ": " << '\n';
        
        if(N <= 3) {
            for(int i = 0; i < N; i++) {
                cout << "0\n";
            }
            continue;
        }
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(j < i) {
                    cur[j] = atan2(Y[j]-Y[i],X[j]-X[i]);
                }else if(i < j) {
                    cur[j-1] = atan2(Y[j]-Y[i],X[j]-X[i]);
                }
            }
            for(int j = 0; j < N-1; j++) {
                if(cur[j] < 0) {
                    cur[j] += 2*pi;
                }
            }
            sort(cur, cur+N-1);
            
            int mxForest = 0;
            for(int j = 0, end = 1; j < N-1; j++) {
                while(1) {
                    int nend = (end+1)%(N-1);
                    if(nend != j) {
                        double ca = cur[nend];
                        if(ca < cur[j]) {
                            ca += 2*pi;
                        }
                        if(ca-cur[j] <= pi+eps) {
                            ++end;
                        }else {
                            break;
                        }
                    }else {
                        break;
                    }
                }
                mxForest = max((end-j+N-1)%(N-1)+1, mxForest);
            }
            
            cout << N-1-mxForest << '\n';
        }
        
    }
    
    return 0;
}