#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
// q.push(el);
// q.front(); q.pop(); 

#include <sstream>
// ostringstream buf;

#include <cstdio>
// sscanf(time.c_str(), "%d:%d:%d", &H, &M, &S);

#include <limits>
// std::numeric_limits<long long>::max();

#include <cctype>
// std::toupper(c)

typedef long long ll;

int find_cn(const std::vector<std::vector<bool>>& M, int i, int j) {
    int ans = 0;
    if (M[i+1][j  ]) ans++;
    if (M[i  ][j+1]) ans++;
    if (M[i-1][j  ]) ans++;
    if (M[i  ][j-1]) ans++;
    return ans;
}

int main() {
    int T;
    std::cin >> T;

    for (int icase = 1; icase<=T; icase++) {
	int R, C, N;
	std::cin >> R >> C >> N;

	std::vector<std::vector<bool>> M(R + 2, std::vector<bool>(C + 2, false));
	for (int i = 1; i<=R; i++)
	    for (int j = 1; j<=C; j++)
		M[i][j] = true;

	int nrem = R*C - N;
	while (nrem--) {
	    int im = -1;
	    int jm = -1;
	    int nm = std::numeric_limits<int>::min();

	    for (int i = 1; i<=R; i++)
		for (int j = 1; j<=C; j++) {
		    if (!M[i][j]) continue;
		    int const cn = find_cn(M, i, j);
		    if (cn>nm) {
			im = i;
			jm = j;
			nm = cn;
		    }
		}
	    M[im][jm] = false;
	}

	int ans = 0;
	for (int i = 1; i<=R; i++)
	    for (int j = 1; j<=C; j++) {
		if (!M[i][j]) continue;
		ans += find_cn(M, i, j);
	    }
	ans /= 2;

	std::cout << "Case #" << icase << ": " << ans << '\n';
    }

}
