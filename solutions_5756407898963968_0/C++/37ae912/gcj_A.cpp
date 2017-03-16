//General Template 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

#include <iostream>
#include <fstream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
#include <bitset> // bitset<N>, set, reset, flip, to_ulong
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORI(it,v) for(typeof(v.begin()) it=v.begin(); it!=v.end(); ++it)
#define MP(x,y) make_pair( (x), (y))
#define PB(x) push_back( x )

template<class T>void checkMin(T& r, T v){if(r>v)r=v;}
template<class T>void checkMax(T& r, T v){if(r<v)r=v;}

typedef long long LL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef pair<int,int> PII;

VI read()
{
    VI res;
    int r;
    cin>>r;
    FOR(i,4){
        FOR(j,4){
            int a;    
            cin>>a;
            if(r==i+1) res.PB(a);
        }
    }
    
    return res;
}

int main()
{
    int T;
    int cs=0;
    cin>>T;
    while(++cs<=T){
        printf("Case #%d: ",cs);
        
        VI va = read();
        VI vb = read();
        
        set<int> sa;
        FORI(it,va){
            FORI(it2,vb)if(*it==*it2) sa.insert(*it);    
        }
        
        if(sa.size()==1) printf("%d\n", *sa.begin());
        else if(sa.size()==0) puts("Volunteer cheated!");
        else puts("Bad magician!");
    }
    return 0;
}
