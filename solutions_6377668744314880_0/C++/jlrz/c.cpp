#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory>
#include <cassert>
#include <set>
#include <numeric>
#include <functional>
#include <bitset>

using namespace std;

#define ALL(x) begin(x), end(x)

#define FORI(i,a,b)   for (decay_t<decltype(b)> i=a, _b=b; i <  _b; ++i)
#define FORLE(i,a,b)  for (decay_t<decltype(b)> i=a, _b=b; i <= _b; ++i)
#define FORD(i,a,b)   for (decay_t<decltype(a)> i=a, _b=b; i >  _b; --i)
#define FORGE(i,a,b)  for (decay_t<decltype(a)> i=a, _b=b; i >= _b; --i)
#define FREACH(x, A)  for (auto &x : A)

#define DISCARD_LINE do { char buf[32]; fin.getline(buf, 32); } while(0)

template <typename T> T read_var() { T var; fin >> var; return var; }

//#define READI(var)   int var;       fin >> var
//#define READLL(var)  long long var; fin >> var
//#define READSTR(var) string var;    fin >> var

#define READI(var)   auto var = read_var<int>()
#define READLL(var)  auto var = read_var<long long>()
#define READSTR(var) auto var = read_var<string>()

#define DPF(...) do { fprintf(fout, __VA_ARGS__); printf(__VA_ARGS__); } while(0)

/* memoization stuff */
template <class RetType, class... Args> struct Memoize { template <class... KeyArgs> static std::map<std::tuple<KeyArgs...>, RetType> make_memoize_cache(KeyArgs... args); }; template <class RetType, class... Args> Memoize<RetType, Args...> make_memoize(RetType(*func)(Args...));
#define MEMOIZATION_HEADER(isLocalCache, funcName, ...) using funcName##_Memoize_Cache = decltype(decltype(make_memoize(funcName))::make_memoize_cache(__VA_ARGS__)); static funcName##_Memoize_Cache _memoizeCache; static int _memoizeLevel = 0; if ((isLocalCache) && _memoizeLevel == 0) _memoizeCache.clear(); funcName##_Memoize_Cache::key_type _memoizeKey{ __VA_ARGS__ }; auto itr = _memoizeCache.find(_memoizeKey); if (itr != end(_memoizeCache)) return itr->second; ++_memoizeLevel; auto& _memoizeReturnValue = _memoizeCache[_memoizeKey]
#define MEMOIZATION_RETURN(retValue) { _memoizeReturnValue = retValue; --_memoizeLevel; return _memoizeReturnValue; }

using dword = unsigned int;
using qword = unsigned long long;

using int32 = int;
#define int long long

using lb = list<bool>;
using lc = list<char>;
using li = list<int>;
using ld = list<double>;
using ls = list<string>;

using vb = vector<bool>;
using vc = vector<char>;
using vi = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vll = vector<long long>;

using vdw = vector<dword>;
using vqw = vector<qword>;

using pii = pair<int, int>;

FILE* fout; ifstream fin;
void parse_cmd_line(int32 argc, char *argv[]){ fin.open((argc < 2 ? "in.txt" : argv[1])); fopen_s(&fout, (argc < 3 ? "out.txt" : argv[2]), "w"); }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct vec2
{
    int x, y;
};

vec2 ortho(const vec2& slope)
{
    vec2 ret;
    ret.x = -slope.y;
    ret.y = slope.x;

    return ret;
}

long long greatest_common_denominator(long long a, long long b)
{
    while (b)
    {
        a = a%b;

        // swap
        a ^= b; b ^= a; a ^= b;
    }

    return a;
}

int dot(const vec2& lhs, const vec2& rhs)
{
    return lhs.x*rhs.x + lhs.y*rhs.y;
}

vec2 get_slope(const vec2& from, const vec2& to)
{
    vec2 ret;
    ret.x = to.x - from.x;
    ret.y = to.y - from.y;

    auto gcd = greatest_common_denominator(abs(ret.x), abs(ret.y));

    ret.x /= gcd;
    ret.y /= gcd;

    return ret;
}


void process()
{
    READI(numTrees);

    vector<vec2> trees(numTrees);

    FORI(i, 0, numTrees)
    {
        READI(x);
        READI(y);

        trees[i].x = x;
        trees[i].y = y;
    }

    vi obsTrees(numTrees);
    fill(ALL(obsTrees), numTrees-1);

    FORI(i, 0, numTrees)
    {
        FORI(j, 0, numTrees)
        {
            if (j == i) continue;

            int sideA = 0;
            int sideB = 0;

            auto slope = get_slope(trees[i], trees[j]);
            auto cross = ortho(slope);

            FORI(k, 0, numTrees)
            {
                if (k == i || k == j) continue;

                auto slope2 = get_slope(trees[i], trees[k]);
                auto dp = dot(cross, slope2);
                if (dp < 0)
                {
                    ++sideA;
                }
                else if (dp > 0)
                {
                    ++sideB;
                }
            }

            int tmp = min(sideA, sideB);
            
            obsTrees[i] = min(obsTrees[i], tmp);
            
            if (obsTrees[i] == 0) break;
        }
    }

    for (auto& i : obsTrees)
    {
        DPF("\n%d", i);
    }
}

int32 main(int32 argc, char *argv[])
{
    parse_cmd_line(argc, argv);

    READI(nCases);
    DISCARD_LINE;

    FORLE(i, 1, nCases)
    {
        DPF("Case #%d: ", i);

        process();

        DPF("\n");
    }

    return 0;
}