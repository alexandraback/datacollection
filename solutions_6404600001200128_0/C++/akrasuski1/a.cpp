#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		int n;
		scanf("%d",&n);
		vector<int>m;
		for(int i=0;i<n;i++){
			int a;
			scanf("%d",&a);
			m.push_back(a);
		}
		int sum=0;
		for(int i=1;i<n;i++){
			if(m[i]<m[i-1]){
				sum-=m[i]-m[i-1];
			}
		}
		int mx=0;
		for(int i=1;i<n;i++){
			mx=max(mx,m[i-1]-m[i]);
		}
		int ans=0;
		for(int i=0;i<n-1;i++){
			ans+=min(mx,m[i]);
		}
		
		printf("Case #%d: %d %d\n",tc,sum,ans);
	}
}
