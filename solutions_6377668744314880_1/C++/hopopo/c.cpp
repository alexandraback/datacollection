#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<long long, long long> point;

point operator-(const point& a, const point& b){
	point p;
	p.first = a.first - b.first;
	p.second = a.second - b.second;
	return p;
}

class cmp{
	public:
		bool operator()(const point& p1, const point& p2) const{
			long double one = 1;
			long double s1 = p1.second*one/p1.first;
			long double s2 = p2.second*one/p2.first;
			return s1 < s2;
		}
};

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
			vector<point> blocks[2];
			vector<point> y;
			int ny = 0, py = 0;
			for(int j = 0; j < n; ++j){
				if(points[i] != points[j]){
					point newp = points[j] - points[i];
					if(newp.first == 0){
						y.push_back(newp);
						if(newp.second > 0) py++;
						else ny++;
					}else{
						blocks[newp.first < 0].push_back(newp);
					}
				}
			}

			for(int j = 0; j < 2; ++j)
				sort(blocks[j].begin(), blocks[j].end(), cmp());


			for(long long j = 0; j < points.size(); ++j){
				if(points[i] == points[j]) continue;
				point slope = points[j] - points[i];

				long long positive = 0, negative = 0;
				if(slope.first == 0){
					positive = blocks[0].size();
					negative = blocks[1].size();
				}else{
					positive = py;
					negative = ny;
					negative += lower_bound(blocks[0].begin(), blocks[0].end(), slope, cmp()) - blocks[0].begin();
					positive += blocks[0].end() - upper_bound(blocks[0].begin(), blocks[0].end(), slope, cmp());
					positive += lower_bound(blocks[1].begin(), blocks[1].end(), slope, cmp()) - blocks[1].begin();
					negative += blocks[1].end() - upper_bound(blocks[1].begin(), blocks[1].end(), slope, cmp());
				}

				mn = min(mn, min(positive, negative));
			}

			cout << mn << endl;
		}
	}

	return 0;
}
