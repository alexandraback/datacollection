

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<ull> vull;
typedef vector<ll> vll;

// TIMER
std::clock_t __start;
double __duration;
void start_timer() { __start = std::clock(); }
void print_timer() {
	__duration = (std::clock() - __start) / (double)CLOCKS_PER_SEC;
	std::cout << "Duration: " << __duration << '\n';
}
// END TIMER

//PI
# define M_PI		3.14159265358979323846
// fast input
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
//char _;

template <class T>
T min_(T a, T b) { return (a < b ? a : b); }
template <class T>
T max_(T a, T b) { return (a > b ? a : b); }
double EPS = 1e-9;
bool eq_(const double& lhs, const double &rhs) {
	return (fabs(lhs - rhs) < EPS);
}

const int INF = int(2e9);
const ll INF_LL = ll(1e18);
const int MAX_N = 1e7;



int main() {
	ios_base::sync_with_stdio(false);
	//cin.tie(0);
	//start_timer();

	ifstream fin("a.in");
	ofstream fout("a.out");

	int T,N;
	int num;
	fin >> T;
	for (int t = 0; t < T; ++t) {
		priority_queue<pair<int, char>> pq;
		fin >> N;
		for (int i = 0; i < N;++i) {
			fin >> num;
			pair<int, char> pp = { num, 'A' + i };
			pq.push(pp);
		}
		fout << "Case #" << t + 1 << ": ";
		if (N == 2) {
			
			for (int i = 0; i < pq.top().first; ++i)
				fout << "AB ";
			fout << '\n';
		}
		else {
			vector<pair<int, char>> curr_pairs;
			while (!pq.empty()) {
				pair<int, char> ptop = pq.top();
				pq.pop();
				curr_pairs.push_back(ptop);
				int cp_idx = curr_pairs.size() - 1;
				int top_num = ptop.first;
				while (!pq.empty() && pq.top().first == top_num) {
					ptop = pq.top();
					pq.pop();
					curr_pairs.push_back(ptop);
				}
				while (true) {
					
					for (int i = 0; i < curr_pairs.size(); ++i) {
						if (curr_pairs[i].first == 1 && 
							i + 2 == curr_pairs.size()) {
							fout << curr_pairs[i].second 
								 << curr_pairs[i + 1].second<<' ';
							curr_pairs[i].first--;
							curr_pairs[i + 1].first--;
							break;
						}
						fout << curr_pairs[i].second<<' ';
						curr_pairs[i].first--;
					}
					if (pq.empty() && curr_pairs[0].first == 0) {
						fout << '\n';
						break;
					}
					else if (!pq.empty() &&
						     curr_pairs[cp_idx].first == pq.top().first) {
						break;
					}
				}
			}
		}
	}

	//print_timer();
	return 0;
}
