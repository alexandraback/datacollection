#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cfloat>
#include <climits>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

const double PI = 2.0 * acos(0.0);

string int_to_str(int v) {
	ostringstream os;
	os << v;
	return os.str();
}

int str_to_int(string s) {
	istringstream is(s);
	int v;
	is >> v;
	return v;

}

int main() {
	int cas, row, row2;
	cin >> cas;
	int cards[2][4][4];
	vi select;
	FOR(cur, 1, cas+1){
		select.clear();
		cin >> row;
		FOR(i, 0, 4) FOR(j, 0, 4) cin >> cards[0][i][j];
		cin>>row2;
		FOR(i, 0, 4) FOR(j, 0, 4) cin >> cards[1][i][j];
		FOR(i, 0, 4) FOR(j, 0, 4){
			if(cards[0][row-1][i]==cards[1][row2-1][j]) select.push_back(cards[0][row-1][i]);
		}
		cout << "Case #" << cur << ": ";
		if(select.size()>1){
			cout << "Bad magician!" << endl;
		}else if(!select.size()){
			cout << "Volunteer cheated!" << endl;
		}else cout << select[0] << endl;
	}
}