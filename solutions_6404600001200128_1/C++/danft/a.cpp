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
#define N 1123

int n, vec[N];

int main(){
        int t, ca = 1;
        cin >> t;
        while( t-- )
        {
                cin >> n;
                for( int i= 0; i<n;i ++ )
                        cin >> vec[i];
                int ans[2] = {0,0};
                int ra = 0;
                for( int i = 1; i<n; i++ )
                        ra = max(ra,vec[i-1]-vec[i]);


                for( int i = 1; i<n; i++ )
                {
                        ans[0] += max(vec[i-1] - vec[i],0);
                }
                for( int i = 0; i<n-1; i++ )
                {
                        ans[1] += min( vec[i], ra );
                }
                cout << "Case #" << ca++ << ": ";
                cout << ans[0] << " " << ans[1] << "\n";
        }

        return 0;
}
