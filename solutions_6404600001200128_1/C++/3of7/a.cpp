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
        int ans1 = 0, ans2 = 1<<30;
        int N;
        cin >> N;
        vector<int> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
            if(i>0 && v[i]<v[i-1]) {
                ans1 += v[i-1]-v[i];
            }
        }
        int rate = 0;
        for(int i = 1; i < N; i++) {
            if(v[i-1] > v[i]) {
                rate = max(rate, v[i-1]-v[i]);
            }
        }
        int tans = 0;
        for(int i = 0; i < N-1; i++) {
            tans += min(v[i], rate);
        }
        ans2 = min(ans2, tans);
        cout << "Case #" << t << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}