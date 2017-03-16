#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define esta(mask, bit) ((mask & (1<<bit)) != 0)

string str[128];

int main () {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T, result = 0;
	int n;
	cin >> T;
	
	for( int tc = 1; tc <= T; tc++ ) {
		cin >> n;
		forn(i,n)
			cin >> str[i];
		
		// representante de los strings
		vector <vector<char> > repr(n,vector<char>() );
		vector <vector<int> > cant(n,vector<int>() );
		for( int j = 0; j < n; j++ ) {
			char charActual = str[j][0];
			int count = 0;
			for( int i = 0; i < (int) str[j].size(); i++ ) {
				if( charActual != str[j][i] ) {
					repr[j].push_back(charActual);
					//cerr << charActual << " " << count << endl;
					cant[j].push_back(count);
					count = 0;
					charActual = str[j][i];
				}
				count++;
			}
			repr[j].push_back(charActual);
			cant[j].push_back(count);
			//cerr << charActual << " " << count << endl;
			//cerr << endl;
		}
		
		// mismos representantes
		bool feglaWon = false;
		for( int i = 0; i < n-1; i++ ) {
			if( repr[i].size() != repr[i+1].size() ) {
				feglaWon = true;
				break;
			}
			for( int j = 0; j < (int) repr[i].size(); j++ ) {
				if( repr[i][j] != repr[i+1][j] ) 
					feglaWon = true;
			}
		}
		
		if( feglaWon ) {
			cout << "Case #" << tc << ": Fegla Won" << endl;
			continue;
		}
		
		// diferencia de cantidades
		result = 0;
		forn(i,repr[0].size()) {
			// digito i
			int costo[128];
			int minCostoActual = 10000000;
			forn(p,128) {
				// costo de poner p de esa letra
				costo[p] = 0;
				forn(j,repr.size()) {
					costo[p] += abs(p-cant[j][i]);
				}
				if( costo[p] < minCostoActual )
					minCostoActual = costo[p];
			}
			result+=minCostoActual;
		}
		
		cout << "Case #" << tc << ": " << result << endl;
	}
}
