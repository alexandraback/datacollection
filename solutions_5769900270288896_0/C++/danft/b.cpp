#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;

int r,c, used,n;
int d[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};

int ch(int x ) {
        int cnt = 0;
        for( int i = 0;i < r; i++ )
                for( int j = 0; j< c; j++ )
                {
                        if( !(x&(1<<(i*c+j))) ) continue;
                        for( int k = 0; k<4; k++ )
                        {
                                int vi = i + d[k][0];
                                int vj = j + d[k][1];
                                if( vi >= 0 && vi < r && vj >= 0 && vj < c )
                                {
                                        //
                                        //jcnt += ((x&(1<<(vi*c+vj)))!=0);
                                        if (x&(1<<(vi*c+vj)))
                                        {
                                                //cout << "A\n";
                                                        cnt++;
                                        }
                                }
                        }
                }
        return cnt/2;
}
void print(int used ) {
        for( int i = 0; i<r; i++ )
        {
                for( int j = 0;j < c; j++ )
                {
                        if( used & (1<<(i*c+j)) )
                                cout << '1';
                        else cout << '0';
                }
                cout << '\n';
        }
}

int main(){

        int t,ca=1;
        cin >> t;
        while(t--)
        {
                cin >> r >> c >> n;

                int ans = INF;
                for( int i = 0;i < (1<<(r*c)); i++ )
                {
                        if( __builtin_popcount(i) == n )
                        {
                                //print(i);
                                ans = min(ans,ch(i));
                        }
                }
                cout << "Case #" << ca++ << ": ";
                cout << ans << "\n";
        }
        return 0;
}
