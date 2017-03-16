#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<complex>
#include<set>
#include<map>
#include<sstream>
#include<string>
#include<deque>
#include<sys/time.h>
#include<fstream>
#include<bitset>
#include<cstring>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define dforn(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(v) v.begin(),v.end()

timeval start,fin;

/*
 Functions used to measure times
*/
void init_time()
{
	gettimeofday(&start,NULL);
}

double get_time()
{
	gettimeofday(&fin,NULL);
	return (1000000*(fin.tv_sec-start.tv_sec)+(fin.tv_usec-start.tv_usec))/1000000.0;
}

typedef long long int tint;
typedef pair<tint,tint> ptt;

tint p(ptt x, ptt y, ptt z)
{
    return (x.first-y.first)*(z.second-y.second) - \
           (x.second-y.second)*(z.first-y.first);
}

int main() {
    int T;
    cin>>T;
    forn(t,T) {
        int n;
        cin>>n;
        vector<ptt> v(n);
        forn(i,n)cin>>v[i].first>>v[i].second;
        cout<<"Case #"<<t+1<<":"<<endl;
        forn(i,n) {
            int m = 5000;
            forn(j,n) if(i!=j) {
                int c = 0;
                int d = 0;
                forn(k,n) {
                    if(p(v[i],v[j],v[k])>0) c++;
                    if(p(v[j],v[i],v[k])>0) d++;
                }
                m = min(m, c);
                m = min(m, d);
            }
            if(n==1)m=0;
            cout<<m<<endl;
        }
    }
}
