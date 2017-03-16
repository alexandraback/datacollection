#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

#define For(i, n) for(int (i) = 0; (i) < (n); (i)++)

int main(){
	int T;
	cin >> T;
	For(t, T){	
		int n,x ,y;
		cin >> n;
		int total = 0;
		priority_queue<pair<int, int> > pq;
		For(i, n){
			cin >> x;
			pq.push({x, i});
			total += x;
		}

		vector<vector<int> > res;
		while(!pq.empty()){
			x = pq.top().first;
			y = pq.top().second;
			pq.pop();

			res.push_back(vector<int> (0));
			res.back().push_back(y);
			total--;
			if(pq.top().first > total / 2 ){
				int x2 = pq.top().first, y2 = pq.top().second;
				pq.pop();
				res.back().push_back(y2);
				total --;
				if(x2 > 1) pq.push({x2-1, y2});
			}
			if(x > 1) pq.push({x - 1, y});
		}

		cout << "Case #" << t + 1 <<  ":" ;
		for(auto v: res){
			cout << " ";
			for(auto vv: v) cout << (char)(vv+65);
		}
		cout << endl;
	}

	return 0;
}