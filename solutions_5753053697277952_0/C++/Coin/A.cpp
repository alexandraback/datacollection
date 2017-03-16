#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
using namespace std; 

struct Node{
	char c;
	int cnt;
	Node(char ch, int n) :c(ch), cnt(n) {}
};

bool cmp(const Node& x, const Node& y) {
	return x.cnt > y.cnt;
}


int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T, kase = 0;
	cin >> T;
	while (++kase <= T) {
		cout << "Case #" << kase << ": ";
		int N;
		cin >> N;
		vector<Node> vec;
		for (int i = 0, c = 'A'; i < N; i++, c++) {
			int num;
			cin >> num;
			vec.push_back(Node((char)c, num));
		}
		if (N == 2) {
			int num = vec[0].cnt;
			for (int i = 0; i < num; i++) {
				if (i != 0) cout << " ";
				cout << "AB";
			}
			cout << endl;
		}
		else {
			sort(vec.begin(), vec.end(), cmp);
			int end = 0;
			bool start = 1;
			while (1) {
				int num = vec[0].cnt;
				if (num == 1)
					break;
				for (int i = 0; i < N; i++) {
					if (vec[i].cnt < num)
						break;
					if (!start)
						cout << " ";
					cout << vec[i].c;
					vec[i].cnt--;
					start = 0;
				}
			}
			for (int i = 0; i < N - 2; i++) {
				if (!start)
					cout << " ";
				cout << vec[i].c;
				start = 0;
			}
			if (!start) cout << " ";
			cout << vec[N - 2].c << vec[N - 1].c << endl;
		}
	}
	return 0;
}