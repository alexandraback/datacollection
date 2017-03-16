#include <bits/stdc++.h>
using namespace std;

const int MAXN = 26;

int N,senSum;
int sen[MAXN];

int main() {
	int T; scanf("%d",&T);
	for (int tt=1; tt<=T; tt++) {
		scanf("%d",&N);
		senSum = 0;
		for (int i=0; i<N; i++) {
			scanf("%d",&sen[i]);
			senSum += sen[i];
		}
		vector<string> plan;
		while (senSum > 0) {
			//for (int i=0; i<N; i++)
			//	cout << sen[i] << " "; cout << endl;
			int maxEle = *max_element(sen,sen+N);
			vector<char> sens;
			for (int i=0; i<N; i++) {
				if (sen[i] == maxEle) {
					sens.push_back(i+'A');
				}
			}
			// Try senators from same party
			sen[sens[0]-'A'] -= 2;
			senSum -= 2;
			bool valid = true;
			for (int i=0; i<N; i++) {
				if (sen[i] > senSum/2) {
					valid = false;
					break;
				}
			}
			if (valid) {
				string ps = ""; 
				ps += sens[0];
				ps += sens[0];
				plan.push_back(ps);
				continue;
			}else {
				senSum += 2;
				sen[sens[0]-'A'] += 2;
				//cout << "1 failed" << endl;
			}

			// Try single senator
			sen[sens[0]-'A']--;
			senSum--;
			valid = true;
			for (int i=0; i<N; i++) {
				if (sen[i] > senSum/2) {
					valid = false;
					break;
				}
			}
			if (valid) {
				string ps = "";
				ps += sens[0];
				plan.push_back(ps);
				continue;
			}else {
				senSum++;
				sen[sens[0]-'A']++;
				//cout << "2 failed" << endl;
			}

			// Make sure that there are two elements
			assert(sens.size() >= 2);
			sen[sens[0]-'A']--;
			sen[sens[1]-'A']--;
			senSum -= 2;
			valid = true;
			for (int i=0; i<N; i++) {
				if (sen[i] > senSum/2) {
					valid = false;
					break;
				}
			}
			if (valid) {
				string ps = "";
				ps += sens[0];
				ps += sens[1];
				plan.push_back(ps);
			}
		}
		printf("Case #%d: ",tt);
		for (string s : plan)
			printf("%s ",s.c_str());
		printf("\n");
	}
	return 0;
}