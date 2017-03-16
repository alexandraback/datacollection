#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define mk make_pair
#define pb push_back
#define fst first
#define snd second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

struct Point{
        ll x,y;
        Point(){x=0,y=0;}
        Point(int xx, int yy) :x(xx),y(yy){}
        Point operator-( const Point &p ) const {
                return Point(x-p.x,y-p.y);
        }
        ll operator^( const Point &p ) const {
                return (1LL*x*p.y) - (1LL*y*p.x);
        }
        ll operator*(const Point &p ) const {
                return (1LL*x*p.x + 1LL*y*p.y);
        }
};

bool chk( vector<Point> X, int pind ) {
        int n = X.size();
        if( n < 3 ) return false;
        int p = 0;
        vector<bool>used(n,false);
        for( int i = 0;i <n; i++ )
                if( X[i].x < X[p].x)
                        p = i;
                else if( X[i].x == X[p].x && X[i].y > X[p].y)
                        p = i;

        int st = p;
        //used[p] = true;
        do{ 
        //        cout << p << endl;
                int m = -1;
                ll dist = 100000000000000LL;
                for( int i= 0; i < n; i++ )
                {
                        if( i == p ) continue;
                        if( used[i] ) continue;
                        if( m == -1 ) m = i;
                        ll cross = (X[i]-X[p])^(X[m]-X[p]);
                        ll d = (X[i]-X[p])*(X[i]-X[p]);
                        if( cross < 0LL )
                        {
                                m =i;
                                dist = d;
                        }
                        else if( cross == 0LL )
                        {
                                if( d < dist )
                                {
                                        dist = d;
                                        m = i;
                                }
                        }
                }
                p = m;
                used[p] = true;
                if( p == pind ) return true;
        }while(st!=p);
        return false;
}


int main(){
        int t,ca=1;
        cin >> t;
        while( t-- )
        {
                int n;
                cin >> n;
                vector<Point> vec;
                for ( int i = 0; i<n; i++ )
                {
                        Point tmp;
                        cin >> tmp.x >> tmp.y;
                        vec.pb(tmp);
                }
                cout << "Case #" << ca++ << ":\n";

                for( int i = 0; i<n; i++ )
                {
                        int ans = n-3;
                        if( n < 3 )
                                ans = 0;
                        else
                        for( int used = 0; used < (1<<n); used++)
                        {
                                //cout << used << endl;
                                if( !(used&(1<<i)) ) continue;
                                if( __builtin_popcount(used) < 3 ) continue;
                                vector<Point> aux;
                                aux.pb( vec[i] );
                                for( int j = 0; j<n; j++ ) 
                                        if( (used & (1<<j))!=0 && j != i )
                                        {
                                                aux.pb(vec[j]);
                                        }

                                if( chk(aux, 0))
                                        ans = min( ans, n - __builtin_popcount(used) );
                        }
                        cout << ans << "\n";
                }
        }

        return 0;
}
