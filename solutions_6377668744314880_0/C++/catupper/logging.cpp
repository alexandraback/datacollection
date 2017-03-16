#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
using namespace std;
typedef long long Int;
typedef pair<Int, Int> P;
typedef pair<double, Int> DP;
#define PI 3.1415926535897932384626
#define EPS 1e-10

/*
Int cnt(vector<P> poInts, Int ind){
	Int n = poInts.size();
	if(n <= 3)return 0;
	vector<double> ps;
	for(Int i = 0;i < n;i++){
		if(i == ind)continue;
		poInts[i].first -= poInts[ind].first;
		poInts[i].second -= poInts[ind].second;
		ps.push_back(atan2(poInts[i].first, poInts[i].second));
	}
	n--;
	sort(ps.begin(), ps.end());
	for(Int i = 0;i < n;i++)ps[i] += i * EPS;
	Int r = 1, res = 1 << 30;
	for(Int i = 0;i < n;i++){
		if(r == i)r = (r+1) % n;
		while(true){
			double dif = ps[r] - ps[i] + PI + PI;
			while(dif > PI - EPS)dif -= 2*PI;
//			cout << dif << endl;
			if(dif > -EPS){
				if((r + 1) % n == i)break;
				r++;
				r %= n;
				continue;
			}
			break;
		}
//		cout << i << " "<< r  <<  endl;

		res = min(res, (r - i + 2 * n - 1) % n);
	}
	return res;
}                  */

Int cnt2(vector<P> poInts, Int ind){
	Int n = poInts.size();
	if(n <= 3)return 0;
	Int res = 1 << 30;
	for(Int i = 0;i < n;i++){
		if(i == ind)continue;
		Int cnt = 0;
		for(Int j = 0;j < n;j++){
			Int a = poInts[i].first - poInts[ind].first;
			Int b = poInts[i].second - poInts[ind].second;
			Int c = poInts[j].first - poInts[ind].first;
			Int d = poInts[j].second - poInts[ind].second;
			if(a * d - b * c < 0)cnt++;			
		}
		res = min(res, cnt);
	}
	return res;
}

void solve(){
	vector<P> poInts;
	Int n, x, y;
	cin >> n;
	for(Int i = 0;i < n;i++){
		cin >> x >> y;
		poInts.push_back(P(x, y));
	}
	for(Int i = 0;i < n;i++){
		cout << cnt2(poInts, i) << endl;
	}
}

int main(){
	Int t;
	cin >> t;
	for(Int i = 1;i <= t;i++){
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}
