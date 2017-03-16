#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 
#include <stack> 
#include <iomanip> 
#include <queue> 

#define pb push_back 
#define mp make_pair 
#define ll long long 
#define abracadabra next 
#define pii pair<int, int> 

using namespace std; 

int p[33];

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++) {
		cout << "Case #" << test << ": ";
		int n;
		cin >> n;
		int sum = 0;
		for(int i =0; i < n; i++) {
			cin >> p[i];
			sum += p[i];
		}
		if (n == 2) {
			for(int i = 0; i < p[0]; i++)
				cout << "AB ";
			cout << endl;
		} else {
		while (sum > 2) {
			int mx = 0;
			int mxi;
			for(int i = 0; i < n; i++) {
				if (p[i] > mx) {
					mx = p[i];
					mxi = i;
				}
			}
			cout << (char)('A' + mxi) << " ";
			sum--;
			p[mxi]--;
		}
		for(int i = 0; i < n; i++) {
				if (p[i] > 0) {
					cout << (char)('A'+i);
				}
			}
		cout << endl;
		}
	}
	
	
	return 0; 
} 
