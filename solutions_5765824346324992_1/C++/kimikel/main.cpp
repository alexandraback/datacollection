#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long T, B, N, m[1100];
    cin >> T;
    for (long long tc = 1; tc <= T; tc++) {
        cin >> B >> N;
        for (long long i = 0; i < B; i++) cin >> m[i];
        
        //double rate = 0;
        //for (long long i = 0; i < B; i++) rate += 1.0/m[i];
        
        //double ans = rate;
        
        long long ans = 0;
        
        long long lo = 0, hi = 1;
        bool findUpperBound = true;
        
        while (true) {

            long long time = findUpperBound ? hi : (lo+hi)/2;
            
            long long finished = 0;
            long long free = 0;
            for (long long i = 0; i < B; i++) {
                finished += time/m[i];
                if (time%m[i] == 0) free++;
            }
            long long working = B-free;
            long long waiting = N-finished-working;

            if (waiting > 0 && free >= waiting) {
                for (long long i = 0; i < B; i++) {
                    if (time%m[i] == 0) waiting--;
                    if (waiting == 0) {
                        ans = i+1;
                        break;
                    }
                }
                //cout << waiting << " " << free << endl;
                break;
            } else if (waiting <= 0) { // decrease time
                if (findUpperBound) {
                    findUpperBound = false;
                } else {
                    hi = time-1;
                }
            } else { // increase time
                if (findUpperBound) {
                    hi *= 2;
                } else {
                    lo = time+1;
                }
            }
        }
        
        
        cout << "Case #" << tc << ": " << ans << endl;
    }

    return 0;
}

