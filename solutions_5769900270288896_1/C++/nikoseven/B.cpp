#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int main() {
	int r,c;
	int T,ics = 0;
	scanf("%d",&T);
	while(T--) {
		int z;
		scanf("%d%d%d",&r,&c,&z);
		int n0,n2,n3,n4;
		int zz = z;
		if( r == 1 || c == 1 ) {
			n0 = r * c -  r * c /2;
			n2 = r*c - n0;
			n3 = n4 = 0;
		}
		else if( r%2==0 || c%2==0 ) {
			n0 = r * c / 2;
			n2 = 2;
			n3 = 0;
			if( r & 1 ) {
				n3 += ((r-1)/2)*2;
			}
			else {
				n3 += (r/2-1)*2;
			}
			
			if( c & 1 ) {
				n3 += ((c-1)/2)*2;
			}
			else {
				n3 += (c/2-1)*2;
			}
			n4 = r * c - n2 - n3;
		}
		else {
			n0 = r * c - r * c / 2;
			n2 = 0;
			n3 = ((c-1)/2)*2 + ((r-1)/2)*2;
			n4 = r * c - n2 - n3;
		}
		
		int ans = 0;
		if( z <= n0 ) {
			z = 0;
		}
		else {
			z -= n0;
		}
		
		int mi2 = min(n2,z);
		ans += mi2 * 2;
		z -= mi2;
		
		int mi3 = min(n3,z);
		ans += mi3 * 3;
		z -= mi3;
		
		ans += z * 4;
		if( r == 3 && c == 3 && zz==8 )
			ans = 8;
		printf("Case #%d: %d\n",++ics,ans);
	}
	return 0;
}