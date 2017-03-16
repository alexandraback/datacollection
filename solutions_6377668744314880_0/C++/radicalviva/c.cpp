#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
struct data {
	LL x , y;
};
data node[3010];
LL res[3010];

int main() {
	int t , n;
	LL xx , yy , zz , a , b , c , temp;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("c.out","w",stdout);
	cin >> t;
	for ( int k = 1; k<=t; ++k ) {
		cin >> n;
		for ( int i = 0 ; i<n ; ++i ) {
			cin >> node[i].x >> node[i].y;
			res[i] = ( n == 1 ? 0 : n );
		}
		cout << "Case #" << k << ":" << endl;
		for ( int i = 0 ; i<n ; ++i ) {
			for ( int j = i + 1 ; j<n ; ++j ) {
				xx = node[j].y - node[i].y;
				yy = node[i].x - node[j].x;
				zz = node[j].x * node[i].y - node[i].x * node[j].y;
				a = b = 0;
				for ( int q = 0; q<n; ++q ) {
					c = xx * node[q].x + yy * node[q].y + zz;
					if ( c > 0) {
						a++;
					}
					else if (c < 0) {
						b++;
					}
				}
				temp = min(a, b);
				res[i] = min( res[i] , temp );
				res[j] = min( res[j], temp );
			}
			cout << res[i] << endl;
		}
	}
	return 0;
}

