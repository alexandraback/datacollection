#include<cstdio>
#include<algorithm>
using namespace std;
int n,i,j,a[1001];
long long x,ub,lb,mid,s;
bool check(long long r){
    s=n;
    for(j=1;j<=n;j++){
        s+=r/a[j];
    }
    return s>=x;
}
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("test123.txt", "w", stdout);
	int tn = 0;
	scanf("%d", &tn);
	for(int w = 1; w <= tn; w++){
    scanf("%d%lld",&n,&x);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    lb = 0;
    ub = x * 100000;
    for(i = 0; i < 100; i++){
    	mid = (lb + ub) / 2;
    	if(check(mid))
    	ub = mid;
    	else
    	lb = mid;
	}
	int before = n;
	int ans = 0;
	for(i = 1; i <= n; i++){
		before+= ((ub - 1) / a[i]);
	}
	if(ub == 0)
	before = 0;
	for(i = 1; i <= n; i++){
		if(ub % a[i] == 0)
		before++;
		if(before == x){
			ans = i;
			before++;
		}
	}
	printf("Case #%d: %d\n", w, ans);
	}
}
