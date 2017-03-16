#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>
#include <list>

using namespace std;

#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))

typedef long long ll;

const int MAX_N = 50;
pair<int, char> a[MAX_N];
int n=0;

int getMax(){
	int mx = 0;
	FOR(i,n) mx = max(mx, a[i].first);
	return mx;
}

void SolveCase()
{
	cin >> n;
	int total = 0;
	FOR(i,n){
		cin >> a[i].first;
		a[i].second = 'A'+i;
		total += a[i].first;
	}
	sort(a,a+n);
	reverse(a,a+n);
	while(a[0].first > a[1].first){
		//if(2*getMax() > total) throw "asdf"; total--;
		cout << a[0].second;
		if(a[0].first >= a[1].first+2){
			cout << a[0].second;
			a[0].first--;
		}
		a[0].first--;
		cout << " ";
	}
	for(int i = 2; i < n; ++i){
		while(a[i].first > 0){
			//if(2*getMax() > total) throw "asdf"; total--;
			cout << a[i].second;
			if(a[i].first >= 2){
				cout << a[i].second;
				a[i].first--;
			}
			a[i].first--;
			cout << " ";
		}
	}
	FOR(i,a[0].first){
		cout << a[0].second;
		cout << a[1].second;
		cout << " ";
	}
}

void test1()
{
}

int main()
{
	//test();return 0;
	int t; cin >> t;
	FOR(i,t){
		cout << "Case #" << i+1 << ": ";
		SolveCase();
		cout << endl;
	}
	return 0;
}