#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const int MAXN = 110, INF=(1<<20);
vector< pair<char,int> > strs[MAXN];

int solve(int N) {
    int ans = 0;
    for( int i=0; i<strs[0].size(); i++ ) {
        int bT = INF;
        for( int T=1; T<110; T++ ) {
            int curT = 0;
            for( int j=0; j<N; j++ ) {
                curT += abs(strs[j][i].second - T);
            }
            bT = min( bT, curT );
        }
        ans += bT;
    }
    return ans;
}

int main() {

    int tcN;
    cin >> tcN;

    for( int tc = 1; tc <= tcN; tc++ ) {
        int N, gAns = -1;
        for( int i=0; i<MAXN; i++ ) strs[i].clear();
        vector< pair<char,int> > superS, minorS;

        cin >> N;
        for( int i=0; i<N; i++ ) {
            string t;
            cin >> t;
            //cout << t << endl;
            for( int j=0; j<t.size(); j++ ) {
                int k = j+1, curC = t[j], cCnt = 1;
                while (k<t.size() && t[k] == t[j]) cCnt++, k++;
                strs[i].push_back( make_pair(curC,cCnt) );
                j = k-1;

            }
        }

        bool ok = true;
        for( int i=1; i<N; i++ ) {
            if( strs[0].size() != strs[i].size() ) {
                ok = false;
                break;
            }
            for(int j=0; j<strs[i].size(); j++ ) {
                if( strs[i][j].first != strs[0][j].first ) {
                    ok = false;
                    break;
                }
            }
        }

        if( !ok ) gAns = -1;
        else {
            gAns = INF;
            gAns = min(gAns, solve(N));
        }



        cout << "Case #" << tc << ": ";
        if( gAns==-1 ) cout << "Fegla Won";
        else cout << gAns;
        cout << endl;
    }

    return 0;
}
