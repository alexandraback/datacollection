#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <cmath>
#include <cassert>

using namespace std;


void task();

int main() {
#ifdef LUNAWYLL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
//	 freopen("bisector.in", "r", stdin);
//	 freopen("bisector.out", "w", stdout);
#endif
	task();
#ifdef LUNAWYLL
	//cout << "\n============\n" <<(double)clock()/CLOCKS_PER_SEC;
#endif
	return 0;
}

#ifdef LUNAWYLL
#define dbg(x) cout << #x << " = " << (x) << endl;
#define dbg2(a, b) cout << #a << " = " << (a) << "; "<<\
#b << " = " << (b) << endl;
#define dbg3(a, b, c) cout << #a << " = " << (a) << "; "<<\
		#b << " = " << (b) << "; "<<\
#c << " = " << (c) << endl;
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#endif

typedef long long int llint;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define ALL(v) ((v).begin()), ((v).end())

const int N = 2e5 + 10;
const llint MOD = (llint)1e9 + 7;
const int INF = 0x3f3f3f3f;
const llint LINF = (llint)8e18 + 100;
const int BUF_SIZE = (int)1e6 + 10;

const double PI = acos(-1);

bool check(vi carry, int sum){
	//dbg2("ch", sum);
	for (int i = 0; i < carry.size(); ++i) if (carry[i]){
		//dbg2(i, carry[i]);
		if (carry[i] > sum/2){
			//dbg("fail");
			return false;
		}
	}
	//dbg("ok");
	return true;
}

vector<string> ans;

bool go(vi carry, int sum){
	//dbg(sum);
	if (sum == 0){
		return true;
	}
	if (sum == 1){
		return false;
	}
	for (int i = 0; i < carry.size(); ++i) if (carry[i]>0){
		carry[i]--;
		for (int j = i; j < carry.size(); ++j) if (carry[j] > 0){
			carry[j]--;
			if (check(carry, sum - 2)){
				if (go(carry, sum - 2)){
					ans.push_back(string(1, i + 'A') + string(1, j + 'A'));
					return true;
				}
			}
			carry[j]++;
		}
		carry[i]++;
	}
	for (int i = 0; i < carry.size(); ++i) if (carry[i] > 0){
		carry[i]--;
		if (check(carry, sum - 1)){
			if (go(carry, sum - 1)){
				ans.push_back(string(1, i + 'A'));
				return true;
			}
		}
		carry[i]++;
	}
	return false;
}


void task(){
	int t;
	cin >> t;
	for (int tnum = 1; tnum <= t; ++tnum){
		int n;
		cin >> n;
		vi a(n);
		int sum = 0;
		for (int i = 0; i < n; ++i){
			cin >> a[i];
			sum += a[i];
		}
		if(go(a, sum)){
			printf("Case #%d: ", tnum);
			for (int i = ans.size() - 1; i>= 0; --i){
				cout << ans[i] << ' ';
			}
			cout << endl;
		} else{
			assert(false);
		}
		ans.clear();

	}
	priority_queue<int> q;

}
