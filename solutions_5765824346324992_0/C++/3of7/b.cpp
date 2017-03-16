#include <algorithm>
#include <bitset>
#include <cmath>
#include <fstream>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        int B, N, ans;
        cin >> B >> N;
        vector<int> v(B);
        for(int i = 0; i < B; i++) {
            cin >> v[i];
        }
        long long lo = 0, hi=(1LL<<62);
        while(lo < hi) {
            long long mid = lo + (hi - lo)/2;
            long long total = 0;
            for(int i = 0; i < B; i++) {
                total += mid / v[i];
            }
            if(total >= N-1) hi = mid;
            else lo = mid+1;
        }
        int rem = N-1;
        vector<int> c(B);
        int best = 1<<30;
        for(int i = 0; i < B; i++) {
            int can = lo/v[i];
            can = min(can, rem);
            rem -= can;
            c[i] = v[i]*can;
            if(c[i] < best) {
                best = c[i];
                ans = i;
            }
        }
        cout << "Case #" << t << ": " << ans + 1 << endl;
    }
    return 0;
}