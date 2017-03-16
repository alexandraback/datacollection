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

int main() {
    int T;
    cin>>T;
    forn(t,T) {
        int n, b;
        cin>>b>>n;
        vector<int>v(b);
        forn(i,b)cin>>v[i];
        tint x = 0, y, z = 100001LL * n;
        while(z>x+1) {
            y = (x+z)/2;
            tint c = 0;
            forn(i,b) c += (y/v[i])+1;
            if(c<n)x=y; else z=y;
        }
        int ans = -1;
        tint c = 0;
        forn(i,b) c += (x/v[i])+1;
        //cerr<<z<<" "<<c<<endl;
        forn(i,b) if(z%v[i] == 0) {
            c++;
            if(c==n) {
                ans = i + 1;
                break;
            }
        }
        if(n==b)ans=n;
        cout<<"Case #"<<t+1<<": "<<ans<<endl;
    }
}
