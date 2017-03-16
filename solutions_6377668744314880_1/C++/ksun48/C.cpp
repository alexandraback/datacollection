#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define PI 3.14159265358979323
#define EPS 0.000000001
main() {
	FILE *fin = freopen("C-large.in", "r", stdin);
	FILE *fout = freopen("C-large.out", "w", stdout);
	assert( fin!=NULL );
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		cout << endl;
		int n;
		cin >> n;
		if(n == 1){
			cin >> n >> n;
			cout << 0 << endl;
			continue;
		}
		LL x[n];
		LL y[n];
		for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
		for(int i = 0; i < n; i++){
			int r = n-1;
			double stuff[3*r];
			for(int j = 0; j < n; j++){
				if(i == j) continue;
				stuff[j-(j>=i)] = atan2((double)(y[j]-y[i]),(double)(x[j]-x[i]));
			}
			sort(stuff, stuff+r);
			/*for(int j = 0; j < r; j++){
				cout << stuff[j] << " ";
			}
			cout << endl;*/
			for(int j = 0; j < r; j++){
				stuff[j+r] = stuff[j]+2.0*PI;
				stuff[j+2*r] = stuff[j+r]+2.0*PI;
			}
			int a = 0;
			int b = 0;
			while(stuff[b] <= stuff[a] + PI + EPS){
				b++;
			}
			int mans = 0;
			while(1){
				a++;
				while((b < 3*r) && (stuff[b] <= stuff[a] + PI + EPS)){
					b++;
				}
				mans = max(mans, b-a);
				if(b == 3*r){
					break;
				}
			}
			cout << r-mans << endl;
		}
	}
	exit(0);
}