//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
#include<cassert>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int SIZE = 200;
vector<pair<char, int> > v[SIZE];
int N;

void print() {
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < v[i].size() ; j++)
            cerr << v[i][j].first << "," << v[i][j].second << "  ";
        cerr << endl;
    }
        
}

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/A-small-attempt0.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/A-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out", "wt", stdout);

    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        
        cin >> N;
        cerr << t << " " << N << endl;
        cout << "Case #" << t << ": ";
        
        int i;
        for(i = 0 ; i < N ; i++){
            string st; cin >> st;
            v[i].clear();
            v[i].push_back(make_pair(st[0], 1));
            for(int j = 1 ; j < st.size() ; j++){
                if(st[j] == st[j-1]) {
                    v[i].back().second ++;
                } else {
                    v[i].push_back(make_pair(st[j], 1));
                }
            }
        }
        //print();
        
        bool ok = true;
        for(i = 0 ; i < N ; i++){
            if(v[i].size() != v[0].size()){
                ok = false;
                break;
            }
            for(int j = 0 ; j < v[0].size() ; j++){
                if(v[i][j].first != v[0][j].first){
                    ok = false;
                    break;
                }
            }
        }
        
        if (!ok){
            cout << "Fegla Won" << endl;
            continue;
        }
        
        int res = 0;
        for(int i = 0 ; i < v[0].size() ; i++){
            vector<int> cnt;
            for(int j = 0 ; j < N ; j++)
                cnt.push_back(v[j][i].second);
            
            int best = 1e9;
            for(int x = 1 ; x <= 100 ; x++){
                int diff = 0;
                for(int j = 0 ; j < cnt.size() ; j++)
                    diff += abs(x-cnt[j]);
                best = min(diff, best);
            }
            res += best;
        }
        cout << res << endl;
        
    }
    
    return 0;
}

