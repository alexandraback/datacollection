#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long LL;

LL solve2(vector<double>& ord){
    const double EPS = M_PI * 0.5e-10;
    LL ans = ord.size();

//cerr << "---" << endl;
    for(size_t i = 0; i < ord.size(); i++){
        double rad = ord[i];
        LL cnt = 0;
        if(rad > EPS){
            cnt += ord.size() - i - 1;
            double cur_val = rad - M_PI - EPS;
            cnt += lower_bound(ord.begin(), ord.end(), cur_val) - ord.begin();
        }else{
            double cur_val = rad + M_PI - EPS;
            cnt += lower_bound(ord.begin(), ord.end(), cur_val) - ord.begin() - i - 1;
        }
        ans = min(ans, cnt);
        //cerr << "d:" << ord[i] << ", " << cnt << endl;
    }
    return ans;
}

LL solve(LL N, vector<pair<LL, LL> >& pos, LL cur){
    LL ans = N;
    if(N <= 2) return 0;

    vector<double> ord;
    vector<double> ord2;
    for(int c = 0; c < N; c++){
        if(c == cur) continue;
        LL dx1 = pos[c].first - pos[cur].first;
        LL dy1 = pos[c].second - pos[cur].second;
        double rad = atan(double(dy1) / double(dx1));
        if(dy1 < 0 && dx1 < 0) rad -= M_PI;
        if(dy1 > 0 && dx1 < 0) rad += M_PI;
        if(dy1 == 0 && dx1 < 0) rad = -M_PI;
        //cerr << cur << ", " << c << " : " << pos[c].first << ", " << pos[c].second << ": " << dx1 << ", " << dy1 << ", " << rad << endl;
        ord.push_back(rad);
        ord2.push_back(-rad);
    }
    sort(ord.begin(), ord.end());
    sort(ord2.begin(), ord2.end());
    ans = min(ans, solve2(ord));
    ans = min(ans, solve2(ord2));
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


