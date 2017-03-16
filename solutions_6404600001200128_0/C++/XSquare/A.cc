#include <iostream>
#include <vector>

using namespace std;

bool can(vector <int> &v, int m, int &t){
	int n = v.size();
	t = 0;
	for (int i = 1; i < n; ++i){
		int d = v[i-1] - 10*m;
		if (v[i] < d) return false;
		t += min(v[i-1], 10*m);
	}
}

int main(){
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t){
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		vector <int> v(N);
		for (int i = 0; i < N ; ++i) cin >> v[i];
		int m = v[0];
		int t1 = 0, t2 = 0;
		int d = 0;
		bool increasing = true;
		for (int i = 1; i < N; ++i){
			if (v[i] < v[i-1]) t1 += v[i-1] - v[i];
			d = max(d, v[i-1] - v[i]);
			//if (v[i] < v[i-1]) increasing = false;
		}
		for (int i = 1; i < N; ++i) t2 += min(d, v[i-1]); 
		cout << t1 << " " << t2 << endl;
	}
}
