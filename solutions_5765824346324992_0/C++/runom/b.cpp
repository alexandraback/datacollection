#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define DEBUG(x) cout << #x << ' ' << x << endl;

typedef long long Int;

Int gcd(Int a, Int b) {
	  return b != 0 ? gcd(b, a % b) : a;
}
Int lcm(Int a, Int b) {
	  return a * b / gcd(a, b);
}
// a x + b y = gcd(a, b)
Int extgcd(Int a, Int b, Int &x, Int &y) {
	Int g = a; x = 1; y = 0;
	if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
	return g;
}

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		int b, n;
		cin >> b >> n;
		vector<int> v(b);
		n--;
		//sort(v.begin(), v.end());
		
		for(int i = 0; i < b; ++i) {
			cin >> v[i];
		}

		long long c = 1;
		
		for(int i = 0; i < b; ++i) {
			c = lcm(c, v[i]);
		}
			
		
		long long r = 0;
		for(int i = 0; i < b; ++i) {
			r += c / v[i];
		}
		
		

		n %= r;

		//if(n == 0) n += r;

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q; //次に動ける時間, ID
		
		vector<int> ans; //i番目の人の担当
		
		for(int i = 0; i < b; ++i) {
			q.emplace(v[i], i);
			ans.push_back(i);
		}

		
		for(int i = 1; i < c; ++i) {
			while(!q.empty()){
				auto p = q.top();
				if(p.first > i) break;
				q.pop();
				ans.push_back(p.second);
				q.emplace(i + v[p.second], p.second);
			}
		}
		cout << "Case #" << t << ": " << ans[n] + 1 << endl;
	}
}
