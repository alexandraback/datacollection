#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

int main(void) {
	int t, testCases;
	cin >> testCases;
	int N, i, j, sameContents, answer, run, index, max, min;
	string s, uniqueS;
	vector<string> str, uniqueStr;
	int counts[128][128];
	
	for (t=1; t<=testCases; t++) {
		cin >> N;
		str.clear();
		for (i=0; i<N; i++) {
			cin >> s;
			str.push_back(s);
		}
		uniqueStr.clear();
		for (i=0; i<N; i++) {
			s = str[i];
			uniqueS.clear();
			uniqueS.push_back(s[0]);
			for (j=1; j<(int)s.length(); j++) {
				if (s[j] != s[j-1]) uniqueS.push_back(s[j]);
			}
			uniqueStr.push_back(uniqueS);
		//	printf("str %s\n", uniqueS.c_str());
		}
		sameContents = 1;
		for (i=1; i<N; i++) {
			if (uniqueStr[0] != uniqueStr[i]) { sameContents = 0; break; }
		}
		
		printf("Case #%d: ", t);
		
	//	printf("sameContents %d\n", sameContents);
		if (sameContents) {
			for (i=0; i<N; i++) {
				run = 1;
				index = 0;
				for (j=1; j<(int)str[i].length(); j++) {
					if (str[i][j] != str[i][j-1]) {
						counts[i][index++] = run;
						run = 1;
					}
					else run++;
				}
				counts[i][index++] = run;
				assert(index == (int)uniqueStr[0].length());
			//	for (j=0; j<index; j++) printf("%d ", counts[i][j]); printf("\n");
			}
			answer = 0;
			for (j=0; j<(int)uniqueStr[0].length(); j++) {
				max = counts[0][j];
				min = max;
				for (i=1; i<N; i++) {
					if (counts[i][j] > max) max = counts[i][j];
					if (counts[i][j] < min) min = counts[i][j];
				}
				answer += (max-min);
			}
			printf("%d", answer);
		}
		else {
			printf("Fegla Won");
		}
		
		printf("\n");
	}
	
	
	return 0;
}