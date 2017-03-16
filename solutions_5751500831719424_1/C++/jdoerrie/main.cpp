#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <cstring>
#include <ctime>
#include <cassert>

#define REP(k,a) for(int k = 0; k < (a); ++k)
#define FOR(k,a,b) for(int k=(a); k < (b); ++k)
#define FRE(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define CLR(c) memset((c), 0, sizeof(c))
#define VCLR(v) fill((v).begin(), (v).end(), 0)
#define PB push_back
#define MP make_pair
#define DBG(x) std::cerr << #x" = " << x << std::endl
#define I1 first
#define I2 second

const int INF = 1000000000;

using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<double> VD;
typedef vector<vector<double> > VVD;
typedef vector<string> VS;
typedef pair<int,int> II;
typedef vector<pair<int,int> > VII;
typedef long long LL;
typedef long double LD;

string normalize(const string& str_)
{
    string str = "";
    str += str_[0];
    for (int i = 1; i < str_.size(); ++i)
    {
        if (str_[i] != str_[i-1])
            str += str_[i];
    }

    return str;
}

bool are_equivalent(const VS& strs)
{
    string str = normalize(strs[0]);
    for (int i = 0; i < strs.size(); ++i)
    {
        if (str != normalize(strs[i]))
        {
            return false;
        }
    }

    return true;
}

VVI get_counts(const VS& strs)
{
    VVI counts(strs.size());
    for (int i = 0; i < strs.size(); ++i)
    {
        int n = 0;
        counts[i].push_back(1);
        for (int j = 1; j < strs[i].size(); ++j)
        {
            if (strs[i][j] == strs[i][j-1])
            {
                counts[i][n]++;
            }
            else
            {
                counts[i].push_back(1);
                ++n;
            }
        }
    }

    return counts;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t)
    {
        cout << "Case #" << t+1 << ": ";
        int N;
        cin >> N;
        VS strs(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> strs[i];
        }

        if (!are_equivalent(strs))
        {
            cout << "Fegla Won" << endl;
            continue;
        }

        VVI counts = get_counts(strs);

        int total_diff = 0;
        for (int i = 0; i < counts[0].size(); ++i)
        {
            int min_diff = INF;
            for (int num = 1; num <= 100; ++num)
            {
                int this_diff = 0;
                for (int j = 0; j < counts.size(); ++j)
                {
                    this_diff += abs(counts[j][i] - num);
                }

                min_diff = min(min_diff, this_diff);
            }

            total_diff += min_diff;
        }

        cout << total_diff << endl;
    }

    return 0;
}
