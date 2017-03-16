#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t,n;
    cin >> t;
    for(int cn=1;cn<=t;cn++){
        cin >> n;
        vector<int> vec(n);
        for(auto&x : vec) cin >> x;
        vector<pair<int,int>> s;
        for(int i=0;i<n;i++){
            s.push_back({vec[i],i});
        }
        int tt = 0;
        for(auto&x : vec) tt += x;
        vector<string> res;
        for(int i=0;;i++){
            sort(s.begin(),s.end(),greater<pair<int,int>>());
            int a = 0;
            for(auto&x : s) a+= x.first;
            if (a==0) break;
            string r = "";
            s[0].first--;
            r.push_back((s[0].second+'A'));
            if (s.size() > 2 &&(s[0].first+1 == s[1].first) &&(s[1].first == s[2].first)) {
                                res.push_back(r);

                    continue;
            }
            if (s.size() > 1 && s[1].first > 0 &&s[1].first > s[0].first){
                s[1].first--;
                r.push_back(s[1].second+'A');
            }
            res.push_back(r);
        }
        cout << "Case #" << cn << ": ";
        for(int i=0;i<res.size();i++){
            cout << res[i] << " \n"[i==res.size()-1];
        }
    }
    return 0;
}
