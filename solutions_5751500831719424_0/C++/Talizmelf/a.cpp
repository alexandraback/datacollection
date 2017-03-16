#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

#define FORi(m) for( int i = 0; i < (m); ++i )
#define FOR(i, M) for( int i = 0; i < (M); ++i )
#define FOR1(i, M) for( int i = 1; i <= (M); ++i )
#define DEBUGGING 1
#define CERRL() if (DEBUGGING) { std::cerr << '\n'; }
#define EXAM(var) if (DEBUGGING) { std::cerr << #var << ": " << (var) << '\n'; }
#define EXAMARR(var, size) if (DEBUGGING) { std::cerr << #var << ": "; for(int __i__ = 0; __i__ < (size); ++__i__) std::cerr << (var)[__i__] << " "; std::cerr << '\n'; }

typedef vector<vector<pair<int, int>>> tdata;

vector<pair<int, int>> process(string s) {
	vector<pair<int, int>> r;
	
	for (int i = 0; i < s.size(); ) {
		char c = s[i];
		int j = i+1;
		while (j < s.size() && s[j] == c) ++j;
		r.push_back(make_pair(c-'a', j-i));
		i = j;
	}
	
	return r;
}

bool equal(const tdata& data, int S) {
	for (int i = 0; i < S; ++i) {
		for(int n = 1; n < data.size(); ++n) {
			if (data[n][i].first != data[0][i].first) return false;
		}
	}
	return true;
}
	
int maxim(const vector<int>& a) {
	int M = a[0];
	for (int i = 1; i < a.size(); ++i) if (a[i] > M) M = a[i];
	return M;
}

int moves(const vector<int>& a) {
	int M = maxim(a);
	int m = 9999;
	for (int k = 1; k <= M; ++k) {
		int c = 0;
		for (int i = 0; c < m && i < a.size(); ++i) c += abs(a[i]-k);
		if (c < m) m = c;
	}
	return m;
}

int min_move(const tdata& data, int S) {
	int count = 0;
	for (int i = 0; i < S; ++i) {
		vector<int> a(data.size());
		FOR(n, data.size()) a[n] = data[n][i].second;
		count += moves(a);
	}
	return count;
}

void solve(int T) {
	FOR1(t, T) {
		int N;
		cin>> N;
		
		tdata data(N);
		
		int S = 0;
		
		FOR(n,N) {
			string s;
			cin >> s;
			data[n] = process(s);
			if (S == 0) S = data[n].size();
			else if (S > 0 && S != data[n].size()) S = -1;
		}
		
		cout << "Case #" << t << ": ";
		
		if (S > 0 && equal(data, S)) cout << min_move(data, S);
		else cout << "Fegla Won";
		
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	solve(T);
}



