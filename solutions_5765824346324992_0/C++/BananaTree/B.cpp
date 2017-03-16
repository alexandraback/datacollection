#include <bits/stdc++.h>
#define FOR(i, n) for (int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
int main() {
    int T;
    cin >> T;
    FOR(tt, T) {
        ll barbe, number;
        cin >> barbe >> number;
        vector<ll> tm(barbe);
        FOR(i, barbe) cin >> tm[i];
        cout << "Case #" << tt + 1 << ": ";
        ll left = 1, right = static_cast<ll>(1e15);
        ll mid = -1, cnt = 0, tmp = 0;
        while (left < right) {
            mid = (left + right) / 2;
            // cout << left << " " << right << endl;
            cnt = tmp = 0;
            FOR(i, barbe) {
                cnt += mid / tm[i];
                tmp += (mid % tm[i] == 0);
            }
            if (cnt < number - 1 && (cnt + tmp) < number) left = mid + 1;
            else if (cnt == number - 1) right = mid;
            else if (cnt < number - 1 && (cnt + tmp) >= number) right = mid;
            else if (cnt > number - 1 && (cnt - tmp) < number - 1) right = mid;
            else if (cnt > number - 1) right = mid - 1;
        }
        mid = left;
        // cout << "mid: " << mid << endl;
        ll res = -1;
        ll rem = tmp;
        cnt = 0;
        FOR(i, barbe) cnt += mid / tm[i];
        tmp = cnt;        
        if (tmp < number) {        
            FOR(i, barbe) {
                if (mid % tm[i] == 0) {
                    ++tmp;
                    if (tmp >= number) { res = i; break; }
                }
            }
        }
        else {
            vector<pair<ll, ll> > v;            
            FOR(i, barbe) {
                if (mid % tm[i] == 0) v.push_back(make_pair(mid - tm[i], i));                
            }
            rem = v.size();
            sort(v.begin(), v.end());
            tmp = tmp - rem;
            assert(tmp < number);
            FOR(i, v.size()) {
                ++tmp;
                if (tmp == number) { res = v[i].second; break; }                
            }
        }
        assert(res != -1);
        cout << res + 1 << endl;
    }
    return 0;
}
