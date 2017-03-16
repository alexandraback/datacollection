#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
const int maxn = 30;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tests; cin >> tests;
	for (int test=1;test<=tests;test++){
		int n, tot = 0; cin >> n;
		priority_queue< pair<int,int> >  q;
		for(int i=0;i<n;i++){
			int x; cin >> x; tot += x;
			q.push(mp(x,i));
		}
		cout << "Case #" << test << ": ";
		while(!q.empty()){
			if(q.size()%2 == 0){
				pair<int,int> x = q.top(); q.pop();
				pair<int,int> y = q.top(); q.pop();
				assert(x.F <= tot/2);
				char c1 = x.S + 'A';
				char c2 = y.S + 'A';
				tot -= 2;
				if(x.F > 1){
					x.F--; q.push(x);
				}
				if(y.F > 1){
					y.F--; q.push(y);
				}
				cout << c1 << c2 << " ";
			} else {
				pair<int,int> x = q.top(); q.pop();
				assert(x.F <= tot/2);
				char c1 = x.S + 'A';
				tot -= 1;
				if(x.F > 1){
					x.F--; q.push(x);
				}
				cout << c1 << " ";
			}
		}
		cout << endl;
	}
	return 0;
}