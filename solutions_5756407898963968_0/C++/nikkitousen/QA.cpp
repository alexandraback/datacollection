#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back

int main()
{
    int T;
    int c1[4][4], c2[4][4];
    int mark[20];
    int r1, r2;
    
    cin >> T;
    REP(c, T) {
        int ans=-1;
        CLEAR(mark);
        cin >> r1;
        REP(i, 4) {
            REP(j, 4) {
                cin >> c1[i][j];
                if(i+1 == r1) mark[c1[i][j]] = 1;
            }
        }
        
        cin >> r2;
        REP(i, 4) {
            REP(j, 4) {
                cin >> c2[i][j];
                if(i+1 == r2) {
                    if(mark[c2[i][j]]) {
                        if(ans < 0) ans = c2[i][j];
                        else if (ans > 0) ans = 0;
                    }
                }
            }
        }
        
        cout << "Case #" << c+1 << ": ";
        if(ans < 0) cout << "Volunteer cheated!";
        else if (ans == 0) cout << "Bad magician!";
        else cout << ans;
        cout << endl;
    }
}
