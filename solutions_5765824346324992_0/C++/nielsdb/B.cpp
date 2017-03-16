#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include <set>
#include <regex>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <functional>
#include <bitset>
#define INF 2000000000
#define endl "\n"
#define gcd(x,y) __gcd((x),(y))
#define	all(c)	(c).begin(), (c).end()
#define rep(i,a,n) for (int i=a;i<n;i++)
const long long mod = 1000000007;

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T> >;

vector<int> readvi(int len){ vector<int> rv; for (int i = 0; i <len; i++){ int temp; cin >> temp; rv.push_back(temp); }return rv; }

int main(){
	int T;
	scanf("%d", &T);

	for (int testNb = 1; testNb <= T; testNb++){
		vector<pair<ull, int>> bezigTotQ;
		
		int B, N;
		scanf("%d%d", &B, &N);
		vi barbers;
		bezigTotQ.resize(B);
		for (int i = 0; i < B; i++){
			int t;
			scanf("%d", &t);
			barbers.push_back(t);
			bezigTotQ[i] = { 0ULL, i };
		}

		vi kadans;
		for(int k = 0; k < N; k++){
			bezigTotQ[0] = { bezigTotQ[0].first + barbers[bezigTotQ[0].second], bezigTotQ[0].second };
			kadans.push_back(bezigTotQ[0].second);
			sort(bezigTotQ.begin(), bezigTotQ.end());

			bool allesGelijk = true;
			for (int i = 1; i < bezigTotQ.size(); i++){
				if (bezigTotQ[i].first != bezigTotQ[0].first){
					allesGelijk = false;
					break;
				}
			}


			if (allesGelijk){
				break;
			}
		}

		printf("Case #%d: %d\n", testNb, kadans[(N-1)%kadans.size()]+1);

	}

	return 0;
}