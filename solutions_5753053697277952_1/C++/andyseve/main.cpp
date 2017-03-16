#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
#define int long long

int power(int a, int b)
{
    if (b == 0) return 1;
    if (b & 1) return power(a, b - 1) * a;
    return power(a * a, b / 2);
}

#undef int
int main()
{
#define int long long
    freopen("in", "r", stdin); freopen("out","w", stdout);
    int t; cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        cerr << "Executing Case #" << tt << "\n";
        int n; cin >> n;
        int p[n];
        for (int i = 0; i < n; i++) cin >> p[i];
        int inside = 0, parties = 0;
        for (int i = 0; i < n; i++) inside += p[i], parties += (! ! p[i]);
        cout << "Case #" << tt << ": ";
        while(inside > 0){
            int m = 0, ret;
            for (int i = 0; i < n; i++){
                if(p[i] > m){
                    ret = i;
                    m = p[i];
                }
            }
            if(parties == 2 && 2 * m == inside){
                for (int i = 0; i < n; i++){
                    if(p[i] > 0){
                        cout << (char) ('A' + i);
                        p[i] --, inside--;
                        if(!p[i]) parties--;
                    }
                }
                cout << " ";
            }
            else{
                p[ret]--, inside--;
                if(p[ret] == 0) parties--;
                cout << (char) ('A' + ret) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
