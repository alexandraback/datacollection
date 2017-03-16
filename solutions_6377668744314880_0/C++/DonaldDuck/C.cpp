// Problem C


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
#include <string.h>
#include <map>
#include <queue>
#include <stack>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define MAXN 3004
#define PI 3.14159265
#define eps 0.0000001

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<ii> vii;

void solve(int t) {
	int N;
	ii a[MAXN];
	cin >> N;
	for (int i=0; i<N; i++)
		cin >> a[i].fs >> a[i].sc;
	
	cout << "Case #" << t << ":\n";
	
	for (int i=0; i<N; i++) {
		vector<float> b;
		for (int j=0; j<N; j++)
			if (j != i) {
				b.pb(atan2((float)(a[j].sc-a[i].sc),(float)(a[j].fs-a[i].fs))*180.0/PI);
				if (b[b.size()-1] < 0)
					b[b.size()-1]+=360.0;
			}
				
		sort(b.begin(), b.end());
		//for (int j=0; j<(int)b.size(); j++) cout << b[j] << " ";
		//cout << endl;
		
		int res = N-1;
		for (int j=0; j<N-1; j++)
			for (int k=1; k<N-2; k++) {
				int y=0;
				if (j+k>=N-1) y=1;
				float c = b[(j+k)%(N-1)] + 360.0*y;
				float x = c-b[j];
				//if (i==4) cout << j << " " << k << " " <<  c << " " << x << endl;
				//if (x>=360.0) x = x-360.0;
				//if (x<0) x = x+360.0;
				if (x >= 180.0-eps)// || x<=-180.0+eps)
					res = min(res, k-1);
			}
			
		cout << res << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		//cout << "Case #" << t << ": ";
		solve(t);
	}
	
	return 0;
}
