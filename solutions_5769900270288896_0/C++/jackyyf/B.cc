#include <bits/stdc++.h>

using namespace std;

namespace Solve {

	template<class T> inline bool _min(T& data, const T& comp) {
		if (comp < data) {
			comp = data;
			return true;
		}
		return false;
	}

	template<class T> inline bool _max(T& data, const T& comp) {
		if (data < comp) {
			comp = data;
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


	long R, C, N;

	long fill0() {
		long c0 = (R * C) >> 1;
		long c2 = ((R & C) & 1) ? 4 : 2;
		long c3 = 0;
		register long i;
		for(i = 1; i < R - 1; ++ i) {
			if (!(i & 1)) ++ c3;
			if (!((i + C - 1) & 1)) ++ c3;
		}
		for(i = 1; i < C - 1; ++ i) {
			if (!(i & 1)) ++ c3;
			if (!((i + R - 1) & 1)) ++ c3;
		}
		long c4 = ((R - 2) * (C - 2) + 1) >> 1;
		assert(c0 + c2 + c3 + c4 == R * C);
		long n = N;
		long ans = 0;
		if (n <= c0) return 0;
		n -= c0;
		if (n <= c2) return n * 2;
		n -= c2;
		ans += 2 * c2;
		if (n <= c3) return n * 3 + ans;
		n -= c3;
		ans += 3 * c3;
		return ans + 4 * n;
	}

	long fill1() {
		long c0 = (R * C + 1) >> 1;
		long c2 = ((R & C) & 1) ? 0 : 2;
		long c3 = 0;
		register long i;
		for(i = 1; i < R - 1; ++ i) {
			if ((i & 1)) ++ c3;
			if (((i + C - 1) & 1)) ++ c3;
		}
		for(i = 1; i < C - 1; ++ i) {
			if ((i & 1)) ++ c3;
			if (((i + R - 1) & 1)) ++ c3;
		}
		long c4 = ((R - 2) * (C - 2)) >> 1;
		assert(c0 + c2 + c3 + c4 == R * C);
		long n = N;
		long ans = 0;
		if (n <= c0) return 0;
		n -= c0;
		if (n <= c2) return n * 2;
		n -= c2;
		ans += 2 * c2;
		if (n <= c3) return n * 3 + ans;
		n -= c3;
		ans += 3 * c3;
		return ans + 4 * n;
	}

	long ans1(const long &R) {
		long n = N;
		if (n <= ((R + 1) >> 1)) return 0;
		if(R & 1) {
			// ODD
			n -= (R + 1) >> 1;
			return n * 2;
		} else {
			// EVEN
			n -= R >> 1;
			return n * 2 - 1;
		}
	}

	void main(void) {
		ios::sync_with_stdio(false);
		register long i, j;
		long T;
		cin >> T;
		for(auto t = 1L; t <= T; ++ t) {
			cin >> R >> C >> N;
			cout << "Case #" << t << ": ";
			if (R < C) swap(R, C);
			if (C == 1) {
				cout << ans1(R) << endl;
				continue;
			}
			long free = (R * C + 1) >> 1;
			if (N <= free) {
				cout << 0 << endl;
				continue;
			}
			cout << min(fill0(), fill1()) << endl;
		}
	}
}

int main(void) {
	Solve::main();
}
