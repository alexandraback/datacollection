#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;

LL solve(LL B, LL N, vector<LL>& interval, LL th){
    LL cnt = 0;
    if(th == 0) return B;
    for(size_t i = 0; i < interval.size(); i++){
        cnt += 1 + th / interval[i];
    }
    return cnt;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        LL B, N;
        cin >> B >> N;
        vector<LL> interval(B);
        for(int i = 0; i < B; i++){
            cin >> interval[i];
        }
        LL left = 0;
        LL right = 1000000000LL * 200000;
        while(left+1 < right){
            LL middle = (left + right) / 2;
            LL ans = solve(B, N, interval, middle);
            if(ans >= N){
                right = middle;
            }else{
                left = middle;
            }
        }
        if(solve(B, N, interval, left) < N) left++;
        LL ans = 0;
        LL cnt = 0;
        for(int i = 0; i < B; i++){
            if(left == 0){
                cnt += 1;
            }else{
                cnt += 1 + (left-1) / interval[i];
            }
            if(cnt == N){
                ans = i+1;
                break;
            }
        }
        for(int i = 0; i < B; i++){
            if(left % interval[i] == 0){
                cnt++;
                if(cnt == N){
                    ans = i+1;
                    break;
                }
            }
        }
        if(ans == 0){
            cerr << "N=" << N << ", B=" << B << endl;
            for(int i = 0; i < B; i++){
                cerr << interval[i] << " " << endl;
            }
        }
        assert(ans != 0);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}


