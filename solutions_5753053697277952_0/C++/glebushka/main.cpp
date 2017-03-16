#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<queue>
#include <stdlib.h>
#include <unordered_set>
#include <memory.h>
#include <iomanip>
#include<stack>
#include<vector>
#include<string>
#include <deque>
#include <unordered_map>
//#include<unordered_set>
using namespace std;
typedef long long ll;
typedef long double ld;

set <pair<int, int> > st;
void print(int tst){
	cout << "Case #" << tst << ": ";
}

int a[50];

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int n;
		cin >> n;
		int sum = 0;
		st.clear();
		for (int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
			st.insert(make_pair(a[i], i));
		}
		
		print(i);
		while (!st.empty()){
			auto it = st.end();
			it--;
			pair <int, int> p2 = *it;
			st.erase(p2);
			if (sum % 2 == 1){
				sum = 0;
				cout << (char)('A' - 1 + p2.second) << " ";
				p2.first--;
				if (p2.first != 0){
					st.insert(p2);
				}
				continue;
			}
			it = st.end();
			it--;

			pair <int, int> p1 = *it;
			st.erase(p1);

			if (p2.first == 1){
				cout << (char)('A' - 1 + p2.second) << (char)('A' - 1 + p1.second) << " ";
				continue;
			}

			if (p2.first > 2 && p2.first > p1.first){
				cout << (char)('A' - 1 + p2.second) << (char)('A' - 1 + p2.second) << " ";
				p2.first -= 2;
				st.insert(p2);
				st.insert(p1);
				continue;
			}
			if (p2.first == 2 && p2.first > p1.first){
				cout << (char)('A' - 1 + p2.second) << (char)('A' - 1 + p2.second) << " ";
				st.insert(p1);
				continue;
			}
			cout << (char)('A' - 1 + p2.second) << (char)('A' - 1 + p1.second) << " ";
			p2.first--;
			p1.first--;
			st.insert(p1);
			st.insert(p2);
		}
		cout << endl;
	}

	return 0;
}