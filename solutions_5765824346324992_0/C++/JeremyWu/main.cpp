//#pragma comment(linker, "/STACK:16777216") //for c++ Compiler
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
#define Max(a,b) (((a) > (b)) ? (a) : (b))
#define Min(a,b) (((a) < (b)) ? (a) : (b))
#define Abs(x) (((x) > 0) ? (x) : (-(x)))
#define MOD 1000000007
#define pi acos(-1.0)

using namespace std;

typedef long long           ll      ;
typedef unsigned long long  ull     ;
typedef unsigned int        uint    ;
typedef unsigned char       uchar   ;

template<class T> inline void checkmin(T &a,T b){if(a>b) a=b;}
template<class T> inline void checkmax(T &a,T b){if(a<b) a=b;}

const double eps = 1e-7      ;
const int M = 1100011*2      ;
const ll P = 10000000097ll   ;
const int MAXN = 10900000    ;
const int INF = 0x3f3f3f3f   ;

int B, N;
int a[1200], cur[1200];

int main(){
    std::ios::sync_with_stdio(false);
    int i, j, t, k, u, v, numCase = 0;

    ofstream fout ("B-small-attempt2.out");
    ifstream fin ("B-small-attempt2.in");

    fin >> t;
    int T = t;
    while (T--) {
        //cout << T << endl;
        fin >> B >> N;
        for (i = 1; i <= B; ++i) {
            fin >> a[i];
        }

        memset (cur, 0, sizeof (cur));

        int flag = 1;
        /*
        for (i = 1; i <= B; ++i) {
            if (a[i] < a[flag]) {
                flag = i;
            }
        }
        */

        int ans[100000];
        int sum = 0;

        for (i = 1; i < N; ++i) {
            //fout << flag << endl;
            cur[flag] += a[flag];
            ans[sum++] = flag;

            int MIN = INF;
            for (j = 1; j <= B; ++j) {
                if (cur[j] < MIN) {
                    MIN = cur[j];
                    flag = j;
                }
            }

            for (j = 1; j < B; ++j) {
                if (cur[j] != cur[j + 1])   break;
            }
            if (j == B) {
                break;
            }
        }
/*
        for (i = 0; i < sum; ++i) {
            cout << ans[i] <<' ';
        }
        cout << endl;
*/
        if (i == N) {
            flag = 1;
            for (i = 2; i <= B; ++i) {
                if (cur[i] < cur[flag]) {
                    flag = i;
                }
            }
        } else {
            //cout << N << ' ' << sum << endl;
            if (N % sum == 0) {
                flag = ans[sum - 1];
            } else {
                flag = ans[N % sum - 1];
            }
        }

        fout << "Case #" << ++numCase << ": " << flag << endl;
    }

    return 0;
}









