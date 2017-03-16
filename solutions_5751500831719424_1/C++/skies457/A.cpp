#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

inline int abs(int x)
{
	if(x > 0) return x;
	return -x;
}

vector<char> ch;
vector<int> co[100];
vector<int> minimal;

char str[105];
int n;

bool read()
{
	bool bad = false;
	scanf("%d", &n);
	int len, k;
	ch.clear();
	minimal.clear();
	for(int i = 0; i < n; i++) {
		scanf("%s", str);
		len = strlen(str);
		co[i].clear();
		if(i == 0) {
			ch.push_back(str[0]);
			co[0].push_back(1);
			for(int j = 1; j < len; j++) {
				if(str[j] != str[j - 1]) {
					ch.push_back(str[j]);
					co[0].push_back(1);
				}
				else co[0][co[0].size() - 1]++;
			}
		} else {
			if(str[0] != ch[0]) bad = true;
			else {
				co[i].resize(ch.size());
				k = 1;
				co[i][0] = 1;
				for(int j = 1; j < len; j++) {
					if(str[j] != str[j - 1]) {
						if(k >= ch.size() || str[j] != ch[k]) {
							bad = true;
							break;
						} else {
							k++;
							co[i][k - 1] = 1;
						}
					} else {
						co[i][k - 1]++;
					}
				}
				if(k != ch.size()) {
					bad = true;
				}
			}
		}	
	}
	return !bad;
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int T = 1; T <= t; T++) {
		if(!read()) {
			printf("Case #%d: Fegla Won\n", T);
			continue;
		}
		minimal.resize(ch.size());
		for(int i = 0; i < minimal.size(); i++) {
			minimal[i] = 1;
			for(int j = 0; j < n; j++) {
				minimal[i] = max(co[j][i], minimal[i]);
			}
		}
		int ans = 0, best;
		for(int i = 0; i < ch.size(); i++) {
			best = 9999999;
			for(int s = 1; s <= minimal[i]; s++) {
				int current = 0;
				for(int j = 0; j < n; j++) {
					current += abs(co[j][i] - s);
				}
				best = min(best, current);
			}
			ans += best;
		}
		printf("Case #%d: %d\n", T, ans);
	}
	return 0;
}

