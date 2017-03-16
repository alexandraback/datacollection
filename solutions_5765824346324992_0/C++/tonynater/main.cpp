//tonynater

#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

const ll MAXRES = (1LL<<50);

const int MAXB = 1010;

int B, N, M[MAXB];

int main() {
    freopen("/Users/tonynater/Downloads/B-small-attempt0.in", "r", stdin);
    freopen("/Users/tonynater/Tony/Computer/Xcode_repos/Miscellaneous/GCJ_2015/R1A_B/r1a_b_small.out", "w", stdout);
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> B >> N;
        for(int i = 0; i < B; i++) {
            cin >> M[i];
        }
        
        ll low = -1, high = MAXRES;
        while(low < high) {
            ll mid = (low+high+1)/2;
            
            ll sum = 0;
            for(int i = 0; i < B; i++) {
                sum += (mid+M[i]-1)/M[i];
            }
            
            if(sum < N) {
                low = mid;
            }else {
                high = mid-1;
            }
        }
        low = high;
        for(int i = 0; i < B; i++) {
            N -= (low+M[i]-1)/M[i];
        }
        
        int res = -1;
        for(int i = 0, cnt = 0; i < B; i++) {
            if(low%M[i] == 0) {
                ++cnt;
                if(cnt == N) {
                    res = i+1;
                    break;
                }
            }
        }
        
        cout << "Case #" << t+1 << ": " << res << '\n';
    }
    
    return 0;
}