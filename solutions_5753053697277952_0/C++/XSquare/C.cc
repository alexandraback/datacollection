#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector <ll> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ld> VD;
typedef vector <VD> VVD;
typedef vector <string> VS;
typedef vector <char> VC;
typedef vector <VC> VVC;
typedef pair <ll, ll> PII;
typedef pair <ll, PII> PIII;
typedef pair <ld, ld> PD;
typedef map <ll, ll> MII;
typedef map <string, int> MSI;
typedef queue <int> QI;
typedef queue <PII> QPI;
typedef set <ll> SI;
typedef SI::iterator IT;

#define F first
#define S second
#define pb push_back

int main(){
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t){
		cout << "Case #" << t << ":";
		int n;
		cin >> n;
		VI v(n);
		int sum = 0;
		for (int i = 0; i < n; ++i){
			cin >> v[i];
			sum += v[i];
		}
		while (sum > 0){
			int maxi = 0;
			int kmax = 0, kmax2 = -1;
			for (int k = 0; k < n; ++k){
				if (v[k] >= maxi){
					maxi = v[k];
					kmax = k;
				}
			}
			for (int k = 0; k < n; ++k){
				if (k != kmax){
					if (v[k] == maxi && 2*v[k] == sum) kmax2 = k;
				}
			}
			if (kmax2 < 0){
				cout << " " <<  char('A' + kmax);
				--sum;
				--v[kmax];
			}
			else{
				cout << " " << char('A' + kmax)  <<  char('A' + kmax2);
				sum -= 2;
				--v[kmax];
				--v[kmax2];
			}
		}
		cout << endl;
	}
}
