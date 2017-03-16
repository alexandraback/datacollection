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
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define CLEAR(v) memset((v), 0, sizeof(v))
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define LL long long

int main()
{
    int T;
    cin >> T;
    REP(caso, T) {
        cout << "Case #" << caso+1 << ": ";

        int N;
        cin >> N;
        vector< PII > a;
        REP(i, N) {
            int k;
            cin >> k;
            a.PB(MP(k,i));
        }
        SORT(a);

        string res = "";

        while(1) {
            int i=N-2;
            while(i >= 0 && a[i].first == a[i+1].first) i--;
            // cout << i << endl;
            if(i < 0) break;
            for(int j=N-1; j>i; j--) {
                res += (char)('A'+a[j].second);
                res += ' ';
                a[j].first--;
            }
        }
        if(N == 2) {
            REP(i, a[0].first) {
                res += (char)('A'+a[0].second);
                res += (char)('A'+a[1].second);
                res += ' ';
            }
        } else {
            REP(i, a[0].first) {
                REP(j, N) {
                    res += (char)('A'+a[j].second);
                    if(!(i == a[0].first-1 && j == N-2)) res += ' ';
                }
            }
        }

        cout << res << endl;
    }
}
