#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
LL arr[1010];

int main( ) {
    int t , n;
    LL ans1 , ans2 , temp2;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a.out","w",stdout);
    cin >> t;
    for ( int k = 1 ; k<=t ; ++k ) {
        cin >> n;
        for ( int i = 1 ; i<=n ; ++i ) {
            cin >> arr[i];
        }
        ans1 = temp2 = ans2 = 0;
        for ( int i = 2 ; i<=n ; ++i ) {
            ans1 += max( arr[i-1]-arr[i] , 0LL );
            temp2 = max( temp2 , arr[i-1]-arr[i] );
        }
        for ( int i = 2 ; i<=n ; ++i ) {
            if ( !arr[i] ) {
                ans2 += arr[i-1];
            }
            else {
                ans2 += min(temp2,arr[i-1]);
            }
        }
        cout << "Case #" << k << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}

