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

std::vector<int64_t> M;

int64_t haircuts_at_time(int64_t t) { int64_t h = 0; REP(i,SZ(M)) h += t / M[i] + 1; return h; }

void solve()
{
    int B; int64_t N; std::cin >> B >> N;
    M.resize(B); REP(i,B) std::cin >> M[i];

    if (N <= B) { std::cout << N << std::endl; return; }

    int64_t lo=1, hi=2;
    while (haircuts_at_time(hi) <= (N-1))
    {
        lo = hi;
        hi *= 2;
    }

    while (hi - lo > 1)
    {
        const int64_t mid = (lo + hi) / 2;
        if (haircuts_at_time(mid) <= (N-1))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    int h = haircuts_at_time(lo);
    REP(j,B) if (hi % M[j] == 0)
    {
        h++; if (h == N) { std::cout << (j+1) << std::endl; break; }
    }
}

int main()
{
    int T; std::cin >> T;
    REP(t,T) { std::cout << "Case #" << (t+1) << ": "; solve(); }
}

