#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

typedef vector <int> vi;
typedef vector<vi>	vvi;
typedef pair<int, int> ii;
typedef vector<ii>  vii;

#define PROBLEM "A-small-attempt1"

void solve() {
    int n, m = 0;
    cin >> n;
    vii p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first;
        m += p[i].first;
        p[i].second = i;
    }
    sort(p.begin(), p.end(), greater<ii>());
    while(m) {
        if (m == 1) {
            cout << " " << (char)('A' + p[0].second);
            break;
        }
        int i, j;
        for (i = 0; i < p.size(); ++i) {
            if (i+1 == p.size() || p[i].first != p[i+1].first) {
                break;
            }
        }
        j = i;
        for (; i > 0 && m != 3; i -= 2) {
            cout << " " << (char)('A' + p[i-1].second) << (char)('A' + p[i].second);
            p[i].first -= 1;
            p[i-1].first -= 1;
            m -= 2;
        }
        if (i > 0 && m == 3) {
            cout << " " << (char)('A' + p[i].second);
            p[i].first -= 1;
            m -= 1;

        } else if (i == 0) {
            if (p[0].first - 2 >= p[1].first) {
                cout << " " << (char)('A' + p[0].second) << (char)('A' + p[0].second);
                p[0].first -= 2;
                m -= 2;
            } else {
                cout << " " << (char)('A' + p[0].second);
                p[0].first -= 1;
                m -= 1;
                if (m & 1 == 1) {
                    for (; j < p.size(); ++j) {
                        if (j+1 == p.size() || p[j].first != p[j+1].first) {
                            break;
                        }
                    }
                    cout << (char)('A' + p[j].second);
                    p[j].first -= 1;
                    m -= 1;
                }
            }
        }
    }
    std::cout << std::endl;
}

int main()
{
	freopen(PROBLEM ".in", "rt", stdin);
	freopen(PROBLEM ".out", "wt", stdout);

	int T;
	std::cin >> T;

	for (int t = 1; t <= T; ++t) {
		std::cout << "Case #" << t << ":";
		solve();
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
