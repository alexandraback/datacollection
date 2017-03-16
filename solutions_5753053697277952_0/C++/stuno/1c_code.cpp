#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000


int main(){
    ios_base::sync_with_stdio(false);
    freopen("C:\\in.txt", "r", stdin);
    freopen("C:\\GCJ_1C_2016\\1c_out.txt", "w", stdout);
    int TC;
    cin >> TC;
    int cas = 1;
    while(TC--){
        ll n;
        cin >> n;
        vector<pair<int, int> > v;
        int left = 0;
        for(int i=0; i<n; ++i){
            int x;
            cin >> x;
            left+= x;
            v.push_back(make_pair(x, i));
        }
        sort(v.rbegin(), v.rend());
        string res = "";
        while(left){
                    if(res.size() != 0) res.push_back(' ');
            if(v.size() > 1){
                if(v[0].first > v[1].first || (v.size() > 2 && v[0].first == 1 && v[1].first == 1 && v[2].first == 1)){
                    res.push_back('A' + v[0].second);
                    left--;
                    v[0].first--;
                } else {
                    res.push_back('A' + v[0].second);
                    left--;
                    v[0].first--;
                    if(v[1].first > 0){
                        res.push_back('A' + v[1].second);
                        v[1].first--;
                        left--;
                    }
                }
            } else {
                //cout << "FAAAAILLL" << endl;
            }
            sort(v.rbegin(), v.rend());
        }
        cout << "Case #" << cas++ <<  ": " << res << endl;
    }
    return 0;
}
