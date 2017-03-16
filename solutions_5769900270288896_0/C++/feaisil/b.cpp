#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>
#include <stack>

using namespace std;

#define VCERR(vect)for(size_t iiivcerr=0; iiivcerr<vect.size(); iiivcerr++) {errlog(vect[iiivcerr]); errlog(" ");} errlog("\n");
#define VIN(t,vect, len) t vect(N); for(size_t iiivcerr=0; iiivcerr<len; iiivcerr++) cin >> vect[iiivcerr];
#define FORN(i, n) for(int i=0; i<n; i++)
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<double> Vd;
typedef pair<int,int> Pi;
typedef vector<pair<int,int> > Vii;
typedef map<int,Vi> MVi;
typedef vector<string> Vstr;
typedef stack<int> Si;

template<typename T, bool a=true>
void errlog(const T& v)
{
    if(a)
    {
        cerr << v;
    }
}

int adj(Vii v)
{
    int r=0;
    FORN(i,v.size())
    {
        for(int j=i+1; j < v.size(); j++)
        {
            if(v[i].first == v[j].first)
            {
                if(abs(v[i].second - v[j].second) == 1)
                {
                    r++;
                }
            }
            if(v[i].second == v[j].second)
            {
                if(abs(v[i].first - v[j].first) == 1)
                {
                    r++;
                }
            }
        }
    }
    return r;
}

int rec(int N, int R, int C, Vii v, int iv = -1, int jv = -1)
{
    if(iv!= -1 and jv != -1)
    {
        v.push_back(make_pair(iv,jv));
    }
    if(N == v.size())
        return adj(v);
    // if remaining cases < N - V.size()

    int i=0, j=0;
    if(not v.empty())
    {

        Pi l = v.back();
        i = l.first;
        j =l.second+1;
        if(j==C)
        {
            i++;
            j=0;
        }
    }

    int m=100000;
    for(;i<R and j<C and (R*C - i*C - j >= N -v.size());)
    {
        m=min(m,rec(N,R,C,v,i,j));
        j++;
        if(j==C)
        {
            i++;
            j=0;
        }
    }
    return m;
}

void solve()
{

    int N,R,C;

    cin >> R >> C >> N;

    Vii v;
    cout << rec(N,R,C,v) << endl;
}

int main()
{
    int T;
    cin >> T;
    cerr << T << endl;
    string re;

    for(int tt=1; tt <= T; tt++)
    {
        if(tt*1000/T%10 ==0)
            cerr << tt << ", " << tt*100/T<< "%" << endl;
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}
