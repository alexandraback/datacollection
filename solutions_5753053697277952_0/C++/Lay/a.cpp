#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <sstream>
#include <map>
#include <queue>
#include <stack>

using namespace std;

int main()
{
	int T;
	cin>>T;

	for(int t=1;t<=T;t++){
		int n;
		cin>>n;
		
		int cnt[26]={};
		int sum=0;
		for(int i=0;i<n;i++) cin>>cnt[i],sum+=cnt[i];
		
		string ans;
		while(sum){
			int tar=-1;
			
			for(int i=0;i<n;i++){
				if(tar==-1 || cnt[tar]<cnt[i]) tar=i;	
			}
			sum--;
			cnt[tar]--;
			ans+=(char)('A'+tar);
			
			tar=-1;
			for(int i=0;i<n;i++){
				if(tar==-1 || cnt[tar]<cnt[i]) tar=i;	
			}
			
			int tar2=-1;
			for(int i=0;i<n;i++){
				if(i==tar) continue;
				if(tar2==-1 || cnt[tar2]<cnt[i]) tar2=i;
			}
			
			if(2*cnt[tar2]<=sum-1){
				sum--;
				cnt[tar]--;
				ans+=(char)('A'+tar);				
			}
			
			ans+=' ';
		}

		printf("Case #%d: %s\n",t,ans.c_str());
	}

	return 0;
}