/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int t1 = 1; t1 <= t; t1++) {
		int n;
		cin >> n;
		int a[n+1];
		int cnt[10010];
		memset(cnt, 0, sizeof(cnt));
		priority_queue < pair < int, int > > pq;
		for (int i = 0; i < n; i++) {
			cin >> a[i];		
			pq.push(make_pair(a[i], i));
			cnt[a[i]]++;
		}
		cout << "Case #" << t1 << ": ";
		while (!pq.empty()) {
			pair < int, int > top = pq.top();
			pq.pop();
			if (top.first != 0) {
				if (!pq.empty()) {
					pair < int, int > top1 = pq.top();
					if ((top.first == top1.first) && (cnt[top.first]%2 == 0)) {
						pq.pop();
						cout << (char)(top.second + 65) << (char)(top1.second + 65) << " ";
						cnt[top.first]--;
						cnt[top.first]--;
						top.first--;
						top1.first--;
						if (top.first >= 0) {
							cnt[top.first]++;
							cnt[top.first]++;
						}
						pq.push(top);
						pq.push(top1);
					}
					else {
						cout << (char)(top.second + 65) << " ";
						cnt[top.first]--;
						top.first--;
						if (top.first >= 0)
							cnt[top.first]++;
						pq.push(top);
					}
				}
				else {
					cout << (char)(top.second + 65) << " ";
					cnt[top.first]--;
					top.first--;
					if (top.first >= 0)
						cnt[top.first]++;
					pq.push(top);
				}
			}
		}
		cout << endl;
	}
	return 0;
}