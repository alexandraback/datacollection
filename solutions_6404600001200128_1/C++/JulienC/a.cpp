#include <algorithm>
#include <cassert>
#include <complex>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <tuple>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0,nn=static_cast<int>(n);i<nn;i++)
#define REP_R(i,n) for(int i=static_cast<int>(n)-1;i>=0;i--)
#define ALL(v) v.begin(),v.end()
#define ALL_R(v) v.rbegin(),v.rend()
#define SZ(v) static_cast<int>(v.size())
template<typename T> inline T sqr(T a) { return a*a; }

void solve()
{
    int N; std::cin >> N;
    std::vector<int> M(N); REP(i,N) std::cin >> M[i];

    int ans1 = 0, D = 0;
    REP(i,N-1) if (M[i] > M[i+1])
    {
        ans1 += (M[i] - M[i+1]);
        D = std::max(D, M[i] - M[i+1]);
    }

    int ans2 = 0;
    REP(i,N-1) ans2 += std::min(D, M[i]);

    std::cout << ans1 << " " << ans2 << std::endl;
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

