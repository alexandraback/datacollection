#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
using namespace std;
typedef long long ll;
typedef pair<double, double> dd;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

vector<ii> sol;

bool solve(set<ii> &q, int rem){
	if(rem == 0){
		return true;
	}
	//cout << rem << endl;

	ii a = *q.begin();
	
	//cout << a.second <<" "<< a.first << " " << rem << endl;
	if(-a.first > rem - (- a.first)){
		return false;
	}
	q.erase(q.begin());

	q.insert(ii(a.first + 1, a.second));
	sol.push_back(ii(a.second, -1));
	int ok = solve(q, rem-1);
	if(ok) return true;
	q.erase(ii(a.first +1, a.second));
	sol.pop_back();

	//cout << "second part " << endl;
	ii b = *q.begin();
	q.erase(q.begin());
	//cout << a.second <<" "<< a.first << " " <<b.second <<" "<< b.first <<" "<< rem << endl;
	q.insert(ii(b.first + 1, b.second));
	q.insert(ii(a.first +1, a.second));
	sol.push_back(ii(a.second, b.second));
	ok = solve(q, rem-2);
	if(ok) return true;
	sol.pop_back();
	q.erase(ii(b.first + 1, b.second));
	q.erase(ii(a.first +1, a.second));
	q.insert(a);
	q.insert(b);
	return false;
}

int main(){
	int T; cin >> T;
	for(int t=1;t<=T;t++){
		int n; cin >> n;
		vector<int> v(n);
		set<ii> q;
		sol = vector<ii>();
		int sum = 0;
		for(int i=0;i<n;i++){
			cin >> v[i];
			q.insert(ii(-v[i], i));
			sum += v[i];
		}
		//cout << sum << endl;
		solve(q, sum);

		string ans = "";
		for(int i=0;i<sol.size();i++){
			ans += 'A' + sol[i].first;
			if(sol[i].second != -1){
				ans += 'A' + sol[i].second;
			}
			if(i != sol.size() -1) ans += " ";
		}
		cout << "Case #"<<t<<": "<<ans << endl;

	}

}
