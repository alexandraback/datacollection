#include<bits/stdc++.h>
using namespace std;
int N;
priority_queue<pair<int,char> >q;
int main(){
	freopen("A-small-attempt0.in", "r",stdin);
	freopen("A.out","w",stdout);
	int t;
	cin >> t;
	int cnt = 0;
	while(t--){
		++cnt;
		while(!q.empty()) q.pop();
		cin >> N;
		for(int i=1; i<=N; ++i){
			int x; cin >> x;
			char y = i + 'A' - 1;
			q.push({x, y});
		}
		cout << "Case #" << cnt << ": ";
//		while(!q.empty()){
//			cout << q.top().first << ' ' << q.top().second << endl; q.pop();
//		}
		while(!q.empty()){
			int num = q.top().first;
			char alp = q.top().second;
			q.pop();
			int num2 = q.top().first;
			char alp2 = q.top().second;
			q.pop();
			if(num == num2 && q.empty()){
				cout << alp << alp2 << ' ';
				if(num > 1){
					q.push({num-1, alp});
					q.push({num-1, alp2});
				}
			}
			else{
				cout << alp << ' ' ;
				if(num > 1) q.push({num-1, alp});
				q.push({num2, alp2});
			}
			int z;
//			cin>>z;
		}
		cout << endl;
	}
}
