#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

const double eps = 1e-9;
const int inf = 1e9 + 23;

const int size = 1000;

const int N = 4;

void write (vector <pair <int, int> > &p, int i) {
	cout << (char) ('A' + p[i].second) << " ";
	return;
}

void write (vector <pair <int, int> > &p, int i, int j) {
	cout << (char) ('A' + p[i].second) << (char) ('A' + p[j].second) << " ";
	return;
}


void evacuate(vector <pair <int, int> > &p, int all){
	int n = p.size();
	assert(n > 1);
	assert(p[0].first * 2 <= all);
	if (n == 2) {
		for (int i = 0; i < all / 2; i++) {
			cout << (char) ('A' + p[0].second) << (char) ('A' + p[1].second) << " ";
		}
		cout << endl;
		return;
	}
	if (p[0].first == 1) {
		if (n % 2 == 1) {
			write(p, n - 1);
			for (int i = 0; i < (n - 1) / 2; i++) {
				write(p, 2 * i, 2 * i + 1);
			}
		}
		cout << endl;
		return;
	}
	if (p[0].first > p[1].first) {
		write(p, 0);
		p[0].first--;
		evacuate(p, all - 1);
		return;
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].first != p[0].first) {
			break;
		}
		else
			k = i;
	}
	write(p, k, k - 1);
	p[k].first --;
	p[k - 1].first --;
	evacuate(p, all - 2);
	return;
}

int main (void){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int t;
	
	cin >> t;
	for (int it = 1; it <= t; it++) {
		cout << "Case #" << it << ": ";
		cin >> n;
		vector <pair <int, int> > p;
		for (int i = 0; i < n; i++) {
			int myint;
			cin >> myint;
			p.push_back(make_pair(myint, i));
		}
		sort(p.begin(), p.end());
		reverse(p.begin(), p.end());
		int all = 0;
		for (int i = 0; i < n; i++)
			all += p[i].first;
		evacuate(p, all);
	}
	
	
	return 0;
}