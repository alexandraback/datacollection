#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<map>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;



int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0..out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int casenum = 1;casenum<=t;casenum++){
		int n;
		vector<int> a;
		scanf("%d",&n);
		for(int i = 0;i<n;i++){
			int tmp;
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		long long sum = 0;
		int rate = 0;
		for(int i = 0;i<n-1;i++){
			if(a[i]>a[i+1]){
				sum+=a[i]-a[i+1];
				rate = max(rate, a[i]-a[i+1]);
			}
			
		}
		long long sum2 = 0;
		for(int i = 0;i<n-1;i++){
			sum2+=min(rate,a[i]);
		}
		cout <<"Case #"<<casenum<<": "<<sum<<" "<<sum2<<endl;
		
	}
	return 0;
}