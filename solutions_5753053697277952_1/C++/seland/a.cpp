#pragma comment(linker,"/STACK:100000000000,100000000000")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>

using namespace std;

#define sz(a) int((a).size())
#define F first
#define S second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;

const double eps=1E-9;
const double Exp=2.718281828459045;
const double Pi=3.1415926535897932;

const int NMAX=40 + 5;
const int MMAX=20;
const int INF=1000000000;
const ll INFLL=1000000000000000000ll;
const int BS=1000000007;

template <typename T> inline T abs(const T a){
    if (a<0) return -a;
    return a;
}
template <typename T> inline T sqr(const T& a){
    return a*a;
}

bool test(int cnt, int all) {
	return cnt * 2 <= all;
}

int main(){
    ios::sync_with_stdio(false);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	for (int T = 1; T <= t; T++) {
		cout << "Case #" << T << ":";
		int n;
		int cnt=0;
		int a[NMAX];
		set <pii> st;
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			cnt += a[i];
			st.insert(mp(-a[i],i));
		}
		
		int mx;
		int mx2;
		while (cnt > 0) {
			mx = st.begin()->S;
			mx2 = (++st.begin())->S;
			if (test(a[mx2],cnt - 1)) {
				cout << " " << (char)('A' + mx);
				st.erase(mp(-a[mx],mx));
				a[mx]--;
				if (a[mx] > 0) {
					st.insert(mp(-a[mx],mx));
				}
				cnt--;
				continue;
			} else {
				cout << " " << (char)('A' + mx) << (char)('A' + mx2);
				st.erase(mp(-a[mx],mx));
				a[mx]--;
				if (a[mx] > 0) {
					st.insert(mp(-a[mx],mx));
				}
				st.erase(mp(-a[mx2],mx2));
				a[mx2]--;
				if (a[mx2] > 0) {
					st.insert(mp(-a[mx2],mx2));
				}
				cnt-=2;
			}
		}
		cout << endl;
	}

    return 0;
}