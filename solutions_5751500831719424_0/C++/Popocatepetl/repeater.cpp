#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n;
		scanf("%d", &n);
		vector<int> vi(n, 0), vp(n, 0);
		vector<string> vs;
		string str;
		for(int j = 0; j < n; ++j){
			cin >> str;
			vs.push_back(str);
		}
		long long vysledok = 0;
		bool ok = true;
		while(vi[0] < int(vs[0].length())){
			char z = vs[0][vi[0]];
			for(int j = 0; j < n; ++j){
				if(vi[j] >= int(vs[j].length()) || vs[j][vi[j]] != z) ok = false;
				while(vi[j] < int(vs[j].length()) && vs[j][vi[j]] == z){
					vi[j]++;
					vp[j]++;
				}
			}
			if(ok){
				int hodnota;
				sort(vp.begin(), vp.end());
				if(n % 2 == 1){
					int stred = n / 2;
					hodnota = vp[stred];
				} else {
					int s1 = (n / 2) - 1;
					hodnota = (vp[s1] + vp[s1 + 1]) / 2;
				}
				for(int k = 0; k < n; ++k){
					int plus = hodnota - vp[k];
					if(plus < 0) plus -= (2 * plus);
					vysledok += plus;
				}
			}
			for(int k = 0; k < n; ++k){
				vp[k] -= vp[k];
			}
		}
		for(int k = 0; k < n; ++k){
			if(vi[k] < int(vs[k].length())) ok = false;
		}
		printf("Case #%d: ", i + 1);
		if(ok){
			printf("%lld\n", vysledok);
		} else {
			printf("Fegla Won\n");
		}
	}
	return 0;
}
