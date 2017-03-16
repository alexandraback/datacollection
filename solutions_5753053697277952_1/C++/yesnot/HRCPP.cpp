#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <limits>

using namespace std;

typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<string> vecs;
typedef vector<int> veci;
typedef vector<long long> vecll;

template <typename T>
string tostring ( T value )
{
    ostringstream ss;
    ss << value;
    return ss.str();
}

template <typename T>
T strtonum ( const string &Text )
{
    istringstream ss(Text);
    T result;
    return ss >> result ? result : 0;
}
#define MOD 1000000007

//----------------------------------
void solve()
{
    int numCases = 1;
    cin >> numCases;

    for ( int ncase=1; ncase <= numCases; ncase++ )
    {
        //===== start case
        long N;
        cin >> N;
        vector<int> sn(26);
        int totN=0;
        for (int i=0;i<N;i++) {
            cin >> sn[i];
            totN += sn[i];
        }

        vector<string> vs;
        while (totN>0) {
            int imax=0;
            for (int i=1;i<N;i++) {
                    if (sn[i]>sn[imax]) {
                        imax=i;
                    }
            }
            sn[imax]--;
            totN--;
            char c1=('A'+imax);
            string s=tostring(c1);

            imax=0;
            for (int i=1;i<N;i++) {
                    if (sn[i]>sn[imax]) {
                        imax=i;
                    }
            }
            if (sn[imax]*2>totN) {
                char c2=('A'+imax);
                sn[imax]--;
                totN--;
                s = s + tostring(c2);

            }

            vs.push_back(s);
        }
        cout << "Case #" << ncase <<": ";
        for (int i=0;i<vs.size();i++) {
            if (i>0)
                cout << " ";
            cout << vs[i];
        }
        cout << endl;
        //===== end case
    }
}

int main()
{
#ifdef CCQTEST
#include "HRCPP1.h"
#endif
    solve();
#ifdef CCQTEST
#include "HRCPP2.h"
#endif
    return 0;
}
