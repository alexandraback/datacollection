#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define INF 0x3f3f3f3f
#define MEMSET_INF 127
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		int r,c,n;
		cin >> r >> c >> n;

		int a;
		int b;
		int nc;
		int ns;
		int nsr;
		int nsc;

		if(r%2 and c%2){
			a = (c*(r/2)) + c/2 + 1;
			b = a-1;
			nsr = max(0,(r-2)/2);
			nsc = max(0,(c-2)/2);
			ns = 2*nsc + 2*nsr;
			nc = 4;
		}else if(r%2 and !(c%2)){
			a = (c*r)/2;
			b = a;
			nc = 2;
			nsc = max(0,(c-2)/2);
			ns = 2*nsc + max(0, r - 2);
		}else if(!(r%2) and c%2){
			a = (c*r)/2;
			b = a;
			nc = 2;
			nsr = max(0,(r-2)/2);
			ns = 2*nsr + max(0, c - 2);
		}else{
			a = (c*r)/2;
			b = a;
			nc = 2;
			ns = 2*max(r/2 - 1, 0) + 2*max(c/2 - 1, 0);
		}

		cout << "Case #" << t << ": ";
		int ans = 0;
		if(r == 1 and c == 1){
			cout << 0 << endl;
		}else if(r == 1 or c == 1){
			int dim = max(r, c);
			if(n <= (dim +1)/2)
				cout << 0 << endl;
			else if (n==dim){
				cout << dim-1 << endl;
			}else if(dim%2){
				cout << (dim -1) - (dim - n) * 2 << endl;
			}else{
				if(n == (dim + 1)/2 + 1){
					cout << 1 << endl;
				}else{
					cout << 1 + (n - (dim/2 + 1)) * 2 << endl;
				}
			}
		}else if(n <= a){
			cout << 0 << endl;
		}else if(a!= b and n == a + 1){
			cout << 3 << endl;
		}else if(n <= b+nc){
			ans = (n-b)*2;
			cout << ans << endl;
		}else if(n <= b+nc+ns){
			ans = nc*2 + (n-b-nc)*3;
			cout << ans << endl;
		}else{
			ans = nc*2 + ns*3 + (n-b-ns-nc)*4;
			cout << ans << endl;
		}

		//cout << "b " << b << "a " << a << "nc " << nc <<"ns " << ns << endl;


		

	}
    return 0;
}