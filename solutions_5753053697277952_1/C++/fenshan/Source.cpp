#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bitset>
using namespace std;

#define For(i, a, b) for (int i = a; i < b; ++i)
#define FOR(i, v) for (int i = 0; i < v.size(); ++i)
#define sol(i) cout << "Case #" << i+1 << ":";

typedef long long int lli;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<bool> vb;

vector <ii> ar(26);

bool vacio(){
	For(j, 0, 26){
		if (ar[j].second != 0)return false;
	}
	return true;
}

bool ord(ii a, ii b){
	return a.second > b.second;
}

int main(){
	int n, a, x;
	cin >> n;
	For(i, 0, n){
		cin >> a;
		For(j, 0, a)cin >> ar[j].second;
		For(j, a, 26)ar[j].second = 0;
		FOR(j, ar) ar[j].first = j;
		sol(i);
		while (!vacio()){
			cout << " ";
			sort(ar.begin(), ar.end(), ord);
			cout << char('A' + ar[0].first);
			if (ar[0].second == ar[1].second && !(ar[0].second == 1 && ar[2].second == 1 && ar[3].second == 0)){
				cout << char('A' + ar[1].first);
				--ar[1].second;
			}
			--ar[0].second;
		}
		cout << "\n";		
	}
	return 0;
}