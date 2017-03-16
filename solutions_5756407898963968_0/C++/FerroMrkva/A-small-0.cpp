#include <algorithm>
#include <set>

using namespace std;

void solve_case(){
	set<int> res;
	res.clear();
	int k;
	scanf("%d",&k);
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			int x;
			scanf("%d",&x);
			if (i+1==k) res.insert(x);
		}
	}
	scanf("%d",&k);
	for(int i=0;i<4;++i){
		for(int j=0;j<4;++j){
			int x;
			scanf("%d",&x);
			if (i+1!=k) res.erase(x);
		}
	}
	if (!res.size()) puts("Volunteer cheated!");
	else if (res.size()>1) puts("Bad magician!");
	else printf("%d\n",*res.begin());
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d: ",t);
		solve_case();
	}
	return 0;
}
