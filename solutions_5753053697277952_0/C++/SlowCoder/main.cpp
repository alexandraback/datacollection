
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <bitset>
#include <deque>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
#include <numeric>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <utility>

#define i64 long long
#define ui64 unsigned long long

using namespace std;

#define READ_IN_FILE 1

#ifdef ONLINE_JUDGE
#define READ_IN_FILE 0
#endif

int cnt[26] = {0};

string solve() {
    
    string result;
    
    while (true) {
        int m1 = -1, m1i = 0, m2 = -1, m2i = 0, nz_cnt = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] > m1) {
                m2 = m1;
                m2i = m1i;
                m1 = cnt[i];
                m1i = i;
            } else if (cnt[i] > m2) {
                m2 = cnt[i];
                m2i = i;
            }
            
            if (cnt[i] > 0) nz_cnt++;
        }
    
        if (nz_cnt == 0) return result;
        
        if (m1 == 1 && nz_cnt % 2) {
            cnt[m1i]--;
            result.push_back('A' + m1i);
            result.push_back(' ');
            continue;
        }

        cnt[m1i]--;
        cnt[m2i]--;
        result.push_back('A' + m1i);
        result.push_back('A' + m2i);
        result.push_back(' ');

    }
    return result;
}

int main()
{
	if (READ_IN_FILE) freopen("in.in", "r", stdin);
	int T = 0;
	scanf("%d\n", &T);
	if (!T) { cerr << "Check input!" << endl; exit(0); }

    // Each case
	for (int t = 1; t <= T; t++) {

        int n;
        cin >> n;
        
        memset(cnt, 0, 26 * sizeof(int));
        
        for (int i = 0; i < n; i++) {
            cin >> cnt[i];
        }

        printf("Case #%d: %s\n", t, solve().c_str());
    }
	
    
	if (READ_IN_FILE) fclose(stdin);
	return 0;
}
