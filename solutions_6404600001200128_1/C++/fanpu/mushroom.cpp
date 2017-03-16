#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
typedef pair<ll,ll> ii;

int main(){
	
	ios_base::sync_with_stdio(0);
	ifstream cin;
	cin.open("alarge.in");
	ofstream cout;
	cout.open("alarge.o");
	
	int tc; cin >> tc;
	for(int a = 1; a <= tc; a++){
		int n; cin >> n;
		ll mushroom[n];
		for(int i = 0; i < n; i++){
			cin >> mushroom[i];
		}
		ll firstMethod = 0;
		ll maxMush = 0;
		for(int i = 1; i < n; i++){
			if(mushroom[i-1] > mushroom[i]){
				firstMethod += mushroom[i-1] - mushroom[i];
				maxMush = max(maxMush, mushroom[i-1] - mushroom[i]);
			}
		}
		ll secondMethod = 0;
		for(int i = 0; i < n - 1; i++){
			if(mushroom[i] < maxMush) secondMethod += mushroom[i];
			else secondMethod += maxMush;
		}
		cout << "Case #" << a << ": " << firstMethod << " " << secondMethod << "\n";
	}
}

