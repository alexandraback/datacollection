#include <bits/stdc++.h>

using namespace std;

int N;
vector< pair<char,int> > vc[105];
void input(){
	scanf("%d", &N);
	char str[1024];
	for (int i=0; i<N; i++){
		scanf("%s", str);
		int len = strlen(str);
		char lst=str[0];
		int cnt=1;
		vc[i].clear();
		for (int j=1; j<len; j++){
			if (str[j] != lst){
				vc[i].push_back(make_pair(lst,cnt));
				lst = str[j];
				cnt = 1;
			} else {
				cnt++;
			}
		}
		vc[i].push_back(make_pair(lst,cnt));
	}
}
void solve(int nT){
	int M = vc[0].size();
	int fail=0;
	int ans=0;
	for (int i=1; i<N; i++){
		if (vc[i].size() != vc[i-1].size()){
			fail = 1;
			break;
		}
	}
	if (!fail){
		for (int j=0; j<M; j++){
			char ch = vc[0][j].first;
			vector<int> num;
			for (int i=0; i<N; i++){
				if (ch != vc[i][j].first){
					fail = 1;
					break;
				}
				num.push_back(vc[i][j].second);
			}
			if (fail){
				break;
			}
			sort(num.begin(),num.end());
			int mid = num[N/2];
			for (int i=0; i<N; i++){
				ans += abs(mid - num[i]);
			}
		}
	}

	if (fail){
		printf("Case #%d: Fegla Won\n", nT);
	} else {
		printf("Case #%d: %d\n", nT, ans);
	}
}

int main(){
	int nT;
	scanf("%d", &nT);
	for (int i=1; i<=nT; i++){
		input();
		solve(i);
	}
}