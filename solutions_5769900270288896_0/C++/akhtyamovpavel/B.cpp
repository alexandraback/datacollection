#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <complex>
#include <iomanip>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<vector<int> > graph;
const int INF = 1000000000;
const ll MOD = 1000000009;
#define FILEIN "B.in"
#define FILEOUT "B.out"



int main(){
    freopen(FILEIN, "r", stdin);
    freopen(FILEOUT, "w", stdout);
    int tests;
    cin >> tests;
    for (int _ = 1; _ <= tests; ++_){
    	
        
        int R, C;
        cin >> R >> C;
        int N;
        cin >> N;
        int minans = 10000;

        for (int m = 0; m < (1<<(R*C)); ++m) {
            int ma[R*C];
            int val = m;
            int sum = 0;
            for (int i =0; i < R*C; ++i) {
                ma[i] = val % 2;
                val /= 2;
                sum += ma[i];

            }
            // cout << m << " " << sum << endl;
            if (sum != N) {
                continue;
            }
            int curans = 0;
            for (int i = 0; i < R*C; ++i) {
                int row = i % R;
                int col = i /R;
                if (ma[i] > 0) {
                    if (row > 0) {
                        int pre_r = R*(col) + row - 1;
                        if (ma[pre_r] > 0) {
                            ++curans;
                        }
                    }
                    if (col > 0) {
                        int pre_c = R*(col - 1) + row;
                        if (ma[pre_c] > 0) {
                            ++curans;
                        }
                    }
                }
            }
            minans = min(curans, minans);
        }

        cout << "Case #" << _ << ": ";
        //Output answer 
        
        cout << minans;
        cout << "\n";
    }
    return 0;
}