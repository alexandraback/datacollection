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

	long d[1024];
	long M, N;

	const long RLIM = 100000000000000; // 1e14

	long count(const long &time) {
		register long i, ret = 0;
		for(i = 0; i < M; ++ i) {
			ret += time / d[i] + 1;
		}
		return ret;
	}

	void main(void) {
		ios::sync_with_stdio(false);
		register long i, j;
		long T;
		cin >> T;
		for(long t = 1; t <= T; ++ t) {
			cin >> M >> N;
			for(i = 0; i < M; ++ i) {
				cin >> d[i];
			}
			cout << "Case #" << t << ": ";
			if (N <= M) {
				cout << N << endl;
				continue;
			}
			long L = 0, R = RLIM;
			while(L < R - 1) {
				long mid = (L + R) >> 1;
				long cnt = count(mid);
				if (cnt < N) L = mid;
				else R = mid;
			}
			long plft = N - count(L), now = L + 1;
			for(i = 0; i < M; ++ i) {
				if (now % d[i] == 0) {
					-- plft;
					if (plft == 0) {
						cout << i + 1 << endl;
						continue;
					}
				}
			}
		}
	}
}

int main(void) {
	Solve::main();
}
