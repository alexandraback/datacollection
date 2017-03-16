#include <cstdio>
#include <vector>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T,n;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		string s[109],ss[109];
		vector<int> cnt[109];
		scanf("%d",&n);
		for (int i=0; i<n; ++i) {
			int begin=0;
			cin>>s[i];
			ss[i].push_back(s[i][0]);
//			cout<<ss[i]<<endl;
			for (int j=1; j<s[i].size(); ++j) {
				if (s[i][j]!=s[i][j-1]) {
					ss[i].push_back(s[i][j]);
					cnt[i].push_back(j-begin);
					begin=j;
				}
			}
			cnt[i].push_back(s[i].size()-begin);
		}
		int i=1;
		for (i=1; i<n; ++i) {
//			printf("%d\n",cnt[i].size());
			if (ss[i]!=ss[0]) {
				printf("Case #%d: Fegla Won\n",iT);
				break;
			}
		}
		if (i==n) {
			int ans=0;
			for (int j=0; j<cnt[0].size(); ++j) {
				int min=1e6;
				for (int to=0; to<=100; ++to) {
					int sum=0;
					for (int l=0; l<n; ++l) {
						sum+=abs(cnt[l][j]-to);
					}
					if (sum<min) {
						min=sum;
					}
				}
//				printf("\nmin=%d\n",min);
				ans+=min;
			}
			printf("Case #%d: %d\n",iT,ans);
		}
	}
    return 0;
}