#include<bits/stdc++.h>
using namespace std;
// written by: MANIKA AGARWAL
// TEMPLATE USED: FROM CODEFORCES
typedef long long ll ;

#define endl '\n'
#define  MP make_pair
#define PB push_back
#define F first
#define S second
#define fileio freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);


int main(){
	fileio;
	int i, j, t, n;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		cin >> n;
		set< pair<int, char> > x;
		set< pair<int, char> > :: iterator it1, it2 ;
		for(i = 0; i < n; i++) {
			cin >> j;
			x.insert(MP(-j, 'A' + i));
		}
		while(x.empty() == false) {
			if(x.size() == 2) {
				it2 = it1 = x.begin();
				it2++;
				if(it1->F != it2->F) {
					cout << it1->S << " ";
					if(it1->F != -1)
						x.insert(MP(it1->F + 1, it1->S));
					x.erase(it1);
				}
				else {
					cout << it2->S << it1->S << " ";
					if(it2->F != -1)
						x.insert(MP(it2->F + 1, it2->S));
					x.erase(it2);
					if(it1->F != -1)
						x.insert(MP(it1->F + 1, it1->S));
					x.erase(it1);
				}
			}
			else {
					it2 = it1 = x.begin();
					it2++;
					cout << it1->S << " ";
					if(it1->F != -1)
						x.insert(MP(it1->F + 1, it1->S));
					x.erase(it1);
			}
		}
		cout << endl;
	}

	return 0 ;
}

