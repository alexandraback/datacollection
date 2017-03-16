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
#define N 1000
int n, vec[N],m;

ll fx( ll tx ) {
        if( tx == 0 ) return 0;
        ll ret = 0;
        for( int i = 0; i < n; i++ )
                ret += tx/vec[i] + 1;
        return ret;
}

int main(){
        int t,ca =1;
        cin >> t;
        while( t-- )
        {
                cin >> n >> m;
                for( int i = 0; i<n; i++ )
                        cin >> vec[i];

                ll lo = 0, hi = 1000000000000000LL;

                while( lo != hi )
                {
                        ll mi = (lo+hi)/2;
                        if( m - 1<= fx( mi ) )
                                hi = mi;
                        else lo = mi+1;
                }
                int ans =0;
                if( fx(lo) > m-1 ) lo--;

                //cout <<"!"<< lo << endl;
                //cout <<"!"<< fx(lo) << endl;

                int xx = m - fx(lo);
                vector< ii >nb;
                for( int i = 0; i<n; i++ )
                {
                        if( lo >= vec[i] )
                        nb.pb( mk( vec[i] - lo%vec[i], i ));
                        else 
                                nb.pb(mk(0,i));
                        //cout << nb[i].fst << endl;
                }
                //cout << xx << "@\n";
                sort( nb.begin(), nb.end() );
                ans = nb[xx-1].snd;
                cout << "Case #" << ca++ << ": ";
                cout << 1+ans << "\n";



        }

        return 0;
}
