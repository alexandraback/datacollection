#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef long long LL;

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        cin >> N;
        vector<LL> state(N);
        for(int i = 0; i < N; i++){
            cin >> state[i];
        }
        int ans1 = 0;
        for(int i = 0; i+1 < N; i++){
            ans1 += max<LL>(0, state[i] - state[i+1]);
        }

        LL ans2 = 0;
        LL max_ratio = 0;
        for(int i = 0; i+1 < N; i++){
            max_ratio = max<LL>(max_ratio, state[i] - state[i+1]);
        }
        for(int i = 0; i+1 < N; i++){
            ans2 += min(state[i], max_ratio);
        }
        cout << "Case #" << t << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}


