#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const double EPS=1e-12;

int n,my;
int bar[1111];

bool input(){
	scanf("%d%d",&n,&my);
	for(int i=0; i<n; i++)scanf("%d",&bar[i]);
	return 1;
}

void solve(){
    static int cas=1;
    printf("Case #%d: ",cas++);
    LL lb=-1,ub=1011110000LL*10000;//ub is ok
    
    while(1<ub-lb){
        LL md=(lb+ub)/2;
        LL cnt=0;
        for(int i=0;i<n; i++)
            cnt+= md/bar[i];
        if(my<=cnt+n)
            ub=md;
        else
            lb=md;
    }
    LL t=ub;
    if(t==0){
        printf("%d\n",my);
        return;
    }
    // printf("t=%lld\n",t);
    vector<int>res;
    LL cnt=n;
    for(int i=0;i<n; i++){
        if (0==t%bar[i])res.push_back(i);
        cnt+= t/bar[i];
    }
    // printf("my %d cnt %lld\n",my,cnt);
    // for(auto a:res)printf("%d ",a);
    //     printf("\n");
    printf("%d\n",res[res.size()-1-(cnt-my)]+1);
}

int main()
{
	int zz;
	scanf("%d",&zz);
	while(zz--){
	    input();
		solve();
	}
    return 0;
}
/*

6 2
ioi
1 3

5 2
ioi
1 2

*/