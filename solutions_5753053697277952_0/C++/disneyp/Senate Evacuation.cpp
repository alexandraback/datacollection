#include <iostream>
#include <string>
using namespace std;
int a[100],n;

void g() {
	int m1,m2,a1,a2;
	m1 = -1; m2 = -1;
	a1 = -1; a2 = -1;
	for(int i=0;i<n;i++) {
		if(m2 < a[i]) {
			m1 = m2;
			a1 = a2;
			m2 = a[i];
			a2 = i;
		}
		else if(m1 < a[i]) {
			m1 = a[i];
			a1 = i;
		}
	}
	if(m2 > 1) {
		cout << " " << (char)('A' + a1) << (char)('A' + a2);
		a[a1] --;
		a[a2] --;
	}
	else if(m2 == 1) {
		int cnt = 0;
		for(int i=0;i<n;i++) if(a[i] == 1) cnt++;
		if(cnt & 1) {
			cout << " " << (char)('A' + a1);
			a[a1] --;
		}
		else {
			cout << " " << (char)('A' + a1) << (char)('A' + a2);
			a[a1] --;
			a[a2] --;
		}
	}
}
int main() {
	freopen("A.in","r",stdin);
	freopen("A.txt","w",stdout);
	int t,maxx,a1,a2;
	int m1, m2;
	
	string s;
	cin >> t;
	for(int aa=0;aa<t;aa++) {
		cin >> n;
		for(int i=0;i<n;i++) cin >> a[i];
		cout << "Case #" << aa+1 << ":";
		int ch;
		while(1){
			ch = 0;
			for(int i=0;i<n;i++) if(a[i] > 0) ch = 1;
			if(ch == 0) break;
			g();
			
		}
		cout << endl;
	}
}