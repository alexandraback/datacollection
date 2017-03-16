#include <bits\stdc++.h>
typedef long long ll;
using namespace std;
int t;
int n;
ll a[(1 << 17)];
int main(){
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;

    for(int qr = 0; qr < t; ++qr){
        ll m_cnt;
        cin >> n;
        cin >> m_cnt;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        ll l = 0;
        ll r = 1e15;
        //cout << -1 << endl;
        while(l < r){
            ll md = (l + r) / 2;
            ll cnt = n;
            for(int i = 0; i < n; ++i){
                cnt += md / a[i];
            }
            if(cnt >= m_cnt){
                r = md;
            }
            else{
                l = md + 1;
            }
        }
        ll cnt = n;
        for(int i = 0; i < n; ++i){
            cnt += l / a[i];
        }
        //cout << -1 << endl;
        vector<int> cur;
        for(int i = 0; i < n; ++i){
            if(l % a[i] == 0){
                cur.push_back(i + 1);
            }
        }
        sort(cur.begin(), cur.end());
        ll ans = cur[cur.size() - (cnt - m_cnt) - 1];
        cout << "Case #" << qr + 1 << ": " << ans << "\n";
    }
}
