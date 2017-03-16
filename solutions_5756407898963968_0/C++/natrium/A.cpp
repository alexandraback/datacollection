#include <cstdio>
#include <vector>
#include <algorithm>

#define reps(i,f,n) for(int i=f; i<int(n); ++i)
#define rep(i,n) reps(i,0,n)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

void solve()
{
	int r;
	scanf("%d", &r);

	vector<bool> data(16, false);
	rep(i, 4) rep(j, 4){
		int a;
		scanf("%d", &a);
		--a;
		if(i+1 == r){
			data[a] = true;
		}
	}

	vi same;
	scanf("%d", &r);
	rep(i, 4) rep(j, 4){
		int a;
		scanf("%d", &a);
		--a;
		if(i+1 == r && data[a]){
			same.push_back(a);
		}
	}

	if(same.size() == 1){
		printf("%d\n", same[0]+1);
	}
	else if(same.size() == 0){
		puts("Volunteer cheated!");
	}
	else{
		puts("Bad magician!");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	rep(i, T){
		printf("Case #%d: ", i+1);
		solve();
	}
}
