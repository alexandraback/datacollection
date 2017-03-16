#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <iomanip>
#include <vector>

#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define clr(a, v) memset( a , v , sizeof(a) )
#define pb push_back
#define mp make_pair
#define sz size()
#define FORN( i , s , n ) for( int64 i = (s) ; i < (n) ; i++ )
#define FOR( i , n ) FORN( i , 0 , n )
#define FORIT( i , x ) for( typeof x.begin() i = x.begin() ; i != x.end() ; i++ )
#define trace(x)    cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define read ios::sync_with_stdio(false)

using namespace std;

typedef long long int64;
typedef vector <int64> vi;
typedef pair <int64,int64> ii;
typedef vector <string> vs;
typedef vector <ii> vii;


int main(){
    freopen("A.in","r",stdin );
    freopen("out.txt","w",stdout);
    read;
    int T;
    cin>>T;
    int cas=1;
    while(T--){
        int64 B,N;
        cin>>B>>N;
        vi V(B);
        FOR(i,B) cin>>V[i];
        int64 lo = 0, hi = 1000000000000000,mi,curr;
        vi ava;
        while(hi-lo>1){
            mi = (hi+lo)/2;
            curr=0;
            ava.clear();
            FOR(i,B){
                mi/V[i];
                if ( mi%V[i]==0 ) {
                    ava.pb(i);
                    curr+=mi/V[i];
                }
                else{
                    curr+=mi/V[i]+1;
                }
            }
            //trace2(curr,N);
            if ( curr>=N ) hi = mi;
            else lo = mi;
        }

        mi = lo;
        curr=0;
        ava.clear();
        FOR(i,B){
            mi/V[i];
            if ( mi%V[i]==0 ) {
                ava.pb(i);
                curr+=mi/V[i];
            }
            else{
                curr+=mi/V[i]+1;
            }
        }
        cout<<"Case #"<<cas++<<": "<<ava[ N-curr-1 ]+1<<endl;
    }
}
