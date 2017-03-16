#include <bits/stdc++.h>
using namespace std;

#define repu(i, a, b) for (int i = (a); i < (b); ++i)
#define repd(i, a, b) for (int i = (a); i > (b); --i)
#define mem(a, x) memset(a, x, sizeof(a))
#define all(a) a.begin(), a.end()
#define uni(a) a.erase(unique(all(a)), a.end())
#define count_bits(x) __builtin_popcount(x)
#define count_bitsll(x) __builtin_popcountll(x)
#define least_bits(x) __builtin_ffs(x)
#define least_bitsll(x) __builtin_ffsll(x)
#define most_bits(x) 32 - __builtin_clz(x)
#define most_bitsll(x) 64 - __builtin_clz(x)

vector<string> split(const string &s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c)) v.push_back(x);
	return v;
}

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }

void err(vector<string>::iterator it) {}

template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) {return (a < b) ? a : b;}
template<class T, class U> inline T tmax(T a, U b) {return (a > b) ? a : b;}
template<class T, class U> inline void amax(T &a, U b) {if (b > a) a = b;}
template<class T, class U> inline void amin(T &a, U b) {if (b < a) a = b;}
template<class T> inline T tabs(T a) {return (a > 0) ? a : -a;}
template<class T> T gcd(T a, T b) {while (b != 0) {T c = a; a = b; b = c % b;} return a;}

int R, C, N;


int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

inline bool inside(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

int solve() {
	vector<vector<bool>> s(R, vector<bool>(C, 1));
	int take = R * C - N;
	int ans = 2 * R * C - R - C;
	if (take == 0) return ans;
	bool done = 0;
	repd(d, 4, 0) {
		repu(i, 0, R) {
			repu(j, 0, C) {
				if (s[i][j]) {
					int tt = 0;
					repu(k, 0, 4) {
						int x = i + dx[k], y = j + dy[k];
						if (inside(x, y) && s[x][y]) tt++;
					}
					if (tt == d) {
						s[i][j] = 0;
						take--;
						ans -= d;
						if (take == 0) {
							done = 1; break;
						}
					}
				}
			}
			if (done) break;
		}
		if (done) break;
	}
	return ans;
}

int main(int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);
    
	int ntest;
	
	cin >> ntest;
	
	repu(t, 1, ntest + 1) {
		cin >> R >> C >> N;
		if (R > C) swap(R, C);
		vector<vector<bool>> s(R, vector<bool>(C, 0));
		int cnt = 0;
		repu(i, 0, R) {
			if (i & 1) {
				for (int j = 1; j < C; j += 2) s[i][j] = 1, cnt++;
			}
			else {
				for (int j = 0; j < C; j += 2) s[i][j] = 1, cnt++;
			}
		}
		int ans = 0;
		if (N > cnt) {
			vector<int> can;
			repu(i, 0, R) repu(j, 0, C) {
				if (!s[i][j]) {
					int tt = 0;
					repu(k, 0, 4) {
						int x = i + dx[k], y = j + dy[k];
						if (inside(x, y) && s[x][y]) tt++;
					}
					can.push_back(tt);
				}
			}
			sort(all(can));
			repu(i, 0, N - cnt) ans += can[i];
		}
		amin(ans, solve());
		printf("Case #%d: %d\n", t, ans);
	}
	
    return 0;
}
