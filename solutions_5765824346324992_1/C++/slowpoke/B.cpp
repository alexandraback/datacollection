#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <array>
#include <string>
#include <deque>
#include <list>
#include <numeric>
#include <limits>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <functional>

using namespace std;

void comp(int tc){
	long long B, N;
	cin >> B >> N;
	vector<long long> v(B);
	for (long long &val : v)
		cin >> val;

	long long lo = 0, hi = v[0] * N;

	while (lo <= hi){
		long long mid = lo + (hi - lo) / 2;
		long long sum = 0;
		for (int i = 0; i < B; ++i){
			sum += (mid + v[i]) / v[i];			
		}

		if (sum + B < N){
			lo = mid + 1;
		}
		else if(sum >= N){
			hi = mid - 1;
		}
		else{
			priority_queue < pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
			for (int i = 0; i < B; ++i){
				pq.emplace(mid / v[i] * v[i] + v[i], i);
			}
			
			while (sum < N - 1){
				auto p = pq.top();
				pq.pop();
				pq.emplace(p.first + v[p.second], p.second);
				++sum;
			}

			cout << "Case #" << tc << ": " << pq.top().second + 1 << endl;
			return;
		}
	}

	priority_queue < pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	for (int i = 0; i < B; ++i){
		pq.emplace(0, i);
	}

	while (N > 1){
		auto p = pq.top();
		pq.pop();
		pq.emplace(p.first + v[p.second], p.second);
		--N;
	}

	cout << "Case #" << tc << ": " << pq.top().second + 1 << endl;
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		comp(i);
	}
}