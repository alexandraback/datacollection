#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>


using namespace std;

int RR, CC;

int numbits(int n){
    int ret = 0;
    while(n != 0){
        n = n&(n-1);
        ret++;
    }
    return ret;
}

bool set(int R, int C, int mask){
    if(R >= RR || C >= CC) return false;
    return (((1<<(R*CC + C))&mask) != 0);
}

int calc(int R, int C, int mask){
    int ret = 0;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(set(r, c, mask) && set(r+1, c, mask)){
                //cout << r << " " << c << endl;
                ret++;
            }
            if(set(r, c, mask) && set(r, c+1, mask)){
                //cout <<"c2: " <<  r << " " << c << endl;
                ret++;
            }
        }
    }
    return ret;
}

int main() {
    int TC;

    cin >> TC;
    int casenum = 1;
    while(TC--){
        int N;
        cin >> RR >> CC >> N;
        // bruteforce
        int ans = 100000;
        for(int bit = 0; bit < 1<<(RR*CC); bit++) if(numbits(bit) == N){
            ans = min(ans, calc(RR, CC, bit));
        }

        cout << "Case #" << casenum++ << ": " << ans << endl;

    }
    return 0;
}
