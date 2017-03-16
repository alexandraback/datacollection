#include <iostream>
using namespace std;

typedef long long LL;
const LL inf = 1e18;
LL arr[1010];

int main() {
    int t , b , n;
    LL L , R , temp , res , M;
    freopen("B-large.in","r",stdin);
    freopen("b.out","w",stdout);
    cin >> t;
    for ( int k = 1 ; k <= t ; ++k ) {
        cin >> b >> n;
        for ( int i = 0; i < b; ++i ) {
            cin >> arr[i];
        }
        L = 0;
        R = inf;
        while ( L<R ) {
            M = L + ( R - L ) / 2;
            temp = 0;
            for ( int i = 0; i < b; ++i ) {
                temp += M / arr[i] + 1;
            }
            if ( temp<n ) {
                L = M + 1;
            }
            else {
                R = M;
            }
        }
        res = 0;
        for ( int i = 0; i < b; ++i ) {
            res += L / arr[i] + 1;
        }
        temp = res - n + 1;
        for ( int i = b - 1; i >= 0; --i ) {
            if ( L % arr[i] == 0 ) {
                -- temp;
                if ( !temp ) {
                    res = i + 1;
                    break;
                }
            }
        }   
        cout << "Case #" << k << ": " << res << endl;
    }
    return 0;
}

