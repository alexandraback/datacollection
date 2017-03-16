#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;

LL solve(LL N, vector<pair<LL, LL> >& pos, LL cur){
    LL ans = N;
    if(N <= 1) return 0;
    for(int c = 0; c < N; c++){
        if(c == cur) continue;
        LL dx1 = pos[cur].first - pos[c].first;
        LL dy1 = pos[cur].second - pos[c].second;
        LL positive = 0;
        LL negative = 0;
        for(int i = 0; i < N; i++){
            if(i == c || i == cur) continue;
            LL dx2 = pos[i].first - pos[c].first;
            LL dy2 = pos[i].second - pos[c].second;
            LL val = (dx1 * dy2) - (dx2 * dy1);
            if(val > 0) positive++;
            if(val < 0) negative++;
        }
        ans = min(ans, positive);
        ans = min(ans, negative);
    }
    return ans;
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        LL N;
        cin >> N;
        vector<pair<LL,LL> > pos(N);
        for(int i = 0; i < N; i++){
            cin >> pos[i].first >> pos[i].second;
        }
        cout << "Case #" << t << ":" << endl;
        for(int i = 0; i < N; i++){
            LL ans = solve(N, pos, i);
            cout << ans << endl;
        }
    }
    return 0;
}


