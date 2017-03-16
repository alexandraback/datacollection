#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

#define REP(i,n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i,a,b) for(int i = (a); i < (int)(b); ++i)
#define FOREACH(i, n) for (__typeof((n).begin()) i = (n).begin(); i != (n).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(v) ((int)v.size())

#define pb push_back
#define mp make_pair


int count_seq( string str, int& pos ){
    char ch = str[pos];
    int ret = 0;

    while(pos < SIZE(str)){
        if (str[pos] == ch){
            ++pos;
            ++ret;
        }
        else{
            break;
        }
    }
    return ret;
}


int main(void)
{
    int TEST_NUM;
    cin >> TEST_NUM;

    for(int test = 0; test < TEST_NUM; ++test){
        int N;
        cin >> N;

        vector<string> strs(N);
        vector<string> uniq(N);
        REP(i,N){
            cin >> strs[i];
            uniq[i] = strs[i];
            uniq[i].erase( unique(ALL(uniq[i])), uniq[i].end() );
        }

        string id = uniq[0];
        bool fegla = false;
        FOR(i, 1, SIZE(uniq)){
            if (uniq[i] != id) {
                fegla = true;
                break;
            }
        }

        int ret = 0;
        if (!fegla)
        {
            vector<int> pos(N);
            FOREACH(ch, id){
                vector<int> counts(N);
                int mn = 10000;
                int mx = -1;
                REP(n, N){
                    counts[n] = count_seq( strs[n], pos[n] );
                    mn = min(counts[n], mn);
                    mx = max(counts[n], mx);
                }

                int mn_move = 10000;
                for( int t = mn; t <= mx; ++t){
                    int move = 0;

                    REP(n, N){
                        move += abs( t - counts[n] );
                    }
                    mn_move = min(move, mn_move);
                }
                ret += mn_move;
            }
        }

        cout << "Case #" << (test+1) << ": ";
        if (fegla) {
            cout << "Fegla Won" << endl;
        }
        else{
            cout << ret << endl;
        }
    }

    return 0;
}
