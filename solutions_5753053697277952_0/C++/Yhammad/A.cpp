#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<string.h>
#include<cmath>
#include<algorithm>
#include<utility>
#include<fstream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int z = 1; z <= t; ++ z){
		cout << "Case #" << z << ": ";
		priority_queue<pair<int,char> > pq;
		int n, r;
		cin >> n;
		for(int i = 0; i < n; ++ i){
			cin >> r;
			pq.push(pair<int,char>(r, 'A' + i));
		}
		vector<char> ret;
		while(!pq.empty()){
			pair<int,char> top = pq.top();
			pq.pop();
			ret.push_back(top.second);
			top.first --;
			if(top.first > 0)
				pq.push(top);
		}
		for(int i = 0; i < ret.size() - 2; i += 2){
			if(i) cout << ' ';
			cout << ret[i];
			if(i + 1 < ret.size() - 2)
				cout << ret[i+1];
		}
		for(int i = ret.size() - 2; i < ret.size(); i += 2){
			if(i) cout << ' ';
			cout << ret[i];
			if(i + 1 < ret.size())
				cout << ret[i+1];
		}
		cout << endl;
	}
	return 0;
}