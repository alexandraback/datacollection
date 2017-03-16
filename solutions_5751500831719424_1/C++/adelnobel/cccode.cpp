/* In the name of ALLAH, most gracious, most merciful */
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;



int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif    
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T, n, t = 1;
    
    cin >> T;
    while(T--){
        cin >> n;
        vector< string > v(n), vv(n, "");
        vector< vector< int > > occ(n);
        int tot = 0;
        for(int i = 0; i < n; i++){
            cin >> v[i];
            vv[i] += v[i][0];
            tot = 1;
            for(int j = 1; j < v[i].size(); j++){
                if(v[i][j] != v[i][j - 1]){
                    vv[i] += v[i][j];
                    occ[i].push_back(tot);
                    tot = 1;
                }else{
                    tot++;
                }
            }
            occ[i].push_back(tot);
        }
        bool ok = true;
        for(int i = 1; i < n && ok; i++){
            if(vv[i] != vv[i - 1]){
                ok = false;
            }
        }
        vector< int > maxi(occ[0].size(), 0);
        if(ok){
            for(int i = 1; i < occ.size(); i++){
                assert(occ[i].size() == occ[i - 1].size());
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < occ[i].size(); j++){
                    maxi[j] = max(occ[i][j], maxi[j]);
                }
            }
        }
        
        int res = 0;
        for(int i = 0; i < occ[0].size(); i++){
            int bestOfThis = 1e9;
            for(int j = 1; j <= maxi[i]; j++){
                int cur = 0;
                for(int k = 0; k < n; k++){
                    cur += abs(j - occ[k][i]); 
                }
                bestOfThis = min(cur, bestOfThis);
            }
            res += bestOfThis;
        }
        cout << "Case #" << t++ << ": ";
        if(!ok){
            cout << "Fegla Won";
        }else{
            cout << res;
        }
        cout << endl;
    }
    
    return 0;
}