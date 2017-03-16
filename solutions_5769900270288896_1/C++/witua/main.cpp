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
const int MAX = 10007;
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
    freopen("B-large (3).in", "r", stdin);
    freopen("out.txt", "w", stdout);


    cin >> T;
    cerr << '-' << endl;
    FOR (test,0,T)
    {
        cin >> n >> m >> k;
        //n = 4;
        //m = 4;
        //k = test;
        /*
        int s = n*m;
        int res = INF;
        int mask2 = 0;
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
            if (sum < res)
            {
                res= min(res, sum);
                mask2 = mask;
            }
        }
        cout << k << ' ' << res/2 << endl << endl;
        FOR (i,0,n)
        {
            FOR (j,0,m)
                if ((mask2 & (1 << (i*m+j))) != 0)
                    cout << 1;
                else
                    cout << 0;
            cout << endl;
        }
        cout << endl;*/

        FOR (i,0,n)
            FOR (j,0,m)
                B[i][j] = 0;
        int cnt = n*m;
        int cnt0 = 0;
        int cnt1 = 0;
        FOR (i,0,n)
            FOR (j,0,m)
                if ((i+j) % 2 == 1)
                {
                    ++ cnt0;
                    B[i][j] = 1;
                }
        int cnt2 = 0;
        int cnt3 = 0;
        int cnt4 = 0;
        VI Q;
        FOR (i,0,n)
            FOR (j,0,m)
            {
                if (B[i][j] == 1)
                    continue;
                int x = 0;
                FOR (d,0,4)
                {
                    int ii = i+dx[d];
                    int jj = j+dy[d];
                    if (OK(ii, jj) && B[ii][jj])
                        ++ x;
                }
                Q.PB(x);
                if (x == 2)
                    ++ cnt2;
                else
                if (x == 3)
                    ++ cnt3;
                else
                    ++ cnt4;
            }
        sort(ALL(Q));
        int res2 = 0;
        if (k <= cnt0)
            res2 = 0;
        else
        {
            FOR (i,0,k-cnt0)
                res2 += Q[i];
        }
        cout << "Case #" << test+1 << ": " << res2 << endl;
        //cout << "Case #" << test+1 << ": " << res/2 << endl;
    }

    return 0;
}
