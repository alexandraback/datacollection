#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

#define VCERR(vect)for(size_t iiivcerr=0; iiivcerr<vect.size(); iiivcerr++) {errlog(vect[iiivcerr]); errlog(" ");} errlog("\n");
#define VIN(t,vect, len) t vect(N); for(size_t iiivcerr=0; iiivcerr<len; iiivcerr++) cin >> vect[iiivcerr];

typedef vector<string> Vs;
typedef vector<int> Vi;
typedef map<int,Vi> MVi;
typedef vector<string> vstr;

template<typename T, bool a=true>
void errlog(T& v)
{
    if(a)
    {
        cerr << v;
    }
}

int f(Vi& v)
{
    int c=0;
    for(int i=0; i < v.size(); i++ )
    {
        if(v[i]<i)
            c++;
    }
    return c;
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

        int N;
        cin >> N;

        VIN(Vi,v, N);
        VCERR(v);
        int c=0, c2=0, m=0;
        for(int i=0; i < v.size()-1; i++ )
        {
            if(v[i] > v[i+1])
            {
                c+=v[i]-v[i+1];
                m=max(m,v[i]-v[i+1]);
            }
        }
        for(int i=0; i < v.size()-1; i++ )
        {
            c2+=min(v[i],m);
        }

        cout << c << " " << c2 << endl;
    }

    return 0;
}
