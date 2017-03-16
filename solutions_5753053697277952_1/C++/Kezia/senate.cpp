#include <bits/stdc++.h>
using namespace std;

int t,n;
struct bum{
	int x,i;
	bool operator < (bum xx) const{
		return x < xx.x;
	}
} a[30];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("senate.in","r",stdin);
	freopen("senate.out","w",stdout);
	cin >> t;
	for (int tc=1;tc<=t;tc++){
		cout << "Case #" << tc << ":";
		cin >> n;
		priority_queue<bum> pq;
		for (int i=1;i<=n;i++){
			cin >> a[i].x; a[i].i=i-1; pq.push(a[i]);
		}
		while (!pq.empty()){
			if (pq.size()==2){
				char c,d;
				bum nowa=pq.top(); pq.pop();
				bum nowb=pq.top(); pq.pop();
				c='A'+nowa.i; d='A'+nowb.i;
				if (nowa.x<nowb.x) swap(c,d);
				for (int i=1;i<=abs(nowa.x-nowb.x);i++)
				cout << ' ' << c;
				for (int i=1;i<=min(nowa.x,nowb.x);i++)
				cout << ' ' << c << d;
				break;
			}
			bum now=pq.top(); pq.pop();
			char c='A'+now.i;
			cout << ' ' << c;
			if (now.x-1){
				now.x--; pq.push(now);
			}
		}
		cout << "\n";
	}
}
