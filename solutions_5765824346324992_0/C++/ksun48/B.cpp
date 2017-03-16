#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

main() {
	FILE *fin = freopen("B-small-attempt0.in", "r", stdin);
	FILE *fout = freopen("B-small-attempt0.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		LL b, n;
		cin >> b >> n;
		LL m[b];
		for(int i = 0; i < b; i++){
			cin >> m[i];
		}
		LL s = -1;
		LL e = 10000000000000000;
		while(s+1 < e){
			LL mid = (s+e)/2;
			LL num = 0;
			for(int i = 0; i < b; i++){
				num += (mid/m[i]);
				num++;
			}
			if(num < n){
				s = mid;
			} else{
				e = mid;
			}
		}
		LL k = 0;
		for(int i = 0; i < b; i++){
				k += (s/m[i]);
				k++;
		}
		LL c = n-k;
		for(LL i = 0; i < b; i++){
			if(e % m[i] == 0){
				c--;
			}
			if(c == 0){
				cout << i + 1 << endl;
				break;
			}

		}


	}
	exit(0);
}