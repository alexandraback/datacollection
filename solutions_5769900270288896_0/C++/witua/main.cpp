#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 100;
const int MAX2 = 7000;
const int BASE = 1000000000;
const int CNT = 100;

int n, m, k, T;
int B[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool OK(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main()
{
    //freopen("in.txt", "r", stdin);
    freopen("B-small-attempt0 (4).in", "r", stdin);
    freopen("out.txt", "w", stdout);


    cin >> T;
    FOR (test,0,T)
    {
        cin >> n >> m >> k;
        int s = n*m;
        int res = INF;
        FOR (mask,0,(1 << s))
        {
            FOR (i,0,n)
                FOR (j,0,m)
                    B[i][j] = 0;
            int cnt = 0;
            FOR (i,0,n)
                FOR (j,0,m)
                    if ((mask & (1 << (i*m+j))) != 0)
                    {
                        ++ cnt;
                        B[i][j] = 1;
                    }
            if (cnt != k)
                continue;
            int sum = 0;
            FOR (i,0,n)
                FOR (j,0,m)
                {
                    if (B[i][j] == 0)
                        continue;
                    FOR (d,0,4)
                    {
                        int ii = i + dx[d];
                        int jj = j + dy[d];
                        if (OK(ii, jj) && B[ii][jj] == 1)
                            ++ sum;
                    }
                }
            res = min(res, sum);
        }
        cout << "Case #" << test+1 << ": " << res/2 << endl;
    }

    return 0;
}
