#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

typedef pair<long long, long long> point;

point operator-(const point& a, const point& b){
	point p;
	p.first = a.first - b.first;
	p.second = a.second - b.second;
	return p;
}

int main(){
	int tests;
	cin >> tests;

	for(int test = 1; test <= tests; ++test){
		long long n;
		vector<point> points;
		cin >> n;

		for(long long i = 0; i < n; ++i){
			point p;
			cin >> p.first >> p.second;

			points.push_back(p);
		}

		printf("Case #%d:\n", test);

		for(long long i = 0; i < n; ++i){
			long long mn = n/2;
			for(long long j = 0; j < n; ++j){
				if(points[i] == points[j]) continue;
				point slope = points[j] - points[i];

				long long positive = 0, negative = 0;
				for(long long k = 0; k < n; ++k){
					point newp = points[k] - points[i];
					long long sign = newp.first * slope.second - newp.second * slope.first;
					positive += sign > 0;
					negative += sign < 0;
				}

				mn = min(mn, min(positive, negative));
			}

			cout << mn << endl;
		}
	}

	return 0;
}
