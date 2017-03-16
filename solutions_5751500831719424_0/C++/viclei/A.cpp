#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const int MAXN = 110, INF=(1<<20);
vector< pair<char,int> > strs[MAXN];

int solve(const vector< pair<char,int> > &t, int N) {
    int ans = 0;
    for( int i=0; i<N; i++ ) {
        for(int j=0; j<strs[i].size(); j++ ) {
            ans += abs(strs[i][j].second-t[j].second);
        }
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
        else gAns = INF;

        for( int i=0; i<N; i++ ) { //user this as the final result
            gAns = min(gAns, solve(strs[i],N));
            for( int j=0; j<strs[i].size(); j++ ) {
                if( j+1 > superS.size() ) {
                    superS.push_back( make_pair(strs[i][j].first, strs[i][j].second) );
                    minorS.push_back( make_pair(strs[i][j].first, strs[i][j].second) );
                }
                else {
                    superS[j].second = max(superS[j].second, strs[i][j].second);
                    minorS[j].second = min(minorS[j].second, strs[i][j].second);
                }
            }
        }
        gAns = min(gAns, solve(superS,N));
        gAns = min(gAns, solve(minorS,N));


        cout << "Case #" << tc << ": ";
        if( gAns==-1 ) cout << "Fegla Won";
        else cout << gAns;
        cout << endl;
    }

    return 0;
}
