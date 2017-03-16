#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
int N;

bool failure(int parties[]) {
    int sum = 0;
    F0(i, N) {
        sum += parties[i];
    }
    F0(i, N) {
        if (parties[i] > sum/2) {
            return true;
        }
    }
    return false;
}

int main() {
//    freopen("x.in", "r", stdin);

//	freopen("A-small-attempt0.in", "r", stdin);
//	freopen("A-small-attempt0.out", "w", stdout);

	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		//cerr << tt << endl;

		cin >> N;
		int parties[N];
		int sum = 0;
		F0(i, N) { cin >> parties[i]; sum += parties[i];}
  		printf("Case #%d:", tt);

		while (sum != 0) {
            int best1 = 0, best2 = 0;
            int i1, i2;
            bool one_only = false;
            F0(j, N) {
                if (parties[j] > best1) {
                    best2 = best1;
                    i2 = i1;
                    best1 = parties[j];
                    i1 = j;
                } else {
                    if (parties[j] > best2) {
                        best2 = parties[j];
                        i2 = j;
                    }
                }
            }
            parties[i1]--;
            parties[i2]--;
            sum -=2;
            char c1 = (char)(65+i1);
            char c2 = (char)(65+i2);
            if (failure(parties)) {
                one_only = true;
                parties[i2]++;
                sum++;
            }
            cout << " " << c1;
            if (!one_only) {
                cout << c2;
            }
		}
		cout << endl;

	}
	return 0;
}
