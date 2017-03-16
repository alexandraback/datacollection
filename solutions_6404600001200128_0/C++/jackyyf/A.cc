#include <bits/stdc++.h>

using namespace std;

namespace Solve {

	template<class T> inline bool _min(T& data, const T& comp) {
		if (comp < data) {
			data = comp;
			return true;
		}
		return false;
	}

	template<class T> inline bool _max(T& data, const T& comp) {
		if (data < comp) {
			data = comp;
			return true;
		}
		return false;
	}

	template<class T> inline vector<T>& operator<< (vector<T> &storage, const T& data) {
		storage.push_back(data);
		return storage;
	}

	template<class T> inline void operator!(const vector<T>& vect) {
		for(const T& data : vect) {
			cout << data << " ";
		}
	}

	template<class T> inline queue<T>& operator<< (queue<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline stack<T>& operator<< (stack<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline priority_queue<T>& operator<< (priority_queue<T> &storage, const T& data) {
		storage.push(data);
		return storage;
	}

	template<class T> inline queue<T>& operator>> (queue<T> &storage, T& data) {
		data = storage.front();
		storage.pop();
		return storage;
	}

	template<class T> inline stack<T>& operator>> (stack<T> &storage, T& data) {
		data = storage.top();
		storage.pop();
		return storage;
	}

	template<class T> inline priority_queue<T>& operator>> (priority_queue<T> &storage, T& data) {
		data = storage.top();
		storage.pop();
		return storage;
	}

	long m[16384];

	void main(void) {
		ios::sync_with_stdio(false);
		register long i, j;
		long T;
		cin >> T;
		for(long t = 1; t <= T; ++ t) {
			long N;
			cin >> N;
			for(i = 0; i < N; ++ i) {
				cin >> m[i];
			}
			cout << "Case #" << t << ": ";
			long ans1 = 0, maxd = -1;
			for(i = 1; i < N; ++ i) {
				ans1 += max(0L, m[i - 1] - m[i]);
				_max(maxd, m[i - 1] - m[i]);
			}
			cout << ans1 << " ";
			long ans2 = 0;
			for(i = 0; i < N - 1; ++ i) {
				ans2 += min(maxd, m[i]);
			}
			cout << ans2 << endl;
		}
	}
}

int main(void) {
	Solve::main();
}
