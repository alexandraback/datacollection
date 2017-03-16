#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;

const int N = 1005;

#define fo(i , st , en) for (int i = st; i <= en; i++)
#define Me(x , y) memset(x , y , sizeof(x))

int t , n , id;
int a[N];
pi b[N];

int main(){
	freopen("t2.in" , "r" , stdin);
	freopen("t2.out" , "w" , stdout);
	scanf("%d" , &t);
	fo (p , 1 , t){
		scanf("%d%d" , &n , &id);
		fo (i , 1 , n) scanf("%d" , a + i);
		if (id <= n){
			printf("Case #%d: %d\n" , p , id); continue;
		}
		ll left = 0 , right = (ll)1e15;
		while (left < right){
			ll mid = left + right + 1 >> 1;
			ll num = 0;
			fo (i , 1 , n) num += mid / a[i] + 1;
			if (num < id) left = mid; else right = mid - 1;
		}
		int cur = 0;
		fo (i , 1 , n) cur += left / a[i] + 1;
		fo (i , 1 , n) b[i] = pi(a[i] - left % a[i] , i);
		sort(b + 1 , b + n + 1);
		printf("Case #%d: %d\n" , p , b[id - cur].second);
	}
	return 0;
}
