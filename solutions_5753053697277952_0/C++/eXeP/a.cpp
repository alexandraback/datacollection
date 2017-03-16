#include <bits/stdc++.h>

#define i64 long long
#define u64 unsigned long long
#define i32 int
#define u32 unsigned int

#define pii pair<int, int>
#define pll pair<long long, long long>

#define defmod 1000000007
using namespace std;
char cr(int i){
	return ((char)('A'+i));
}


int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	
	int tests; cin >> tests;
	for(int test = 1; test <= tests; test++){
		int n; cin >> n;
		vector<int> f(27, 0);
		int all = 0;
		deque<pii> lol;
		for(int i = 0; i < n; i++){
			cin >> f[i];
			all+=f[i];
			if(f[i])
				lol.push_back({f[i], i});
		}
		cout << "Case #" << test << ": ";
		while(lol.size()){
			sort(lol.begin(), lol.end());
			int nn = lol.size();
			
			if(nn == 2){
				while(lol.back().first > lol.front().first){
					cout << cr(lol.back().second) << " ";
					lol.back().first--;
				}
				while(lol.back().first){
					cout << cr(lol.back().second) << cr(lol.front().second)<<" ";
					lol.back().first--;

				}
				break;
			}
			else{
				while(lol.back().first >= lol[nn-2].first){
					cout << cr(lol.back().second) << " ";
					lol.back().first--;
				}
				if(lol.back().first == 0)
					lol.pop_back();

			}
			
		}

		cout << endl;

	}
	return 0;
}