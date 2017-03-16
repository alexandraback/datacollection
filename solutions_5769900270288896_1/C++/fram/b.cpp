#include <iostream>
using namespace std;



void solve(){
	int r, c, n;
	cin >> r >> c >> n;
	if(r < c){int t=r; r=c; c=t;}
	if(n <= r*c/2 + r*c%2) {cout << 0 << endl; return;}
	
	if(r*c == 1) {cout << 0 << endl; return;}
	
	n = r*c - n;
	int ans = 2*r*c - (r+c);
	
	if(c == 1){
		if(n <= (r-2)/2 + r%2){cout << ans - 2*n << endl; return;}
		if(n <= r/2){cout << ans-1-2*(n-1) << endl; return;}
		cout << ans-2*(n-1) << endl; return;
	}
	
//~ cerr << r << ' ' << c << ' ' << n << ' ' << ans << endl;
	int a4, a3, a2;
	a4 = (r-2)*(c-2)/2 + (r-2)*(c-2)%2;
	if(c%2==0 || r%2==0) a3 = r-2 + c-2;
	else a3 = r-3+c-3;
	if(c%2 == 0 || r%2 == 0) a2 = 2;
	else a2 = 4;
	
	int b4, b3, b2;
	b4 = (r-2)*(c-2) - a4;
	b3 = 2*(r-2+c-2) - a3;
	b2 = 4 - a2;
//~ cerr << n << endl;
//~ cerr << r << ' ' << c << endl;
//~ cerr << a4 << ' ' << a3 << ' ' << a2 << endl;
//~ cerr << b4 << ' ' << b3 << ' ' << b2 << endl;

	int a = 0;
	if(n <= a4) a = 4*n;
	else if(n <= a4 + a3) a = 4*a4 + 3*(n-a4);
	else if(n <= a4 + a3 + a2) a = 4*a4 + 3*a3 + 2*(n-a4-a3);
//~ cerr << ans << endl;
//~ cerr << a << endl;
	int b = 0;
	if(n <= b4) b = 4*n;
	else if(n <= b4 + b3) b = 4*b4 + 3*(n-b4);
	else if(n <= b4 + b3 + b2) b = 4*b4 + 3*b3 + 2*(n-b4-b3);
//~ cerr << b << endl;
	if(a < b) a = b;
//~ cerr << endl;

	cout << ans - a << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	for(int i=1; i<=t; i++){
		cout << "Case #" << i << ": ";
		cout.flush();
		solve();
	}
	
	return 0;
}
