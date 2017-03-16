#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, L;

int gcd(int a, int b)
{
  return ( (b == 0) ? a : gcd(b, a % b) );
}

void exec(int case_num)
{
	int B, N;
	int cycLen = 0;
	cin >> B >> N;
	vector<int> tm(B);
	double custPerMin = 0.0;
	for(int i = 0; i < B; ++i) {
		cin >> tm[i];
		custPerMin += 1.0 / tm[i];
	}
	int g = 1;
	if(B > 1) g = gcd(tm[0], tm[1]);
	for(int i = 2; i < B; ++i) g = gcd(tm[i], g);
#define epsilon 1E-9
	for(cycLen = g; ; cycLen += g) {
		const double mul = cycLen * custPerMin;
		const int t = int(mul);
		if(mul - t < epsilon || t + 1 - mul < epsilon) break;
	}
	int cust = int(cycLen * custPerMin);
	if(cycLen * custPerMin - cust > 0.5) ++cust;
	if(cust < B) cust = B;

	N %= cust;
	if(0 == N) N = cust;

	vector< pair<int, int> > vpi;
	for(int i = 0; i < B; ++i) {
		vpi.push_back( make_pair(int(0), i) );
	}

	while(N > 1) {
		for(int i = 0; i < B; ++i) {
			vpi[0].first += cycLen;
			if(tm[vpi[i].second] == vpi[i].first) {
			  vpi[0].first = 0;
			  --N;
			}
			if(1 == N) break;
		}
	}

	int ans = 0;
	while(0 == ans) {
		for(int i = 0; i < B; ++i) {
			vpi[0].first += cycLen;
			if(tm[vpi[i].second] == vpi[i].first) {
				ans = vpi[i].second + 1;
				break;
			}
		}
	}
    cout << "Case #" << case_num << ": " << ans << endl;
}

int main()
{
  int T;
  cin >> T;
  for(int case_num = 1; case_num <= T; ++case_num) {
	exec(case_num);
  }
  return 0;
}


