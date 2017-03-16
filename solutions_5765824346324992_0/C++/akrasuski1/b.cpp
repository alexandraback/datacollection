#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		fprintf(stderr,"%d\n",tc);
		int b,n;
		scanf("%d %d",&b,&n);
		vector<int>m;
		for(int i=0;i<b;i++){
			int a;
			scanf("%d",&a);
			m.push_back(a);
		}
		set<pair<int,int>>barbers;
		for(int i=0;i<b;i++){
			barbers.insert(pair<int,int>(-1,i));//first one is time when they end their job, 
			//second id
		}
		int prod=1;
		for(int i=0;i<b;i++){
			prod*=m[i];
		}
		int sum=0;
		for(int i=0;i<b;i++){
			sum+=prod/m[i];
		}
		n%=sum;
		n+=sum;

		for(int i=0;i<n-1;i++){
			pair<int,int> barb=*(barbers.begin());
			barbers.erase(barbers.begin());
			barb.first+=m[barb.second];
			barbers.insert(barb);
		}
		printf("Case #%d: %d\n",tc,barbers.begin()->second+1);
	}
}
