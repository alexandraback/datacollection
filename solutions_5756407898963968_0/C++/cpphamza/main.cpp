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
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

int pos[2][16], a[2];

int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/A-small-attempt0.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/1.out", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        for(int i = 0 ; i < 2 ; i++){
            cin >> a[i]; a[i]--;
            for(int r = 0 ; r < 4 ; r++)
                for(int j = 0; j < 4 ; j++){
                    int x; cin >> x;
                    pos[i][x-1] = r;
                }
        }
        
        int res = 0, cnt = 0;
        for(int i = 0 ; i < 16 ; i++)
            if(pos[0][i] == a[0] && a[1] == pos[1][i]){
                res = i+1 ; cnt++;
            }
        
        switch(cnt) {
            case 1:
                cout << "Case #" << t << ": " << res << endl;
                break;
            case 0:
                cout << "Case #" << t << ": Volunteer cheated!" << endl;
                break;
            default:
                cout << "Case #" << t << ": Bad magician!" << endl;
                break;
        }
        
    }
    
    return 0;
}

