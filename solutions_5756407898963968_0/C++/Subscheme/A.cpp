#include <iostream>
#include <algorithm>
using namespace std;
#define fo(i,n) for(int i=0,_n=(n); i<_n; ++i)

const int N = 17;
bool v1[N], v2[N];
int T;

void getValid(bool v[N]) {
	int row;
	fo(i,N) v[i] = false;
	cin >> row;
	fo(i,4) {
		int a;
		fo(j,4) {
			cin >> a;
			if(i+1 == row) v[a] = true;
		}
	}
}

int main() {
	cin >> T;
	fo(t,T) {
		getValid(v1);
		getValid(v2);
		int a = 0, b;
		fo(i,N) if(v1[i] && v2[i]) ++a, b = i;
		cout << "Case #" << t + 1 << ": ";
		if(a == 0) cout << "Volunteer cheated!\n";
		else if(a == 1) cout << b << '\n';
		else cout << "Bad magician!\n";
	}
}