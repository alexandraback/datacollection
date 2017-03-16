#include <bits/stdc++.h>

#define R(i,a,b) for (int i=a; i<=b; i++)

using namespace std;

int T,tmp;

int main () {
	cin >> T;
	for (int tc =1; tc <= T; tc++) {
		set<int> sets;
		vector<int> v;
		
		scanf ("%d",&tmp);
		R(i,1,4) R(j,1,4) {
			int a;
			scanf ("%d",&a);
			if (i == tmp)
				sets.insert(a);
		}
		
		scanf ("%d",&tmp);
		R(i,1,4) R(j,1,4) {
			int a;
			scanf ("%d",&a);
			if (i == tmp)
				if (sets.count(a)) v.push_back(a);
		}
		printf ("Case #%d: ",tc);
		if (v.empty()) puts("Volunteer cheated!");
		else if (v.size() > 1) puts("Bad magician!");
		else cout << v[0] <<endl;
	}
}
