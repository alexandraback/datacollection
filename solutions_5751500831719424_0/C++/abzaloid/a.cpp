#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>

using namespace std;

string s[101];

bool was[101][101];
int last[101];

            
int main () {
	
	freopen ("input.txt", "r", stdin);
 	freopen ("output.txt", "w", stdout);


 	int t;
 	cin >> t;

 	int test = 1;

 	while (t--) {
		
		int n;
 		cin >> n;
 		
 		bool ok = true;

 		int cnt = 0;
	
	    memset (was, false, sizeof(was));
	    memset (last, 0, sizeof(last));

 		for (int i = 0; i < n; i++)
 			cin >> s[i];
	
		vector <int> len;
		 	for (int i = 0; i < s[0].size() && ok; i++) {
		 	len.clear();			
			for (int j = 0; j < n && ok; j++) {
				int curLen = 0;
				bool finish = false;
				for (int k = last[j]; k < s[j].size() && ok; k++)
					if (s[j][k] == s[0][i]) {
						curLen++;
						was[j][k] = true;
					}
					else {
						finish = true;
						last[j] = k;
						break;
					}	
				if (curLen == 0) {
					ok = false;
					break;
				} else
					len.push_back(curLen);

				if (!finish)
					last[j] = s[j].size();
				
			}
	
	        
			int minSum = 999999999;
			
			for (int jj = 1; jj <= 110; jj++) {
			int curSum = 0;
			for (int ii = 0; ii < len.size(); ii++)
				curSum += abs (len[ii] - jj);
			minSum = min(minSum, curSum);	
			}
			cnt+=minSum;	
			i = last[0] - 1;
 		}

 		for (int i = 0; i < n; i++)
 			for (int j = 0; j < s[i].size(); j++)
 				if (!was[i][j])
 					ok = false;
	
		if (!ok) {
 			printf ("Case #%d: Fegla Won\n", test++);		
		} else 			
 			printf ("Case #%d: %d\n", test++, cnt);
 	}

	return 0;
}
