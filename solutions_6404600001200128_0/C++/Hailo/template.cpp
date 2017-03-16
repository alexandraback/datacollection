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
typedef vector <int> vi;
typedef pair <int64,int64> ii;
typedef vector <string> vs;
typedef vector <ii> vii;

int cnt[32];
int esp[32];
map<int,int> mapa;

int main(){
    freopen("A.in","r",stdin );
    freopen("out.txt","w",stdout);
    read;
    int T;
    cin>>T;
    int cas=1;
    while(T--){
        int N;
        cin>>N;
        vi V(N);
        //trace(N);
        int f=0,s=0,act,nxt;
        cin>>act;
        V[0] = act;
        int rate = 0;
        FOR(i,N-1) {
            cin>>nxt;
            V[i+1] = nxt;
            //trace2(nxt,act);
            if (nxt<act) f+=(act-nxt);
            rate = ( nxt<act ) ? max(rate,act-nxt):rate;
            act=nxt;
        }
        FOR(i,N-1){
            s+=min(V[i],rate);
        }
        cout<<"Case #"<<cas++<<": "<<f<<" "<<s<<endl;
    }
}
