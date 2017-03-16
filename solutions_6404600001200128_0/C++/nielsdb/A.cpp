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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T> >;

int main(){
	int T;
	scanf("%d", &T);
	for (int testNb = 1; testNb <= T; testNb++){
		int N;
		scanf("%d", &N);
		vi mush;
		int prev;
		int maxNaarBeneden=0;
		int methode1=0;
		for (int i = 0; i < N; i++){
			int t;
			scanf("%d", &t);
			mush.push_back(t);
			if (i > 0){
				maxNaarBeneden = max(maxNaarBeneden, prev-t);
				if (prev - t > 0){
					methode1 += prev - t;
				}
			}
			prev = t;
		}

		int methode2 = 0;
		for (int i = 0; i < mush.size() - 1; i++){
			methode2 += min(mush[i], maxNaarBeneden);
		}
		printf("Case #%d: %d %d\n", testNb, methode1, methode2);

	}



	return 0;
}