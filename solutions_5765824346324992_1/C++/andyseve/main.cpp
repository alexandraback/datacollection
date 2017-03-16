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

int B, N;
int M[1005], barb[1005];
long long lo = 0, hi = 100000000000025;
int djfafjakljdlak = 0;
int search(long long in){
    long long cur = 0, ava = 0;
    for(int i = 0; i < B; i++){
        cur += in / M[i];
        if(in % M[i]) cur += 1;
        else{
            barb[ava] = i;
            if(djfafjakljdlak < 60) cerr << i << "\n";
            ava++;
        }
    }
    if(djfafjakljdlak < 60) cerr << lo << " " << in << " " << hi << " " << cur << " " << ava<< "\n";
    djfafjakljdlak++;
    if(cur < N && cur + ava >= N){
        return barb[N-cur-1];
    }
    else if(cur > N-1){
        hi = in;
        in = (lo + hi) / 2;
        return search(in);
    }
    else{
        lo = in;
        in = (lo + hi) / 2;
        return search(in);
    }
}

int main()
{
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _T;
    cin >> _T;
    for(int T = 0; T < _T; T++){
        cout << "Case #" << T+1 << ": ";
        cin >> B >> N;
        for(int i = 0; i < B; i++) cin >> M[i];
        int k = 0;
        for(int i = 0; i < B; i++) if(M[i] > k) k = M[i];
        lo = 0, hi = ((long long) 1000000000 * k)/B + 23, T == 2 ? djfafjakljdlak = 0 : djfafjakljdlak=61;
        long long in = (lo + hi) / 2;
        cout << search(in) + 1 << "\n";
    }
    return 0;
}
