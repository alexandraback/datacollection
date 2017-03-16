#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <random>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int,int> PII;
#define FOR(k,a,b) for(typeof(a) k=(a); k <= (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define REPD(k,a) for(int k=(a)-1; k >= 0; --k)
#define PB push_back 
#define MP make_pair

int main()
{
	int T;
	std::cin >> T;
	for (int t = 0; t < T; ++t) {
		std::cout << "Case #" << (t + 1) << ": ";
		int N;
		cin >> N;
		vector < pair<char, int> > s;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			int n;
			cin >> n;
			sum += n;
			s.push_back(make_pair('A' + i, n));
		}
		auto sf = [](const pair<char, int>& a, const pair<char, int>& b) {return a.second > b.second; };
		std::sort(s.begin(), s.end(), sf);
		while (sum > 0) {
			if (s[1].second > (sum - 1) / 2) {
				std::cout << s[0].first << s[1].first << " ";
				s[0].second -= 1;
				s[1].second -= 1;
				sum -= 2;
			} else {
				cout << s[0].first << " ";
				s[0].second -= 1;
				sum -= 1;
			}
			std::sort(s.begin(), s.end(), sf);
		}
		std::cout << std::endl;
		//std::cout << ncmax << std::endl;
	}
	return 0;
}
