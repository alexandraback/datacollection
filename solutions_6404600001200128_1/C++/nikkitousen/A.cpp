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

int N;
int m[1010];

int main()
{
  int T;
  cin >> T;
  REP(caso, T) {
    cout << "Case #" << caso+1 << ": ";
    cin >> N;
    REP(i, N) cin >> m[i];
    
    int met1 = 0;
    REP(i, N-1) met1 += max(m[i]-m[i+1], 0);
    
    
    
    int maxdif = 0;
    REP(i, N-1) maxdif = max(maxdif, m[i]-m[i+1]);
    
    int met2 = 0;
    REP(i, N-1) met2 += min(m[i], maxdif);
    
    
    cout << met1 << " " << met2 << endl;
  }
}
